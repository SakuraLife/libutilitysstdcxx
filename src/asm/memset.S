  .globl  _ZN7utility4sstd6memsetEPvim
  .type  _ZN7utility4sstd6memsetEPvim, @function
_ZN7utility4sstd6memsetEPvim:
  movq  %rsi,%rax
  andq  $0xff,%rax
  movq  %rdx,%rcx
  movq  %rdi,%r11

  cld

  cmpq  $0x0f,%rcx
  jle  L1

  movb  %al,%ah
  movl  %eax,%edx
  sall  $16,%eax
  orl  %edx,%eax

  movl  %eax,%edx
  salq  $32,%rax
  orq  %rdx,%rax

  movq  %rdi,%rdx
  negq  %rdx
  andq  $7,%rdx
  movq  %rcx,%r8
  subq  %rdx,%r8

  movq  %rdx,%rcx
  rep
  stosb

  movq  %r8,%rcx
  shrq  $3,%rcx
  rep
  stosq

  movq  %r8,%rcx
  andq  $7,%rcx
L1:  rep
  stosb
  movq  %r11,%rax

  ret

  .size _ZN7utility4sstd6memsetEPvim, . - _ZN7utility4sstd6memsetEPvim
  .section  .note.GNU-stack,"",@progbits
