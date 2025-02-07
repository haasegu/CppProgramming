	.file	"Ex1121_file.cpp"
	.text
	.p2align 4
	.type	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, @function
_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0:
.LFB3613:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	(%rdi), %rax
	movq	-24(%rax), %rax
	movq	240(%rdi,%rax), %r12
	testq	%r12, %r12
	je	.L7
	cmpb	$0, 56(%r12)
	movq	%rdi, %rbp
	je	.L3
	movsbl	67(%r12), %esi
.L4:
	movq	%rbp, %rdi
	call	_ZNSo3putEc@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	movq	%rax, %rdi
	popq	%r12
	.cfi_def_cfa_offset 8
	jmp	_ZNSo5flushEv@PLT
.L3:
	.cfi_restore_state
	movq	%r12, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%r12), %rax
	movl	$10, %esi
	movq	%r12, %rdi
	call	*48(%rax)
	movsbl	%al, %esi
	jmp	.L4
.L7:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE3613:
	.size	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0, .-_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Calculation of polynom with degree "
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC3:
	.string	"  Read X"
.LC4:
	.string	"  x = "
.LC6:
	.string	"slow (   pow) = "
.LC8:
	.string	" ("
.LC9:
	.string	" sec.)"
.LC10:
	.string	"fast (no pow) = "
	.section	.text.unlikely,"ax",@progbits
.LCOLDB11:
	.section	.text.startup,"ax",@progbits
.LHOTB11:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2884:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2884
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pxor	%xmm0, %xmm0
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$152, %rsp
	.cfi_def_cfa_offset 208
	movq	%fs:40, %rax
	movq	%rax, 136(%rsp)
	xorl	%eax, %eax
	leaq	112(%rsp), %rax
	leaq	96(%rsp), %rdi
	movq	$10, 104(%rsp)
	movq	%rax, 32(%rsp)
	leaq	64(%rsp), %rsi
	movq	%rax, 96(%rsp)
	movabsq	$3544665459438677609, %rax
	movq	%rax, 112(%rsp)
	movl	$12594, %eax
	movw	%ax, 120(%rsp)
	movb	$0, 122(%rsp)
	movq	$0, 80(%rsp)
	movaps	%xmm0, 64(%rsp)
.LEHB0:
	call	_Z21read_vector_from_fileRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt6vectorIdSaIdEE@PLT
	movq	72(%rsp), %rbp
	leaq	_ZSt4cout(%rip), %r14
	subq	64(%rsp), %rbp
	movl	$35, %edx
	sarq	$3, %rbp
	leaq	.LC2(%rip), %rsi
	movq	%r14, %rdi
	movl	%ebp, %r13d
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leal	-1(%rbp), %eax
	movq	%r14, %rdi
	movl	%eax, %esi
	movl	%eax, 44(%rsp)
	call	_ZNSolsEi@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$8, %edx
	leaq	.LC3(%rip), %rsi
	movq	%r14, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$6, %edx
	leaq	.LC4(%rip), %rsi
	movq	%r14, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	56(%rsp), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSi10_M_extractIdEERSiRT_@PLT
	movq	%r14, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movl	$10000000, %r12d
	movl	%ebp, %ebp
	movq	$0x000000000, 24(%rsp)
	movq	%rax, _ZL11MyStopWatch(%rip)
	.p2align 4,,10
	.p2align 3
.L9:
	pxor	%xmm2, %xmm2
	testl	%r13d, %r13d
	js	.L13
	movsd	56(%rsp), %xmm7
	movq	64(%rsp), %rbx
	xorl	%r15d, %r15d
	pxor	%xmm2, %xmm2
	movsd	%xmm7, 16(%rsp)
	.p2align 4,,10
	.p2align 3
.L10:
	pxor	%xmm1, %xmm1
	movsd	16(%rsp), %xmm0
	movsd	%xmm2, 8(%rsp)
	cvtsi2sdl	%r15d, %xmm1
	call	pow@PLT
	mulsd	(%rbx,%r15,8), %xmm0
	movsd	8(%rsp), %xmm2
	movq	%r15, %rdx
	addq	$1, %r15
	addsd	%xmm0, %xmm2
	cmpq	%rdx, %rbp
	jne	.L10
