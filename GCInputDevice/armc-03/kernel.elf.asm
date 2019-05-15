
C:/Users/koehlerjj/Desktop/workspace/senior-workspace/gagecubeTasRobot/GCInputDevice/armc-03/kernel.elf:     file format elf32-littlearm


Disassembly of section .text:

00008000 <main>:
    8000:	e10f0000 	mrs	r0, CPSR
    8004:	e3c0001f 	bic	r0, r0, #31
    8008:	e3800013 	orr	r0, r0, #19
    800c:	e16ff000 	msr	SPSR_fsxc, r0
    8010:	e28f0004 	add	r0, pc, #4
    8014:	e12ef300 	msr	ELR_hyp, r0
    8018:	e160006e 	eret
    801c:	ee1c1f10 	mrc	15, 0, r1, cr12, cr0, {0}
    8020:	e3a00902 	mov	r0, #32768	; 0x8000
    8024:	e8b003fc 	ldm	r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    8028:	e8a103fc 	stmia	r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    802c:	e8b003fc 	ldm	r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    8030:	e8a103fc 	stmia	r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    8034:	e3a0c000 	mov	ip, #0
    8038:	ee07cf3a 	mcr	15, 0, ip, cr7, cr10, {1}
    803c:	f57ff04f 	dsb	sy
    8040:	e3a0c000 	mov	ip, #0
    8044:	ee07cf15 	mcr	15, 0, ip, cr7, cr5, {0}
    8048:	e3a0c000 	mov	ip, #0
    804c:	ee07cfd5 	mcr	15, 0, ip, cr7, cr5, {6}
    8050:	f57ff04f 	dsb	sy
    8054:	f57ff06f 	isb	sy
    8058:	ee112f10 	mrc	15, 0, r2, cr1, cr0, {0}
    805c:	e3822a01 	orr	r2, r2, #4096	; 0x1000
    8060:	ee012f10 	mcr	15, 0, r2, cr1, cr0, {0}
    8064:	e3082958 	movw	r2, #35160	; 0x8958
    8068:	e3402001 	movt	r2, #1
    806c:	e3a03000 	mov	r3, #0
    8070:	e3433f20 	movt	r3, #16160	; 0x3f20
    8074:	e5823000 	str	r3, [r2]
    8078:	e3083958 	movw	r3, #35160	; 0x8958
    807c:	e3403001 	movt	r3, #1
    8080:	e5933000 	ldr	r3, [r3]
    8084:	e5932000 	ldr	r2, [r3]
    8088:	e3083958 	movw	r3, #35160	; 0x8958
    808c:	e3403001 	movt	r3, #1
    8090:	e5933000 	ldr	r3, [r3]
    8094:	e3822a01 	orr	r2, r2, #4096	; 0x1000
    8098:	e5832000 	str	r2, [r3]
    809c:	e3083958 	movw	r3, #35160	; 0x8958
    80a0:	e3403001 	movt	r3, #1
    80a4:	e5933000 	ldr	r3, [r3]
    80a8:	e5932000 	ldr	r2, [r3]
    80ac:	e3083958 	movw	r3, #35160	; 0x8958
    80b0:	e3403001 	movt	r3, #1
    80b4:	e5933000 	ldr	r3, [r3]
    80b8:	e3822c02 	orr	r2, r2, #512	; 0x200
    80bc:	e5832000 	str	r2, [r3]
    80c0:	e3083958 	movw	r3, #35160	; 0x8958
    80c4:	e3403001 	movt	r3, #1
    80c8:	e5933000 	ldr	r3, [r3]
    80cc:	e5932000 	ldr	r2, [r3]
    80d0:	e3083958 	movw	r3, #35160	; 0x8958
    80d4:	e3403001 	movt	r3, #1
    80d8:	e5933000 	ldr	r3, [r3]
    80dc:	e3c2290e 	bic	r2, r2, #229376	; 0x38000
    80e0:	e5832000 	str	r2, [r3]
    80e4:	e3083958 	movw	r3, #35160	; 0x8958
    80e8:	e3403001 	movt	r3, #1
    80ec:	e5933000 	ldr	r3, [r3]
    80f0:	e2833004 	add	r3, r3, #4
    80f4:	e5932000 	ldr	r2, [r3]
    80f8:	e3083958 	movw	r3, #35160	; 0x8958
    80fc:	e3403001 	movt	r3, #1
    8100:	e5933000 	ldr	r3, [r3]
    8104:	e2833004 	add	r3, r3, #4
    8108:	e3c22007 	bic	r2, r2, #7
    810c:	e5832000 	str	r2, [r3]
    8110:	e3083958 	movw	r3, #35160	; 0x8958
    8114:	e3403001 	movt	r3, #1
    8118:	e5933000 	ldr	r3, [r3]
    811c:	e2833028 	add	r3, r3, #40	; 0x28
    8120:	e3a02008 	mov	r2, #8
    8124:	e5832000 	str	r2, [r3]
    8128:	e3083958 	movw	r3, #35160	; 0x8958
    812c:	e3403001 	movt	r3, #1
    8130:	e5933000 	ldr	r3, [r3]
    8134:	e283301c 	add	r3, r3, #28
    8138:	e3a02008 	mov	r2, #8
    813c:	e5832000 	str	r2, [r3]
    8140:	eb000016 	bl	81a0 <testRead>
    8144:	e3083948 	movw	r3, #35144	; 0x8948
    8148:	e3403001 	movt	r3, #1
    814c:	e5933000 	ldr	r3, [r3]
    8150:	e3530001 	cmp	r3, #1
    8154:	1afffff9 	bne	8140 <main+0x140>
    8158:	eb0001dd 	bl	88d4 <output0>
    815c:	eb0001dc 	bl	88d4 <output0>
    8160:	eb0001bf 	bl	8864 <output1>
    8164:	eb0001da 	bl	88d4 <output0>
    8168:	eb0001bd 	bl	8864 <output1>
    816c:	eb0001d8 	bl	88d4 <output0>
    8170:	eb0001d7 	bl	88d4 <output0>
    8174:	eb0001ba 	bl	8864 <output1>
    8178:	eb0001d5 	bl	88d4 <output0>
    817c:	eb0001d4 	bl	88d4 <output0>
    8180:	eb0001d3 	bl	88d4 <output0>
    8184:	eb0001d2 	bl	88d4 <output0>
    8188:	eb0001d1 	bl	88d4 <output0>
    818c:	eb0001d0 	bl	88d4 <output0>
    8190:	eb0001cf 	bl	88d4 <output0>
    8194:	eb0001ce 	bl	88d4 <output0>
    8198:	eb0001b1 	bl	8864 <output1>
    819c:	eaffffe7 	b	8140 <main+0x140>

