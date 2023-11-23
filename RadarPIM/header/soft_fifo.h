#ifndef __SOFT_FIFO_H__
#define __SOFT_FIFO_H__

#define FIFO_MAX_SIZE 100

typedef struct
{
  int storage[FIFO_MAX_SIZE];
  int wtag;
  int rtag;
} SoftFifo;

void soft_fifo_init(SoftFifo* fifo);
int soft_fifo_is_empty(const SoftFifo* fifo);
int soft_fifo_is_full(const SoftFifo* fifo);
int soft_fifo_valid_size(const SoftFifo* fifo);
void soft_fifo_push(SoftFifo* fifo, int value);
int soft_fifo_pop(SoftFifo* fifo);

#endif
