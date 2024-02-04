/*
 * Copyright 2016-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    final_project.c
 * @brief   Application entry point.
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"

/* TODO: insert other include files here. */
#include "morseConverter.h"

/* TODO: insert other definitions and declarations here. */

#define MAX_INPUT_LENGTH 100
volatile int simulationFlag = 1;

/*
 * @brief   Application entry point.
 */

int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    while (1)
    {
        // Check the flag to determine whether to run the simulation
        if (simulationFlag > 0)
        {
            runSimulation();
            simulationFlag = 0; // Reset the flag after completing the simulation
        }
    }

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}

// Code referenced from Lab 7
void SW2_GPIOD_IRQHANDLER(void) //Interrupt Service Routine for SW2
{
    // clear interrupt flag set by button SW2 connected to pin PTC6
    GPIO_PortClearInterruptFlags(GPIOD, 1U << 11U);
    simulationFlag = 1;
}

// Code referenced from Lab 7
void SW3_GPIOA_IRQHANDLER(void) //Interrupt Service Routine for SW3
{
    // clear interrupt flag set by button SW3 connected to pin PTA4
    GPIO_PortClearInterruptFlags(GPIOA, 1U << 10U);
    simulationFlag = -1;
}

// Function to run the simulation
void runSimulation(void)
{
    char userInput[MAX_INPUT_LENGTH + 1]; // Plus one for null terminator

    // Prompt the user to enter a sentence
    PRINTF("\r\nEnter a sentence to convert into Morse Code: ");

    // Wait for user input
    readString(userInput, MAX_INPUT_LENGTH);

    // Process each character and display Morse code using LED
    PRINTF("\r\nThe user entered: ");
    for (int i = 0; userInput[i] != '\0'; i++)
    {
        // if we want to stop the execution in between just change the flag back to 0
        if (simulationFlag < 0)
        {
            PRINTF("\r\nSimulation interrupted.");
            return; // Exit the function if the flag is negative
        }

        PRINTF("%c ", userInput[i]);


        charToMorse(userInput[i]); // Convert the character to Morse code
        delayLong();
    }
    PRINTF("\r\n");
	PRINTF("Simulation completed.\r\n");
}

// Custom function to read a string character by character
void readString(char *buffer, uint32_t length)
{
    char c;
    uint32_t count = 0;

    while (count < length)
    {
        c = GETCHAR(); // Read a character

        // Check for Enter key or newline character
        if (c == '\r' || c == '\n')
        {
            buffer[count] = '\0'; // Add null terminator to mark the end of the string
            break;
        }
        else
        {
            buffer[count] = c; // Store the character in the buffer
            count++;
        }
    }

    // If the buffer is filled without an Enter key, ensure null termination
    if (count == length)
    {
        buffer[length - 1] = '\0';
    }
}
