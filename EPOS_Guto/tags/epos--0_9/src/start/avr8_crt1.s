        .file   "avr8_crt1.s"

        .text
        .align 1
        .globl __epos_library_app_entry
__epos_library_app_entry:
        call  main
