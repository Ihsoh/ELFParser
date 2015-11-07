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
		default:
			return "Unknow";
	}
}

static const char * _parse_symbol_type(unsigned char info)
{
	switch(ELF32_ST_TYPE(info))
	{
		case STT_NOTYPE:
			return "NOTYPE";
		case STT_OBJECT:
			return "OBJECT";
		case STT_FUNC:
			return "FUNC";
		case STT_SECTION:
			return "SECTION";
		case STT_FILE:
			return "FILE";
		default:
			return "Unknow";
	}
}

static const char * _parse_symbol_bind(unsigned char info)
{
	switch(ELF32_ST_BIND(info))
	{
		case STB_LOCAL:
			return "LOCAL";
		case STB_GLOBAL:
			return "GLOBAL";
		case STB_WEAK:
			return "WEAK";
		default:
			return "Unknow";
	}
}

static const char * _parse_relocation_type(Elf32_Word info)
{
	switch(ELF32_R_TYPE(info))
	{
		case R_386_NONE:
			return "R_386_NONE";
		case R_386_32:
			return "R_386_32";
		case R_386_PC32:
			return "R_386_PC32";
		case R_386_GOT32:
			return "R_386_GOT32";
		case R_386_PLT32:
			return "R_386_PLT32";
		case R_386_COPY:
			return "R_386_COPY";
		case R_386_GLOB_DAT:
			return "R_386_GLOB_DAT";
		case R_386_JMP_SLOT:
			return "R_386_JMP_SLOT";
		case R_386_RELATIVE:
			return "R_386_RELATIVE";
		case R_386_GOTOFF:
			return "R_386_GOTOFF";
		case R_386_GOTPC:
			return "R_386_GOTPC";
		default:
			return "Unknow";
	}
}