000081a0 <testRead>:
    81a0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
    81a4:	e28db000 	add	fp, sp, #0
    81a8:	e3083948 	movw	r3, #35144	; 0x8948
    81ac:	e3403001 	movt	r3, #1
    81b0:	e3a02000 	mov	r2, #0
    81b4:	e5832000 	str	r2, [r3]
    81b8:	e3083958 	movw	r3, #35160	; 0x8958
    81bc:	e3403001 	movt	r3, #1
    81c0:	e5933000 	ldr	r3, [r3]
    81c4:	e283301c 	add	r3, r3, #28
    81c8:	e3a02010 	mov	r2, #16
    81cc:	e5832000 	str	r2, [r3]
    81d0:	ea000000 	b	81d8 <testRead+0x38>
    81d4:	e320f000 	nop	{0}
    81d8:	e3083958 	movw	r3, #35160	; 0x8958
    81dc:	e3403001 	movt	r3, #1
    81e0:	e5933000 	ldr	r3, [r3]
    81e4:	e2833034 	add	r3, r3, #52	; 0x34
    81e8:	e5933000 	ldr	r3, [r3]
    81ec:	e2033b01 	and	r3, r3, #1024	; 0x400
    81f0:	e3530000 	cmp	r3, #0
    81f4:	1afffff6 	bne	81d4 <testRead+0x34>
    81f8:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    81fc:	e3b01f4b 	movs	r1, #300	; 0x12c
    8200:	e2511001 	subs	r1, r1, #1
    8204:	1afffffd 	bne	8200 <testRead+0x60>
    8208:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    820c:	e3083958 	movw	r3, #35160	; 0x8958
    8210:	e3403001 	movt	r3, #1
    8214:	e5933000 	ldr	r3, [r3]
    8218:	e2833034 	add	r3, r3, #52	; 0x34
    821c:	e5933000 	ldr	r3, [r3]
    8220:	e2032b01 	and	r2, r3, #1024	; 0x400
    8224:	e3083948 	movw	r3, #35144	; 0x8948
    8228:	e3403001 	movt	r3, #1
    822c:	e5933000 	ldr	r3, [r3]
    8230:	e1a03083 	lsl	r3, r3, #1
    8234:	e283300a 	add	r3, r3, #10
    8238:	e1a02332 	lsr	r2, r2, r3
    823c:	e3083948 	movw	r3, #35144	; 0x8948
    8240:	e3403001 	movt	r3, #1
    8244:	e5832000 	str	r2, [r3]
    8248:	e3083958 	movw	r3, #35160	; 0x8958
    824c:	e3403001 	movt	r3, #1
    8250:	e5933000 	ldr	r3, [r3]
    8254:	e2833028 	add	r3, r3, #40	; 0x28
    8258:	e3a02010 	mov	r2, #16
    825c:	e5832000 	str	r2, [r3]
    8260:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8264:	e3b0106e 	movs	r1, #110	; 0x6e
    8268:	e2511001 	subs	r1, r1, #1
    826c:	1afffffd 	bne	8268 <testRead+0xc8>
    8270:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8274:	e3083958 	movw	r3, #35160	; 0x8958
    8278:	e3403001 	movt	r3, #1
    827c:	e5933000 	ldr	r3, [r3]
    8280:	e283301c 	add	r3, r3, #28
    8284:	e3a02010 	mov	r2, #16
    8288:	e5832000 	str	r2, [r3]
    828c:	ea000000 	b	8294 <testRead+0xf4>
    8290:	e320f000 	nop	{0}
    8294:	e3083958 	movw	r3, #35160	; 0x8958
    8298:	e3403001 	movt	r3, #1
    829c:	e5933000 	ldr	r3, [r3]
    82a0:	e2833034 	add	r3, r3, #52	; 0x34
    82a4:	e5933000 	ldr	r3, [r3]
    82a8:	e2033b01 	and	r3, r3, #1024	; 0x400
    82ac:	e3530000 	cmp	r3, #0
    82b0:	1afffff6 	bne	8290 <testRead+0xf0>
    82b4:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    82b8:	e3b01f4b 	movs	r1, #300	; 0x12c
    82bc:	e2511001 	subs	r1, r1, #1
    82c0:	1afffffd 	bne	82bc <testRead+0x11c>
    82c4:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    82c8:	e3083958 	movw	r3, #35160	; 0x8958
    82cc:	e3403001 	movt	r3, #1
    82d0:	e5933000 	ldr	r3, [r3]
    82d4:	e2833034 	add	r3, r3, #52	; 0x34
    82d8:	e5933000 	ldr	r3, [r3]
    82dc:	e2032b01 	and	r2, r3, #1024	; 0x400
    82e0:	e3083948 	movw	r3, #35144	; 0x8948
    82e4:	e3403001 	movt	r3, #1
    82e8:	e5933000 	ldr	r3, [r3]
    82ec:	e1a03083 	lsl	r3, r3, #1
    82f0:	e283300a 	add	r3, r3, #10
    82f4:	e1a02332 	lsr	r2, r2, r3
    82f8:	e3083948 	movw	r3, #35144	; 0x8948
    82fc:	e3403001 	movt	r3, #1
    8300:	e5832000 	str	r2, [r3]
    8304:	e3083958 	movw	r3, #35160	; 0x8958
    8308:	e3403001 	movt	r3, #1
    830c:	e5933000 	ldr	r3, [r3]
    8310:	e2833028 	add	r3, r3, #40	; 0x28
    8314:	e3a02010 	mov	r2, #16
    8318:	e5832000 	str	r2, [r3]
    831c:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8320:	e3b0106e 	movs	r1, #110	; 0x6e
    8324:	e2511001 	subs	r1, r1, #1
    8328:	1afffffd 	bne	8324 <testRead+0x184>
    832c:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8330:	e3083958 	movw	r3, #35160	; 0x8958
    8334:	e3403001 	movt	r3, #1
    8338:	e5933000 	ldr	r3, [r3]
    833c:	e283301c 	add	r3, r3, #28
    8340:	e3a02010 	mov	r2, #16
    8344:	e5832000 	str	r2, [r3]
    8348:	ea000000 	b	8350 <testRead+0x1b0>
    834c:	e320f000 	nop	{0}
    8350:	e3083958 	movw	r3, #35160	; 0x8958
    8354:	e3403001 	movt	r3, #1
    8358:	e5933000 	ldr	r3, [r3]
    835c:	e2833034 	add	r3, r3, #52	; 0x34
    8360:	e5933000 	ldr	r3, [r3]
    8364:	e2033b01 	and	r3, r3, #1024	; 0x400
    8368:	e3530000 	cmp	r3, #0
    836c:	1afffff6 	bne	834c <testRead+0x1ac>
    8370:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8374:	e3b01f4b 	movs	r1, #300	; 0x12c
    8378:	e2511001 	subs	r1, r1, #1
    837c:	1afffffd 	bne	8378 <testRead+0x1d8>
    8380:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8384:	e3083958 	movw	r3, #35160	; 0x8958
    8388:	e3403001 	movt	r3, #1
    838c:	e5933000 	ldr	r3, [r3]
    8390:	e2833034 	add	r3, r3, #52	; 0x34
    8394:	e5933000 	ldr	r3, [r3]
    8398:	e2032b01 	and	r2, r3, #1024	; 0x400
    839c:	e3083948 	movw	r3, #35144	; 0x8948
    83a0:	e3403001 	movt	r3, #1
    83a4:	e5933000 	ldr	r3, [r3]
    83a8:	e1a03083 	lsl	r3, r3, #1
    83ac:	e283300a 	add	r3, r3, #10
    83b0:	e1a02332 	lsr	r2, r2, r3
    83b4:	e3083948 	movw	r3, #35144	; 0x8948
    83b8:	e3403001 	movt	r3, #1
    83bc:	e5832000 	str	r2, [r3]
    83c0:	e3083958 	movw	r3, #35160	; 0x8958
    83c4:	e3403001 	movt	r3, #1
    83c8:	e5933000 	ldr	r3, [r3]
    83cc:	e2833028 	add	r3, r3, #40	; 0x28
    83d0:	e3a02010 	mov	r2, #16
    83d4:	e5832000 	str	r2, [r3]
    83d8:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    83dc:	e3b0106e 	movs	r1, #110	; 0x6e
    83e0:	e2511001 	subs	r1, r1, #1
    83e4:	1afffffd 	bne	83e0 <testRead+0x240>
    83e8:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    83ec:	e3083958 	movw	r3, #35160	; 0x8958
    83f0:	e3403001 	movt	r3, #1
    83f4:	e5933000 	ldr	r3, [r3]
    83f8:	e283301c 	add	r3, r3, #28
    83fc:	e3a02010 	mov	r2, #16
    8400:	e5832000 	str	r2, [r3]
    8404:	ea000000 	b	840c <testRead+0x26c>
    8408:	e320f000 	nop	{0}
    840c:	e3083958 	movw	r3, #35160	; 0x8958
    8410:	e3403001 	movt	r3, #1
    8414:	e5933000 	ldr	r3, [r3]
    8418:	e2833034 	add	r3, r3, #52	; 0x34
    841c:	e5933000 	ldr	r3, [r3]
    8420:	e2033b01 	and	r3, r3, #1024	; 0x400
    8424:	e3530000 	cmp	r3, #0
    8428:	1afffff6 	bne	8408 <testRead+0x268>
    842c:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8430:	e3b01f4b 	movs	r1, #300	; 0x12c
    8434:	e2511001 	subs	r1, r1, #1
    8438:	1afffffd 	bne	8434 <testRead+0x294>
    843c:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8440:	e3083958 	movw	r3, #35160	; 0x8958
    8444:	e3403001 	movt	r3, #1
    8448:	e5933000 	ldr	r3, [r3]
    844c:	e2833034 	add	r3, r3, #52	; 0x34
    8450:	e5933000 	ldr	r3, [r3]
    8454:	e2032b01 	and	r2, r3, #1024	; 0x400
    8458:	e3083948 	movw	r3, #35144	; 0x8948
    845c:	e3403001 	movt	r3, #1
    8460:	e5933000 	ldr	r3, [r3]
    8464:	e1a03083 	lsl	r3, r3, #1
    8468:	e283300a 	add	r3, r3, #10
    846c:	e1a02332 	lsr	r2, r2, r3
    8470:	e3083948 	movw	r3, #35144	; 0x8948
    8474:	e3403001 	movt	r3, #1
    8478:	e5832000 	str	r2, [r3]
    847c:	e3083958 	movw	r3, #35160	; 0x8958
    8480:	e3403001 	movt	r3, #1
    8484:	e5933000 	ldr	r3, [r3]
    8488:	e2833028 	add	r3, r3, #40	; 0x28
    848c:	e3a02010 	mov	r2, #16
    8490:	e5832000 	str	r2, [r3]
    8494:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8498:	e3b0106e 	movs	r1, #110	; 0x6e
    849c:	e2511001 	subs	r1, r1, #1
    84a0:	1afffffd 	bne	849c <testRead+0x2fc>
    84a4:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    84a8:	e3083958 	movw	r3, #35160	; 0x8958
    84ac:	e3403001 	movt	r3, #1
    84b0:	e5933000 	ldr	r3, [r3]
    84b4:	e283301c 	add	r3, r3, #28
    84b8:	e3a02010 	mov	r2, #16
    84bc:	e5832000 	str	r2, [r3]
    84c0:	ea000000 	b	84c8 <testRead+0x328>
    84c4:	e320f000 	nop	{0}
    84c8:	e3083958 	movw	r3, #35160	; 0x8958
    84cc:	e3403001 	movt	r3, #1
    84d0:	e5933000 	ldr	r3, [r3]
    84d4:	e2833034 	add	r3, r3, #52	; 0x34
    84d8:	e5933000 	ldr	r3, [r3]
    84dc:	e2033b01 	and	r3, r3, #1024	; 0x400
    84e0:	e3530000 	cmp	r3, #0
    84e4:	1afffff6 	bne	84c4 <testRead+0x324>
    84e8:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    84ec:	e3b01f4b 	movs	r1, #300	; 0x12c
    84f0:	e2511001 	subs	r1, r1, #1
    84f4:	1afffffd 	bne	84f0 <testRead+0x350>
    84f8:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    84fc:	e3083958 	movw	r3, #35160	; 0x8958
    8500:	e3403001 	movt	r3, #1
    8504:	e5933000 	ldr	r3, [r3]
    8508:	e2833034 	add	r3, r3, #52	; 0x34
    850c:	e5933000 	ldr	r3, [r3]
    8510:	e2032b01 	and	r2, r3, #1024	; 0x400
    8514:	e3083948 	movw	r3, #35144	; 0x8948
    8518:	e3403001 	movt	r3, #1
    851c:	e5933000 	ldr	r3, [r3]
    8520:	e1a03083 	lsl	r3, r3, #1
    8524:	e283300a 	add	r3, r3, #10
    8528:	e1a02332 	lsr	r2, r2, r3
    852c:	e3083948 	movw	r3, #35144	; 0x8948
    8530:	e3403001 	movt	r3, #1
    8534:	e5832000 	str	r2, [r3]
    8538:	e3083958 	movw	r3, #35160	; 0x8958
    853c:	e3403001 	movt	r3, #1
    8540:	e5933000 	ldr	r3, [r3]
    8544:	e2833028 	add	r3, r3, #40	; 0x28
    8548:	e3a02010 	mov	r2, #16
    854c:	e5832000 	str	r2, [r3]
    8550:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8554:	e3b0106e 	movs	r1, #110	; 0x6e
    8558:	e2511001 	subs	r1, r1, #1
    855c:	1afffffd 	bne	8558 <testRead+0x3b8>
    8560:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8564:	e3083958 	movw	r3, #35160	; 0x8958
    8568:	e3403001 	movt	r3, #1
    856c:	e5933000 	ldr	r3, [r3]
    8570:	e283301c 	add	r3, r3, #28
    8574:	e3a02010 	mov	r2, #16
    8578:	e5832000 	str	r2, [r3]
    857c:	ea000000 	b	8584 <testRead+0x3e4>
    8580:	e320f000 	nop	{0}
    8584:	e3083958 	movw	r3, #35160	; 0x8958
    8588:	e3403001 	movt	r3, #1
    858c:	e5933000 	ldr	r3, [r3]
    8590:	e2833034 	add	r3, r3, #52	; 0x34
    8594:	e5933000 	ldr	r3, [r3]
    8598:	e2033b01 	and	r3, r3, #1024	; 0x400
    859c:	e3530000 	cmp	r3, #0
    85a0:	1afffff6 	bne	8580 <testRead+0x3e0>
    85a4:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    85a8:	e3b01f4b 	movs	r1, #300	; 0x12c
    85ac:	e2511001 	subs	r1, r1, #1
    85b0:	1afffffd 	bne	85ac <testRead+0x40c>
    85b4:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    85b8:	e3083958 	movw	r3, #35160	; 0x8958
    85bc:	e3403001 	movt	r3, #1
    85c0:	e5933000 	ldr	r3, [r3]
    85c4:	e2833034 	add	r3, r3, #52	; 0x34
    85c8:	e5933000 	ldr	r3, [r3]
    85cc:	e2032b01 	and	r2, r3, #1024	; 0x400
    85d0:	e3083948 	movw	r3, #35144	; 0x8948
    85d4:	e3403001 	movt	r3, #1
    85d8:	e5933000 	ldr	r3, [r3]
    85dc:	e1a03083 	lsl	r3, r3, #1
    85e0:	e283300a 	add	r3, r3, #10
    85e4:	e1a02332 	lsr	r2, r2, r3
    85e8:	e3083948 	movw	r3, #35144	; 0x8948
    85ec:	e3403001 	movt	r3, #1
    85f0:	e5832000 	str	r2, [r3]
    85f4:	e3083958 	movw	r3, #35160	; 0x8958
    85f8:	e3403001 	movt	r3, #1
    85fc:	e5933000 	ldr	r3, [r3]
    8600:	e2833028 	add	r3, r3, #40	; 0x28
    8604:	e3a02010 	mov	r2, #16
    8608:	e5832000 	str	r2, [r3]
    860c:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8610:	e3b0106e 	movs	r1, #110	; 0x6e
    8614:	e2511001 	subs	r1, r1, #1
    8618:	1afffffd 	bne	8614 <testRead+0x474>
    861c:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8620:	e3083958 	movw	r3, #35160	; 0x8958
    8624:	e3403001 	movt	r3, #1
    8628:	e5933000 	ldr	r3, [r3]
    862c:	e283301c 	add	r3, r3, #28
    8630:	e3a02010 	mov	r2, #16
    8634:	e5832000 	str	r2, [r3]
    8638:	ea000000 	b	8640 <testRead+0x4a0>
    863c:	e320f000 	nop	{0}
    8640:	e3083958 	movw	r3, #35160	; 0x8958
    8644:	e3403001 	movt	r3, #1
    8648:	e5933000 	ldr	r3, [r3]
    864c:	e2833034 	add	r3, r3, #52	; 0x34
    8650:	e5933000 	ldr	r3, [r3]
    8654:	e2033b01 	and	r3, r3, #1024	; 0x400
    8658:	e3530000 	cmp	r3, #0
    865c:	1afffff6 	bne	863c <testRead+0x49c>
    8660:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8664:	e3b01f4b 	movs	r1, #300	; 0x12c
    8668:	e2511001 	subs	r1, r1, #1
    866c:	1afffffd 	bne	8668 <testRead+0x4c8>
    8670:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8674:	e3083958 	movw	r3, #35160	; 0x8958
    8678:	e3403001 	movt	r3, #1
    867c:	e5933000 	ldr	r3, [r3]
    8680:	e2833034 	add	r3, r3, #52	; 0x34
    8684:	e5933000 	ldr	r3, [r3]
    8688:	e2032b01 	and	r2, r3, #1024	; 0x400
    868c:	e3083948 	movw	r3, #35144	; 0x8948
    8690:	e3403001 	movt	r3, #1
    8694:	e5933000 	ldr	r3, [r3]
    8698:	e1a03083 	lsl	r3, r3, #1
    869c:	e283300a 	add	r3, r3, #10
    86a0:	e1a02332 	lsr	r2, r2, r3
    86a4:	e3083948 	movw	r3, #35144	; 0x8948
    86a8:	e3403001 	movt	r3, #1
    86ac:	e5832000 	str	r2, [r3]
    86b0:	e3083958 	movw	r3, #35160	; 0x8958
    86b4:	e3403001 	movt	r3, #1
    86b8:	e5933000 	ldr	r3, [r3]
    86bc:	e2833028 	add	r3, r3, #40	; 0x28
    86c0:	e3a02010 	mov	r2, #16
    86c4:	e5832000 	str	r2, [r3]
    86c8:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    86cc:	e3b0106e 	movs	r1, #110	; 0x6e
    86d0:	e2511001 	subs	r1, r1, #1
    86d4:	1afffffd 	bne	86d0 <testRead+0x530>
    86d8:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    86dc:	e3083958 	movw	r3, #35160	; 0x8958
    86e0:	e3403001 	movt	r3, #1
    86e4:	e5933000 	ldr	r3, [r3]
    86e8:	e283301c 	add	r3, r3, #28
    86ec:	e3a02010 	mov	r2, #16
    86f0:	e5832000 	str	r2, [r3]
    86f4:	ea000000 	b	86fc <testRead+0x55c>
    86f8:	e320f000 	nop	{0}
    86fc:	e3083958 	movw	r3, #35160	; 0x8958
    8700:	e3403001 	movt	r3, #1
    8704:	e5933000 	ldr	r3, [r3]
    8708:	e2833034 	add	r3, r3, #52	; 0x34
    870c:	e5933000 	ldr	r3, [r3]
    8710:	e2033b01 	and	r3, r3, #1024	; 0x400
    8714:	e3530000 	cmp	r3, #0
    8718:	1afffff6 	bne	86f8 <testRead+0x558>
    871c:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8720:	e3b01f4b 	movs	r1, #300	; 0x12c
    8724:	e2511001 	subs	r1, r1, #1
    8728:	1afffffd 	bne	8724 <testRead+0x584>
    872c:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8730:	e3083958 	movw	r3, #35160	; 0x8958
    8734:	e3403001 	movt	r3, #1
    8738:	e5933000 	ldr	r3, [r3]
    873c:	e2833034 	add	r3, r3, #52	; 0x34
    8740:	e5933000 	ldr	r3, [r3]
    8744:	e2032b01 	and	r2, r3, #1024	; 0x400
    8748:	e3083948 	movw	r3, #35144	; 0x8948
    874c:	e3403001 	movt	r3, #1
    8750:	e5933000 	ldr	r3, [r3]
    8754:	e1a03083 	lsl	r3, r3, #1
    8758:	e283300a 	add	r3, r3, #10
    875c:	e1a02332 	lsr	r2, r2, r3
    8760:	e3083948 	movw	r3, #35144	; 0x8948
    8764:	e3403001 	movt	r3, #1
    8768:	e5832000 	str	r2, [r3]
    876c:	e3083958 	movw	r3, #35160	; 0x8958
    8770:	e3403001 	movt	r3, #1
    8774:	e5933000 	ldr	r3, [r3]
    8778:	e2833028 	add	r3, r3, #40	; 0x28
    877c:	e3a02010 	mov	r2, #16
    8780:	e5832000 	str	r2, [r3]
    8784:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8788:	e3b0106e 	movs	r1, #110	; 0x6e
    878c:	e2511001 	subs	r1, r1, #1
    8790:	1afffffd 	bne	878c <testRead+0x5ec>
    8794:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8798:	e3083958 	movw	r3, #35160	; 0x8958
    879c:	e3403001 	movt	r3, #1
    87a0:	e5933000 	ldr	r3, [r3]
    87a4:	e283301c 	add	r3, r3, #28
    87a8:	e3a02010 	mov	r2, #16
    87ac:	e5832000 	str	r2, [r3]
    87b0:	ea000000 	b	87b8 <testRead+0x618>
    87b4:	e320f000 	nop	{0}
    87b8:	e3083958 	movw	r3, #35160	; 0x8958
    87bc:	e3403001 	movt	r3, #1
    87c0:	e5933000 	ldr	r3, [r3]
    87c4:	e2833034 	add	r3, r3, #52	; 0x34
    87c8:	e5933000 	ldr	r3, [r3]
    87cc:	e2033b01 	and	r3, r3, #1024	; 0x400
    87d0:	e3530000 	cmp	r3, #0
    87d4:	1afffff6 	bne	87b4 <testRead+0x614>
    87d8:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    87dc:	e3b01f4b 	movs	r1, #300	; 0x12c
    87e0:	e2511001 	subs	r1, r1, #1
    87e4:	1afffffd 	bne	87e0 <testRead+0x640>
    87e8:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    87ec:	e3083958 	movw	r3, #35160	; 0x8958
    87f0:	e3403001 	movt	r3, #1
    87f4:	e5933000 	ldr	r3, [r3]
    87f8:	e2833034 	add	r3, r3, #52	; 0x34
    87fc:	e5933000 	ldr	r3, [r3]
    8800:	e2032b01 	and	r2, r3, #1024	; 0x400
    8804:	e3083948 	movw	r3, #35144	; 0x8948
    8808:	e3403001 	movt	r3, #1
    880c:	e5933000 	ldr	r3, [r3]
    8810:	e1a03083 	lsl	r3, r3, #1
    8814:	e283300a 	add	r3, r3, #10
    8818:	e1a02332 	lsr	r2, r2, r3
    881c:	e3083948 	movw	r3, #35144	; 0x8948
    8820:	e3403001 	movt	r3, #1
    8824:	e5832000 	str	r2, [r3]
    8828:	e3083958 	movw	r3, #35160	; 0x8958
    882c:	e3403001 	movt	r3, #1
    8830:	e5933000 	ldr	r3, [r3]
    8834:	e2833028 	add	r3, r3, #40	; 0x28
    8838:	e3a02010 	mov	r2, #16
    883c:	e5832000 	str	r2, [r3]
    8840:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8844:	e3b0106e 	movs	r1, #110	; 0x6e
    8848:	e2511001 	subs	r1, r1, #1
    884c:	1afffffd 	bne	8848 <testRead+0x6a8>
    8850:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8854:	e320f000 	nop	{0}
    8858:	e28bd000 	add	sp, fp, #0
    885c:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
    8860:	e12fff1e 	bx	lr

