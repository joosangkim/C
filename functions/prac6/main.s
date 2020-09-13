	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	leaq	-21(%rbp), %rdi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -28(%rbp)
	movq	L___const.main.str(%rip), %rax
	movq	%rax, -21(%rbp)
	movl	L___const.main.str+8(%rip), %ecx
	movl	%ecx, -13(%rbp)
	movb	L___const.main.str+12(%rip), %dl
	movb	%dl, -9(%rbp)
	leaq	L_.str(%rip), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rsi
	callq	_strTok
	movq	%rax, -48(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -48(%rbp)
	je	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	-48(%rbp), %rdi
	callq	_puts
	xorl	%ecx, %ecx
	movl	%ecx, %edi
	movq	-40(%rbp), %rsi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_strTok
	movq	%rax, -48(%rbp)
	jmp	LBB0_1
LBB0_3:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_5
## %bb.4:
	xorl	%eax, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_5:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_strTok                 ## -- Begin function strTok
	.p2align	4, 0x90
_strTok:                                ## @strTok
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movl	$0, -28(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB1_4
## %bb.1:
	cmpq	$0, _strTok.next(%rip)
	jne	LBB1_3
## %bb.2:
	movq	$0, -8(%rbp)
	jmp	LBB1_11
LBB1_3:
	movq	_strTok.next(%rip), %rax
	movq	%rax, -16(%rbp)
LBB1_4:
	jmp	LBB1_5
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	cmpl	$0, %edx
	jne	LBB1_7
## %bb.6:
	movq	$0, _strTok.next(%rip)
	jmp	LBB1_10
LBB1_7:                                 ##   in Loop: Header=BB1_5 Depth=1
	movq	-16(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movsbl	(%rax,%rcx), %edx
	movq	-24(%rbp), %rax
	movsbl	(%rax), %esi
	cmpl	%esi, %edx
	jne	LBB1_9
## %bb.8:
	movq	-16(%rbp), %rax
	movslq	-28(%rbp), %rcx
	movb	$0, (%rax,%rcx)
	movq	-16(%rbp), %rax
	movl	-28(%rbp), %edx
	addl	$1, %edx
	movslq	%edx, %rcx
	addq	%rcx, %rax
	movq	%rax, _strTok.next(%rip)
	jmp	LBB1_10
LBB1_9:                                 ##   in Loop: Header=BB1_5 Depth=1
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
	jmp	LBB1_5
LBB1_10:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
LBB1_11:
	movq	-8(%rbp), %rax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L___const.main.str:                     ## @__const.main.str
	.asciz	"111-222-3333"

L_.str:                                 ## @.str
	.asciz	"-"

.zerofill __DATA,__bss,_strTok.next,8,3 ## @strTok.next

.subsections_via_symbols
