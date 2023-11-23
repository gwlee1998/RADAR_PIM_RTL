/*======================================================================*/
/* Proxy kernel linker script                                           */
/*======================================================================*/
/* This is the linker script used when building the proxy kernel. */

/*----------------------------------------------------------------------*/
/* Setup                                                                */
/*----------------------------------------------------------------------*/

/* The OUTPUT_ARCH command specifies the machine architecture where the
   argument is one of the names used in the BFD library. More
   specifically one of the entires in bfd/cpu-mips.c */

OUTPUT_ARCH( "riscv" )

MEMORY 
{
  sram (rwx)  : ORIGIN = 0x40080000, LENGTH = 0x40000
}
ENTRY(_start)

SECTIONS
{
	.text.init	:
  {
		_cacheable_start = .;
		*(.text.init)
		. = ALIGN(8);
		*(.init)
		. = ALIGN(8);
  } >sram

	.text :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    *(.text .text.*)
    *(.gnu.linkonce.t.*)
		. = ALIGN(8);
  } >sram

  .rodata	:
  {
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
		. = ALIGN(8);
  } >sram
	
	.stack :
	{
		. = ALIGN(64);
		. += (0x2000*2);
		. = ALIGN(64);
		PROVIDE( _sp = . );
	} >sram

	.cached :
	{
		. = ALIGN(64);
		*(.cached)
		*(.exclusive)
		. = ALIGN(131072);
		_cacheable_end = NEXT(64);
  } >sram
	.bigdata :
	{
		. = ALIGN(64);
		*(.bigdata)
	} >sram

	.once :
	{
		. = ALIGN(64);
		*(.once)
	} >sram

	.bigdata_bss :
	{
		. = ALIGN(64);
		_bigdata_bss_start = .;
		*(.bigdata_bss)
		_bigdata_bss_end = NEXT(4);
	} >sram
	.fini           :
	{
		KEEP (*(SORT_NONE(.fini)))
	} >sram

	.preinit_array  :
	{
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	} >sram

	.init_array     :
	{
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
		KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
		PROVIDE_HIDDEN (__init_array_end = .);
	} >sram

	.fini_array     :
	{
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
		KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
		PROVIDE_HIDDEN (__fini_array_end = .);
	} >sram

	.ctors          :
	{
		KEEP (*crtbegin.o(.ctors))
		KEEP (*crtbegin?.o(.ctors))
		KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
		KEEP (*(SORT(.ctors.*)))
		KEEP (*(.ctors))
	} >sram

	.dtors          :
	{
		KEEP (*crtbegin.o(.dtors))
		KEEP (*crtbegin?.o(.dtors))
		KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
		KEEP (*(SORT(.dtors.*)))
		KEEP (*(.dtors))
	} >sram
	
	.data :
	{
		. = ALIGN(8);
		*(.data .data.*)
    *(.gnu.linkonce.d.*)
		. = ALIGN(8);
		*(.notcached)
		. = ALIGN(8);
	} >sram

	.sdata :
	{
		. = ALIGN(8);
		_gp = . + 0x800;
		*(.sdata .sdata.*)
    *(.gnu.linkonce.s.*)
		. = ALIGN(8);
		*(.srodata .srodata.*)
		. = ALIGN(8);
  } >sram

  .sbss :
	{
		. = ALIGN(8);
		PROVIDE( _fbss = . );
		_bss_start = .;
    *(.sbss .sbss.* .gnu.linkonce.sb.*)
    *(.scommon)
		. = ALIGN(8);
	} >sram

	.bss :
	{
		. = ALIGN(8);
		*(.bss .bss.*)
		*(.gnu.linkonce.b.*)
		*(COMMON)
		. = ALIGN(8);
		_bss_end = NEXT(4);
	} >sram
  .must_sram :
	{
    . = ALIGN(64);
	} >sram

  .heap_sram :
	{
		. = ALIGN(64);
		_heap_sram_start = .;
	} >sram
	/DISCARD/ : {}
}
