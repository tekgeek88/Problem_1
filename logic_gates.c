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
    /* The output of the AND function is 1 if and only if both inputs are 1
     * in all other cases the output is 0. */
    if (maskBit(a) && maskBit(b)) return 1;
    else return 0;
}


Bit qand(Bit a, Bit b, Bit c, Bit d) {
    // truth table AND: 0 0 = 0, 0 1 = 0, 1 0 = 0, 1 1 = 1
    /* The output of the AND function is 1 if and only if both inputs are 1
     * in all other cases the output is 0. */
    if (and(and(a, b), and(c, d))) return 1;
    else return 0;
}



/* or
performs a bitwise OR on two operand bits
returns a single bit result
*/
Bit or(Bit a, Bit b) {
// truth table OR: 0 0 = 0, 0 1 = 1, 1 0 = 0, 1 1 = 1
// ToDo: implement algorithm similar to AND
    /* Similar to the and if either input a or b is 1 the result is 1
     * and zero in all other cases. */
    if (maskBit(a) || maskBit(b)) return 1;
    else return 0;
}

/* xor
performs a bitwise XOR on two operand bits
returns a single bit result
*/
Bit xor(Bit a, Bit b) {
// truth table XOR: 0 0 = 0, 0 1 = 1, 1 0 = 1, 1 1 = 0
// ToDo: implement algorithm similar to AND
    /* Because soup OR salad is included with your meal you may have one but not both.
     * The output of XOR is always zero when both inputs are 1. */
    if (maskBit(a) == maskBit(b)) return 0;
    else return 1;
}

/* not
performs a not operation on a single bit
returns a single bit result
*/
Bit not(Bit a) {
// ToDo: implement algorithm similar to AND
    /* If the input is a 1 the output is zero
     * likewise, if the input is 0 the output is 1. */
    if (maskBit(a) == 1) return 0;
    else return 1;
}

Bit nand(Bit a, Bit b) {
    // truth table AND: 0 0 = 0, 0 1 = 0, 1 0 = 0, 1 1 = 1
    /* The output of the AND function is 1 if and only if both inputs are 1
     * in all other cases the output is 0. */
    return not(and(a, b));
}

int decoder(Bit a, Bit b) {
    // truth table AND: 0 0 = 0, 0 1 = 0, 1 0 = 0, 1 1 = 1
    /* The output of the AND function is 1 if and only if both inputs are 1
     * in all other cases the output is 0. */
    Bit A = and(not(a), not(b));
    Bit B = and(not(a), b);
    Bit C = and(a, not(b));
    Bit D = and(a, b);
    printf("A=%d B=%d C=%d D=%d", A, B, C, D);
    return 0;
}


int mux(Bit a, Bit b, Bit c, Bit d, Bit s1, Bit s2) {
    // truth table AND: 0 0 = 0, 0 1 = 0, 1 0 = 0, 1 1 = 1
    /* The output of the AND function is 1 if and only if both inputs are 1
     * in all other cases the output is 0. */
    Bit A, B, C, D;
    A = and(a, and(not(s1), not(s2)));
    B = and(b, and(not(s1), s2));
    C = and(c, and(s1, not(s2)));
    D = and(d, and(s1, s2));


    printf("S[%d:%d] = %d" , s1, s2, or(or(A, B), or(C, D)));
    return 0;
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