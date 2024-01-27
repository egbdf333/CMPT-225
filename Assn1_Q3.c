/* 
 * Filename: Assn1_Q3.c
 *
 * Description:
 *
 * Authors: Our textbook + AL + Linus Pui
 * Student number: 301554378
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

// Question 3 a.
void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf("%p %.2x\n", &start[i], start[i]);
  }
  printf("\n");
  return;	
}

// Question 3 b.
// Put your answer to Question 3 b) here as a comment
// little endian, because it takes the LSB 39 and stores it first, then it stores the MSB 30


// Question 3 c.
void show_bytes_2(byte_pointer start, size_t len) {
  unsigned char* traversePtr;
  traversePtr = start;
  size_t i;
  for (i = 0; i < len; i++) {
    printf("%p %.2x\n", &traversePtr, *traversePtr); 	
    traversePtr++;
  }
  printf("\n");
  return;		
}

// Question 3 d.
void show_bits(int decimal) {
	int number;
  int i;
  int n;
  int mask;
  int binaryDigit;
  number = decimal;
  n = sizeof(unsigned int) * 8;

  mask = 1 << (n - 1); // create mask by shifting by n, subtracting 1, same concept as Q3e

  for (i = 0; i < n; i++) {
    binaryDigit = (number&mask ? 1 : 0); // binary num logic help from Stack Overflow
    printf("%u", binaryDigit); 
    number = number << 1;
  }
  printf("\n");
  
  return; 
}	


// Question 3 e.
int mask_LSbits(int n) {
  // if n >= w
  int w;
  w = sizeof(int)*8;
  int mask;

  if (n >= w) {
    // mask of n >= w is all 1s. For unsigned int is a very large number, for signed is -1
    mask = -1;
  }

  if (n <= 0) {
    // mask of n <= 0 is just all 0s
    mask = 0;
  }

  // for normal case
  if (0 < n < w) {
    // to create mask, you need shift 1 by n times then subtract by 1
    // e.g. you want to create a mask for 00000010. shift 1 by 2 times 1 -> 00000100, then subtract 1 00000100 -> 00000011 which is the resultant bit mask
    mask = (1 << n) - 1;
  }

  return mask; 
}

void show_int(int x) {
  printf("\nival = %d\n", x); 
  show_bytes((byte_pointer) &x, sizeof(int)); 
  show_bytes_2((byte_pointer) &x, sizeof(int)); 
  return;	
}

void show_float(float x) {
  printf("fval = %f\n", x); 	
  show_bytes((byte_pointer) &x, sizeof(float));
  show_bytes_2((byte_pointer) &x, sizeof(float)); 
  return;	
}

void show_pointer(void *x) {
  printf("pval = %p\n", x); 
  show_bytes((byte_pointer) &x, sizeof(void *));
  show_bytes_2((byte_pointer) &x, sizeof(void *));
  return;	
}
