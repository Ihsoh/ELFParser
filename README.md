ELFParser
=========
This is a simple elf32 parser.

### How to use? ###
```
$ make
$ elfparser <elf32 file>
```

### Example ###
```
./bin/elfparser bin/test	
####Elf File Infomation####
File: bin/test
Size: 16268

####Elf Header####
Data: 2's Complement, Little Endian
Version: 0x1
Type: Executable file
Machine: 0x3(Intel 80386)
Version: 0x1
EntryPoint: 0x08048541
ProgramHeaderTableOffset: 0x00000034
SectionHeaderTableOffset: 0x00003adc
Flags: 0x00000000
ELFHeaderSize: 52(0x00000034)
ProgramHeaderEntrySize: 32(0x00000020)
ProgramHeaderEntryNumber: 9(0x00000009)
SectionHeaderEntrySize: 40(0x00000028)
SectionHeaderEntryNumber: 30(0x0000001e)
SectionHeaderNameIndex: 27(0x0000001b)

####Elf Section Header Table####
SectionHeaderTable:
   Index |                     Name |     Type |       Addr |     Offset |       Size | ES |      Flags | Lk | Inf | Al
=======================================================================================================================
       0 |                          |     NULL | 0x00000000 | 0x00000000 |          0 |  0 | 0x00000000 |  0 |   0 |  0
       1 |                  .interp | PROGBITS | 0x08048154 | 0x00000154 |         19 |  0 | 0x00000002 |  0 |   0 |  1
       2 |            .note.ABI-tag |     NOTE | 0x08048168 | 0x00000168 |         32 |  0 | 0x00000002 |  0 |   0 |  4
       3 |       .note.gnu.build-id |     NOTE | 0x08048188 | 0x00000188 |         36 |  0 | 0x00000002 |  0 |   0 |  4
       4 |                .gnu.hash |   Unknow | 0x080481ac | 0x000001ac |         32 |  4 | 0x00000002 |  5 |   0 |  4
       5 |                  .dynsym |   DYNSYM | 0x080481cc | 0x000001cc |        208 | 16 | 0x00000002 |  6 |   1 |  4
       6 |                  .dynstr |   STRTAB | 0x0804829c | 0x0000029c |        175 |  0 | 0x00000002 |  0 |   0 |  1
       7 |             .gnu.version |   Unknow | 0x0804834c | 0x0000034c |         26 |  2 | 0x00000002 |  5 |   0 |  2
       8 |           .gnu.version_r |   Unknow | 0x08048368 | 0x00000368 |         80 |  0 | 0x00000002 |  6 |   1 |  4
       9 |                 .rel.dyn |      REL | 0x080483b8 | 0x000003b8 |          8 |  8 | 0x00000002 |  5 |   0 |  4
      10 |                 .rel.plt |      REL | 0x080483c0 | 0x000003c0 |         88 |  8 | 0x00000042 |  5 |  12 |  4
      11 |                    .init | PROGBITS | 0x08048418 | 0x00000418 |         35 |  0 | 0x00000006 |  0 |   0 |  4
      12 |                     .plt | PROGBITS | 0x08048440 | 0x00000440 |        192 |  4 | 0x00000006 |  0 |   0 | 16
      13 |                    .text | PROGBITS | 0x08048500 | 0x00000500 |       3474 |  0 | 0x00000006 |  0 |   0 | 16
      14 |                    .fini | PROGBITS | 0x08049294 | 0x00001294 |         20 |  0 | 0x00000006 |  0 |   0 |  4
      15 |                  .rodata | PROGBITS | 0x080492c0 | 0x000012c0 |       2657 |  0 | 0x00000002 |  0 |   0 | 32
      16 |            .eh_frame_hdr | PROGBITS | 0x08049d24 | 0x00001d24 |         68 |  0 | 0x00000002 |  0 |   0 |  4
      17 |                .eh_frame | PROGBITS | 0x08049d68 | 0x00001d68 |       1380 |  0 | 0x00000002 |  0 |   0 |  4
      18 |              .init_array |   Unknow | 0x0804bf08 | 0x00002f08 |          4 |  0 | 0x00000003 |  0 |   0 |  4
      19 |              .fini_array |   Unknow | 0x0804bf0c | 0x00002f0c |          4 |  0 | 0x00000003 |  0 |   0 |  4
      20 |                     .jcr | PROGBITS | 0x0804bf10 | 0x00002f10 |          4 |  0 | 0x00000003 |  0 |   0 |  4
      21 |                 .dynamic |  DYNAMIC | 0x0804bf14 | 0x00002f14 |        232 |  8 | 0x00000003 |  6 |   0 |  4
      22 |                     .got | PROGBITS | 0x0804bffc | 0x00002ffc |          4 |  4 | 0x00000003 |  0 |   0 |  4
      23 |                 .got.plt | PROGBITS | 0x0804c000 | 0x00003000 |         56 |  4 | 0x00000003 |  0 |   0 |  4
      24 |                    .data | PROGBITS | 0x0804c038 | 0x00003038 |          8 |  0 | 0x00000003 |  0 |   0 |  4
      25 |                     .bss |   NOBITS | 0x0804c040 | 0x00003040 |         24 |  0 | 0x00000003 |  0 |   0 |  4
      26 |                 .comment | PROGBITS | 0x00000000 | 0x00003040 |         72 |  1 | 0x00000030 |  0 |   0 |  1
      27 |                .shstrtab |   STRTAB | 0x00000000 | 0x00003088 |        262 |  0 | 0x00000000 |  0 |   0 |  1
      28 |                  .symtab |   SYMTAB | 0x00000000 | 0x00003190 |       1472 | 16 | 0x00000000 | 29 |  59 |  4
      29 |                  .strtab |   STRTAB | 0x00000000 | 0x00003750 |        905 |  0 | 0x00000000 |  0 |   0 |  1

SectionHeaderTable(.dynsym):
   Index |      Value |       Size |       Type |       Bind |    Ndx |Name
===========================================================================
       0 | 0x00000000 |          0 |     NOTYPE |      LOCAL |      0 | 
       1 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | free
       2 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fclose
       3 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __stack_chk_fail
       4 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __xstat
       5 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fread
       6 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | malloc
       7 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | __gmon_start__
       8 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | exit
       9 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __libc_start_main
      10 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fopen
      11 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __printf_chk
      12 | 0x080492c4 |          4 |     OBJECT |     GLOBAL |     15 | _IO_stdin_used

SectionHeaderTable(.symtab):
   Index |      Value |       Size |       Type |       Bind |    Ndx |Name
===========================================================================
       0 | 0x00000000 |          0 |     NOTYPE |      LOCAL |      0 | 
       1 | 0x08048154 |          0 |    SECTION |      LOCAL |      1 | 
       2 | 0x08048168 |          0 |    SECTION |      LOCAL |      2 | 
       3 | 0x08048188 |          0 |    SECTION |      LOCAL |      3 | 
       4 | 0x080481ac |          0 |    SECTION |      LOCAL |      4 | 
       5 | 0x080481cc |          0 |    SECTION |      LOCAL |      5 | 
       6 | 0x0804829c |          0 |    SECTION |      LOCAL |      6 | 
       7 | 0x0804834c |          0 |    SECTION |      LOCAL |      7 | 
       8 | 0x08048368 |          0 |    SECTION |      LOCAL |      8 | 
       9 | 0x080483b8 |          0 |    SECTION |      LOCAL |      9 | 
      10 | 0x080483c0 |          0 |    SECTION |      LOCAL |     10 | 
      11 | 0x08048418 |          0 |    SECTION |      LOCAL |     11 | 
      12 | 0x08048440 |          0 |    SECTION |      LOCAL |     12 | 
      13 | 0x08048500 |          0 |    SECTION |      LOCAL |     13 | 
      14 | 0x08049294 |          0 |    SECTION |      LOCAL |     14 | 
      15 | 0x080492c0 |          0 |    SECTION |      LOCAL |     15 | 
      16 | 0x08049d24 |          0 |    SECTION |      LOCAL |     16 | 
      17 | 0x08049d68 |          0 |    SECTION |      LOCAL |     17 | 
      18 | 0x0804bf08 |          0 |    SECTION |      LOCAL |     18 | 
      19 | 0x0804bf0c |          0 |    SECTION |      LOCAL |     19 | 
      20 | 0x0804bf10 |          0 |    SECTION |      LOCAL |     20 | 
      21 | 0x0804bf14 |          0 |    SECTION |      LOCAL |     21 | 
      22 | 0x0804bffc |          0 |    SECTION |      LOCAL |     22 | 
      23 | 0x0804c000 |          0 |    SECTION |      LOCAL |     23 | 
      24 | 0x0804c038 |          0 |    SECTION |      LOCAL |     24 | 
      25 | 0x0804c040 |          0 |    SECTION |      LOCAL |     25 | 
      26 | 0x00000000 |          0 |    SECTION |      LOCAL |     26 | 
      27 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | crtstuff.c
      28 | 0x0804bf10 |          0 |     OBJECT |      LOCAL |     20 | __JCR_LIST__
      29 | 0x08048580 |          0 |       FUNC |      LOCAL |     13 | deregister_tm_clones
      30 | 0x080485b0 |          0 |       FUNC |      LOCAL |     13 | register_tm_clones
      31 | 0x080485f0 |          0 |       FUNC |      LOCAL |     13 | __do_global_dtors_aux
      32 | 0x0804c040 |          1 |     OBJECT |      LOCAL |     25 | completed.6877
      33 | 0x0804bf0c |          0 |     OBJECT |      LOCAL |     19 | __do_global_dtors_aux_fini_array_entry
      34 | 0x08048610 |          0 |       FUNC |      LOCAL |     13 | frame_dummy
      35 | 0x0804bf08 |          0 |     OBJECT |      LOCAL |     18 | __frame_dummy_init_array_entry
      36 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | die.c
      37 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | helper.c
      38 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | parser.c
      39 | 0x0804c054 |          4 |     OBJECT |      LOCAL |     25 | _path
      40 | 0x0804c050 |          4 |     OBJECT |      LOCAL |     25 | _file_size
      41 | 0x0804c04c |          4 |     OBJECT |      LOCAL |     25 | _file_content
      42 | 0x0804c048 |          4 |     OBJECT |      LOCAL |     25 | _offset
      43 | 0x0804c044 |          4 |     OBJECT |      LOCAL |     25 | _header
      44 | 0x08049b60 |        252 |     OBJECT |      LOCAL |     15 | CSWTCH.36
      45 | 0x08049ce0 |         48 |     OBJECT |      LOCAL |     15 | CSWTCH.24
      46 | 0x08049cb8 |         20 |     OBJECT |      LOCAL |     15 | CSWTCH.26
      47 | 0x08049cac |         12 |     OBJECT |      LOCAL |     15 | CSWTCH.28
      48 | 0x08049c5c |         28 |     OBJECT |      LOCAL |     15 | CSWTCH.32
      49 | 0x08049c80 |         44 |     OBJECT |      LOCAL |     15 | CSWTCH.30
      50 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | main.c
      51 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | crtstuff.c
      52 | 0x0804a2c8 |          0 |     OBJECT |      LOCAL |     17 | __FRAME_END__
      53 | 0x0804bf10 |          0 |     OBJECT |      LOCAL |     20 | __JCR_END__
      54 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | 
      55 | 0x0804bf0c |          0 |     NOTYPE |      LOCAL |     18 | __init_array_end
      56 | 0x0804bf14 |          0 |     OBJECT |      LOCAL |     21 | _DYNAMIC
      57 | 0x0804bf08 |          0 |     NOTYPE |      LOCAL |     18 | __init_array_start
      58 | 0x0804c000 |          0 |     OBJECT |      LOCAL |     23 | _GLOBAL_OFFSET_TABLE_
      59 | 0x08049290 |          2 |       FUNC |     GLOBAL |     13 | __libc_csu_fini
      60 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _ITM_deregisterTMCloneTable
      61 | 0x08048570 |          4 |       FUNC |     GLOBAL |     13 | __x86.get_pc_thunk.bx
      62 | 0x0804c038 |          0 |     NOTYPE |       WEAK |     24 | data_start
      63 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | free@@GLIBC_2.0
      64 | 0x0804c040 |          0 |     NOTYPE |     GLOBAL |     24 | _edata
      65 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fclose@@GLIBC_2.1
      66 | 0x08049294 |          0 |       FUNC |     GLOBAL |     14 | _fini
      67 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __stack_chk_fail@@GLIBC_2.4
      68 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __xstat@@GLIBC_2.0
      69 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fread@@GLIBC_2.0
      70 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | malloc@@GLIBC_2.0
      71 | 0x0804c038 |          0 |     NOTYPE |     GLOBAL |     24 | __data_start
      72 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | __gmon_start__
      73 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | exit@@GLIBC_2.0
      74 | 0x0804c03c |          0 |     OBJECT |     GLOBAL |     24 | __dso_handle
      75 | 0x080492c4 |          4 |     OBJECT |     GLOBAL |     15 | _IO_stdin_used
      76 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __libc_start_main@@GLIBC_2.0
      77 | 0x08049220 |         97 |       FUNC |     GLOBAL |     13 | __libc_csu_init
      78 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fopen@@GLIBC_2.1
      79 | 0x0804c058 |          0 |     NOTYPE |     GLOBAL |     25 | _end
      80 | 0x08048541 |          0 |       FUNC |     GLOBAL |     13 | _start
      81 | 0x080492c0 |          4 |     OBJECT |     GLOBAL |     15 | _fp_hw
      82 | 0x0804c040 |          0 |     NOTYPE |     GLOBAL |     25 | __bss_start
      83 | 0x08048500 |         65 |       FUNC |     GLOBAL |     13 | main
      84 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __printf_chk@@GLIBC_2.3.4
      85 | 0x0804865c |         69 |       FUNC |     GLOBAL |     13 | get_file_size
      86 | 0x0804863c |         31 |       FUNC |     GLOBAL |     13 | die
      87 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _Jv_RegisterClasses
      88 | 0x080486a4 |       2932 |       FUNC |     GLOBAL |     13 | parse
      89 | 0x0804c040 |          0 |     OBJECT |     GLOBAL |     24 | __TMC_END__
      90 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _ITM_registerTMCloneTable
      91 | 0x08048418 |          0 |       FUNC |     GLOBAL |     11 | _init

SectionHeaderTable(.rel.dyn):
   Index |     Offset |       Info |                 Type |      Value | Name
=============================================================================
       0 | 0x0804bffc | 0x00000706 |       R_386_GLOB_DAT | 0x00000000 | __gmon_start__

SectionHeaderTable(.rel.plt):
   Index |     Offset |       Info |                 Type |      Value | Name
=============================================================================
       0 | 0x0804c00c | 0x00000107 |       R_386_JMP_SLOT | 0x00000000 | free
       1 | 0x0804c010 | 0x00000207 |       R_386_JMP_SLOT | 0x00000000 | fclose
       2 | 0x0804c014 | 0x00000307 |       R_386_JMP_SLOT | 0x00000000 | __stack_chk_fail
       3 | 0x0804c018 | 0x00000407 |       R_386_JMP_SLOT | 0x00000000 | __xstat
       4 | 0x0804c01c | 0x00000507 |       R_386_JMP_SLOT | 0x00000000 | fread
       5 | 0x0804c020 | 0x00000607 |       R_386_JMP_SLOT | 0x00000000 | malloc
       6 | 0x0804c024 | 0x00000707 |       R_386_JMP_SLOT | 0x00000000 | __gmon_start__
       7 | 0x0804c028 | 0x00000807 |       R_386_JMP_SLOT | 0x00000000 | exit
       8 | 0x0804c02c | 0x00000907 |       R_386_JMP_SLOT | 0x00000000 | __libc_start_main
       9 | 0x0804c030 | 0x00000a07 |       R_386_JMP_SLOT | 0x00000000 | fopen
      10 | 0x0804c034 | 0x00000b07 |       R_386_JMP_SLOT | 0x00000000 | __printf_chk


####Elf Program Header Table####
ProgramHeaderTable:
   Index |                     Type |     Offset |   VirtAddr |   PhysAddr |   FileSize |    MemSize | Flg |      Align
=======================================================================================================================
       0 |                     PHDR | 0x00000034 | 0x08048034 | 0x08048034 | 0x00000120 | 0x00000120 | R E | 0x00000004
       1 |                   INTERP | 0x00000154 | 0x08048154 | 0x08048154 | 0x00000013 | 0x00000013 | R   | 0x00000001
       2 |                     LOAD | 0x00000000 | 0x08048000 | 0x08048000 | 0x000022cc | 0x000022cc | R E | 0x00001000
       3 |                     LOAD | 0x00002f08 | 0x0804bf08 | 0x0804bf08 | 0x00000138 | 0x00000150 | RW  | 0x00001000
       4 |                  DYNAMIC | 0x00002f14 | 0x0804bf14 | 0x0804bf14 | 0x000000e8 | 0x000000e8 | RW  | 0x00000004
       5 |                     NOTE | 0x00000168 | 0x08048168 | 0x08048168 | 0x00000044 | 0x00000044 | R   | 0x00000004
       6 |                   Unknow | 0x00001d24 | 0x08049d24 | 0x08049d24 | 0x00000044 | 0x00000044 | R   | 0x00000004
       7 |                   Unknow | 0x00000000 | 0x00000000 | 0x00000000 | 0x00000000 | 0x00000000 | RW  | 0x00000010
       8 |                   Unknow | 0x00002f08 | 0x0804bf08 | 0x0804bf08 | 0x000000f8 | 0x000000f8 | R   | 0x00000001
```

### TODO List ###
* To parse Program Header Table.

