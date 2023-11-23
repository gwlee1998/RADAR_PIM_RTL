.global GET_AUTO_ID
.global SET_STACK_POINTER

.macro GET_AUTO_ID
	li t0, (MMAP_PLATFORM_REGISTER_PROC_AUTO_ID)
	lw a0, 0(t0)
.endm

.macro SET_STACK_POINTER
	li t0, STACK_SIZE
	mul t0, t0, a0
	la sp, _sp
	sub sp, sp, t0
.endm

.macro INIT_ONCE
	la a0, _bss_start
	la a1, _bss_end
	jal clear_bss
	la a0, _bigdata_bss_start
	la a1, _bigdata_bss_end
	jal clear_bss
	la a0, __libc_fini_array
	call atexit
	call __libc_init_array
	INIT_HEAP
	jal set_initialized
.endm

.macro INIT_HEAP
#ifdef INCLUDE_SRAM
	la a0, _heap_sram_start	
#else
	li a0, 0
#endif
#ifdef INCLUDE_DRAM
	la a1, _heap_dram_start	
#else
	li a1, 0
#endif
	jal init_heap
.endm

.macro INIT_EACH_CORE
	la a0, _cacheable_start
	la a1, (_cacheable_end-1)
	jal init_each_core
.endm

.macro INIT_PLATFORM
	jal init_platform
.endm
