	.file	1 "Q1_test.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	Cal_Fib
	.set	nomips16
	.set	nomicromips
	.ent	Cal_Fib
	.type	Cal_Fib, @function
Cal_Fib:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	lw	$2,24($fp)
	slt	$2,$2,2
	beq	$2,$0,$L2
	nop

	lw	$2,24($fp)
	.option	pic0
	b	$L3
	nop

	.option	pic2
$L2:
	sw	$0,0($fp)
	li	$2,1			# 0x1
	sw	$2,4($fp)
	li	$2,2			# 0x2
	sw	$2,8($fp)
	.option	pic0
	b	$L4
	nop

	.option	pic2
$L5:
	lw	$3,4($fp)
	lw	$2,0($fp)
	addu	$2,$3,$2
	sw	$2,12($fp)
	lw	$2,4($fp)
	sw	$2,0($fp)
	lw	$2,12($fp)
	sw	$2,4($fp)
	lw	$2,8($fp)
	addiu	$2,$2,1
	sw	$2,8($fp)
$L4:
	lw	$3,8($fp)
	lw	$2,24($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L5
	nop

	lw	$2,4($fp)
$L3:
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	Cal_Fib
	.size	Cal_Fib, .-Cal_Fib
	.rdata
	.align	2
$LC1:
	.ascii	"elapsed time :%.12f secs.\012\000"
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,88,$31		# vars= 56, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-88
	sw	$31,84($sp)
	sw	$fp,80($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	lw	$2,%got(__stack_chk_guard)($28)
	lw	$2,0($2)
	sw	$2,76($fp)
	addiu	$2,$fp,60
	li	$5,1			# 0x1
	move	$4,$2
	lw	$2,%call16(timespec_get)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,timespec_get
1:	jalr	$25
	nop

	lw	$28,16($fp)
	li	$2,100			# 0x64
	sw	$2,28($fp)
	addiu	$2,$fp,68
	li	$5,1			# 0x1
	move	$4,$2
	lw	$2,%call16(timespec_get)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,timespec_get
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$3,68($fp)
	lw	$2,60($fp)
	subu	$2,$3,$2
	mtc1	$2,$f0
	cvt.d.w	$f0,$f0
	sdc1	$f0,32($fp)
	lw	$3,72($fp)
	lw	$2,64($fp)
	subu	$2,$3,$2
	mtc1	$2,$f0
	cvt.d.w	$f0,$f0
	sdc1	$f0,40($fp)
	ldc1	$f2,40($fp)
	lui	$2,%hi($LC0)
	ldc1	$f0,%lo($LC0)($2)
	mul.d	$f0,$f2,$f0
	ldc1	$f2,32($fp)
	add.d	$f0,$f2,$f0
	sdc1	$f0,48($fp)
	lw	$7,52($fp)
	lw	$6,48($fp)
	lui	$2,%hi($LC1)
	addiu	$4,$2,%lo($LC1)
	lw	$2,%call16(printf)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,printf
1:	jalr	$25
	nop

	lw	$28,16($fp)
	move	$2,$0
	move	$4,$2
	lw	$2,%got(__stack_chk_guard)($28)
	lw	$3,76($fp)
	lw	$2,0($2)
	beq	$3,$2,$L8
	nop

	lw	$2,%call16(__stack_chk_fail)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,__stack_chk_fail
1:	jalr	$25
	nop

$L8:
	move	$2,$4
	move	$sp,$fp
	lw	$31,84($sp)
	lw	$fp,80($sp)
	addiu	$sp,$sp,88
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.rdata
	.align	3
$LC0:
	.word	1041313291
	.word	3894859413
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
