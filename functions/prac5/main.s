	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.intel_syntax noprefix
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 416
	lea	rax, [rbp - 112]
	mov	rcx, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rcx, qword ptr [rcx]
	mov	qword ptr [rbp - 8], rcx
	mov	dword ptr [rbp - 340], 0
	mov	rcx, rax
	mov	rdi, rcx
	lea	rsi, [rip + l___const.main.str1]
	mov	ecx, 100
	mov	rdx, rcx
	mov	qword ptr [rbp - 352], rax ## 8-byte Spill
	mov	qword ptr [rbp - 360], rcx ## 8-byte Spill
	call	_memcpy
	lea	rax, [rbp - 224]
	mov	rdi, rax
	lea	rsi, [rip + l___const.main.str2]
	mov	rdx, qword ptr [rbp - 360] ## 8-byte Reload
	call	_memcpy
	mov	rdi, qword ptr [rbp - 352] ## 8-byte Reload
	call	_strLen
	lea	rdi, [rip + L_.str]
	mov	rsi, qword ptr [rbp - 352] ## 8-byte Reload
	mov	edx, eax
	mov	al, 0
	call	_printf
	lea	rcx, [rbp - 224]
	mov	rdi, rcx
	mov	dword ptr [rbp - 364], eax ## 4-byte Spill
	mov	qword ptr [rbp - 376], rcx ## 8-byte Spill
	call	_strLen
	lea	rdi, [rip + L_.str]
	mov	rsi, qword ptr [rbp - 376] ## 8-byte Reload
	mov	edx, eax
	mov	al, 0
	call	_printf
	lea	rsi, [rbp - 112]
	lea	rdi, [rbp - 336]
	mov	dword ptr [rbp - 380], eax ## 4-byte Spill
	call	_strCpy
	lea	rsi, [rbp - 336]
	lea	rdi, [rip + L_.str.1]
	mov	dword ptr [rbp - 384], eax ## 4-byte Spill
	mov	al, 0
	call	_printf
	lea	rsi, [rbp - 224]
	lea	rdi, [rbp - 336]
	mov	dword ptr [rbp - 388], eax ## 4-byte Spill
	call	_strCat
	lea	rsi, [rbp - 336]
	lea	rdi, [rip + L_.str.2]
	mov	dword ptr [rbp - 392], eax ## 4-byte Spill
	mov	al, 0
	call	_printf
	lea	rcx, [rbp - 336]
	mov	rdi, rcx
	mov	dword ptr [rbp - 396], eax ## 4-byte Spill
	mov	qword ptr [rbp - 408], rcx ## 8-byte Spill
	call	_strLen
	lea	rdi, [rip + L_.str]
	mov	rsi, qword ptr [rbp - 408] ## 8-byte Reload
	mov	edx, eax
	mov	al, 0
	call	_printf
	mov	rcx, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rcx, qword ptr [rcx]
	mov	rsi, qword ptr [rbp - 8]
	cmp	rcx, rsi
	mov	dword ptr [rbp - 412], eax ## 4-byte Spill
	jne	LBB0_2
## %bb.1:
	xor	eax, eax
	add	rsp, 416
	pop	rbp
	ret
LBB0_2:
	call	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.globl	_strLen                 ## -- Begin function strLen
	.p2align	4, 0x90
_strLen:                                ## @strLen
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	dword ptr [rbp - 12], 0
	mov	dword ptr [rbp - 16], 0
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 16]
	mov	edx, ecx
	add	edx, 1
	mov	dword ptr [rbp - 16], edx
	movsxd	rsi, ecx
	movsx	ecx, byte ptr [rax + rsi]
	cmp	ecx, 0
	je	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	mov	eax, dword ptr [rbp - 12]
	add	eax, 1
	mov	dword ptr [rbp - 12], eax
	jmp	LBB1_1
LBB1_3:
	mov	eax, dword ptr [rbp - 12]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_strCpy                 ## -- Begin function strCpy
	.p2align	4, 0x90
_strCpy:                                ## @strCpy
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 0
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 20]
	mov	edx, ecx
	add	edx, 1
	mov	dword ptr [rbp - 20], edx
	movsxd	rsi, ecx
	movsx	ecx, byte ptr [rax + rsi]
	cmp	ecx, 0
	je	LBB2_3
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 20]
	sub	ecx, 1
	movsxd	rdx, ecx
	mov	sil, byte ptr [rax + rdx]
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 20]
	sub	ecx, 1
	movsxd	rdx, ecx
	mov	byte ptr [rax + rdx], sil
	jmp	LBB2_1
LBB2_3:
	mov	eax, dword ptr [rbp - 20]
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_strCat                 ## -- Begin function strCat
	.p2align	4, 0x90
_strCat:                                ## @strCat
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	mov	qword ptr [rbp - 8], rdi
	mov	qword ptr [rbp - 16], rsi
	mov	dword ptr [rbp - 20], 0
	mov	rdi, qword ptr [rbp - 8]
	call	_strLen
	mov	dword ptr [rbp - 24], eax
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 20]
	mov	edx, ecx
	add	edx, 1
	mov	dword ptr [rbp - 20], edx
	movsxd	rsi, ecx
	movsx	ecx, byte ptr [rax + rsi]
	cmp	ecx, 0
	je	LBB3_3
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	mov	rax, qword ptr [rbp - 16]
	mov	ecx, dword ptr [rbp - 20]
	sub	ecx, 1
	movsxd	rdx, ecx
	mov	sil, byte ptr [rax + rdx]
	mov	rax, qword ptr [rbp - 8]
	mov	ecx, dword ptr [rbp - 24]
	mov	edi, dword ptr [rbp - 20]
	sub	edi, 1
	add	ecx, edi
	movsxd	rdx, ecx
	mov	byte ptr [rax + rdx], sil
	jmp	LBB3_1
LBB3_3:
	mov	eax, dword ptr [rbp - 24]
	mov	ecx, dword ptr [rbp - 20]
	sub	ecx, 1
	add	eax, ecx
	add	rsp, 32
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4               ## @__const.main.str1
l___const.main.str1:
	.asciz	"Good morning!\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.p2align	4               ## @__const.main.str2
l___const.main.str2:
	.asciz	"HaHaHa!\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"len of \"%s\": %d\n"

L_.str.1:                               ## @.str.1
	.asciz	"copy string :  \"%s\"\n"

L_.str.2:                               ## @.str.2
	.asciz	"concat : \"%s\"\n"


.subsections_via_symbols
