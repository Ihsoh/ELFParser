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
Size: 16240

####Elf Header####
Data: 2's Complement, Little Endian
Version: 0x1
Type: Executable file
Machine: 0x3(Intel 80386)
Version: 0x1
EntryPoint: 0x08048541
ProgramHeaderTableOffset: 0x00000034
SectionHeaderTableOffset: 0x00003ac0
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
      13 |                    .text | PROGBITS | 0x08048500 | 0x00000500 |       3074 |  0 | 0x00000006 |  0 |   0 | 16
      14 |                    .fini | PROGBITS | 0x08049104 | 0x00001104 |         20 |  0 | 0x00000006 |  0 |   0 |  4
      15 |                  .rodata | PROGBITS | 0x08049120 | 0x00001120 |       2369 |  0 | 0x00000002 |  0 |   0 | 32
      16 |            .eh_frame_hdr | PROGBITS | 0x08049a64 | 0x00001a64 |         68 |  0 | 0x00000002 |  0 |   0 |  4
      17 |                .eh_frame | PROGBITS | 0x08049aa8 | 0x00001aa8 |       1264 |  0 | 0x00000002 |  0 |   0 |  4
      18 |              .init_array |   Unknow | 0x0804af08 | 0x00002f08 |          4 |  0 | 0x00000003 |  0 |   0 |  4
      19 |              .fini_array |   Unknow | 0x0804af0c | 0x00002f0c |          4 |  0 | 0x00000003 |  0 |   0 |  4
      20 |                     .jcr | PROGBITS | 0x0804af10 | 0x00002f10 |          4 |  0 | 0x00000003 |  0 |   0 |  4
      21 |                 .dynamic |  DYNAMIC | 0x0804af14 | 0x00002f14 |        232 |  8 | 0x00000003 |  6 |   0 |  4
      22 |                     .got | PROGBITS | 0x0804affc | 0x00002ffc |          4 |  4 | 0x00000003 |  0 |   0 |  4
      23 |                 .got.plt | PROGBITS | 0x0804b000 | 0x00003000 |         56 |  4 | 0x00000003 |  0 |   0 |  4
      24 |                    .data | PROGBITS | 0x0804b038 | 0x00003038 |          8 |  0 | 0x00000003 |  0 |   0 |  4
      25 |                     .bss |   NOBITS | 0x0804b040 | 0x00003040 |         24 |  0 | 0x00000003 |  0 |   0 |  4
      26 |                 .comment | PROGBITS | 0x00000000 | 0x00003040 |         72 |  1 | 0x00000030 |  0 |   0 |  1
      27 |                .shstrtab |   STRTAB | 0x00000000 | 0x00003088 |        262 |  0 | 0x00000000 |  0 |   0 |  1
      28 |                  .symtab |   SYMTAB | 0x00000000 | 0x00003190 |       1456 | 16 | 0x00000000 | 29 |  58 |  4
      29 |                  .strtab |   STRTAB | 0x00000000 | 0x00003740 |        895 |  0 | 0x00000000 |  0 |   0 |  1

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
      12 | 0x08049124 |          4 |     OBJECT |     GLOBAL |     15 | _IO_stdin_used

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
      14 | 0x08049104 |          0 |    SECTION |      LOCAL |     14 | 
      15 | 0x08049120 |          0 |    SECTION |      LOCAL |     15 | 
      16 | 0x08049a64 |          0 |    SECTION |      LOCAL |     16 | 
      17 | 0x08049aa8 |          0 |    SECTION |      LOCAL |     17 | 
      18 | 0x0804af08 |          0 |    SECTION |      LOCAL |     18 | 
      19 | 0x0804af0c |          0 |    SECTION |      LOCAL |     19 | 
      20 | 0x0804af10 |          0 |    SECTION |      LOCAL |     20 | 
      21 | 0x0804af14 |          0 |    SECTION |      LOCAL |     21 | 
      22 | 0x0804affc |          0 |    SECTION |      LOCAL |     22 | 
      23 | 0x0804b000 |          0 |    SECTION |      LOCAL |     23 | 
      24 | 0x0804b038 |          0 |    SECTION |      LOCAL |     24 | 
      25 | 0x0804b040 |          0 |    SECTION |      LOCAL |     25 | 
      26 | 0x00000000 |          0 |    SECTION |      LOCAL |     26 | 
      27 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | crtstuff.c
      28 | 0x0804af10 |          0 |     OBJECT |      LOCAL |     20 | __JCR_LIST__
      29 | 0x08048580 |          0 |       FUNC |      LOCAL |     13 | deregister_tm_clones
      30 | 0x080485b0 |          0 |       FUNC |      LOCAL |     13 | register_tm_clones
      31 | 0x080485f0 |          0 |       FUNC |      LOCAL |     13 | __do_global_dtors_aux
      32 | 0x0804b040 |          1 |     OBJECT |      LOCAL |     25 | completed.6877
      33 | 0x0804af0c |          0 |     OBJECT |      LOCAL |     19 | __do_global_dtors_aux_fini_array_entry
      34 | 0x08048610 |          0 |       FUNC |      LOCAL |     13 | frame_dummy
      35 | 0x0804af08 |          0 |     OBJECT |      LOCAL |     18 | __frame_dummy_init_array_entry
      36 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | die.c
      37 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | helper.c
      38 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | parser.c
      39 | 0x0804b054 |          4 |     OBJECT |      LOCAL |     25 | _path
      40 | 0x0804b050 |          4 |     OBJECT |      LOCAL |     25 | _file_size
      41 | 0x0804b04c |          4 |     OBJECT |      LOCAL |     25 | _file_content
      42 | 0x0804b048 |          4 |     OBJECT |      LOCAL |     25 | _offset
      43 | 0x0804b044 |          4 |     OBJECT |      LOCAL |     25 | _header
      44 | 0x080498e0 |        252 |     OBJECT |      LOCAL |     15 | CSWTCH.32
      45 | 0x08049a20 |         48 |     OBJECT |      LOCAL |     15 | CSWTCH.22
      46 | 0x08049a04 |         20 |     OBJECT |      LOCAL |     15 | CSWTCH.24
      47 | 0x080499f8 |         12 |     OBJECT |      LOCAL |     15 | CSWTCH.26
      48 | 0x080499dc |         28 |     OBJECT |      LOCAL |     15 | CSWTCH.28
      49 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | main.c
      50 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | crtstuff.c
      51 | 0x08049f94 |          0 |     OBJECT |      LOCAL |     17 | __FRAME_END__
      52 | 0x0804af10 |          0 |     OBJECT |      LOCAL |     20 | __JCR_END__
      53 | 0x00000000 |          0 |       FILE |      LOCAL |  65521 | 
      54 | 0x0804af0c |          0 |     NOTYPE |      LOCAL |     18 | __init_array_end
      55 | 0x0804af14 |          0 |     OBJECT |      LOCAL |     21 | _DYNAMIC
      56 | 0x0804af08 |          0 |     NOTYPE |      LOCAL |     18 | __init_array_start
      57 | 0x0804b000 |          0 |     OBJECT |      LOCAL |     23 | _GLOBAL_OFFSET_TABLE_
      58 | 0x08049100 |          2 |       FUNC |     GLOBAL |     13 | __libc_csu_fini
      59 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _ITM_deregisterTMCloneTable
      60 | 0x08048570 |          4 |       FUNC |     GLOBAL |     13 | __x86.get_pc_thunk.bx
      61 | 0x0804b038 |          0 |     NOTYPE |       WEAK |     24 | data_start
      62 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | free@@GLIBC_2.0
      63 | 0x0804b040 |          0 |     NOTYPE |     GLOBAL |     24 | _edata
      64 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fclose@@GLIBC_2.1
      65 | 0x08049104 |          0 |       FUNC |     GLOBAL |     14 | _fini
      66 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __stack_chk_fail@@GLIBC_2.4
      67 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __xstat@@GLIBC_2.0
      68 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fread@@GLIBC_2.0
      69 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | malloc@@GLIBC_2.0
      70 | 0x0804b038 |          0 |     NOTYPE |     GLOBAL |     24 | __data_start
      71 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | __gmon_start__
      72 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | exit@@GLIBC_2.0
      73 | 0x0804b03c |          0 |     OBJECT |     GLOBAL |     24 | __dso_handle
      74 | 0x08049124 |          4 |     OBJECT |     GLOBAL |     15 | _IO_stdin_used
      75 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __libc_start_main@@GLIBC_2.0
      76 | 0x08049090 |         97 |       FUNC |     GLOBAL |     13 | __libc_csu_init
      77 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | fopen@@GLIBC_2.1
      78 | 0x0804b058 |          0 |     NOTYPE |     GLOBAL |     25 | _end
      79 | 0x08048541 |          0 |       FUNC |     GLOBAL |     13 | _start
      80 | 0x08049120 |          4 |     OBJECT |     GLOBAL |     15 | _fp_hw
      81 | 0x0804b040 |          0 |     NOTYPE |     GLOBAL |     25 | __bss_start
      82 | 0x08048500 |         65 |       FUNC |     GLOBAL |     13 | main
      83 | 0x00000000 |          0 |       FUNC |     GLOBAL |      0 | __printf_chk@@GLIBC_2.3.4
      84 | 0x0804865c |         69 |       FUNC |     GLOBAL |     13 | get_file_size
      85 | 0x0804863c |         31 |       FUNC |     GLOBAL |     13 | die
      86 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _Jv_RegisterClasses
      87 | 0x080486a4 |       2531 |       FUNC |     GLOBAL |     13 | parse
      88 | 0x0804b040 |          0 |     OBJECT |     GLOBAL |     24 | __TMC_END__
      89 | 0x00000000 |          0 |     NOTYPE |       WEAK |      0 | _ITM_registerTMCloneTable
      90 | 0x08048418 |          0 |       FUNC |     GLOBAL |     11 | _init


