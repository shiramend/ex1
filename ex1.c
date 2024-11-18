/******************
Name: Shira Mendelson
ID: 327654992
Assignment: 1
*******************/
#include <stdio.h>

// REMIDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE.

int main() {
    // number and position variables that will be used throughout the tasks
    int number, position;
    // variable for task 1 - will represent the value of the bit in the requested position
    int bitInPosition;
    // variables for task 2 - number with bit on and number with bit off
    int bitOn, bitOff;
    // variable for task 3 - will represent the number with the requested bit toggled
    int toggledNumber;
    // variable for task 4 - isEven
    int isEven;
    // variables for task 5 that will represent two octal numbers, their sum, and bits in 3,5,7,11 positions
    int octal1, octal2, sum, bit3, bit5, bit7, bit11;

    // What bit
    printf("What bit:\n");
    /*Scan two integers (representing number and a position)
      Print the bit in this position. */

    printf("Please enter a number:\n");
    scanf("%d", &number);
    printf("Please enter a position:\n");
    scanf("%d", &position);

    /* Shift the number to the right so the bit at the requested position becomes the LSB,
       then, use mask &1 in order to get 0 if that bit is 0, or 1 otherwise. */
    bitInPosition = (number >> position) & 1;
    printf("The bit in position %d of number %d is: %d\n", position, number, bitInPosition);

    // Set bit
    printf("\nSet bit:\n");
    /*Scan two integers (representing number and a position)
      Make sure the bit in this position is "on" (equal to 1)
      Print the output
      Now make sure it's "off" (equal to 0)
      Print the output */

    printf("Please enter a number:\n");
    scanf("%d", &number);
    printf("Please enter a position:\n");
    scanf("%d", &position);

    /* Take 1 and move its only bit that is equal to 1(the LSB) to the requested position
       Then, use OR with it and with the number, in order to switch on the number's bit in that position */
    bitOn = (1 << position) | number;
    printf("Number with bit %d set to 1: %d\n", position, bitOn);

    /* Take 1 and move its only bit that is equal to 1(the LSB) to the requested position
       Use NOT in order to flip all the bits and get all 1s and a 0 only in the requested position
       Then, use AND with it and with the number, in order to get a 0 in the requested position */
    bitOff = ~(1 << position) & number;
    printf("Number with bit %d set to 0: %d\n", position, bitOff);

    // Toggle bit
    printf("\nToggle bit:\n");
    /*Scan two integers (representing number and a position)
      Toggle the bit in this position
      Print the new number */

    printf("Please enter a number:\n");
    scanf("%d", &number);
    printf("Please enter a position:\n");
    scanf("%d", &position);

    /* Take 1 and move its only bit that is equal to 1(the LSB) to the requested position
       use XOR with it and with the number, in order to flip the requested bit and leave the rest as it was */
    toggledNumber = (1 << position) ^ number;
    printf("Number with bit %d toggled: %d\n", position, toggledNumber);

    // Even - Odd
    printf("\nEven - Odd:\n");
    /* Scan an integer
      If the number is even - print 1, else - print 0. */

    printf("Please enter a number:\n");
    scanf("%d", &number);

    /* Use XOR on the number and 1 in order to flip the LSB(that indicates if the number is even-0 or odd-1)
       Then, use mask &1 in order to get 0 in every position except for the LSB,
       in the LSB the bit will remain as it was (1 for even, 0 for odd) */
    isEven = (number ^ 1) & 1;
    printf("%d\n", isEven);

    // 3, 5, 7, 11
    printf("\n3, 5, 7, 11:\n");
    /* Scan two integers in octal base
      sum them up and print the result in hexadecimal base
      Print only 4 bits, in positions: 3,5,7,11 in the result. */

    printf("Please enter the first number (octal):\n");
    scanf("%o", &octal1);
    printf("Please enter the second number (octal):\n");
    scanf("%o", &octal2);

    sum = octal1 + octal2;
    printf("The sum in hexadecimal: %X\n", sum);

    /* Shift the number to the right so the bit at the requested position becomes the LSB,
       then, use mask &1 in order to get 0 if that bit is 0, or 1 otherwise. */
    bit3 = ((sum >> 3) & 1);
    bit5 = ((sum >> 5) & 1);
    bit7 = ((sum >> 7) & 1);
    bit11 = ((sum >> 11) & 1);
    printf("The 3,5,7,11 bits are: %d%d%d%d\n", bit3, bit5, bit7, bit11);

    printf("Bye!\n");

    return 0;
}
