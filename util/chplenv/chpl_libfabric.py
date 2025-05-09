#!/usr/bin/env python3
import sys
import glob
import os

import chpl_comm, chpl_comm_debug, chpl_launcher, chpl_platform, chpl_comm_ofi_oob
import overrides, third_party_utils

from utils import error, memoize, try_run_command, warning, check_valid_var

@memoize
def get():
    comm_val = chpl_comm.get()
    if comm_val == 'ofi':
        libfabric_val = overrides.get('CHPL_LIBFABRIC')
        if not libfabric_val:
            if third_party_utils.pkgconfig_system_has_package('libfabric'):
                libfabric_val = 'system'
            else:
                libfabric_val = 'bundled'

        check_valid_var('CHPL_LIBFABRIC', libfabric_val, ['bundled', 'system'])
        if chpl_platform.is_hpe_cray('target') and libfabric_val != 'system':
            warning('CHPL_LIBFABRIC!=system is discouraged on HPE Cray')

    else:
        libfabric_val = 'none'

    return libfabric_val


@memoize
def get_uniq_cfg_path():
    base_uniq_cfg = third_party_utils.default_uniq_cfg_path()
    if chpl_comm_debug.get() == 'debug':
        base_uniq_cfg += '-debug'
    oob = chpl_comm_ofi_oob.get()
    return base_uniq_cfg + '/oob-' + oob

# returns 2-tuple of lists
#  (compiler_bundled_args, compiler_system_args)
@memoize
def get_compile_args():
    args = ([ ], [ ])
    libfabric_val = get()
    if libfabric_val == 'bundled':
        ucp_val = get_uniq_cfg_path()
        args = third_party_utils.get_bundled_compile_args('libfabric',
                                                          ucp=ucp_val)
    elif libfabric_val == 'system':
        flags = [ ]

        # Allow overriding pkg-config via LIBFABRIC_DIR, for platforms
        # without pkg-config.
        libfab_dir_val = overrides.get('LIBFABRIC_DIR')
        if libfab_dir_val:
            args[1].append('-I' + libfab_dir_val + '/include')
        else:
            # Try using pkg-config to get the compile-time flags.
            x = third_party_utils.pkgconfig_get_system_compile_args('libfabric')
            if x == (None, None):
                error("Could not find a system install of 'libfabric', try setting LIBFABRIC_DIR")
            args = x

    return args


# returns 2-tuple of lists
#  (linker_bundled_args, linker_system_args)
@memoize
def get_link_args():
    args = ([ ], [ ])
    libfabric_val = get()
    if libfabric_val == 'bundled':
        args = third_party_utils.pkgconfig_get_bundled_link_args(
                                          'libfabric', ucp=get_uniq_cfg_path())
    elif libfabric_val == 'system':
        libs = [ ]
        # Allow overriding pkg-config via LIBFABRIC_DIR, for platforms
        # without pkg-config.
        libfab_dir_val = overrides.get('LIBFABRIC_DIR')
        if libfab_dir_val:
            libs.extend(['-L' + libfab_dir_val + '/lib',
                         '-Wl,-rpath,' + libfab_dir_val + '/lib',
                         '-lfabric'])
        else:
            # Try using pkg-config to get the libraries to link
            # libfabric with.
            tup = third_party_utils.pkgconfig_get_system_link_args('libfabric')
            if tup == (None, None):
                error("Could not find a system install of 'libfabric', try setting LIBFABRIC_DIR")
            # put the two lists together (but expect tup[0] to be empty)
            pclibs = tup[0] + tup[1]

            # add -Wl,-rpath for the -L options
            # this was a workaround and is probably not needed anymore
            for pcl in pclibs:
                libs.append(pcl)
                if pcl.startswith('-L'):
                    libs.append(pcl.replace('-L', '-Wl,-rpath,', 1))

        args[1].extend(libs)

    return args


def _main():
    libfabric_val = get()
    sys.stdout.write("{0}\n".format(libfabric_val))


if __name__ == '__main__':
    _main()
