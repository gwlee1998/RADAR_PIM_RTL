#ifndef __ERVP_FAKEFILE_H__
#define __ERVP_FAKEFILE_H__

typedef struct text{
  void *base_pt;
  void *current_pt;
  void *end_pt;
} FAKEFILE;

#define ffopen ffopen_
FAKEFILE *ffopen_(char *pt, int mem_size);

#define ffgetl ffgetl_
char *ffgetl_(FAKEFILE *mem);

#define ffread ffread_
void ffread_(void *dest, int size, int count, FAKEFILE *mem);

#endif
