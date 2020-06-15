#include <tock.h>

int main(void) {
  
  void * input_buffer_1 = memop(12, 2);
  void * input_buffer_2 = memop(12, 1);

  int num1 = 0;
  int * num1_pointer = &num1;
  memcpy(num1_pointer, input_buffer_1, sizeof(*num1_pointer));

  int num2 = 0;
  int * num2_pointer = &num2;
  memcpy(num2_pointer, input_buffer_2, sizeof(*num2_pointer));

  printf("Test app 2 verifies that %d + %d = %d. \n", num1, num2, num1+num2);

  exit(0);
}