####Elf Program Header Table####
ProgramHeaderTable:
   Index |                     Type |     Offset |   VirtAddr |   PhysAddr |   FileSize |    MemSize | Flg |      Align
=======================================================================================================================
       0 |                     PHDR | 0x00000034 | 0x08048034 | 0x08048034 | 0x00000120 | 0x00000120 | R E | 0x00000004
       1 |                   INTERP | 0x00000154 | 0x08048154 | 0x08048154 | 0x00000013 | 0x00000013 | R   | 0x00000001
       2 |                     LOAD | 0x00000000 | 0x08048000 | 0x08048000 | 0x00001f98 | 0x00001f98 | R E | 0x00001000
       3 |                     LOAD | 0x00002f08 | 0x0804af08 | 0x0804af08 | 0x00000138 | 0x00000150 | RW  | 0x00001000
       4 |                  DYNAMIC | 0x00002f14 | 0x0804af14 | 0x0804af14 | 0x000000e8 | 0x000000e8 | RW  | 0x00000004
       5 |                     NOTE | 0x00000168 | 0x08048168 | 0x08048168 | 0x00000044 | 0x00000044 | R   | 0x00000004
       6 |                   Unknow | 0x00001a64 | 0x08049a64 | 0x08049a64 | 0x00000044 | 0x00000044 | R   | 0x00000004
       7 |                   Unknow | 0x00000000 | 0x00000000 | 0x00000000 | 0x00000000 | 0x00000000 | RW  | 0x00000010
       8 |                   Unknow | 0x00002f08 | 0x0804af08 | 0x0804af08 | 0x000000f8 | 0x000000f8 | R   | 0x00000001

```

### TODO List ###
* To parse Program Header Table.

