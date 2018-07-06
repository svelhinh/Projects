#include <stdio.h>

int main(int ac, char **av)
{
	FILE *fd = fopen("/home/user/end/.pass", "r");

	if (fd != 0 && ac == 2)
	{
		char buf_read[24];

		fread(buf_read, 1, 66, fd);
		char buf_atoi[atoi(av[1])] = "/0";
		char buf_read2[66];
		fread(buf_read2, 1, 65, fd);
		fclose(fd);
		if (strcmp(buf_atoi, av[1]) == 0)
			execl("/bin/sh", "sh", (char *)0);
		else
			puts("");
	}
}