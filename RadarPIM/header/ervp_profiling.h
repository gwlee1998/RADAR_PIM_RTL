#ifndef __ERVP_PROFILING_H__
#define __ERVP_PROFILING_H__

#include "platform_info.h"

#ifdef USE_PROFILING

void profiling_start(const char* name);
void profiling_end(const char* name);
void profiling_print();

#else

static inline void profiling_start(const char* name){};
static inline void profiling_end(const char* name){};
static inline void profiling_print(){};

#endif

#endif
