	.file	"listSave.c"
	.text
	.globl	makeNode
	.type	makeNode, @function
makeNode:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$48, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L2
	movl	$48, %edi
	call	malloc
	movq	%rax, -8(%rbp)
.L2:
	movq	-8(%rbp), %rax
	movq	$0, 40(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	makeNode, .-makeNode
	.section	.rodata
.LC0:
	.string	"no info to write!"
.LC1:
	.string	"w"
.LC2:
	.string	"person.dat"
.LC3:
	.string	"fopen error"
.LC4:
	.string	"write error!"
.LC5:
	.string	"write OK ..."
	.text
	.globl	writeFile
	.type	writeFile, @function
writeFile:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	cmpq	$0, -40(%rbp)
	je	.L5
	movq	-40(%rbp), %rax
	movq	40(%rax), %rax
	testq	%rax, %rax
	jne	.L6
.L5:
	movl	$.LC0, %edi
	call	puts
	jmp	.L4
.L6:
	movl	$.LC1, %esi
	movl	$.LC2, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L8
	movl	$.LC3, %edi
	call	perror
	jmp	.L4
.L8:
	movq	-40(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L9
.L12:
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$40, %esi
	movq	%rax, %rdi
	call	fwrite
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jg	.L10
	movl	$.LC4, %edi
	call	puts
	jmp	.L11
.L10:
	movq	-16(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -16(%rbp)
.L9:
	cmpq	$0, -16(%rbp)
	jne	.L12
.L11:
	movl	$.LC5, %edi
	call	puts
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	nop
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	writeFile, .-writeFile
	.section	.rodata
.LC6:
	.string	"r"
.LC7:
	.string	"fread error"
.LC8:
	.string	"read OK ..."
	.text
	.globl	readFile
	.type	readFile, @function
readFile:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %eax
	call	makeNode
	movq	%rax, -16(%rbp)
	movl	$.LC6, %esi
	movl	$.LC2, %edi
	call	fopen
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L14
	movl	$.LC7, %edi
	call	perror
	movl	$0, %eax
	jmp	.L15
.L14:
	movl	$0, %eax
	call	makeNode
	movq	%rax, -24(%rbp)
	jmp	.L16
.L17:
	movq	-16(%rbp), %rax
	movq	40(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 40(%rax)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 40(%rax)
	movl	$0, %eax
	call	makeNode
	movq	%rax, -24(%rbp)
.L16:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, %rcx
	movl	$1, %edx
	movl	$40, %esi
	movq	%rax, %rdi
	call	fread
	testq	%rax, %rax
	jne	.L17
	movl	$.LC8, %edi
	call	puts
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-16(%rbp), %rax
.L15:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	readFile, .-readFile
	.section	.rodata
.LC9:
	.string	"clear"
.LC10:
	.string	"\345\247\223\345\220\215: "
.LC11:
	.string	"%s"
.LC12:
	.string	"\345\271\264\351\276\204: "
.LC13:
	.string	"%d"
.LC14:
	.string	"\346\200\247\345\210\253: "
.LC15:
	.string	"%c"
	.text
	.globl	getData
	.type	getData, @function
getData:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$.LC9, %edi
	call	system
	leaq	-48(%rbp), %rax
	movl	$40, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	$.LC10, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC11, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	call	getchar
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rsi
	movl	$.LC13, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	call	getchar
	movl	$.LC14, %edi
	movl	$0, %eax
	call	printf
	leaq	-48(%rbp), %rax
	addq	$36, %rax
	movq	%rax, %rsi
	movl	$.LC15, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	call	getchar
	movq	-56(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-32(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-24(%rbp), %rdx
	movq	%rdx, 24(%rax)
	movq	-16(%rbp), %rdx
	movq	%rdx, 32(%rax)
	movq	-56(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L20
	call	__stack_chk_fail
.L20:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	getData, .-getData
	.section	.rodata
.LC16:
	.string	"phead is NULL!"
	.text
	.globl	headInsert
	.type	headInsert, @function
headInsert:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	cmpq	$0, -40(%rbp)
	jne	.L22
	movl	$.LC16, %edi
	call	perror
	movl	$-1, %eax
	jmp	.L23
.L22:
	movl	$0, %eax
	call	makeNode
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	getData
	movq	-96(%rbp), %rax
	movq	%rax, (%rbx)
	movq	-88(%rbp), %rax
	movq	%rax, 8(%rbx)
	movq	-80(%rbp), %rax
	movq	%rax, 16(%rbx)
	movq	-72(%rbp), %rax
	movq	%rax, 24(%rbx)
	movq	-64(%rbp), %rax
	movq	%rax, 32(%rbx)
	movq	-40(%rbp), %rax
	movq	40(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, 40(%rax)
	movq	-40(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 40(%rax)
	movq	$0, -32(%rbp)
	movl	$0, %eax
.L23:
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L24
	call	__stack_chk_fail
.L24:
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	headInsert, .-headInsert
	.section	.rodata
.LC17:
	.string	"the link is empty!"
.LC18:
	.string	"%d--%s--%c\n"
	.text
	.globl	showList
	.type	showList, @function
showList:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L26
	movq	-24(%rbp), %rax
	movq	40(%rax), %rax
	testq	%rax, %rax
	jne	.L27
.L26:
	movl	$.LC17, %edi
	call	puts
	jmp	.L25
.L27:
	movq	-24(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L29
.L30:
	movq	-8(%rbp), %rax
	movzbl	36(%rax), %eax
	movsbl	%al, %ecx
	movq	-8(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	32(%rax), %eax
	movl	%eax, %esi
	movl	$.LC18, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, -8(%rbp)
.L29:
	cmpq	$0, -8(%rbp)
	jne	.L30
	nop
.L25:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	showList, .-showList
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	readFile
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	showList
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
