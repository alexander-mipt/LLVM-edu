	.text
	.file	"random.c"
	.globl	main
	.type	main,@function
main:
	ADDi r2 r2 -28
	STi r1 r2 24
	STi r3 r2 20
	ADDi r3 r2 28
	MOVli r4 0
	STi r4 r3 -12
	STi r4 r3 -16
	STi r4 r3 -20
	B .LBB0_1
.LBB0_1:
	LDi r4 r3 -20
	MOVli r9 127
	B.GT r4 r9 .LBB0_8
	B .LBB0_2
.LBB0_2:
	MOVli r4 0
	STi r4 r3 -16
	B .LBB0_3
.LBB0_3:
	LDi r4 r3 -16
	MOVli r9 255
	B.GT r4 r9 .LBB0_6
	B .LBB0_4
.LBB0_4:
	LDi r4 r3 -16
	STi r4 r3 -24
	LDi r4 r3 -20
	STi r4 r3 -28
	CALL simRand
	LDi r10 r3 -28
	ADDi r11 r9 0
	LDi r9 r3 -24
	CALL simSetPixel
	B .LBB0_5
.LBB0_5:
	LDi r4 r3 -16
	ADDi r4 r4 1
	STi r4 r3 -16
	B .LBB0_3
.LBB0_6:
	CALL simFlush
	B .LBB0_7
.LBB0_7:
	LDi r4 r3 -20
	ADDi r4 r4 1
	STi r4 r3 -20
	B .LBB0_1
.LBB0_8:
	MOVli r9 0
	LDi r3 r2 20
	LDi r1 r2 24
	ADDi r2 r2 28
	RET
.Lfunc_end0:
	.size	main, .Lfunc_end0-main

	.ident	"clang version 14.0.0 (git@github.com:alexander-mipt/LLVM-edu.git 967bb80c4580fe9edc563cf67587fded6d5f9819)"
	.section	".note.GNU-stack","",@progbits
