#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "helper.h"
#include "die.h"
#include "elf.h"

static const char * _path = NULL;
static unsigned int _file_size = 0;
static unsigned char * _file_content = NULL;
static unsigned int _offset = 0;
static Elf32_Ehdr * _header = NULL;

#define	_REMAINING_SIZE	(_file_size - _offset)
#define	_CHECK_SIZE(_n)	{ if(_n > _REMAINING_SIZE) die("Cannot continue to parse this file!"); }
#define	_PROCESSED(_n) (_offset += _n)

static void _start(void)
{
	printf("####Elf File Infomation####\n");
	printf("File: %s\n", _path);
	printf("Size: %u\n", _file_size);
	printf("\n");
}

static void _parse_header(void)
{
	_CHECK_SIZE(sizeof(Elf32_Ehdr));
	_header = (Elf32_Ehdr *)_file_content;
	printf("####Elf Header####\n");
	// e_ident[EI_MAG0 ~ EI_MAG3]
	if(	_header->e_ident[EI_MAG0] != ELFMAG0
		|| _header->e_ident[EI_MAG1] != ELFMAG1
		|| _header->e_ident[EI_MAG2] != ELFMAG2
		|| _header->e_ident[EI_MAG3] != ELFMAG3)
		die("This file is not ELF file!");
	// e_ident[EI_CLASS]
	if(_header->e_ident[EI_CLASS] != ELFCLASS32)
		die("Not ELF32 file is not be supported by elfparser!");
	// e_ident[EI_DATA]
	if(_header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("Data: 2's Complement, Little Endian\n");
	else if(_header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("Data: 2's Complement, Big Endian\n");
	else
		printf("Data: Unknow\n");
	// e_ident[EI_VERSION]
	printf("Version: 0x%x\n", _header->e_ident[EI_VERSION]);
	// e_type
	switch(_header->e_type)
	{
		case ET_NONE:
			printf("Type: No file type\n");
			break;
		case ET_REL:
			printf("Type: Relocatable file\n");
			break;
		case ET_EXEC:
			printf("Type: Executable file\n");
			break;
		case ET_DYN:
			printf("Type: Shared object file\n");
			break;
		case ET_CORE:
			printf("Type: Core file\n");
			break;
		case ET_LOPROC:
			printf("Type: Processor-specific\n");
			break;
		case ET_HIPROC:
			printf("Type: Processor-specific\n");
			break;
		default:
			die("Invalid type in elf header!");
			break;
	}
	// e_machine
	const char * machine = NULL;
	switch(_header->e_machine)
	{
		case EM_NONE:
			machine = EM_NONE_MEANING;
			break;
		case EM_M32:
			machine = EM_M32_MEANING;
			break;
		case EM_SPARC:
			machine = EM_SPARC_MEANING;
			break;
		case EM_386:
			machine = EM_386_MEANING;
			break;
		case EM_68K:
			machine = EM_68K_MEANING;
			break;
		case EM_88K:
			machine = EM_88K_MEANING;
			break;
		case EM_860:
			machine = EM_860_MEANING;
			break;
		case EM_MIPS:
			machine = EM_MIPS_MEANING;
			break;
		case EM_X86_64:
			machine = EM_X86_64_MEANING;
			break;
		case EM_ARM:
			machine = EM_ARM_MEANING;
			break;
	}
	if(machine == NULL)
		printf(	"Machine: 0x%x(Unknow Machine)\n",
				_header->e_machine);
	else
		printf(	"Machine: 0x%x(%s)\n",
				_header->e_machine,
				machine);
	// e_version
	printf("Version: 0x%x\n", _header->e_version);
	// e_entry
	if(_header->e_entry == 0)
		printf(	"EntryPoint: 0x%.8x(Not Exists)\n",
				_header->e_entry);
	else
		printf(	"EntryPoint: 0x%.8x\n",
				_header->e_entry);
	// e_phoff
	if(_header->e_phoff == 0)
		printf("ProgramHeaderTableOffset: 0x%.8x(Not Exists)\n",
				_header->e_phoff);
	else
		printf("ProgramHeaderTableOffset: 0x%.8x\n",
				_header->e_phoff);
	// e_shoff
	if(_header->e_shoff == 0)
		printf("SectionHeaderTableOffset: 0x%.8x(Not Exists)\n",
				_header->e_shoff);
	else
		printf("SectionHeaderTableOffset: 0x%.8x\n",
				_header->e_shoff);
	// e_flags
	printf("Flags: 0x%.8x\n", _header->e_flags);
	// e_ehsize
	printf(	"ELFHeaderSize: %u(0x%.8x)\n",
			_header->e_ehsize,
			_header->e_ehsize);
	// e_phentsize
	printf(	"ProgramHeaderEntrySize: %u(0x%.8x)\n",
			_header->e_phentsize,
			_header->e_phentsize);
	// e_phnum
	printf(	"ProgramHeaderEntryNumber: %u(0x%.8x)\n",
			_header->e_phnum,
			_header->e_phnum);
	// e_shentsize
	printf(	"SectionHeaderEntrySize: %u(0x%.8x)\n",
			_header->e_shentsize,
			_header->e_shentsize);
	// e_shnum
	printf(	"SectionHeaderEntryNumber: %u(0x%.8x)\n",
			_header->e_shnum,
			_header->e_shnum);
	// e_shstrndx
	printf(	"SectionHeaderNameIndex: %u(0x%.8x)\n",
			_header->e_shstrndx,
			_header->e_shstrndx);
	printf("\n");
	_PROCESSED(sizeof(Elf32_Ehdr));
}

static const char * _parse_shdr_type(Elf32_Word type)
{
	switch(type)
	{
		case SHT_NULL:
			return "NULL";
		case SHT_PROGBITS:
			return "PROGBITS";
		case SHT_SYMTAB:
			return "SYMTAB";
		case SHT_STRTAB:
			return "STRTAB";
		case SHT_RELA:
			return "RELA";
		case SHT_HASH:
			return "HASH";
		case SHT_DYNAMIC:
			return "DYNAMIC";
		case SHT_NOTE:
			return "NOTE";
		case SHT_NOBITS:
			return "NOBITS";
		case SHT_REL:
			return "REL";
		case SHT_SHLIB:
			return "SHLIB";
		case SHT_DYNSYM:
			return "DYNSYM";
		case SHT_LOPROC:
			return "LOPROC";
		case SHT_HIPROC:
			return "HIPROC";
		case SHT_LOUSER:
			return "LOUSER";
		case SHT_HIUSER:
			return "HIUSER";
		default:
			return "Unknow";
	}
}

static void _parse_sht(void)
{
	printf("####Elf Section Header Table####\n");
	Elf32_Shdr * shdr = (Elf32_Shdr *)(_file_content + _header->e_shoff);
	Elf32_Shdr * shstr_shdr = shdr + _header->e_shstrndx;
	const char * shstr_shdr_offset = _file_content + shstr_shdr->sh_offset;
	unsigned int w = printf("%8s | %24s | %8s | %10s | %10s | %10s | %2s | %10s | %2s | %3s | %2s\n",
							"Index",
							"Name",
							"Type",
							"Addr",
							"Offset",
							"Size",
							"ES",
							"Flags",
							"Lk",
							"Inf",
							"Al") - 1;
	for(unsigned int ui = 0; ui < w; ui++)
		printf("=");
	printf("\n");
	for(int index = 0; index < _header->e_shnum; index++)
	{
		const char * name = "";
		if((shstr_shdr_offset + shdr->sh_name)[0] != '\0')
			name = shstr_shdr_offset + shdr->sh_name;
		const char * type_name = _parse_shdr_type(shdr->sh_type);
		printf(	"%8d | %24s | %8s | 0x%.8x | 0x%.8x | %10u | %2u | 0x%.8x | %2u | %3u | %2u\n",
				index,
				name,
				type_name,
				shdr->sh_addr,
				shdr->sh_offset,
				shdr->sh_size,
				shdr->sh_entsize,
				shdr->sh_flags,
				shdr->sh_link,
				shdr->sh_info,
				shdr->sh_addralign);
		shdr++;
	}
	printf("\n");
}

static void _end(void)
{
}

static void _parse(void)
{
	_start();
	_parse_header();
	_parse_sht();
	_end();
}

void parse(const char * path)
{
	_path = path;
	FILE * fptr = fopen(path, "rb");
	if(fptr == NULL)
		die("Cannot open this file!");
	_file_size = get_file_size(path);
	_file_content = (unsigned char *)malloc(_file_size);
	if(fptr == NULL)
		die("Cannot allocate a memory block!");
	if(!fread(_file_content, _file_size, sizeof(unsigned char), fptr))
		die("Cannot read file content!");
	fclose(fptr);
	_parse();
	free(_file_content);
}
