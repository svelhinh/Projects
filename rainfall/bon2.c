int language = 0;

void greetuser(char *buf)
{
	char *buf_hello[72];

	if (language == 1)
		strcpy(buf_hello, "Hyvää päivää ");
	else if (language == 2)
		strcpy(buf_hello, "Goedemiddag! ");
	else if (language == 0)
		strcpy(buf_hello, "Hello ");
	puts(strcat(buf_hello, buf));
}

int main(int ac, char **av)
{
	char buf[160];		// 0xbffff660

	if (ac == 3)
	{
		strncpy(&buf[80], av[1], 40);
		strncpy(&buf[120], av[2], 32);
		char *retGetEnv = getenv("LANG");
		if (!memcmp(retGetEnv, "fi", 2))
			language = 1;
		else if (!memcmp(retGetEnv, "nl", 2))
			language = 2;
		greetuser(buf);
	}
	return 0;
}