int main(int ac, char **av)
{
	char buf_main[60] = av[1];
	int buf_int = atoi(buf_main[1]);

	if (buf_int <= 9)
	{
		memcpy(buf_main, av[2], buf_int * 4);
		if (buf_int == 0x574f4c46)
			execl("/bin/sh", "", (char *)0);
	}
}