#include <timer.h>
#include <tock.h>

int main(void) {
    printf("Hello from print loop");

    // This delay uses an underlying timer in the kernel.
    delay_ms(1000);
}
