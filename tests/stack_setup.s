.global stack_setup
stack_setup:
bl _main
nop
b inject_point + 0x04
