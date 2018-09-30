/* logic_gates.c simulates a bitwise logical operations on bit operands

Programmer: Carl Argabright
Date: 10/3/2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char Bit; // simulates a single bit, we'll use the low order bit in a byte
#define BIT0_MASK 0x01

Bit maskBit(Bit a) {
    a &= 0x01;
    return a;
}

/* and
performs a bitwise AND on two operand bits
returns a single bit result
*/
Bit and(Bit a, Bit b) {
// truth table AND: 0 0 = 0, 0 1 = 0, 1 0 = 0, 1 1 = 1
    if (maskBit(a) == 0) return 0;
    else if (maskBit(b) == 0) return 0;
    else return 1;
}

/* or
performs a bitwise OR on two operand bits
returns a single bit result
*/
Bit or(Bit a, Bit b) {
// truth table OR: 0 0 = 0, 0 1 = 1, 1 0 = 0, 1 1 = 1
// ToDo: implement algorithm similar to AND
    if (maskBit(a) == 1) return 1;
    if (maskBit(b) == 1) return 1;
    else return 0;
}

/* xor
performs a bitwise XOR on two operand bits
returns a single bit result
*/
Bit xor(Bit a, Bit b) {
// truth table XOR: 0 0 = 0, 0 1 = 1, 1 0 = 1, 1 1 = 0
// ToDo: implement algorithm similar to AND
    if (maskBit(a) == maskBit(b)) return 0;
    else return 1;
}

/* not
performs a not operation on a single bit
returns a single bit result
*/
Bit not(Bit a) {
// ToDo: implement algorithm similar to AND
    if (maskBit(a) == 1) return 0;
    else return 1;
}

// Test driver for logic gates
// This program is a model for testing modules in C programs

int main(int argc, char *argv[]) {
// command line input: ./logic_gates -a 1 1 -- run the program anding 1 and 1
// -a and, -o or, -n not, -x xor
// for simplicity for NOT operations enter -n 1 0 as arguments.
//
    Bit a, b, r;
    char op[11];

    if (argc < 4) {
        printf ("Invalid input to program\n");
        exit (0);
    }
    a = (argv[2][0] - 0x30); // convert to numeric value
    b = (argv[3][0] - 0x30);
    if (argv[1][1] == 'a') {
        r = and(a, b);
        strcpy(op, "AND");
        printf("%d %s %d = %d\n",a, op, b, r);
    }
    else if (argv[1][1] == 'o') {
        r = or(a, b);
        strcpy(op, "OR");
        printf("%d %s %d = %d\n",a, op, b, r);
    }
    else if (argv[1][1] == 'x') {
        r = xor(a, b);
        strcpy(op, "XOR");
        printf("%d %s %d = %d\n",a, op, b, r);
    }
    else if (argv[1][1] == 'n') {
        r = not(a);
        strcpy(op, "NOT");
        printf("%d %s = %d\n",a, op, r);
    }

    return 0;
}