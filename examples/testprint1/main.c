#include <tock.h>

int main(void) {
    
  void * output_buffer = memop(13, 0);
  void * input_buffer = memop(12, 0);

  int num = 0;
  int * num_pointer = &num;
  memcpy(num_pointer, input_buffer, sizeof(*num_pointer));
  printf("Test app 1 multiplies %d by 2. \n", num);

  num = num * 2;
  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));

  exit(0);
}

