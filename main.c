#include <stdio.h>

#include "die.h"
#include "parser.h"

int main(int argc, char * argv[])
{
	if(argc != 2)
		die("elfparser <file>");
	parse(argv[1]);
	return 0;
}
