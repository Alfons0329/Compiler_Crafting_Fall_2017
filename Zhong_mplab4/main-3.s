	.syntax	unified
	.cpu	cortex-m4
	.thumb

.data
	password:	.byte	11	// 1011
	read_pw:	.byte	0

.text
	.global	main
	.equ	RCC_AHB2ENR,	0x4002104c
	.equ	timer,		0x80000		// 2^22 / 8 = 2^19

	.equ	GPIOA_MODER,	0x48000000
	.equ	GPIOA_OTYPER,	0x48000004
	.equ	GPIOA_OSPEEDR,	0x48000008
	.equ	GPIOA_PUPDR,	0x4800000c
	.equ	GPIOA_IDR,	0x48000010

	.equ	GPIOB_MODER,	0x48000400
	.equ	GPIOB_OTYPER,	0x48000404
	.equ	GPIOB_OSPEEDR,	0x48000408
	.equ	GPIOB_PUPDR,	0x4800040c
	.equ	GPIOB_ODR,	0x48000414

	.equ	GPIOC_MODER,	0x48000800
	.equ	GPIOC_OTYPER,	0x48000804
	.equ	GPIOC_OSPEEDR,	0x48000808
	.equ	GPIOC_PUPDR,	0x4800080c
	.equ	GPIOC_IDR,	0x48000810

main:
	bl	GPIO_init

loop:
	bl	button
	bl	read_switch
	bl	auth
	b	loop

blink_1:
	push	{lr}
	ldr	r1, =GPIOB_ODR
	movs	r0, 0
	strh	r0, [r1]
	bl	delay
	mvns	r0, 0
	strh	r0, [r1]
	pop	{pc}

blink_3:
	push	{lr}
	ldr	r1, =GPIOB_ODR
	movs	r0, 0
	strh	r0, [r1]
	bl	delay
	mvns	r0, 0
	strh	r0, [r1]
	bl	delay
	movs	r0, 0
	strh	r0, [r1]
	bl	delay
	mvns	r0, 0
	strh	r0, [r1]
	bl	delay
	movs	r0, 0
	strh	r0, [r1]
	bl	delay
	mvns	r0, 0
	strh	r0, [r1]
	pop	{pc}

delay:
	/* delay for 0.5 s */
	ldr	r0, =timer	// 2
delay_L:
	subs	r0, r0, 1	// 1
	bne	delay_L		// 3 or 1
	bx	lr		// 1

auth:
	push	{lr}
	ldr	r0, =password
	ldrb	r0, [r0]
	ldr	r1, =read_pw
	ldrb	r1, [r1]
	cmp	r0, r1
	it	ne
	blne	blink_1
	it	eq
	bleq	blink_3
	pop	{pc}

read_switch:
	ldr	r0, =GPIOA_IDR
	ldr	r0, [r0]
	lsrs	r0, 6
	mvns	r0, r0
	ands	r0, 0xf
	ldr	r1, =read_pw
	strb	r0, [r1]
	bx	lr

button:
	ldr	r0, =GPIOC_IDR
	ldr	r0, [r0]
	lsrs	r0, 14
	it	cs	/* if the button is not pressed */
	bcs	button
	bx	lr

GPIO_init:
	/* enable AHB2 clock for port A, B and C */
	movs	r0, 0x7
	ldr	r1, =RCC_AHB2ENR
	str	r0, [r1]

	/* set PA6-9 as input mode */
	ldr	r0, =GPIOA_MODER
	ldr	r1, [r0]
	ands	r1, r1, 0xfff00fff
	str	r1, [r0]

	/* set PB3-6 as output mode */
	movs	r0, 0x1540
	ldr	r1, =GPIOB_MODER
	ldr	r2, [r1]
	ands	r2, r2, 0xffffc03f
	orrs	r2, r2, r0
	str	r2, [r1]

	/* set PC13 as input mode */
	ldr	r1, =GPIOC_MODER
	ldr	r2, [r1]
	ands	r2, r2, 0xf3ffffff
	str	r2, [r1]

	/* default is push-pull, no need to set */

	/* set PA6-9 as high speed mode */
	movs	r0, 0xaa000
	ldr	r1, =GPIOA_OSPEEDR
	str	r0, [r1]

	/* set PB3-6 as high speed mode */
	movs	r0, 0x2a80
	ldr	r1, =GPIOB_OSPEEDR
	str	r0, [r1]

	/* turn off all the leds (PB3-6) */
	ldr	r1, =GPIOB_ODR
	mvns	r0, 0
	strh	r0, [r1]
	bx	lr
