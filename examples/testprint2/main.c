#include <tock.h>

int main(void) {
  
  void * input_buffer = memop(12, 1);

  int brightness_change = 0;
  int * num_pointer = &brightness_change;
  memcpy(num_pointer, input_buffer, sizeof(*num_pointer));

  exit(0);
}
