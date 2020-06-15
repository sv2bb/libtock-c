#include <tock.h>

int main(void) {
    
//  void * output_buffer = memop(13, 0);
//  void * input_buffer = memop(12, 2);
//
//  int num = 0;
//  int * num_pointer = &num;
//  memcpy(num_pointer, input_buffer, sizeof(*num_pointer));
//  printf("Test app 1 multiplies %d by 4. \n", num);
//
//  num = num * 4;
//  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));
//
//  exit(0);

  void * output_buffer = memop(13, 0);
  printf("Test app 1 starting value: 30 \n");

  int num = 30;
  int * num_pointer = &num;
  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));

  exit(0);
}

