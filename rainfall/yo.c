void *auth;			// 0x8049aac
void *service;		// 0x8049ab0

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
		}
	}
}
