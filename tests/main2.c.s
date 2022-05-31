	.text
	.file	"main2.c"
	.globl	foo
	.type	foo,@function
foo:
	ADDi r2 r2 -16
	STi r1 r2 12
	STi r3 r2 8
	ADDi r3 r2 16
	STi r9 r3 -12
	STi r10 r3 -16
	LDi r4 r3 -12
	LDi r9 r3 -16
	ADD r9 r4 r9
	LDi r3 r2 8
	LDi r1 r2 12
	ADDi r2 r2 16
	BR r1
.Lfunc_end0:
	.size	foo, .Lfunc_end0-foo

	.globl	main
	.type	main,@function
main:
	ADDi r2 r2 -20
	STi r1 r2 16
	STi r3 r2 12
	ADDi r3 r2 20
	MOVli r4 0
	STi r4 r3 -12
	STi r4 r3 -16
	STi r4 r3 -20
	B .LBB1_1
.LBB1_1:
	LDi r4 r3 -20
	MOVli r9 9
	B.GT r4 r9 .LBB1_4
	B .LBB1_2
.LBB1_2:
	LDi r9 r3 -16
	LDi r10 r3 -20
	BL r1 foo
	STi r9 r3 -16
	B .LBB1_3
.LBB1_3:
	LDi r4 r3 -20
	ADDi r4 r4 1
	STi r4 r3 -20
	B .LBB1_1
.LBB1_4:
	LDi r9 r3 -16
	LDi r3 r2 12
	LDi r1 r2 16
	ADDi r2 r2 20
	BR r1
.Lfunc_end1:
	.size	main, .Lfunc_end1-main

	.ident	"clang version 14.0.0 (git@github.com:alexander-mipt/LLVM-edu.git 94dc0932dcc0a7be1c1a36def26164399df1be53)"
	.section	".note.GNU-stack","",@progbits
