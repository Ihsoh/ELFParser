#include <sys/stat.h>

unsigned int get_file_size(const char * path)
{
	struct stat stat_buff;
	if(stat(path, &stat_buff) < 0)
		return 0;
	else
		return (unsigned int)stat_buff.st_size;
}
