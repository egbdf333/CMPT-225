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
  unsigned int size;
  unsigned int mask;
  number = decimal;

  size = sizeof(unsigned int);
  mask = 1 << (size * 8 - 1); // shifts so that you can mask the MSB

  for (i = 0; i < size*8; i++) {
    printf("%u", number&mask ? 1 : 0); // %d\n", number&mask ? 1 : 0, number);
    number = number << 1;
  }
  printf("\n");
  
  return; 
}	


// Question 3 e.
int mask_LSbits(int n) {
	
  // put your code here!

  // feel free to modify this return statement if needed
  return 0; 
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