static void _parse_sht(void)
{
	printf("####Elf Section Header Table####\n");
	Elf32_Shdr * shdr = (Elf32_Shdr *)(_file_content + _header->e_shoff);
	unsigned int w = 0;
	Elf32_Shdr * strtab = NULL;
	Elf32_Shdr * dynstr = NULL;
	Elf32_Shdr * dynsym = NULL;
	// Print all Section Header Table infomation.
	printf("SectionHeaderTable:\n");
	Elf32_Shdr * itr_shdr = NULL;
	Elf32_Shdr * shstr_shdr = shdr + _header->e_shstrndx;
	const char * shstr_shdr_offset = _file_content + shstr_shdr->sh_offset;
	w = printf(	"%8s | %24s | %8s | %10s | %10s | %10s | %2s | %10s | %2s | %3s | %2s\n",
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
	itr_shdr = shdr;
	for(int index = 0;
		index < _header->e_shnum;
		index++, itr_shdr++)
	{
		const char * name = "";
		if((shstr_shdr_offset + itr_shdr->sh_name)[0] != '\0')
			name = shstr_shdr_offset + itr_shdr->sh_name;
		if(strcmp(name, ".strtab") == 0)
			strtab = itr_shdr;
		else if(strcmp(name, ".dynstr") == 0)
			dynstr = itr_shdr;
		else if(strcmp(name, ".dynsym") == 0)
			dynsym = itr_shdr;
		const char * type_name = _parse_shdr_type(itr_shdr->sh_type);
		printf(	"%8d | %24s | %8s | 0x%.8x | 0x%.8x | %10u | %2u | 0x%.8x | %2u | %3u | %2u\n",
				index,
				name,
				type_name,
				itr_shdr->sh_addr,
				itr_shdr->sh_offset,
				itr_shdr->sh_size,
				itr_shdr->sh_entsize,
				itr_shdr->sh_flags,
				itr_shdr->sh_link,
				itr_shdr->sh_info,
				itr_shdr->sh_addralign);
	}
	printf("\n");
	// Print all Symbol Table infomation.
	itr_shdr = shdr;
	const char * strtab_offset = NULL;
	if(strtab != NULL)
		strtab_offset = _file_content + strtab->sh_offset;
	const char * dynstr_offset = NULL;
	if(dynstr != NULL)
		dynstr_offset = _file_content + dynstr->sh_offset;
	for(int index = 0;
		index < _header->e_shnum;
		index++, itr_shdr++)
		if(	itr_shdr->sh_type == SHT_SYMTAB
			|| itr_shdr->sh_type == SHT_DYNSYM)
		{
			const char * name = "";
			if((shstr_shdr_offset + itr_shdr->sh_name)[0] != '\0')
				name = shstr_shdr_offset + itr_shdr->sh_name;
			printf("SectionHeaderTable(%s):\n", name);
			w = printf(	"%8s | %10s | %10s | %10s | %10s | %6s |%s\n",
						"Index",
						"Value",
						"Size",
						"Type",
						"Bind",
						"Ndx",
						"Name") - 1;
			for(unsigned int ui = 0; ui < w; ui++)
				printf("=");
			printf("\n");
			Elf32_Sym * sym = (Elf32_Sym *)(_file_content + itr_shdr->sh_offset);
			for(int symidx = 0;
				symidx < itr_shdr->sh_size / itr_shdr->sh_entsize;
				symidx++, sym++)
			{
				const char * sym_name = "";
				if(itr_shdr->sh_type == SHT_SYMTAB)
				{
					if(	strtab_offset != NULL
						&& (strtab_offset + sym->st_name)[0] != '\0')
						sym_name = strtab_offset + sym->st_name;
				}
				else if(itr_shdr->sh_type == SHT_DYNSYM)
				{
					if(	dynstr_offset != NULL
						&& (dynstr_offset + sym->st_name)[0] != '\0')
						sym_name = dynstr_offset + sym->st_name;
				}

				const char * sym_type_name = _parse_symbol_type(sym->st_info);
				const char * sym_bind_name = _parse_symbol_bind(sym->st_info);
				printf(	"%8u | 0x%.8x | %10u | %10s | %10s | %6u | %s\n",
						symidx,
						sym->st_value,
						sym->st_size,
						sym_type_name,
						sym_bind_name,
						sym->st_shndx,
						sym_name);
			}
			printf("\n");
		}
	// Print all Relocation Table infomation.
	itr_shdr = shdr;
	for(int index = 0;
		index < _header->e_shnum;
		index++, itr_shdr++)
		if(itr_shdr->sh_type == SHT_REL)
		{
			const char * name = "";
			if((shstr_shdr_offset + itr_shdr->sh_name)[0] != '\0')
				name = shstr_shdr_offset + itr_shdr->sh_name;
			printf("SectionHeaderTable(%s):\n", name);
			w = printf(	"%8s | %10s | %10s | %20s | %10s | %s\n",
						"Index",
						"Offset",
						"Info",
						"Type",
						"Value",
						"Name") - 1;
			for(unsigned int ui = 0; ui < w; ui++)
				printf("=");
			printf("\n");
			Elf32_Rel * rel = (Elf32_Rel *)(_file_content + itr_shdr->sh_offset);
			for(int relidx = 0;
				relidx < itr_shdr->sh_size / itr_shdr->sh_entsize;
				relidx++, rel++)
			{
				unsigned int sym_index = ELF32_R_SYM(rel->r_info);
				Elf32_Sym * sym = (Elf32_Sym *)(_file_content + dynsym->sh_offset) + sym_index;
				const char * rel_sym_name = "";
				if(	dynstr_offset != NULL
					&& (dynstr_offset + sym->st_name)[0] != '\0')
					rel_sym_name = dynstr_offset + sym->st_name;
				const char * rel_type_name = _parse_relocation_type(rel->r_info);
				printf(	"%8u | 0x%.8x | 0x%.8x | %20s | 0x%.8x | %s\n",
						relidx,
						rel->r_offset,
						rel->r_info,
						rel_type_name,
						sym->st_value,
						rel_sym_name);
			}
			printf("\n");
		}

	printf("\n");
}

static const char * _parse_phdr_type(Elf32_Word type)
{
	switch(type)
	{
		case PT_NULL:
			return "NULL";
		case PT_LOAD:
			return "LOAD";
		case PT_DYNAMIC:
			return "DYNAMIC";
		case PT_INTERP:
			return "INTERP";
		case PT_NOTE:
			return "NOTE";
		case PT_SHLIB:
			return "SHLIB";
		case PT_PHDR:
			return "PHDR";
		default:
			return "Unknow";
	}
}

static void _parse_pht(void)
{
	printf("####Elf Program Header Table####\n");
	Elf32_Phdr * phdr = (Elf32_Phdr *)(_file_content + _header->e_phoff);
	unsigned int w = 0;
	// Print all Program Header Table infomation.
	printf("ProgramHeaderTable:\n");
	Elf32_Phdr * itr_phdr = NULL;
	w = printf(	"%8s | %24s | %10s | %10s | %10s | %10s | %10s | %3s | %10s\n",
				"Index",
				"Type",
				"Offset",
				"VirtAddr",
				"PhysAddr",
				"FileSize",
				"MemSize",
				"Flg",
				"Align") - 1;
	for(unsigned int ui = 0; ui < w; ui++)
		printf("=");
	printf("\n");
	itr_phdr = phdr;
	for(int index = 0;
		index < _header->e_phnum;
		index++, itr_phdr++)
	{
		const char * phdr_type_name = _parse_phdr_type(itr_phdr->p_type);
		char flags[4] = {' ', ' ', ' ', '\0'};
		if(itr_phdr->p_flags & PF_R)
			flags[0] = 'R';
		if(itr_phdr->p_flags & PF_W)
			flags[1] = 'W';
		if(itr_phdr->p_flags & PF_X)
			flags[2] = 'E';
		printf(	"%8u | %24s | 0x%.8x | 0x%.8x | 0x%.8x | 0x%.8x | 0x%.8x | %s | 0x%.8x\n",
				index,
				phdr_type_name,
				itr_phdr->p_offset,
				itr_phdr->p_vaddr,
				itr_phdr->p_paddr,
				itr_phdr->p_filesz,
				itr_phdr->p_memsz,
				flags,
				itr_phdr->p_align);
	}
}

static void _end(void)
{
}

static void _parse(void)
{
	_start();
	_parse_header();
	_parse_sht();
	_parse_pht();
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
