ENTRY(boot) /* entry point for the kernel */

SECTIONS {
  . = 0x80200000; /* base address */

  .text :{ /* contains the code of the program */
    KEEP(*(.text.boot));
    *(.text .text.*);
  }

  .rodata : ALIGN(4) { /* contains constant (read only) data such as static string, numbers */
    *(.rodata .rodata.*);
  }

  .data : ALIGN(4) { /* contains read and write data */
    *(.data .data.*);
  }

  .bss : ALIGN(4) { /* contains read and write data with initial value of zero */
    __bss = .;
    *(.bss .bss.* .sbss .sbss.*);
    __bss_end = .;
  }

  . = ALIGN(4);
  . += 128 * 1024; /* 128KB */
  __stack_top = .;
}

