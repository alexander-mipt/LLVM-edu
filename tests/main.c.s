	.text
	.file	"main.c"
	.globl	main
	.type	main,@function
main:
	ADDi r2 r2 -12
	STi r1 r2 8
	STi r3 r2 4
	ADDi r3 r2 12
	MOVli r9 0
	STi r9 r3 -12
	LDi r3 r2 4
	LDi r1 r2 8
	ADDi r2 r2 12
	BR r1
.Lfunc_end0:
	.size	main, .Lfunc_end0-main

	.ident	"clang version 14.0.0 (git@github.com:alexander-mipt/LLVM-edu.git 94dc0932dcc0a7be1c1a36def26164399df1be53)"
	.section	".note.GNU-stack","",@progbits
