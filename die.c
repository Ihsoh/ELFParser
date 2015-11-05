#include <stdlib.h>
#include <stdio.h>

#include "die.h"

void die(const char * message)
{
	printf("**** Error: %s ****\n", message);
	exit(-1);
}
