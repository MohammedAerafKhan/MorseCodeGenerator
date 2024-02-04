.syntax unified             @ unified syntax used
.cpu cortex-m4              @ cpu is cortex-m4
.thumb                      @ use thumb encoding

.text                       @ put code in the code section

// delays are longer for demonstration purposes

// Assembly function to produce a short delay (for dots)
.global delayShort
.type delayShort, %function
delayShort:
    mov r0, #5000
delayShortOuterLoop:
    mov r1, #5000
delayShortInnerLoop:
    subs r1, #1
    bne delayShortInnerLoop
    subs r0, #1
    bne delayShortOuterLoop
    bx lr

// Assembly function to produce a long delay (for dashes)
.global delayLong
.type delayLong, %function
delayLong:
    mov r0, #10000
delayLongOuterLoop:
    mov r1, #10000
delayLongInnerLoop:
    subs r1, #1
    bne delayLongInnerLoop
    subs r0, #1
    bne delayLongOuterLoop
    bx lr


// Code referenced from Lab 7
.global led_on           @ declare as a global variable
.type led_on, %function 	@ set to function type
led_on:
	ldr r1, =0x400FF080
    mov r0, #0x00000000     @ set output to LOW, LED on
    str r0, [r1]            @ apply setting
    bx lr

// Code referenced from Lab 7
.global led_off           @ declare as a global variable
.type led_off, %function 	@ set to function type
led_off:
	ldr r1, =0x400FF080
    mov r0, #0x00000200     @ set output to HIGH, LED off
    str r0, [r1]            @ apply setting
    bx lr


.global dot           @ declare as a global variable
.type dot, %function 	@ set to function type
dot:
	push {lr}
	bl led_on
	bl delayShort		// .
	bl led_off

	bl delayShort
	pop {pc}


.global dash           @ declare as a global variable
.type dash, %function 	@ set to function type
dash:
	push {lr}
	bl led_on
	bl delayLong		// -
	bl led_off

	bl delayShort
	pop {pc}


.global number1           @ declare as a global variable
.type number1, %function 	@ set to function type
number1:
	push {lr}
	bl dot
	bl dash
	bl dash
	bl dash
	bl dash
	pop {pc}


.global number2          @ declare as a global variable
.type number2, %function 	@ set to function type
number2:
	push {lr}
	bl dot
	bl dot
	bl dash
	bl dash
	bl dash
	pop {pc}


.global number3          @ declare as a global variable
.type number3, %function 	@ set to function type
number3:
	push {lr}
	bl dot
	bl dot
	bl dot
	bl dash
	bl dash
	pop {pc}


.global number4          @ declare as a global variable
.type number4, %function 	@ set to function type
number4:
	push {lr}
	bl dot
	bl dot
	bl dot
	bl dot
	bl dash
	pop {pc}



.global number5          @ declare as a global variable
.type number5, %function 	@ set to function type
number5:
	push {lr}
	bl dot
	bl dot
	bl dot
	bl dot
	bl dot
	pop {pc}

.global number6         @ declare as a global variable
.type number6, %function 	@ set to function type
number6:
	push {lr}
	bl dash
	bl dot
	bl dot
	bl dot
	bl dot
	pop {pc}

.global number7         @ declare as a global variable
.type number7, %function 	@ set to function type
number7:
	push {lr}
	bl dash
	bl dash
	bl dot
	bl dot
	bl dot
	pop {pc}

.global number8         @ declare as a global variable
.type number8, %function 	@ set to function type
number8:
	push {lr}
	bl dash
	bl dash
	bl dash
	bl dot
	bl dot
	pop {pc}

.global number9         @ declare as a global variable
.type number9, %function 	@ set to function type
number9:
	push {lr}
	bl dash
	bl dash
	bl dash
	bl dash
	bl dot
	pop {pc}

.global number0         @ declare as a global variable
.type number0, %function 	@ set to function type
number0:
	push {lr}
	bl dash
	bl dash
	bl dash
	bl dash
	bl dash
	pop {pc}
