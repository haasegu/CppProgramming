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
.LC3:
	.string	"Calculation of polynom with degree "
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC4:
	.string	"  Read X"
.LC5:
	.string	"  x = "
.LC8:
	.string	"slow (   pow) = "
.LC10:
	.string	" ("
.LC11:
	.string	" sec.)"
.LC12:
	.string	"fast (no pow) = "
	.section	.text.unlikely,"ax",@progbits
.LCOLDB13:
	.section	.text.startup,"ax",@progbits
.LHOTB13:
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
	subq	$232, %rsp
	.cfi_def_cfa_offset 288
	movq	%fs:40, %rax
	movq	%rax, 216(%rsp)
	xorl	%eax, %eax
	leaq	192(%rsp), %rax
	leaq	176(%rsp), %rdi
	movq	$10, 184(%rsp)
	movq	%rax, 112(%rsp)
	leaq	144(%rsp), %rsi
	movq	%rax, 176(%rsp)
	movabsq	$3544665459438677609, %rax
	movq	%rax, 192(%rsp)
	movl	$12594, %eax
	movw	%ax, 200(%rsp)
	movb	$0, 202(%rsp)
	movq	$0, 160(%rsp)
	movaps	%xmm0, 144(%rsp)
.LEHB0:
	call	_Z21read_vector_from_fileRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEERSt6vectorIdSaIdEE@PLT
	movq	152(%rsp), %rbx
	subq	144(%rsp), %rbx
	movl	$35, %edx
	leaq	.LC3(%rip), %rsi
	sarq	$3, %rbx
	leaq	_ZSt4cout(%rip), %rdi
	movl	%ebx, %ebp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leal	-1(%rbx), %eax
	leaq	_ZSt4cout(%rip), %rdi
	movl	%eax, %esi
	movl	%eax, 124(%rsp)
	call	_ZNSolsEi@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$8, %edx
	leaq	.LC4(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$6, %edx
	leaq	.LC5(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	136(%rsp), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSi10_M_extractIdEERSiRT_@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	leal	1(%rbx), %ecx
	movl	%ebx, 104(%rsp)
	movsd	136(%rsp), %xmm6
	movq	%rax, _ZL11MyStopWatch(%rip)
	movl	%ecx, %eax
	movq	144(%rsp), %r13
	movl	$10000000, %r12d
	movl	%ecx, 120(%rsp)
	shrl	$2, %eax
	andl	$-4, %ecx
	movapd	%xmm6, %xmm7
	subl	$1, %eax
	movl	%ecx, 108(%rsp)
	unpcklpd	%xmm7, %xmm7
	movq	$0x000000000, 96(%rsp)
	salq	$5, %rax
	movsd	%xmm6, 88(%rsp)
	leaq	32(%r13,%rax), %rbx
	movaps	%xmm7, (%rsp)
	.p2align 4,,10
	.p2align 3
.L9:
	testl	%ebp, %ebp
	js	.L15
	cmpl	$2, 104(%rsp)
	jbe	.L25
	movdqa	.LC0(%rip), %xmm4
	movq	%r13, %r14
	pxor	%xmm5, %xmm5
	.p2align 4,,10
	.p2align 3
.L11:
	movdqa	%xmm4, %xmm2
	movapd	(%rsp), %xmm0
	paddd	.LC6(%rip), %xmm4
	addq	$32, %r14
	movaps	%xmm5, 64(%rsp)
	cvtdq2pd	%xmm2, %xmm1
	movaps	%xmm4, 48(%rsp)
	movaps	%xmm2, 32(%rsp)
	call	_ZGVbN2vv_pow@PLT
	movdqa	32(%rsp), %xmm2
	movaps	%xmm0, 16(%rsp)
	movapd	(%rsp), %xmm0
	pshufd	$238, %xmm2, %xmm1
	cvtdq2pd	%xmm1, %xmm1
	call	_ZGVbN2vv_pow@PLT
	movupd	-16(%r14), %xmm6
	movupd	-32(%r14), %xmm1
	movapd	16(%rsp), %xmm3
	movapd	64(%rsp), %xmm5
	cmpq	%r14, %rbx
	mulpd	%xmm6, %xmm0
	movdqa	48(%rsp), %xmm4
	mulpd	%xmm3, %xmm1
	addpd	%xmm1, %xmm0
	addpd	%xmm0, %xmm5
	jne	.L11
	movl	108(%rsp), %eax
	movapd	%xmm5, %xmm2
	movl	120(%rsp), %edi
	unpckhpd	%xmm5, %xmm2
	addpd	%xmm5, %xmm2
	movl	%eax, %r15d
	cmpl	%edi, %eax
	je	.L12
.L10:
	pxor	%xmm1, %xmm1
	movsd	88(%rsp), %xmm0
	movsd	%xmm2, 16(%rsp)
	cvtsi2sdl	%r15d, %xmm1
	call	pow@PLT
	movslq	%r15d, %rdx
	movsd	16(%rsp), %xmm2
	mulsd	0(%r13,%rdx,8), %xmm0
	leaq	0(,%rdx,8), %r14
	leal	1(%r15), %edx
	addsd	%xmm0, %xmm2
	cmpl	%edx, %ebp
	jl	.L12
	pxor	%xmm1, %xmm1
	movsd	88(%rsp), %xmm0
	movsd	%xmm2, 16(%rsp)
	cvtsi2sdl	%edx, %xmm1
	call	pow@PLT
	mulsd	8(%r13,%r14), %xmm0
	movsd	16(%rsp), %xmm2
	leal	2(%r15), %eax
	addsd	%xmm0, %xmm2
	cmpl	%eax, %ebp
	jl	.L12
	pxor	%xmm1, %xmm1
	movsd	88(%rsp), %xmm0
	movsd	%xmm2, 16(%rsp)
	cvtsi2sdl	%eax, %xmm1
	call	pow@PLT
	mulsd	16(%r13,%r14), %xmm0
	movsd	16(%rsp), %xmm2
	addsd	%xmm0, %xmm2
.L12:
	addsd	96(%rsp), %xmm2
	movsd	%xmm2, 96(%rsp)
.L15:
	subl	$1, %r12d
	jne	.L9
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	pxor	%xmm0, %xmm0
	subq	_ZL11MyStopWatch(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	mulsd	.LC7(%rip), %xmm0
	movq	%xmm0, %rbx
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	movq	144(%rsp), %rsi
	movl	$10000000, %ecx
	movq	$0x000000000, (%rsp)
	movsd	136(%rsp), %xmm3
	movq	%rax, _ZL11MyStopWatch(%rip)
	movl	124(%rsp), %eax
	movsd	(%rsi), %xmm4
	leaq	16(%rsi,%rax,8), %rdx
	.p2align 4,,10
	.p2align 3
.L18:
	testl	%ebp, %ebp
	jle	.L26
	movsd	.LC2(%rip), %xmm0
	leaq	8(%rsi), %rax
	movapd	%xmm4, %xmm1
	.p2align 4,,10
	.p2align 3
.L17:
	mulsd	%xmm3, %xmm0
	movsd	(%rax), %xmm2
	addq	$8, %rax
	mulsd	%xmm0, %xmm2
	addsd	%xmm2, %xmm1
	cmpq	%rax, %rdx
	jne	.L17
	addsd	(%rsp), %xmm1
	movsd	%xmm1, (%rsp)
	subl	$1, %ecx
	jne	.L18
.L40:
	call	_ZNSt6chrono3_V212system_clock3nowEv@PLT
	pxor	%xmm0, %xmm0
	subq	_ZL11MyStopWatch(%rip), %rax
	movl	$16, %edx
	cvtsi2sdq	%rax, %xmm0
	mulsd	.LC7(%rip), %xmm0
	leaq	.LC8(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%xmm0, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movsd	.LC9(%rip), %xmm0
	mulsd	96(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	.LC10(%rip), %r12
	movl	$2, %edx
	movq	%rax, %rdi
	movq	%rax, %r13
	movq	%r12, %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbx, %xmm0
	movq	%r13, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	.LC11(%rip), %r13
	movq	%rax, %rdi
	movl	$6, %edx
	movq	%r13, %rsi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	movl	$16, %edx
	leaq	.LC12(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movsd	.LC9(%rip), %xmm0
	mulsd	(%rsp), %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$2, %edx
	movq	%r12, %rsi
	movq	%rax, %rdi
	movq	%rax, %r14
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %xmm0
	movq	%r14, %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$6, %edx
	movq	%r13, %rsi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_.isra.0
.LEHE0:
	movq	144(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L19
	movq	160(%rsp), %rsi
	subq	%rdi, %rsi
	call	_ZdlPvm@PLT
.L19:
	movq	176(%rsp), %rdi
	cmpq	112(%rsp), %rdi
	je	.L20
	movq	192(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L20:
	movq	216(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L39
	addq	$232, %rsp
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
.L26:
	.cfi_restore_state
	movapd	%xmm4, %xmm1
	addsd	(%rsp), %xmm1
	movsd	%xmm1, (%rsp)
	subl	$1, %ecx
	jne	.L18
	jmp	.L40
	.p2align 4,,10
	.p2align 3
.L25:
	xorl	%r15d, %r15d
	pxor	%xmm2, %xmm2
	jmp	.L10
.L39:
	call	__stack_chk_fail@PLT
.L27:
	endbr64
	movq	%rax, %rbp
	jmp	.L21
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
	.uleb128 .L27-.LFB2884
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
.L21:
	.cfi_def_cfa_offset 288
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	144(%rsp), %rdi
	movq	160(%rsp), %rsi
	subq	%rdi, %rsi
	testq	%rdi, %rdi
	je	.L22
	call	_ZdlPvm@PLT
.L22:
	movq	176(%rsp), %rdi
	cmpq	112(%rsp), %rdi
	je	.L23
	movq	192(%rsp), %rax
	leaq	1(%rax), %rsi
	call	_ZdlPvm@PLT
.L23:
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
	.uleb128 .LEHB1-.LCOLDB13
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSEC2884:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE13:
	.section	.text.startup
.LHOTE13:
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.section	.rodata.cst16
	.align 16
.LC6:
	.long	4
	.long	4
	.long	4
	.long	4
	.section	.rodata.cst8
	.align 8
.LC7:
	.long	-400107883
	.long	1041313291
	.align 8
.LC9:
	.long	-1698910392
	.long	1048238066
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
