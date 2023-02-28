OUTPUT_FORMAT("elf64-littleaarch64", "elf64-bigaarch64", "elf64-littleaarch64")
OUTPUT_ARCH(aarch64)
ENTRY(_start)
PHDRS {
 text PT_LOAD FLAGS(5);
 data PT_LOAD FLAGS(6);
 dynamic PT_DYNAMIC FLAGS(6);
 gnu_stack PT_GNU_STACK FLAGS(6);
 gnu_relro 0x6474e552 FLAGS(4);
}
SECTIONS {
 __elfloader_start_link = .;
 __elfloader_start_load = .;
 __elfloader_start = .;
 .text : {
  *(.text.start)
  *(.text)
  . = ALIGN(4096);
  __vector_table_start = .;
  *(.vector)
  __vector_table_end = .;
 } :text
 . = ALIGN(4096);
 . = DATA_SEGMENT_ALIGN (CONSTANT (MAXPAGESIZE), CONSTANT (COMMONPAGESIZE));
 .dynamic : { *(.dynamic) } : dynamic :data
 . = DATA_SEGMENT_RELRO_END (0, .);
 .data : {
  *(.data)
  . = ALIGN(8); __module_inits_start = .; __module_inits_lv0_start = .; KEEP(*(.moduleinit0.init)) __module_inits_lv0_end = .; __module_inits_lv1_start = .; KEEP(*(.moduleinit1.init)) __module_inits_lv1_end = .; __module_inits_lv2_start = .; KEEP(*(.moduleinit2.init)) __module_inits_lv2_end = .; __module_inits_lv3_start = .; KEEP(*(.moduleinit3.init)) __module_inits_lv3_end = .; __module_inits_lv4_start = .; KEEP(*(.moduleinit4.init)) __module_inits_lv4_end = .; __module_inits_lv5_start = .; KEEP(*(.moduleinit5.init)) __module_inits_lv5_end = .; __module_inits_lv6_start = .; KEEP(*(.moduleinit6.init)) __module_inits_lv6_end = .; __module_inits_end = .;
  . = ALIGN(4096);
  __archive_start = .;
  *(.archive)
  __archive_end = .;
  . = ALIGN(4096);
  __rootfs_start = .;
  *(.rootfs)
  __rootfs_end = .;
 } :data
 .bss : {
  __bss_start_load = .;
  __bss_start = .;
  *(.bss)
  __bss_end_load = .;
  __bss_end = .;
 } :data
 . = DATA_SEGMENT_END (.);
 _edata = .;
 . = ALIGN(4096);
 __elfloader_end = .;
}
