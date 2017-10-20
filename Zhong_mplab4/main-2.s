	.syntax	unified
	.cpu	cortex-m4
	.thumb

.data
	leds:		.byte	2
	march:		.word	0xffffffff
	direction:	.word	1

.text
	.global	main
	.equ	RCC_AHB2ENR,	0x4002104c
	.equ	timer,		0x38e39		// 2^22 / 18 = 233016.89 = 233017
	.equ	deb_time,	0x28f6		// 2^22 / 400 = 10485.76 = 10486

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
	bl	displayLED
	bl	delay
	bl	walker
	b	loop

delay:
	/* wait for 1 s */
	push	{lr}		// 2
	ldr	r0, =timer	// 2
delay_L:
	/* check whether the button is pressed */
	ldr	r1, =GPIOC_IDR	// 2
	ldr	r1, [r1]	// 2
	lsrs	r1, 14		// 1
	it	cc		// 1
	blcc	pressed		// 3 (taken) or 1 (not taken)
	/* if the button is not pressed */
	/* then check march */
	ldr	r1, =march	// 2
	ldr	r1, [r1]	// 2
	cmp	r1, 0		// 1
	it	eq		// 1
	beq	delay_L		// 3 (taken) or 1 (not taken)
	subs	r0, r0, 1	// 1
	bne	delay_L		// 3 (taken) or 1 (not taken)
	pop	{pc}		// 4

pressed:
	/* wait for 10 ms */
	ldr	r1, =deb_time
deb_L:
	subs	r1, r1, 1	// 1
	bne	deb_L		// 3 (taken) or 1 (not taken)
	/* check whether the button is up */
	ldr	r1, =GPIOC_IDR
	ldr	r1, [r1]
	lsrs	r1, 14
	it	cc	/* if the button is still down */
	bcc	pressed	/* then just wait */
	/* if the button is up */
	/* then change the state of march */
	ldr	r1, =march
	ldr	r2, [r1]
	mvn	r2, r2
	str	r2, [r1]
	bx	lr

walker:
	ldr	r3, =direction
	ldr	r2, [r3]
	ldr	r0, =leds
	ldrb	r1, [r0]
	cmp	r1, 6	/* if r1 == 6 */
	it	eq
	mvneq	r2, 0	/* then r2 = -1 */
	cmp	r1, 2	/* if r1 == 2 */
	it	eq
	moveq	r2, 1	/* then r2 = 1 */
	adds	r1, r1, r2
	strb	r1, [r0]
	str	r2, [r3]
	bx	lr

displayLED:
	/* set up the output value */
	ldr	r1, =leds
	ldrb	r1, [r1]
	movs	r0, 0x3
	lsl	r0, r0, r1
	mvns	r0, r0
	ldr	r1, =GPIOB_ODR
	strh	r0, [r1]
	bx	lr

GPIO_init:
	/* enable AHB2 clock for port B and C */
	movs	r0, 0x3 << 1
	ldr	r1, =RCC_AHB2ENR
	str	r0, [r1]

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

	/* set PB3-6 as high speed mode */
	movs	r0, 0x2a80
	ldr	r1, =GPIOB_OSPEEDR
	str	r0, [r1]
	bx	lr
