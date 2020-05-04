/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svelhinh <svelhinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:17:02 by svelhinh          #+#    #+#             */
/*   Updated: 2017/09/26 19:06:15 by svelhinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_tolower(int c);
int ft_toupper(int c);
int ft_isprint(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isalpha(int c);
int ft_isalnum(int c);
void ft_puts(const char * s);
int ft_strlen(const char * s);
void ft_bzero(void *s, size_t n);
char *ft_strcat(char *dst, const char *src);
void *ft_memset(void *str, int c, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strdup(const char *str);
void ft_cat(int fd);

int ft_islower(int c);
int ft_isupper(int c);

#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;

	printf("tolower : %c\n", ft_tolower('C'));
	printf("toupper : %c\n", ft_toupper('c'));
	printf("isprint : %d\n", ft_isprint('c'));
	printf("isascii : %d\n", ft_isascii('c'));
	printf("isdigit : %d\n", ft_isdigit('5'));
	printf("isalpha : %d\n", ft_isalpha('c'));
	printf("isalnum : %d\n", ft_isalnum('c'));
	ft_puts("Hello World !");
	printf("strlen : %d\n", ft_strlen("yoyoyo"));
	char yo[6] = "yoyoyo";
	ft_bzero(yo, 3);
	printf("bzero : ");
	for (int i = 0; i < 6; i++)
		printf("%c", yo[i]);
	printf(" ( ");
	for (int i = 0; i < 6; i++)
		printf("%d ", yo[i]);
	printf(")\n");

	char dest[6] = "hello";
	ft_strcat(dest, " world");
	printf("strcat : %s\n", dest);

	char yo2[6] = "yoyoyo";
	ft_memset(yo2, 'c', 3);
	printf("memset : ");
	for (int i = 0; i < 6; i++)
		printf("%c", yo2[i]);
	printf(" ( ");
	for (int i = 0; i < 6; i++)
		printf("%d ", yo2[i]);
	printf(")\n");

	char yo3[6] = "yoyoyo";
	ft_memcpy(yo3, "ayayay", 3);
	printf("memcpy : ");
	for (int i = 0; i < 6; i++)
		printf("%c", yo3[i]);
	printf(" ( ");
	for (int i = 0; i < 6; i++)
		printf("%d ", yo3[i]);
	printf(")\n");

	printf("strdup : %s\n", ft_strdup("titi"));

	printf("islower : %d\n", ft_islower('C'));
	printf("isupper : %d\n", ft_isupper('C'));

	int fd = open(av[1], O_RDONLY);
	ft_cat(fd);
	return (0);
}