00008864 <output1>:
    8864:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
    8868:	e28db000 	add	fp, sp, #0
    886c:	e3083958 	movw	r3, #35160	; 0x8958
    8870:	e3403001 	movt	r3, #1
    8874:	e5933000 	ldr	r3, [r3]
    8878:	e2833028 	add	r3, r3, #40	; 0x28
    887c:	e3a02008 	mov	r2, #8
    8880:	e5832000 	str	r2, [r3]
    8884:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8888:	e3b01069 	movs	r1, #105	; 0x69
    888c:	e2511001 	subs	r1, r1, #1
    8890:	1afffffd 	bne	888c <output1+0x28>
    8894:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8898:	e3083958 	movw	r3, #35160	; 0x8958
    889c:	e3403001 	movt	r3, #1
    88a0:	e5933000 	ldr	r3, [r3]
    88a4:	e283301c 	add	r3, r3, #28
    88a8:	e3a02008 	mov	r2, #8
    88ac:	e5832000 	str	r2, [r3]
    88b0:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    88b4:	e3b01f4b 	movs	r1, #300	; 0x12c
    88b8:	e2511001 	subs	r1, r1, #1
    88bc:	1afffffd 	bne	88b8 <output1+0x54>
    88c0:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    88c4:	e320f000 	nop	{0}
    88c8:	e28bd000 	add	sp, fp, #0
    88cc:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
    88d0:	e12fff1e 	bx	lr

