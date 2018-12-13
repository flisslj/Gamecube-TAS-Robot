/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

.section ".text.boot"

.global _start

_start:
    //********************************************************************************************************
    mrs     x1, mpidr_el1 // read cpu id, stop slave cores
    sub     x1, x1, #0 //and all core numbers with 0b11
    cbnz     x1, 5f //if zero, branch forward to 2:, otherwise continue to 1:


2:  // cpu id == 0 
    // set stack before our code
    ldr     x1, =_start //load stack loaction into x1
    mov     sp, x1 //load x1(stack location) into stack pointer

    // clear bss
    ldr     x1, =__bss_start //load bss_start location into x1
    ldr     w2, =__bss_size //load bss_size location into w2
    
3:  
    cbz     w2, 4f //if w2 is zero, jump to 4. 
    str     xzr, [x1], #8
    sub     w2, w2, #1 //subtract 1 from w2
    cbnz    w2, 3b //if not zero, branch back to 3. 


4:  // jump to C code, should not return
    bl      mainA
    // for failsafe, halt this core too

1:  wfe //wait for event
    b       1b //branch backwards and continue loop


    //********************************************************************************************************
5:
    mrs     x1, mpidr_el1 // read cpu id, stop slave cores
    sub     x1, x1, #1 //and all core numbers with 0b11
    cbnz     x1, 5f //if zero, branch forward to 2:, otherwise continue to 1:


2:  // cpu id == 0 
    // set stack before our code
    ldr     x1, =_start //load stack loaction into x1
    mov     sp, x1 //load x1(stack location) into stack pointer

    // clear bss
    ldr     x1, =__bss_start //load bss_start location into x1
    ldr     w2, =__bss_size //load bss_size location into w2
    
3:  
    cbz     w2, 4f //if w2 is zero, jump to 4. 
    str     xzr, [x1], #8
    sub     w2, w2, #1 //subtract 1 from w2
    cbnz    w2, 3b //if not zero, branch back to 3. 


4:  // jump to C code, should not return
    bl      mainB
    // for failsafe, halt this core too

1:  wfe //wait for event
    b       1b //branch backwards and continue loop

    //********************************************************************************************************

    mrs     x1, mpidr_el1 // read cpu id, stop slave cores
    sub     x1, x1, #2 //and all core numbers with 0b11
    cbnz     x1, 5f //if zero, branch forward to 2:, otherwise continue to 1:


2:  // cpu id == 0 
    // set stack before our code
    ldr     x1, =_start //load stack loaction into x1
    mov     sp, x1 //load x1(stack location) into stack pointer

    // clear bss
    ldr     x1, =__bss_start //load bss_start location into x1
    ldr     w2, =__bss_size //load bss_size location into w2
    
3:  
    cbz     w2, 4f //if w2 is zero, jump to 4. 
    str     xzr, [x1], #8
    sub     w2, w2, #1 //subtract 1 from w2
    cbnz    w2, 3b //if not zero, branch back to 3. 


4:  // jump to C code, should not return
    bl      mainC
    // for failsafe, halt this core too

1:  wfe //wait for event
    b       1b //branch backwards and continue loop

    //********************************************************************************************************
    mrs     x1, mpidr_el1 // read cpu id, stop slave cores
    sub     x1, x1, #3 //and all core numbers with 0b11
    cbnz     x1, 5f //if zero, branch forward to 2:, otherwise continue to 1:


2:  // cpu id == 0 
    // set stack before our code
    ldr     x1, =_start //load stack loaction into x1
    mov     sp, x1 //load x1(stack location) into stack pointer

    // clear bss
    ldr     x1, =__bss_start //load bss_start location into x1
    ldr     w2, =__bss_size //load bss_size location into w2
    
3:  
    cbz     w2, 4f //if w2 is zero, jump to 4. 
    str     xzr, [x1], #8
    sub     w2, w2, #1 //subtract 1 from w2
    cbnz    w2, 3b //if not zero, branch back to 3. 


4:  // jump to C code, should not return
    bl      mainD
    // for failsafe, halt this core too

1:  
    wfe //wait for event
    b       1b //branch backwards and continue loop

5:  //Should not run. 
    wfe //wait for event
    b       5b //branch backwards and continue loop