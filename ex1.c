/******************
Name: Shira Mendelson
ID: 327654992
Assignment: 1
*******************/
#include <stdio.h>

// REMIDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE.

int main() {
    // What bit
    printf("What bit:\n");
    /*Scan two integers (representing number and a position)
      Print the bit in this position. */

    int number, position;
    printf("Please enter a number:\n");
    scanf("%d", &number);

    printf("Please enter a position:\n");
    scanf("%d", &position);

    /* Shift right so the bit at the requested position becomes the LSB,
     then, use mask &1 in order to get 0 if that bit is 0, or 1 otherwise. */
    int result = (number >> position) & 1;

    printf("The bit in position %d of number %d is: %d\n", position, number, result);

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
      then, use OR with it and with the number, in order to switch on the number's bit in that position */
    int bit_on = (1 << position) | number;

        /* Take 1 and move its only bit that is equal to 1(the LSB) to the requested position.
         * use NOT in order to flip all the bits and get all 1s and a 0 only in the requested position
         * use AND with it and with the number, in order to get a 0 in the requested position and leave the rest of the number as it was.
         */

    int bit_off = ~(1 << position) & number;
    printf("Number with bit %d set to 1: %d\n", position, bit_on);
    printf("Number with bit %d set to 0: %d\n", position, bit_off);


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
    int toggled = (1 << position) ^ number;
    printf("Number with bit %d toggled: %d\n", position, toggled);

      // Even - Odd
    printf("\nEven - Odd:\n");
    /* Scan an integer
      If the number is even - print 1, else - print 0. */
    printf("Please enter a number:\n");
    scanf("%d", &number);

      int isEven = (number ^ 1) & 1;
      printf("%d\n", isEven);

      // 3, 5, 7, 11
    printf("\n3, 5, 7, 11:\n");
      /* Scan two integers in octal base
      sum them up and print the result in hexadecimal base
      Print only 4 bits, in positions: 3,5,7,11 in the result. */
    int oct1, oct2;
    printf("Please enter the first number (octal):\n");
    scanf("%o", &oct1);

    printf("Please enter the second number (octal):\n");
    scanf("%o", &oct2);
    int sum = oct1 + oct2;

    printf("The sum in hexadecimal: %X\n", sum);
    printf("The 3,5,7,11 bits are: %d%d%d%d\n", ((sum>>3)&1), ((sum>>5)&1), ((sum>>7)&1), ((sum>>11)&1));

    printf("Bye!\n");

    return 0;
}