000088d4 <output0>:
    88d4:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
    88d8:	e28db000 	add	fp, sp, #0
    88dc:	e3083958 	movw	r3, #35160	; 0x8958
    88e0:	e3403001 	movt	r3, #1
    88e4:	e5933000 	ldr	r3, [r3]
    88e8:	e2833028 	add	r3, r3, #40	; 0x28
    88ec:	e3a02008 	mov	r2, #8
    88f0:	e5832000 	str	r2, [r3]
    88f4:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    88f8:	e3b01f4e 	movs	r1, #312	; 0x138
    88fc:	e2511001 	subs	r1, r1, #1
    8900:	1afffffd 	bne	88fc <output0+0x28>
    8904:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8908:	e3083958 	movw	r3, #35160	; 0x8958
    890c:	e3403001 	movt	r3, #1
    8910:	e5933000 	ldr	r3, [r3]
    8914:	e283301c 	add	r3, r3, #28
    8918:	e3a02008 	mov	r2, #8
    891c:	e5832000 	str	r2, [r3]
    8920:	e52d1004 	push	{r1}		; (str r1, [sp, #-4]!)
    8924:	e3b01050 	movs	r1, #80	; 0x50
    8928:	e2511001 	subs	r1, r1, #1
    892c:	1afffffd 	bne	8928 <output0+0x54>
    8930:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8934:	e320f000 	nop	{0}
    8938:	e28bd000 	add	sp, fp, #0
    893c:	e49db004 	pop	{fp}		; (ldr fp, [sp], #4)
    8940:	e12fff1e 	bx	lr

Disassembly of section .bss:

00018944 <j>:
   18944:	00000000 	andeq	r0, r0, r0

00018948 <v1>:
   18948:	00000000 	andeq	r0, r0, r0

0001894c <v2>:
   1894c:	00000000 	andeq	r0, r0, r0

00018950 <tim>:
   18950:	00000000 	andeq	r0, r0, r0

00018954 <inputValue>:
   18954:	00000000 	andeq	r0, r0, r0

00018958 <gpio>:
   18958:	00000000 	andeq	r0, r0, r0

0001895c <tim1>:
   1895c:	00000000 	andeq	r0, r0, r0

00018960 <risingEdge>:
   18960:	00000000 	andeq	r0, r0, r0

Disassembly of section .comment:

00000000 <_stack-0x80000>:
   0:	3a434347 	bcc	10d0d24 <_stack+0x1050d24>
   4:	4e472820 	cdpmi	8, 4, cr2, cr7, cr0, {1}
   8:	6f542055 	svcvs	0x00542055
   c:	20736c6f 	rsbscs	r6, r3, pc, ror #24
  10:	20726f66 	rsbscs	r6, r2, r6, ror #30
  14:	206d7241 	rsbcs	r7, sp, r1, asr #4
  18:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xfffff2bb
  1c:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  20:	6f725020 	svcvs	0x00725020
  24:	73736563 	cmnvc	r3, #415236096	; 0x18c00000
  28:	2073726f 	rsbscs	r7, r3, pc, ror #4
  2c:	30322d38 	eorscc	r2, r2, r8, lsr sp
  30:	712d3831 			; <UNDEFINED> instruction: 0x712d3831
  34:	616d2d34 	cmnvs	sp, r4, lsr sp
  38:	29726f6a 	ldmdbcs	r2!, {r1, r3, r5, r6, r8, r9, sl, fp, sp, lr}^
  3c:	322e3820 	eorcc	r3, lr, #32, 16	; 0x200000
  40:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  44:	31383130 	teqcc	r8, r0, lsr r1
  48:	20333132 	eorscs	r3, r3, r2, lsr r1
  4c:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  50:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  54:	675b2029 	ldrbvs	r2, [fp, -r9, lsr #32]
  58:	382d6363 	stmdacc	sp!, {r0, r1, r5, r6, r8, r9, sp, lr}
  5c:	6172622d 	cmnvs	r2, sp, lsr #4
  60:	2068636e 	rsbcs	r6, r8, lr, ror #6
  64:	69766572 	ldmdbvs	r6!, {r1, r4, r5, r6, r8, sl, sp, lr}^
  68:	6e6f6973 			; <UNDEFINED> instruction: 0x6e6f6973
  6c:	37363220 	ldrcc	r3, [r6, -r0, lsr #4]!
  70:	5d343730 	ldcpl	7, cr3, [r4, #-192]!	; 0xffffff40
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
   c:	00000000 	andeq	r0, r0, r0
  10:	00008000 	andeq	r8, r0, r0
  14:	00000944 	andeq	r0, r0, r4, asr #18
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000161 	andeq	r0, r0, r1, ror #2
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000000d 	andeq	r0, r0, sp
  10:	0000ea0c 	andeq	lr, r0, ip, lsl #20
  14:	00015100 	andeq	r5, r1, r0, lsl #2
  18:	00800000 	addeq	r0, r0, r0
  1c:	00094400 	andeq	r4, r9, r0, lsl #8
  20:	00000000 	andeq	r0, r0, r0
  24:	00e00200 	rsceq	r0, r0, r0, lsl #4
  28:	83010000 	movwhi	r0, #4096	; 0x1000
  2c:	00003718 	andeq	r3, r0, r8, lsl r7
  30:	58030500 	stmdapl	r3, {r8, sl}
  34:	03000189 	movweq	r0, #393	; 0x189
  38:	00004404 	andeq	r4, r0, r4, lsl #8
  3c:	07040400 	streq	r0, [r4, -r0, lsl #8]
  40:	00000000 	andeq	r0, r0, r0
  44:	00003d05 	andeq	r3, r0, r5, lsl #26
  48:	69740600 	ldmdbvs	r4!, {r9, sl}^
  4c:	8601006d 	strhi	r0, [r1], -sp, rrx
  50:	00004417 	andeq	r4, r0, r7, lsl r4
  54:	50030500 	andpl	r0, r3, r0, lsl #10
  58:	02000189 	andeq	r0, r0, #1073741858	; 0x40000022
  5c:	000001ae 	andeq	r0, r0, lr, lsr #3
  60:	740e8701 	strvc	r8, [lr], #-1793	; 0xfffff8ff
  64:	05000000 	streq	r0, [r0, #-0]
  68:	01895c03 	orreq	r5, r9, r3, lsl #24
  6c:	05040700 	streq	r0, [r4, #-1792]	; 0xfffff900
  70:	00746e69 	rsbseq	r6, r4, r9, ror #28
  74:	00006d05 	andeq	r6, r0, r5, lsl #26
  78:	00ba0200 	adcseq	r0, sl, r0, lsl #4
  7c:	88010000 	stmdahi	r1, {}	; <UNPREDICTABLE>
  80:	00004417 	andeq	r4, r0, r7, lsl r4
  84:	54030500 	strpl	r0, [r3], #-1280	; 0xfffffb00
  88:	02000189 	andeq	r0, r0, #1073741858	; 0x40000022
  8c:	000000d5 	ldrdeq	r0, [r0], -r5
  90:	44178901 	ldrmi	r8, [r7], #-2305	; 0xfffff6ff
  94:	05000000 	streq	r0, [r0, #-0]
  98:	01896003 	orreq	r6, r9, r3
  9c:	006a0600 	rsbeq	r0, sl, r0, lsl #12
  a0:	44178a01 	ldrmi	r8, [r7], #-2561	; 0xfffff5ff
  a4:	05000000 	streq	r0, [r0, #-0]
  a8:	01894403 	orreq	r4, r9, r3, lsl #8
  ac:	31760600 	cmncc	r6, r0, lsl #12
  b0:	178b0100 	strne	r0, [fp, r0, lsl #2]
  b4:	00000044 	andeq	r0, r0, r4, asr #32
  b8:	89480305 	stmdbhi	r8, {r0, r2, r8, r9}^
  bc:	76060001 	strvc	r0, [r6], -r1
  c0:	f3010032 	vqadd.u8	d0, d1, d18
  c4:	0000740e 	andeq	r7, r0, lr, lsl #8
  c8:	4c030500 	cfstr32mi	mvfx0, [r3], {-0}
  cc:	08000189 	stmdaeq	r0, {r0, r3, r7, r8}
  d0:	000000c5 	andeq	r0, r0, r5, asr #1
  d4:	0601f301 	streq	pc, [r1], -r1, lsl #6
  d8:	000088d4 	ldrdeq	r8, [r0], -r4
  dc:	00000070 	andeq	r0, r0, r0, ror r0
  e0:	cd089c01 	stcgt	12, cr9, [r8, #-4]
  e4:	01000000 	mrseq	r0, (UNDEF: 0)
  e8:	640601c1 	strvs	r0, [r6], #-449	; 0xfffffe3f
  ec:	70000088 	andvc	r0, r0, r8, lsl #1
  f0:	01000000 	mrseq	r0, (UNDEF: 0)
  f4:	00b1099c 	umlalseq	r0, r1, ip, r9
  f8:	f4010000 	vst4.8	{d0-d3}, [r1], r0
  fc:	0081a006 	addeq	sl, r1, r6
 100:	0006c400 	andeq	ip, r6, r0, lsl #8
 104:	0a9c0100 	beq	fe70050c <_stack+0xfe68050c>
 108:	000000e5 	andeq	r0, r0, r5, ror #1
 10c:	6d058f01 	stcvs	15, cr8, [r5, #-4]
 110:	00000000 	andeq	r0, r0, r0
 114:	a0000080 	andge	r0, r0, r0, lsl #1
 118:	01000001 	tsteq	r0, r1
 11c:	81400b9c 			; <UNDEFINED> instruction: 0x81400b9c
 120:	005c0000 	subseq	r0, ip, r0
 124:	b10c0000 	mrslt	r0, (UNDEF: 12)
 128:	01000000 	mrseq	r0, (UNDEF: 0)
 12c:	006d03d3 	ldrdeq	r0, [sp], #-51	; 0xffffffcd	; <UNPREDICTABLE>
 130:	01380000 	teqeq	r8, r0
 134:	000d0000 	andeq	r0, sp, r0
 138:	0081580b 	addeq	r5, r1, fp, lsl #16
 13c:	00004400 	andeq	r4, r0, r0, lsl #8
 140:	00c50c00 	sbceq	r0, r5, r0, lsl #24
 144:	da010000 	ble	4014c <__bss_end__+0x277e8>
 148:	00006d04 	andeq	r6, r0, r4, lsl #26
 14c:	00015300 	andeq	r5, r1, r0, lsl #6
 150:	0e000d00 	cdpeq	13, 0, cr0, cr0, cr0, {0}
 154:	000000cd 	andeq	r0, r0, sp, asr #1
 158:	6d04dc01 	stcvs	12, cr13, [r4, #-4]
 15c:	0d000000 	stceq	0, cr0, [r0, #-0]
 160:	00000000 	andeq	r0, r0, r0
	...

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  18:	0b3b0b3a 	bleq	ec2d08 <_stack+0xe42d08>
  1c:	13490b39 	movtne	r0, #39737	; 0x9b39
  20:	1802193f 	stmdane	r2, {r0, r1, r2, r3, r4, r5, r8, fp, ip}
  24:	0f030000 	svceq	0x00030000
  28:	490b0b00 	stmdbmi	fp, {r8, r9, fp}
  2c:	04000013 	streq	r0, [r0], #-19	; 0xffffffed
  30:	0b0b0024 	bleq	2c00c8 <_stack+0x2400c8>
  34:	0e030b3e 	vmoveq.16	d3[0], r0
  38:	35050000 	strcc	r0, [r5, #-0]
  3c:	00134900 	andseq	r4, r3, r0, lsl #18
  40:	00340600 	eorseq	r0, r4, r0, lsl #12
  44:	0b3a0803 	bleq	e82058 <_stack+0xe02058>
  48:	0b390b3b 	bleq	e42d3c <_stack+0xdc2d3c>
  4c:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	; <UNPREDICTABLE>
  50:	00001802 	andeq	r1, r0, r2, lsl #16
  54:	0b002407 	bleq	9078 <output0+0x7a4>
  58:	030b3e0b 	movweq	r3, #48651	; 0xbe0b
  5c:	08000008 	stmdaeq	r0, {r3}
  60:	193f002e 	ldmdbne	pc!, {r1, r2, r3, r5}	; <UNPREDICTABLE>
  64:	0b3a0e03 	bleq	e83878 <_stack+0xe03878>
  68:	0b39053b 	bleq	e4155c <_stack+0xdc155c>
  6c:	06120111 			; <UNDEFINED> instruction: 0x06120111
  70:	42971840 	addsmi	r1, r7, #64, 16	; 0x400000
  74:	09000019 	stmdbeq	r0, {r0, r3, r4}
  78:	193f002e 	ldmdbne	pc!, {r1, r2, r3, r5}	; <UNPREDICTABLE>
  7c:	0b3a0e03 	bleq	e83890 <_stack+0xe03890>
  80:	0b390b3b 	bleq	e42d74 <_stack+0xdc2d74>
  84:	06120111 			; <UNDEFINED> instruction: 0x06120111
  88:	42971840 	addsmi	r1, r7, #64, 16	; 0x400000
  8c:	0a000019 	beq	f8 <main-0x7f08>
  90:	193f012e 	ldmdbne	pc!, {r1, r2, r3, r5, r8}	; <UNPREDICTABLE>
  94:	0b3a0e03 	bleq	e838a8 <_stack+0xe038a8>
  98:	0b390b3b 	bleq	e42d8c <_stack+0xdc2d8c>
  9c:	13491927 	movtne	r1, #39207	; 0x9927
  a0:	06120111 			; <UNDEFINED> instruction: 0x06120111
  a4:	42961840 	addsmi	r1, r6, #64, 16	; 0x400000
  a8:	0b000019 	bleq	114 <main-0x7eec>
  ac:	0111010b 	tsteq	r1, fp, lsl #2
  b0:	00000612 	andeq	r0, r0, r2, lsl r6
  b4:	3f012e0c 	svccc	0x00012e0c
  b8:	3a0e0319 	bcc	380d24 <_stack+0x300d24>
  bc:	390b3b0b 	stmdbcc	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  c0:	3c13490b 			; <UNDEFINED> instruction: 0x3c13490b
  c4:	00130119 	andseq	r0, r3, r9, lsl r1
  c8:	00180d00 	andseq	r0, r8, r0, lsl #26
  cc:	2e0e0000 	cdpcs	0, 0, cr0, cr14, cr0, {0}
  d0:	03193f01 	tsteq	r9, #1, 30
  d4:	3b0b3a0e 	blcc	2ce914 <_stack+0x24e914>
  d8:	490b390b 	stmdbmi	fp, {r0, r1, r3, r8, fp, ip, sp}
  dc:	00193c13 	andseq	r3, r9, r3, lsl ip
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000349 	andeq	r0, r0, r9, asr #6
   4:	007d0003 	rsbseq	r0, sp, r3
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	43010000 	movwmi	r0, #4096	; 0x1000
  1c:	73552f3a 	cmpvc	r5, #58, 30	; 0xe8
  20:	2f737265 	svccs	0x00737265
  24:	68656f6b 	stmdavs	r5!, {r0, r1, r3, r5, r6, r8, r9, sl, fp, sp, lr}^
  28:	6a72656c 	bvs	1c995e0 <_stack+0x1c195e0>
  2c:	65442f6a 	strbvs	r2, [r4, #-3946]	; 0xfffff096
  30:	6f746b73 	svcvs	0x00746b73
  34:	6f772f70 	svcvs	0x00772f70
  38:	70736b72 	rsbsvc	r6, r3, r2, ror fp
  3c:	2f656361 	svccs	0x00656361
  40:	696e6573 	stmdbvs	lr!, {r0, r1, r4, r5, r6, r8, sl, sp, lr}^
  44:	772d726f 	strvc	r7, [sp, -pc, ror #4]!
  48:	736b726f 	cmnvc	fp, #-268435450	; 0xf0000006
  4c:	65636170 	strbvs	r6, [r3, #-368]!	; 0xfffffe90
  50:	6761672f 	strbvs	r6, [r1, -pc, lsr #14]!
  54:	62756365 	rsbsvs	r6, r5, #-1811939327	; 0x94000001
  58:	73615465 	cmnvc	r1, #1694498816	; 0x65000000
  5c:	6f626f52 	svcvs	0x00626f52
  60:	43472f74 	movtmi	r2, #32628	; 0x7f74
  64:	75706e49 	ldrbvc	r6, [r0, #-3657]!	; 0xfffff1b7
  68:	76654474 			; <UNDEFINED> instruction: 0x76654474
  6c:	2f656369 	svccs	0x00656369
  70:	636d7261 	cmnvs	sp, #268435462	; 0x10000006
  74:	0033302d 	eorseq	r3, r3, sp, lsr #32
  78:	6d726100 	ldfvse	f6, [r2, #-0]
  7c:	33302d63 	teqcc	r0, #6336	; 0x18c0
  80:	0100632e 	tsteq	r0, lr, lsr #6
  84:	05000000 	streq	r0, [r0, #-0]
  88:	02050001 	andeq	r0, r5, #1
  8c:	00008000 	andeq	r8, r0, r0
  90:	01018f03 	tsteq	r1, r3, lsl #30
  94:	2f150205 	svccs	0x00150205
  98:	2f2f2f2f 	svccs	0x002f2f2f
  9c:	302f322f 	eorcc	r3, pc, pc, lsr #4
  a0:	312f2f2f 			; <UNDEFINED> instruction: 0x312f2f2f
  a4:	2f2f2f2f 	svccs	0x002f2f2f
  a8:	2f2f2f2f 	svccs	0x002f2f2f
  ac:	2f2e0b03 	svccs	0x002e0b03
  b0:	31070532 	tstcc	r7, r2, lsr r5
  b4:	08a21505 	stmiaeq	r2!, {r0, r2, r8, sl, ip}
  b8:	08220821 	stmdaeq	r2!, {r0, r5, fp}
  bc:	08060521 	stmdaeq	r6, {r0, r5, r8, sl}
  c0:	82120559 	andshi	r0, r2, #373293056	; 0x16400000
  c4:	054d0605 	strbeq	r0, [sp, #-1541]	; 0xfffff9fb
  c8:	03058212 	movweq	r8, #21010	; 0x5212
  cc:	04053050 	streq	r3, [r5], #-80	; 0xffffffb0
  d0:	2f2f2fa3 	svccs	0x002f2fa3
  d4:	2f2f2f30 	svccs	0x002f2f30
  d8:	2f2f2f30 	svccs	0x002f2f30
  dc:	2f2f2f30 	svccs	0x002f2f30
  e0:	03020530 	movweq	r0, #9520	; 0x2530
  e4:	01052e62 	tsteq	r5, r2, ror #28
  e8:	052e2503 	streq	r2, [lr, #-1283]!	; 0xfffffafd
  ec:	06054c05 	streq	r4, [r5], -r5, lsl #24
  f0:	82120584 	andshi	r0, r2, #132, 10	; 0x21000000
  f4:	054c0805 	strbeq	r0, [ip, #-2053]	; 0xfffff7fb
  f8:	0e053003 	cdpeq	0, 0, cr3, cr5, cr3, {0}
  fc:	9e1c052c 	cfmul64ls	mvdx0, mvdx12, mvdx12
 100:	052e0805 	streq	r0, [lr, #-2053]!	; 0xfffff7fb
 104:	2f2f5002 	svccs	0x002f5002
 108:	0c052f2f 	stceq	15, cr2, [r5], {47}	; 0x2f
 10c:	9e1a0530 	cfmvr64hls	r0, mvdx10
 110:	052e3d05 	streq	r3, [lr, #-3333]!	; 0xfffff2fb
 114:	2c058237 	sfmcs	f0, 1, [r5], {55}	; 0x37
 118:	2e05052e 	cfsh32cs	mvfx0, mvfx5, #30
 11c:	05670605 	strbeq	r0, [r7, #-1541]!	; 0xfffff9fb
 120:	02058212 	andeq	r8, r5, #536870913	; 0x20000001
 124:	2f2f2f4c 	svccs	0x002f2f4c
 128:	2f06052f 	svccs	0x0006052f
 12c:	05821205 	streq	r1, [r2, #517]	; 0x205
 130:	03054c08 	movweq	r4, #23560	; 0x5c08
 134:	2c0e0530 	cfstr32cs	mvfx0, [lr], {48}	; 0x30
 138:	059e1c05 	ldreq	r1, [lr, #3077]	; 0xc05
 13c:	02052e08 	andeq	r2, r5, #8, 28	; 0x80
 140:	2f2f2f50 	svccs	0x002f2f50
 144:	300c052f 	andcc	r0, ip, pc, lsr #10
 148:	059e1a05 	ldreq	r1, [lr, #2565]	; 0xa05
 14c:	37052e3d 	smladxcc	r5, sp, lr, r2
 150:	2e2c0582 	cfsh64cs	mvdx0, mvdx12, #-62
 154:	052e0505 	streq	r0, [lr, #-1285]!	; 0xfffffafb
 158:	12056706 	andne	r6, r5, #1572864	; 0x180000
 15c:	4c020582 	cfstr32mi	mvfx0, [r2], {130}	; 0x82
 160:	2f2f2f2f 	svccs	0x002f2f2f
 164:	052f0605 	streq	r0, [pc, #-1541]!	; fffffb67 <_stack+0xfff7fb67>
 168:	08058212 	stmdaeq	r5, {r1, r4, r9, pc}
 16c:	3003054c 	andcc	r0, r3, ip, asr #10
 170:	052c0e05 	streq	r0, [ip, #-3589]!	; 0xfffff1fb
 174:	08059e1c 	stmdaeq	r5, {r2, r3, r4, r9, sl, fp, ip, pc}
 178:	5002052e 	andpl	r0, r2, lr, lsr #10
 17c:	2f2f2f2f 	svccs	0x002f2f2f
 180:	05300c05 	ldreq	r0, [r0, #-3077]!	; 0xfffff3fb
 184:	3d059e1a 	stccc	14, cr9, [r5, #-104]	; 0xffffff98
 188:	8237052e 	eorshi	r0, r7, #192937984	; 0xb800000
 18c:	052e2c05 	streq	r2, [lr, #-3077]!	; 0xfffff3fb
 190:	06052e05 	streq	r2, [r5], -r5, lsl #28
 194:	82120567 	andshi	r0, r2, #432013312	; 0x19c00000
 198:	2f4c0205 	svccs	0x004c0205
 19c:	052f2f2f 	streq	r2, [pc, #-3887]!	; fffff275 <_stack+0xfff7f275>
 1a0:	12052f06 	andne	r2, r5, #6, 30
 1a4:	4c080582 	cfstr32mi	mvfx0, [r8], {130}	; 0x82
 1a8:	05300305 	ldreq	r0, [r0, #-773]!	; 0xfffffcfb
 1ac:	1c052c0e 	stcne	12, cr2, [r5], {14}
 1b0:	2e08059e 	mcrcs	5, 0, r0, cr8, cr14, {4}
 1b4:	2f500205 	svccs	0x00500205
 1b8:	052f2f2f 	streq	r2, [pc, #-3887]!	; fffff291 <_stack+0xfff7f291>
 1bc:	1a05300c 	bne	14c1f4 <_stack+0xcc1f4>
 1c0:	2e3d059e 	mrccs	5, 1, r0, cr13, cr14, {4}
 1c4:	05823705 	streq	r3, [r2, #1797]	; 0x705
 1c8:	05052e2c 	streq	r2, [r5, #-3628]	; 0xfffff1d4
 1cc:	6706052e 	strvs	r0, [r6, -lr, lsr #10]
 1d0:	05821205 	streq	r1, [r2, #517]	; 0x205
 1d4:	2f2f4c02 	svccs	0x002f4c02
 1d8:	06052f2f 	streq	r2, [r5], -pc, lsr #30
 1dc:	8212052f 	andshi	r0, r2, #197132288	; 0xbc00000
 1e0:	054c0805 	strbeq	r0, [ip, #-2053]	; 0xfffff7fb
 1e4:	0e053003 	cdpeq	0, 0, cr3, cr5, cr3, {0}
 1e8:	9e1c052c 	cfmul64ls	mvdx0, mvdx12, mvdx12
 1ec:	052e0805 	streq	r0, [lr, #-2053]!	; 0xfffff7fb
 1f0:	2f2f5002 	svccs	0x002f5002
 1f4:	0c052f2f 	stceq	15, cr2, [r5], {47}	; 0x2f
 1f8:	9e1a0530 	cfmvr64hls	r0, mvdx10
 1fc:	052e3d05 	streq	r3, [lr, #-3333]!	; 0xfffff2fb
 200:	2c058237 	sfmcs	f0, 1, [r5], {55}	; 0x37
 204:	2e05052e 	cfsh32cs	mvfx0, mvfx5, #30
 208:	05670605 	strbeq	r0, [r7, #-1541]!	; 0xfffff9fb
 20c:	02058212 	andeq	r8, r5, #536870913	; 0x20000001
 210:	2f2f2f4c 	svccs	0x002f2f4c
 214:	2f06052f 	svccs	0x0006052f
 218:	05821205 	streq	r1, [r2, #517]	; 0x205
 21c:	03054c08 	movweq	r4, #23560	; 0x5c08
 220:	2c0e0530 	cfstr32cs	mvfx0, [lr], {48}	; 0x30
 224:	059e1c05 	ldreq	r1, [lr, #3077]	; 0xc05
 228:	02052e08 	andeq	r2, r5, #8, 28	; 0x80
 22c:	2f2f2f50 	svccs	0x002f2f50
 230:	300c052f 	andcc	r0, ip, pc, lsr #10
 234:	059e1a05 	ldreq	r1, [lr, #2565]	; 0xa05
 238:	37052e3d 	smladxcc	r5, sp, lr, r2
 23c:	2e2c0582 	cfsh64cs	mvdx0, mvdx12, #-62
 240:	052e0505 	streq	r0, [lr, #-1285]!	; 0xfffffafb
 244:	12056706 	andne	r6, r5, #1572864	; 0x180000
 248:	4c020582 	cfstr32mi	mvfx0, [r2], {130}	; 0x82
 24c:	2f2f2f2f 	svccs	0x002f2f2f
 250:	052f0605 	streq	r0, [pc, #-1541]!	; fffffc53 <_stack+0xfff7fc53>
 254:	08058212 	stmdaeq	r5, {r1, r4, r9, pc}
 258:	3003054c 	andcc	r0, r3, ip, asr #10
 25c:	052c0e05 	streq	r0, [ip, #-3589]!	; 0xfffff1fb
 260:	08059e1c 	stmdaeq	r5, {r2, r3, r4, r9, sl, fp, ip, pc}
 264:	5002052e 	andpl	r0, r2, lr, lsr #10
 268:	2f2f2f2f 	svccs	0x002f2f2f
 26c:	05300c05 	ldreq	r0, [r0, #-3077]!	; 0xfffff3fb
 270:	3d059e1a 	stccc	14, cr9, [r5, #-104]	; 0xffffff98
 274:	8237052e 	eorshi	r0, r7, #192937984	; 0xb800000
 278:	052e2c05 	streq	r2, [lr, #-3077]!	; 0xfffff3fb
 27c:	06052e05 	streq	r2, [r5], -r5, lsl #28
 280:	82120567 	andshi	r0, r2, #432013312	; 0x19c00000
 284:	2f4c0205 	svccs	0x004c0205
 288:	052f2f2f 	streq	r2, [pc, #-3887]!	; fffff361 <_stack+0xfff7f361>
 28c:	12052f06 	andne	r2, r5, #6, 30
 290:	4c080582 	cfstr32mi	mvfx0, [r8], {130}	; 0x82
 294:	05300305 	ldreq	r0, [r0, #-773]!	; 0xfffffcfb
 298:	1c052c0e 	stcne	12, cr2, [r5], {14}
 29c:	2e08059e 	mcrcs	5, 0, r0, cr8, cr14, {4}
 2a0:	2f500205 	svccs	0x00500205
 2a4:	052f2f2f 	streq	r2, [pc, #-3887]!	; fffff37d <_stack+0xfff7f37d>
 2a8:	1a05300c 	bne	14c2e0 <_stack+0xcc2e0>
 2ac:	2e3d059e 	mrccs	5, 1, r0, cr13, cr14, {4}
 2b0:	05823705 	streq	r3, [r2, #1797]	; 0x705
 2b4:	05052e2c 	streq	r2, [r5, #-3628]	; 0xfffff1d4
 2b8:	6706052e 	strvs	r0, [r6, -lr, lsr #10]
 2bc:	05821205 	streq	r1, [r2, #517]	; 0x205
 2c0:	2f2f4c02 	svccs	0x002f4c02
 2c4:	06052f2f 	streq	r2, [r5], -pc, lsr #30
 2c8:	8212052f 	andshi	r0, r2, #197132288	; 0xbc00000
 2cc:	054c0805 	strbeq	r0, [ip, #-2053]	; 0xfffff7fb
 2d0:	0e053003 	cdpeq	0, 0, cr3, cr5, cr3, {0}
 2d4:	9e1c052c 	cfmul64ls	mvdx0, mvdx12, mvdx12
 2d8:	052e0805 	streq	r0, [lr, #-2053]!	; 0xfffff7fb
 2dc:	2f2f5002 	svccs	0x002f5002
 2e0:	0c052f2f 	stceq	15, cr2, [r5], {47}	; 0x2f
 2e4:	9e1a0530 	cfmvr64hls	r0, mvdx10
 2e8:	052e3d05 	streq	r3, [lr, #-3333]!	; 0xfffff2fb
 2ec:	2c058237 	sfmcs	f0, 1, [r5], {55}	; 0x37
 2f0:	2e05052e 	cfsh32cs	mvfx0, mvfx5, #30
 2f4:	05670605 	strbeq	r0, [r7, #-1541]!	; 0xfffff9fb
 2f8:	02058212 	andeq	r8, r5, #536870913	; 0x20000001
 2fc:	2f2f2f4c 	svccs	0x002f2f4c
 300:	2f01052f 	svccs	0x0001052f
 304:	4e060585 	cfsh32mi	mvfx0, mvfx6, #-59
 308:	05821205 	streq	r1, [r2, #517]	; 0x205
 30c:	4a110302 	bmi	440f1c <_stack+0x3c0f1c>
 310:	2f2f2f2f 	svccs	0x002f2f2f
 314:	05300605 	ldreq	r0, [r0, #-1541]!	; 0xfffff9fb
 318:	02058212 	andeq	r8, r5, #536870913	; 0x20000001
 31c:	2f4a0f03 	svccs	0x004a0f03
 320:	052f2f2f 	streq	r2, [pc, #-3887]!	; fffff3f9 <_stack+0xfff7f3f9>
 324:	05852f01 	streq	r2, [r5, #3841]	; 0xf01
 328:	12054b06 	andne	r4, r5, #6144	; 0x1800
 32c:	03020582 	movweq	r0, #9602	; 0x2582
 330:	2f2f4a11 	svccs	0x002f4a11
 334:	06052f2f 	streq	r2, [r5], -pc, lsr #30
 338:	82120530 	andshi	r0, r2, #48, 10	; 0xc000000
 33c:	0d030205 	sfmeq	f0, 4, [r3, #-20]	; 0xffffffec
 340:	2f2f2f4a 	svccs	0x002f2f4a
 344:	2f01052f 	svccs	0x0001052f
 348:	01000802 	tsteq	r0, r2, lsl #16
 34c:	Address 0x0000034c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	0000000c 	andeq	r0, r0, ip
  14:	00000000 	andeq	r0, r0, r0
  18:	00008000 	andeq	r8, r0, r0
  1c:	000001a0 	andeq	r0, r0, r0, lsr #3
  20:	00000020 	andeq	r0, r0, r0, lsr #32
  24:	00000000 	andeq	r0, r0, r0
  28:	000081a0 	andeq	r8, r0, r0, lsr #3
  2c:	000006c4 	andeq	r0, r0, r4, asr #13
  30:	8b040e42 	blhi	103940 <_stack+0x83940>
  34:	0b0d4201 	bleq	350840 <_stack+0x2d0840>
  38:	0d035a03 	vstreq	s10, [r3, #-12]
  3c:	0ecb420d 	cdpeq	2, 12, cr4, cr11, cr13, {0}
  40:	00000000 	andeq	r0, r0, r0
  44:	0000001c 	andeq	r0, r0, ip, lsl r0
  48:	00000000 	andeq	r0, r0, r0
  4c:	00008864 	andeq	r8, r0, r4, ror #16
  50:	00000070 	andeq	r0, r0, r0, ror r0
  54:	8b040e42 	blhi	103964 <_stack+0x83964>
  58:	0b0d4201 	bleq	350864 <_stack+0x2d0864>
  5c:	420d0d70 	andmi	r0, sp, #112, 26	; 0x1c00
  60:	00000ecb 	andeq	r0, r0, fp, asr #29
  64:	0000001c 	andeq	r0, r0, ip, lsl r0
  68:	00000000 	andeq	r0, r0, r0
  6c:	000088d4 	ldrdeq	r8, [r0], -r4
  70:	00000070 	andeq	r0, r0, r0, ror r0
  74:	8b040e42 	blhi	103984 <_stack+0x83984>
  78:	0b0d4201 	bleq	350884 <_stack+0x2d0884>
  7c:	420d0d70 	andmi	r0, sp, #112, 26	; 0x1c00
  80:	00000ecb 	andeq	r0, r0, fp, asr #29

Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xfffff199
   8:	746e6920 	strbtvc	r6, [lr], #-2336	; 0xfffff6e0
   c:	554e4700 	strbpl	r4, [lr, #-1792]	; 0xfffff900
  10:	37314320 	ldrcc	r4, [r1, -r0, lsr #6]!
  14:	322e3820 	eorcc	r3, lr, #32, 16	; 0x200000
  18:	3220312e 	eorcc	r3, r0, #-2147483637	; 0x8000000b
  1c:	31383130 	teqcc	r8, r0, lsr r1
  20:	20333132 	eorscs	r3, r3, r2, lsr r1
  24:	6c657228 	sfmvs	f7, 2, [r5], #-160	; 0xffffff60
  28:	65736165 	ldrbvs	r6, [r3, #-357]!	; 0xfffffe9b
  2c:	675b2029 	ldrbvs	r2, [fp, -r9, lsr #32]
  30:	382d6363 	stmdacc	sp!, {r0, r1, r5, r6, r8, r9, sp, lr}
  34:	6172622d 	cmnvs	r2, sp, lsr #4
  38:	2068636e 	rsbcs	r6, r8, lr, ror #6
  3c:	69766572 	ldmdbvs	r6!, {r1, r4, r5, r6, r8, sl, sp, lr}^
  40:	6e6f6973 			; <UNDEFINED> instruction: 0x6e6f6973
  44:	37363220 	ldrcc	r3, [r6, -r0, lsr #4]!
  48:	5d343730 	ldcpl	7, cr3, [r4, #-192]!	; 0xffffff40
  4c:	666d2d20 	strbtvs	r2, [sp], -r0, lsr #26
  50:	74616f6c 	strbtvc	r6, [r1], #-3948	; 0xfffff094
  54:	6962612d 	stmdbvs	r2!, {r0, r2, r3, r5, r8, sp, lr}^
  58:	7261683d 	rsbvc	r6, r1, #3997696	; 0x3d0000
  5c:	6d2d2064 	stcvs	0, cr2, [sp, #-400]!	; 0xfffffe70
  60:	3d757066 	ldclcc	0, cr7, [r5, #-408]!	; 0xfffffe68
  64:	70797263 	rsbsvc	r7, r9, r3, ror #4
  68:	6e2d6f74 	mcrvs	15, 1, r6, cr13, cr4, {3}
  6c:	2d6e6f65 	stclcs	15, cr6, [lr, #-404]!	; 0xfffffe6c
  70:	612d7066 			; <UNDEFINED> instruction: 0x612d7066
  74:	38766d72 	ldmdacc	r6!, {r1, r4, r5, r6, r8, sl, fp, sp, lr}^
  78:	636d2d20 	cmnvs	sp, #32, 26	; 0x800
  7c:	633d7570 	teqvs	sp, #112, 10	; 0x1c000000
  80:	6574726f 	ldrbvs	r7, [r4, #-623]!	; 0xfffffd91
  84:	35612d78 	strbcc	r2, [r1, #-3448]!	; 0xfffff288
  88:	6d2d2033 	stcvs	0, cr2, [sp, #-204]!	; 0xffffff34
  8c:	206d7261 	rsbcs	r7, sp, r1, ror #4
  90:	72616d2d 	rsbvc	r6, r1, #2880	; 0xb40
  94:	613d6863 	teqvs	sp, r3, ror #16
  98:	38766d72 	ldmdacc	r6!, {r1, r4, r5, r6, r8, sl, fp, sp, lr}^
  9c:	632b612d 			; <UNDEFINED> instruction: 0x632b612d
  a0:	632b6372 			; <UNDEFINED> instruction: 0x632b6372
  a4:	74707972 	ldrbtvc	r7, [r0], #-2418	; 0xfffff68e
  a8:	672d206f 	strvs	r2, [sp, -pc, rrx]!
  ac:	304f2d20 	subcc	r2, pc, r0, lsr #26
  b0:	73657400 	cmnvc	r5, #0, 8
  b4:	61655274 	smcvs	21796	; 0x5524
  b8:	6e690064 	cdpvs	0, 6, cr0, cr9, cr4, {3}
  bc:	56747570 			; <UNDEFINED> instruction: 0x56747570
  c0:	65756c61 	ldrbvs	r6, [r5, #-3169]!	; 0xfffff39f
  c4:	74756f00 	ldrbtvc	r6, [r5], #-3840	; 0xfffff100
  c8:	30747570 	rsbscc	r7, r4, r0, ror r5
  cc:	74756f00 	ldrbtvc	r6, [r5], #-3840	; 0xfffff100
  d0:	31747570 	cmncc	r4, r0, ror r5
  d4:	73697200 	cmnvc	r9, #0, 4
  d8:	45676e69 	strbmi	r6, [r7, #-3689]!	; 0xfffff197
  dc:	00656764 	rsbeq	r6, r5, r4, ror #14
  e0:	6f697067 	svcvs	0x00697067
  e4:	69616d00 	stmdbvs	r1!, {r8, sl, fp, sp, lr}^
  e8:	3a43006e 	bcc	10c02a8 <_stack+0x10402a8>
  ec:	6573552f 	ldrbvs	r5, [r3, #-1327]!	; 0xfffffad1
  f0:	6b2f7372 	blvs	bdcec0 <_stack+0xb5cec0>
  f4:	6c68656f 	cfstr64vs	mvdx6, [r8], #-444	; 0xfffffe44
  f8:	6a6a7265 	bvs	1a9ca94 <_stack+0x1a1ca94>
  fc:	7365442f 	cmnvc	r5, #788529152	; 0x2f000000
 100:	706f746b 	rsbvc	r7, pc, fp, ror #8
 104:	726f772f 	rsbvc	r7, pc, #12320768	; 0xbc0000
 108:	6170736b 	cmnvs	r0, fp, ror #6
 10c:	732f6563 			; <UNDEFINED> instruction: 0x732f6563
 110:	6f696e65 	svcvs	0x00696e65
 114:	6f772d72 	svcvs	0x00772d72
 118:	70736b72 	rsbsvc	r6, r3, r2, ror fp
 11c:	2f656361 	svccs	0x00656361
 120:	65676167 	strbvs	r6, [r7, #-359]!	; 0xfffffe99
 124:	65627563 	strbvs	r7, [r2, #-1379]!	; 0xfffffa9d
 128:	52736154 	rsbspl	r6, r3, #84, 2
 12c:	746f626f 	strbtvc	r6, [pc], #-623	; 134 <main-0x7ecc>
 130:	4943472f 	stmdbmi	r3, {r0, r1, r2, r3, r5, r8, r9, sl, lr}^
 134:	7475706e 	ldrbtvc	r7, [r5], #-110	; 0xffffff92
 138:	69766544 	ldmdbvs	r6!, {r2, r6, r8, sl, sp, lr}^
 13c:	612f6563 			; <UNDEFINED> instruction: 0x612f6563
 140:	2d636d72 	stclcs	13, cr6, [r3, #-456]!	; 0xfffffe38
 144:	612f3330 			; <UNDEFINED> instruction: 0x612f3330
 148:	2d636d72 	stclcs	13, cr6, [r3, #-456]!	; 0xfffffe38
 14c:	632e3330 			; <UNDEFINED> instruction: 0x632e3330
 150:	5c3a4300 	ldcpl	3, cr4, [sl], #-0
 154:	72657355 	rsbvc	r7, r5, #1409286145	; 0x54000001
 158:	6f6b5c73 	svcvs	0x006b5c73
 15c:	656c6865 	strbvs	r6, [ip, #-2149]!	; 0xfffff79b
 160:	5c6a6a72 			; <UNDEFINED> instruction: 0x5c6a6a72
 164:	6b736544 	blvs	1cd967c <_stack+0x1c5967c>
 168:	5c706f74 	ldclpl	15, cr6, [r0], #-464	; 0xfffffe30
 16c:	6b726f77 	blvs	1c9bf50 <_stack+0x1c1bf50>
 170:	63617073 	cmnvs	r1, #115	; 0x73
 174:	65735c65 	ldrbvs	r5, [r3, #-3173]!	; 0xfffff39b
 178:	726f696e 	rsbvc	r6, pc, #1802240	; 0x1b8000
 17c:	726f772d 	rsbvc	r7, pc, #11796480	; 0xb40000
 180:	6170736b 	cmnvs	r0, fp, ror #6
 184:	675c6563 	ldrbvs	r6, [ip, -r3, ror #10]
 188:	63656761 	cmnvs	r5, #25427968	; 0x1840000
 18c:	54656275 	strbtpl	r6, [r5], #-629	; 0xfffffd8b
 190:	6f527361 	svcvs	0x00527361
 194:	5c746f62 	ldclpl	15, cr6, [r4], #-392	; 0xfffffe78
 198:	6e494347 	cdpvs	3, 4, cr4, cr9, cr7, {2}
 19c:	44747570 	ldrbtmi	r7, [r4], #-1392	; 0xfffffa90
 1a0:	63697665 	cmnvs	r9, #105906176	; 0x6500000
 1a4:	72615c65 	rsbvc	r5, r1, #25856	; 0x6500
 1a8:	302d636d 	eorcc	r6, sp, sp, ror #6
 1ac:	69740033 	ldmdbvs	r4!, {r0, r1, r4, r5}^
 1b0:	Address 0x000001b0 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003841 	andeq	r3, r0, r1, asr #16
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000002e 	andeq	r0, r0, lr, lsr #32
  10:	412d3805 			; <UNDEFINED> instruction: 0x412d3805
  14:	070e0600 	streq	r0, [lr, -r0, lsl #12]
  18:	09010841 	stmdbeq	r1, {r0, r6, fp}
  1c:	0c070a02 			; <UNDEFINED> instruction: 0x0c070a02
  20:	14041203 	strne	r1, [r4], #-515	; 0xfffffdfd
  24:	17011501 	strne	r1, [r1, -r1, lsl #10]
  28:	19011803 	stmdbne	r1, {r0, r1, fp, ip}
  2c:	1c011a01 			; <UNDEFINED> instruction: 0x1c011a01
  30:	22061e01 	andcs	r1, r6, #1, 28
  34:	44012a01 	strmi	r2, [r1], #-2561	; 0xfffff5ff
  38:	Address 0x00000038 is out of bounds.