.L13:
	addsd	24(%rsp), %xmm2
	movsd	%xmm2, 24(%rsp)
	subl	$1, %r12d
	jne	.L9
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	pxor	%xmm0, %xmm0
	subq	_ZL11MyStopWatch(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC5(%rip), %xmm0
	movq	%xmm0, %rbx
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	64(%rsp), %rsi
	movsd	56(%rsp), %xmm3
	movq	$0x000000000, 8(%rsp)
	movq	%rax, _ZL11MyStopWatch(%rip)
	movl	44(%rsp), %eax
	movl	$10000000, %ecx
	movsd	(%rsi), %xmm4
	leaq	16(%rsi,%rax,8), %rdx
	.p2align 4,,10
	.p2align 3
.L16:
	testl	%r13d, %r13d
	jle	.L23
	movsd	.LC1(%rip), %xmm0
	leaq	8(%rsi), %rax
	movapd	%xmm4, %xmm1
	.p2align 4,,10
	.p2align 3
.L15:
	mulsd	%xmm3, %xmm0
	movsd	(%rax), %xmm2
	addq	$8, %rax
	mulsd	%xmm0, %xmm2
	addsd	%xmm2, %xmm1
	cmpq	%rdx, %rax
	jne	.L15
.L14:
	addsd	8(%rsp), %xmm1
	movsd	%xmm1, 8(%rsp)
	subl	$1, %ecx
	jne	.L16
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	pxor	%xmm0, %xmm0
	movl	$16, %edx
	movq	%r14, %rdi
	subq	_ZL11MyStopWatch(%rip), %rax
	leaq	.LC6(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	divsd	.LC5(%rip), %xmm0
	movq	%xmm0, %r15
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	movsd	24(%rsp), %xmm0
	divsd	.LC7(%rip), %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	.LC8(%rip), %r12
	movl	$2, %edx
	movq	%rax, %rdi
	movq	%rax, %r13
	movq	%r12, %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbx, %xmm0
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	.LC9(%rip), %r13
	movq	%rax, %rdi
	movl	$6, %edx
	movq	%r13, %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$16, %edx
	leaq	.LC10(%rip), %rsi
	movq	%r14, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	movsd	8(%rsp), %xmm0
	divsd	.LC7(%rip), %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$2, %edx
	movq	%r12, %rsi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r15, %xmm0
	movq	%rbp, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$6, %edx
	movq	%r13, %rsi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movq	%r14, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
.LEHE0:
	movq	64(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L17
	movq	80(%rsp), %rsi
	subq	%rdi, %rsi
	call	_ZdlPvm@PLT
.L17:
	movq	96(%rsp), %rdi
	cmpq	32(%rsp), %rdi
	je	.L18
	movq	112(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L18:
	movq	136(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L36
	addq	$152, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	.cfi_restore_state
	movapd	%xmm4, %xmm1
	jmp	.L14
.L36:
	call	__stack_chk_fail@PLT
.L24:
	endbr64
	movq	%rax, %rbp
	jmp	.L19
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA2884:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2884-.LLSDACSB2884
.LLSDACSB2884:
	.uleb128 .LEHB0-.LFB2884
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L24-.LFB2884
	.uleb128 0
.LLSDACSE2884:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC2884
	.type	main.cold, @function
main.cold:
.LFSB2884:
.L19:
	.cfi_def_cfa_offset 208
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	64(%rsp), %rdi
	movq	80(%rsp), %rsi
	subq	%rdi, %rsi
	testq	%rdi, %rdi
	je	.L20
	call	_ZdlPvm@PLT
.L20:
	movq	96(%rsp), %rdi
	cmpq	32(%rsp), %rdi
	je	.L21
	movq	112(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L21:
	movq	%rbp, %rdi
.LEHB1:
	call	_Unwind_Resume@PLT
.LEHE1:
	.cfi_endproc
.LFE2884:
	.section	.gcc_except_table
.LLSDAC2884:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC2884-.LLSDACSBC2884
.LLSDACSBC2884:
	.uleb128 .LEHB1-.LCOLDB11
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSEC2884:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE11:
	.section	.text.startup
.LHOTE11:
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB3609:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE3609:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.local	_ZL11MyStopWatch
	.comm	_ZL11MyStopWatch,8,8
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1072693248
	.align 8
.LC5:
	.long	0
	.long	1104006501
	.align 8
.LC7:
	.long	0
	.long	1097011920
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
