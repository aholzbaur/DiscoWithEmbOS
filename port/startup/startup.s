  .syntax unified

  .global Reset_Handler
  .extern _vectors

  .section .init, "ax"
  .thumb_func

  .equ VTOR_REG, 0xE000ED08
  .equ FPU_CPACR_REG, 0xE000ED88

#define STACK_INIT_VAL __stack_end__

Reset_Handler:
  /* Initialise main stack */
  ldr r0, =STACK_INIT_VAL
  bic r0, #0x7
  mov sp, r0

  /* Initialise system */
  ldr r0, =SystemInit
  blx r0
  .pushsection .init_array, "aw", %init_array
  .align 2
  .word SystemCoreClockUpdate
  .popsection

  /* Configure vector table offset register */
  ldr r0, =VTOR_REG
  ldr r1, =_vectors
  str r1, [r0]

  /* Enable FPU */
  ldr r0, =FPU_CPACR_REG
  ldr r1, [r0]
  orr r1, r1, #(0xF << 20)
  str r1, [r0]
  dsb
  isb

  /* Jump to program start */
  ldr r0, =_start
  blx r0
