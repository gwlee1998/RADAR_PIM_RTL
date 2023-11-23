#ifndef __ERVP_BARRIER_H__
#define __ERVP_BARRIER_H__

#include "platform_info.h"

#ifdef INCLUDE_MULTICORE

void reach_and_pass_barrier(int barrier_index, int num_core);
int request_unique_grant(int barrier_index, int num_core);
void release_unique_grant(int barrier_index, int num_core);

#else

static inline void reach_and_pass_barrier(int barrier_index, int num_core){ return; }
static inline int request_unique_grant(int barrier_index, int num_core){ return 1; }
static inline void release_unique_grant(int barrier_index, int num_core){ return; }

#endif

#endif
