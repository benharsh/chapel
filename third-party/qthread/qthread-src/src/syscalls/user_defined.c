#include <stdint.h>

/* System Headers */
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include <sys/syscall.h> /* for SYS_accept and others */

/* Internal Headers */
#include "qt_asserts.h"
#include "qt_io.h"
#include "qt_qthread_mgmt.h"
#include "qthread_innards.h" /* for qlib */

extern TLS_DECL(qthread_t *, IO_task_struct);

void API_FUNC qt_begin_blocking_action(void) {
  qthread_t *me;

  if ((qlib != NULL) && ((me = qthread_internal_self()) != NULL)) {
    qt_blocking_queue_node_t *job = ALLOC_SYSCALLJOB();

    assert(job);
    job->next = NULL;
    job->thread = me;
    job->op = USER_DEFINED;

    assert(me->rdata);

    me->rdata->blockedon.io = job;
    atomic_store_explicit(
      &me->thread_state, QTHREAD_STATE_SYSCALL, memory_order_relaxed);
    qthread_back_to_master(me);
    /* ...and I wake up in a dedicated pthread! */
  }
}

void API_FUNC qt_end_blocking_action(void) {
  qthread_t *me = TLS_GET(IO_task_struct);

  if ((qlib != NULL) && (me != NULL)) {
    assert(me != NULL);
    qthread_back_to_master(me);
  }
}

/* vim:set expandtab: */
