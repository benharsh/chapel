// refCountedType.chpl
//
// Implementation of a reference counted type for use in other tests.
//


// The implementation of a reference-counted type.
// Invariants:
//  - The contents of the reference count in the implementation is always
//    equal to the number of handles pointing to it.
class Impl 
{
  var count: int; // The reference count
  var value: real; // the payload.
  var freed: bool = false;

  proc retain() { count += 1; }
  proc release() : int { count -= 1; return count; }
}

// A handle to the reference-counted type,.
// Copying a handle creates a new reference to the implementation, so the 
// reference count therein must be increased.
// Deleting a handle removes a reference from the implementation, so the
// reference count therein must be decremented.
// When the reference count goes to zero, the implementation is deleted.
record Handle
{
  var _impl : unmanaged Impl?;

  proc init() { _impl = nil; }

  proc init(val: real) { _impl = new unmanaged Impl(1, val); }

  proc init=(other: Handle) {
    if other._impl == nil then halt("Illegal copy of uninitialized Handle.");
    _impl = other._impl;
    _impl!.retain();
  }


// Destructor
  proc ref deinit() { this.release_helper(); }
  inline proc ref release_helper()
  {
    if _impl != nil && _impl!.release() == 0
    {
      _impl!.freed = true;
      delete _impl;
      _impl = nil;
    }
  }

// Accessors
  proc value do return _impl!.value;
  proc freed do return _impl!.freed;
}

// Assignment
operator Handle.=(ref lhs: Handle, rhs:Handle)
{
  // The rhs gains a new reference.
  if rhs._impl == nil then halt("Illegal read of uninitialized Handle.");
  rhs._impl!.retain();

  // The lhs loses a reference.
  lhs.release_helper();

  // The handle now copies a reference to its implementation from the RHS.
  // The implementation is of class type, so this is a pointer copy.
  lhs._impl = rhs._impl;
}
