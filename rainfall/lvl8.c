void *auth;				// 0x8049aac
void *service;			// 0x8049ab0

int main()
{
	while (1)
	{
		printf("%p, %p \n", auth, service);
		
		char *s;
		s = fgets(s, 128, 0);
		if (s != NULL)
		{
			char *s2 = s;
			s = "auth ";
			if (s == s2)
			{
				auth = malloc(4);
				int i = 5;
				int nbc = 0;
				while (s2[i] != 0)
					nbc++;
				if (nbc < 30)
					strcpy(auth, s2[i]);
			}
			if (s2 == "reset")
				free(auth);
			if (s2 == "service")
				service = strdup(s2[7]);
			if (s2 == "login")
			{
				if (auth != NULL)
					system("/bin/sh");
				else
					fwrite("Password:\n", 1, 10, 1);
			}
		}
	}
	return 0;
}