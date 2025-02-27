#include "kernel.h"
#include "common.h"

extern char __bss[], __bss_end[], __stack_top[];

struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4,
                       long arg5, long fid, long eid) {

  register long a0 __asm__("a0") = arg0; // function arguments/return values
  register long a1 __asm__("a1") = arg1; // function arguments/return values

  register long a2 __asm__("a2") = arg2; // function arguments
  register long a3 __asm__("a3") = arg3; // function arguments
  register long a4 __asm__("a4") = arg4; // function arguments
  register long a5 __asm__("a5") = arg5; // function arguments
  register long a6 __asm__("a6") = fid;  // function arguments
  register long a7 __asm__("a7") = eid;  // function arguments

  __asm__ __volatile__("ecall"
                       : "=r"(a0), "=r"(a1)
                       : "r"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
                         "r"(a6), "r"(a7)
                       : "memory");

  return (struct sbiret){.error = a0, .value = a1};
}

void putchar(char ch) {
  sbi_call(ch, 0, 0, 0, 0, 0, 0, 1 /* Console Putchar */);
}

void kernel_main(void) {
  memset(__bss, 0, __bss_end - __bss);

  printf("\n\nHello World!\n");

  printf("1 + 2 = %d, %x\n", 1 + 2, 0x1234abcd);

  for (;;) {
    __asm__ __volatile__("wfi");
  }
}

/**
 * The execution of the kernel starts from 'boot' function, which is specified
 * as the entry point in our linker file.
 **/
__attribute__((section(".text.boot"))) __attribute__((naked)) void boot(void) {
  __asm__ __volatile__(
      "mv sp, %[stack_top]\n" // set the stack pointer
      "j kernel_main\n"       // jump to the kernel main function
      :
      : [stack_top] "r"(
          __stack_top) // pass the stack top address as %[stack_top]
  );
}
