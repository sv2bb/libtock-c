#include <tock.h>

int main(void) {
  
  void * input_buffer = memop(12, 0);

  int num = 0;
  int * num_pointer = &num;
  memcpy(num_pointer, input_buffer, sizeof(*num_pointer));

  printf("Test app 2 verifies the answer is %d. \n", num);

  exit(0);
}
