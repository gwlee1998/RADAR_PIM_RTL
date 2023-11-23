#ifndef __ERVP_BIT_UTIL_H__
#define __ERVP_BIT_UTIL_H__

#include "ervp_printf.h"

static inline unsigned int generate_mask_by_size(unsigned int bit_size)
{
	return (1<<bit_size) - 1;
}

static inline unsigned int generate_mask_by_index(unsigned int upper_index, unsigned int lower_index)
{
	unsigned int mask;
	if(upper_index==lower_index)
		mask = (1 << upper_index);
	else
		mask = generate_mask_by_size(upper_index+1) - generate_mask_by_size(lower_index);
	return mask;
}

static inline unsigned int clear_bits_by_index(unsigned int value, unsigned int upper_index, unsigned int lower_index)
{
	unsigned int updated_value;
	updated_value = value & (~generate_mask_by_index(upper_index, lower_index));
	return updated_value;
}

static inline unsigned int set_bits_by_index(unsigned int value, unsigned int upper_index, unsigned int lower_index)
{
	unsigned int updated_value;
	updated_value = value | generate_mask_by_index(upper_index, lower_index);
	return updated_value;
}

static inline unsigned int get_partial_bits_by_size(unsigned int value, unsigned int bit_size)
{
	return (value & generate_mask_by_size(bit_size));
}

static inline unsigned int get_partial_bits_by_index(unsigned int value, unsigned int upper_index, unsigned int lower_index)
{
	return (get_partial_bits_by_size(value, upper_index+1) >> lower_index);
}

static inline unsigned int replace_partial_bits(unsigned int value, unsigned int upper_index, unsigned int lower_index, unsigned int new_value)
{
	return clear_bits_by_index(value, upper_index, lower_index) | (get_partial_bits_by_size(new_value,upper_index-lower_index+1) << lower_index);
}

static inline int check_if_bit_is_set(unsigned int value, unsigned int index)
{
  return ((value>>index)&1);
}

static inline int check_if_has_same_bits(unsigned int value, unsigned int ref)
{
  return ((value&ref)!=0);
}

#endif
