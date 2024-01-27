/* 
 * Filename: Assn1_main.c
 *
 * Description: Test driver for Assn1_Q3.c
 *
 * Authors: AL + Linus Pui
 * Student number: 301554378
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer, size_t);
void show_bytes_2(byte_pointer, size_t);
void show_bits(int);
void show_int(int);
void show_float(float);
void show_pointer(void *);
int  mask_LSbits(int);

int main() {
    int ival = -12345; // tested various numbers
    float fval = (float) ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
    show_bits(ival);


    // test cases 0, 2 and 15, all produce expected result
    int result;
    int n;
    n = 0; // change test cases here

    result = mask_LSbits(n);
    printf("%d\n", result);


    return 0;

}