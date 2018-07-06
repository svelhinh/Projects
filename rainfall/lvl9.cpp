#include <string.h>
#include <stdlib.h>

class N
{
	public:

		char _annotation[104];	// 0x804a00c
		int _nb;				// 0x804a070
		
		N(int nb)
		{
			_nb = nb;
		}

		void setAnnotation(char *s)
		{
			memcpy(_annotation, s, strlen(s));
		}
		
		N operator+(N & ref)
		{
			return _nb + ref._nb;
		}
		
		N operator-(N & ref)
		{
			return _nb - ref._nb;
		}
};


int main(int ac, char **av)
{
	if (ac <= 1)
		exit(1);
	N *yo = new N(5);		// 0x0804a008
	N *yo2 = new N(6);		// 0x0804a078
	
	yo->setAnnotation(av[1]);
	*yo2 = *yo2 + *yo;
		
}

4c 88 04 08