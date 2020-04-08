#include <tock.h>

int main(void) {
  void * output_buffer = memop(13, 0);
  printf("Test app 0 starting value: 5 \n");

  int num = 5;
  int * num_pointer = &num;
  memcpy(output_buffer, num_pointer, sizeof(*num_pointer));

  exit(0);
}
