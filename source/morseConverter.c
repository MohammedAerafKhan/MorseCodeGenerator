// morceConverter.cpp: source file for morseConverter

#include "morseConverter.h"
#include "board.h"
#include "fsl_debug_console.h"

// Function to produce a short delay
//void delayShort() {
//    volatile uint32_t i = 10000000; // Adjust the loop count based on your clock frequency
//    while (i--) {
//        __asm("nop");
//    }
//}
//
//// Function to produce a long delay (for dashes)
//void delayLong() {
//    volatile uint32_t i = 20000000; // Adjust the loop count based on your clock frequency
//    while (i--) {
//        __asm("nop");
//    }
//}

void charToMorse(char character) {
    switch (character) {
        case 'A':
        case 'a':	// .-
            dot();
            dash();
            break;

        case 'B':
        case 'b':	// -...
        	dash();
        	dot();
        	dot();
        	dot();
            break;

        case 'C':
        case 'c':	 // -.-.
        	dash();
        	dot();
        	dash();
        	dot();
            break;

        case 'D':
        case 'd':	// -..
        	dash();
			dot();
			dot();
            break;

        case 'E':
        case 'e':	// .
        	dot();
            break;

        case 'F':
        case 'f':	// ..-.
			dot();
			dot();
			dash();
			dot();
            break;

        case 'G':
        case 'g':	// --.
			dash();
			dash();
			dot();
            break;

        case 'H':
        case 'h':	// ....
        	dot();
        	dot();
        	dot();
        	dot();
            break;

        case 'I':
        case 'i':	// ..
        	dot();
        	dot();
            break;

        case 'J':
        case 'j':	// .---
        	dot();
        	dash();
        	dash();
        	dash();
            break;

        case 'K':
        case 'k':	// -.-
        	dash();
        	dot();
        	dash();
            break;

        case 'L':
        case 'l':	// .-..
        	dot();
        	dash();
        	dot();
        	dot();
            break;

        case 'M':
        case 'm':	// --
        	dash();
        	dash();
            break;

        case 'N':
        case 'n':	// -.
        	dash();
        	dot();
            break;

        case 'O':
        case 'o':	// ---
        	dash();
        	dash();
        	dash();
            break;

        case 'P':
        case 'p':	// .--.
        	dot();
        	dash();
        	dash();
        	dot();
            break;

        case 'Q':
        case 'q':	// --.-
        	dash();
        	dash();
        	dot();
        	dash();
            break;

        case 'R':
        case 'r':	// .-.
        	dot();
        	dash();
        	dot();
            break;

        case 'S':
        case 's':	// ...
        	dot();
        	dot();
        	dot();
            break;

        case 'T':
        case 't':	// -
        	dash();
            break;

        case 'U':
		case 'u':	// ..-
			dot();
			dot();
			dash();
			break;

        case 'V':
		case 'v':	// ...-
			dot();
			dot();
			dot();
			dash();
			break;

        case 'W':
		case 'w':	// .--
			dot();
			dash();
			dash();
			break;

        case 'X':
		case 'x':	// -..-
			dash();
			dot();
			dot();
			dash();
			break;

        case 'Y':
		case 'y':	// -.--
			dash();
			dot();
			dash();
			dash();
			break;

        case 'Z':
		case 'z':	// --..
			dash();
			dash();
			dot();
			dot();
			break;

		case '1':
			number1();
			delayLong();
			break;

		case '2':
			number2();
			delayLong();
			break;

		case '3':
			number3();
			delayLong();
			break;

		case '4':
			number4();
			delayLong();
			break;

		case '5':
			number5();
			delayLong();
			break;

		case '6':
			number6();
			delayLong();
			break;

		case '7':
			number7();
			delayLong();
			break;

		case '8':
			number8();
			delayLong();
			break;

		case '9':
			number9();
			delayLong();
			break;

		case '0':
			number0();
			delayLong();
			break;

        case ' ':
        	delayShort();
        	break;

        default:
            PRINTF(" (<= invalid character) ");
    }
}
