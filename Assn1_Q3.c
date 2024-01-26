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
  int remainder;
  int last;
  int arraySize;
  int i;
  int isNegative;
  arraySize = 32;
  int binaryNum[arraySize];
  last = 31; // 31 is the last index in a 32 element array
  number = decimal;
  isNegative = 0;

  if (number < 0) {
    number = number * -1;
    isNegative = 1;
  }

  // initalize the array to 0
  for (i = 0; i < arraySize; i++) {
    binaryNum[i] = 0;
  }
  
  // construct the binary number from right to left
  while(number != 1) {
    remainder = number % 2;
    number = number / 2;
    binaryNum[last] = remainder;
    last--;
  }
  binaryNum[last] = 1; // sets the final binary digit to be 1 as the loop was exited early
  
  if (isNegative = 1);

  for (i = 0; i < arraySize; i++) {

  }

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
