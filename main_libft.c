/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:15:11 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/31 16:44:21 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	Main to test all the functions of the libft library
**
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#include "libft.h"

void	rebuild(char *str_n, char *str_u, char *str_s, char *str_m, char *str_b, char *str_i)
{
	strcpy(str_n, "");
	strcpy(str_u, "c");
	strcpy(str_s, "ciao");
	strcpy(str_m, "c1ao_a");
	strcpy(str_b, "ciao_a_tutti");
	strcpy(str_i, "Iao");
}

void	print_split(char **p)
{
	if(p)
	{
		while(*p)
		{
			printf("%p : ", &*p);
			printf("%s\n", *p);
			p++;
		}
		printf("*p nullo : %p , contenuto : %p\n", &*p,*p);
	}
	else
		printf("**p nullo : %p\n", p);
}

char	add_i_to_char(unsigned int i, char c)
{
	return (c + i);
}

char	minus_i_to_char(unsigned int i, char c)
{
	return (c - i);
}

void	print_elem(t_list *elem)
{
	printf("content: %s\n", elem->content);
	printf("next: %p\n\n", elem->next);
}

void	print_lst(t_list **lst)
{
	if(lst && *lst)
	{
		t_list *elem;
		
		elem = *lst;
		while(elem)
		{
			print_elem(elem);
			elem = elem->next;
		}
	}
	else if (!lst)
		printf("lista nulla\n");
	else
		printf("lista vuota\n");
}

/* this function is used to delete the content of the item declared t_list on libft.h */
/* assuming content is treated as a string */

void	delete_item_content(void *content)
{
	if(content)
		ft_memcpy(content, "\0", 1);
}

/* this function is used to change the content of the item declared t_list on libft.h */
/* assuming content is treated as a string */

void	change_item_content(void *content)
{
	if(content)
		ft_memcpy(content, "GG\0", 3);
}

/* this function is used to return a new content for the item declared t_list on libft.h */
/* assuming content is treated as a string (not destructive on the passed content) */

void	*new_item_content(void *content)
{
	char *new_content = ft_calloc(4, sizeof(*new_content));
	if(content && new_content)
		ft_memcpy(new_content, "NEW\0", 4);
	return (new_content);
}

int main(void)
{
	char str_n[]="";
	char str_u[]="c";
	char str_s[]="ciao";
	char str_m[]="c1ao_a";
	char str_b[]="ciao_a_tutti";
	char str_i[]="Iao";
	char str_v[1]="\0";
	char *str_a;

	char num_1[]=" 	d";
	char num_2[]=" 	+--+-d";
	char num_3[]=" 	+--+--++ ";
	char num_4[]=" 	+--+--+1f";
	char num_5[]=" 	+--+--+145 ";
	char num_6[]=" 	-42";
	char num_7[]="-214748364942";
	char num_8[]=" 	 -56b";
	
	printf("\n-- TEST strncmp --\n\n");

	printf("TEST original function\n");
	printf("%d\n",strncmp(str_n, str_n, 42));
	printf("%d\n",strncmp(str_s, str_n, 5));
	printf("%d\n",strncmp(str_s, str_i, 2));
	printf("%d\n",strncmp(str_m, str_b, 4));
	printf("%d\n",strncmp(str_s, str_b, 4));
	printf("%d\n",strncmp("\200", "\0", 4));
	
	printf("TEST ft function\n");
	printf("%d\n",ft_strncmp(str_n, str_n, 42));
	printf("%d\n",ft_strncmp(str_s, str_n, 5));
	printf("%d\n",ft_strncmp(str_s, str_i, 2));
	printf("%d\n",ft_strncmp(str_m, str_b, 4));
	printf("%d\n",ft_strncmp(str_s, str_b, 4));
	printf("%d\n",ft_strncmp("\200", "\0", 4));
	
	printf("\n-- TEST atoi --\n\n");

	printf("TEST original function\n");
	printf("%d\n",atoi(num_1));
	printf("%d\n",atoi(num_2));
	printf("%d\n",atoi(num_3));
	printf("%d\n",atoi(num_4));
	printf("%d\n",atoi(num_5));
	printf("%d\n",atoi(num_6));
	printf("%d\n",atoi(num_7));
	printf("%d\n",atoi(num_8));
	printf("%d\n",atoi("-9999999999999999999999999999999"));
	printf("%d\n",atoi("9999999999999999999999999999999"));
	
	printf("TEST ft function\n");
	printf("%d\n",ft_atoi(num_1));
	printf("%d\n",ft_atoi(num_2));
	printf("%d\n",ft_atoi(num_3));
	printf("%d\n",ft_atoi(num_4));
	printf("%d\n",ft_atoi(num_5));
	printf("%d\n",ft_atoi(num_6));
	printf("%d\n",ft_atoi(num_7));
	printf("%d\n",ft_atoi(num_8));
	printf("%d\n",ft_atoi("-9999999999999999999999999999"));
	printf("%d\n",ft_atoi("9999999999999999999999999999"));
	
	printf("\n-- TEST strlen --\n\n");

	printf("TEST original function\n");
	printf("%lu\n",strlen(str_n));
	printf("%lu\n",strlen(str_m));
	printf("%lu\n",strlen(str_s));
	printf("%lu\n",strlen(str_b));
	printf("%lu\n",strlen(str_i));

	printf("TEST ft function\n");
	printf("%lu\n",ft_strlen(str_n));
	printf("%lu\n",ft_strlen(str_m));
	printf("%lu\n",ft_strlen(str_s));
	printf("%lu\n",ft_strlen(str_b));
	printf("%lu\n",ft_strlen(str_i));

	printf("\n-- TEST strrchr --\n\n");

	printf("TEST original function\n");
	/* Not found  - B */
	printf("%p\n",strrchr(str_n, 66));
	printf("%s\n",strrchr(str_n, 66));
	/* null character  */
	printf("%p\n",strrchr(str_s, 0));
	printf("%s\n",strrchr(str_s, 0));
	/* last character - o  */
	printf("%p\n",strrchr(str_s, 111));
	printf("%s\n",strrchr(str_s, 111));
	/* first character - c */
	printf("%p\n",strrchr(str_m, 99));
	printf("%s\n",strrchr(str_m, 99));
	/* third character - a  */
	printf("%p\n",strrchr(str_s, 97));
	printf("%s\n",strrchr(str_s, 97));
	/* penultimate character - t */
	printf("%p\n",strrchr(str_b, 116));
	printf("%s\n",strrchr(str_b, 116));
	/* int not in ascii - loop */
	//printf("%p\n",ft_strrchr(str_b, 242));
	//printf("%s\n",ft_strrchr(str_b, 242));
	
	printf("TEST ft function\n");
	/* Not found  - B */
	printf("%p\n",ft_strrchr(str_n, 66));
	printf("%s\n",ft_strrchr(str_n, 66));
	/* null character  */
	printf("%p\n",ft_strrchr(str_s, 0));
	printf("%s\n",ft_strrchr(str_s, 0));
	/* last character - o  */
	printf("%p\n",ft_strrchr(str_s, 111));
	printf("%s\n",ft_strrchr(str_s, 111));
	/* first character - c */
	printf("%p\n",ft_strrchr(str_m, 99));
	printf("%s\n",ft_strrchr(str_m, 99));
	/* third character - a  */
	printf("%p\n",ft_strrchr(str_s, 97));
	printf("%s\n",ft_strrchr(str_s, 97));
	/* penultimate character - t */
	printf("%p\n",ft_strrchr(str_b, 116));
	printf("%s\n",ft_strrchr(str_b, 116));
	/* int not in ascii - null */
	//printf("%p\n",ft_strrchr(str_b, 242));
	//printf("%s\n",ft_strrchr(str_b, 242));

	printf("\n-- TEST memset --\n\n");

	printf("TEST original function\n");
	printf("%s\n",memset(str_u, 126, 2));
	// gcc error - overflow
	//printf("%s\n",memset(str_n, 126, 3));
	printf("%s\n",memset(str_s, 42, 1));
	printf("%s\n",memset(str_m, 42, 5));
	printf("%s\n",memset(str_b, 300, 1));
	printf("%s\n",memset(str_i, 300, (0)));

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("TEST ft function\n");
	printf("%s\n",ft_memset(str_u, 126, 2));
	// no error - copying outside the range of the string | fill the entire string
	// printf("%s\n",ft_memset(str_n, 126, 3));
	printf("%s\n",ft_memset(str_s, 42, 1));
	printf("%s\n",ft_memset(str_m, 42, 5));
	printf("%s\n",ft_memset(str_b, 300, 1));
	printf("%s\n",ft_memset(str_i, 300, 0));

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("\n-- TEST bzero --\n\n");
	
	printf("TEST original function\n");
	// gcc error - overflow (bzero use memsert)
	//printf("%s\n",bzero(str_n, 2));
	bzero(str_s, 3);
	write(1,&str_s, 4);
	write(1,"\n", 1);

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("TEST ft function\n");
	// no error - (ft_bzero use ft_memsert)
	//printf("%s\n",ft_bzero(str_n, 2));
	ft_bzero(str_s, 3);
	write(1,&str_s, 4);
	write(1,"\n", 1);

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("\n-- TEST memcpy --\n\n");
	
	printf("TEST original function\n");
	str_a = str_b + 5;
	printf("%s\n", memcpy(str_a, str_b, 6));
	printf("%s\n", memcpy(str_s, str_i, 2));
	memcpy(str_m, str_n, 5);
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// gcc error - overflow
	//printf("%s\n", memcpy(str_n, str_u, 3));
	printf("%s\n", memcpy(str_u, str_b, 0));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("TEST ft function\n");
	str_a = str_b + 5;
	printf("%s\n", ft_memcpy(str_a, str_b, 6));
	printf("%s\n", ft_memcpy(str_s, str_i, 2));
	ft_memcpy(str_m, str_n, 5);
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// no error - overflow
	//printf("%s\n", ft_memcpy(str_n, str_u, 3));
	printf("%s\n", ft_memcpy(str_u, str_b, 0));

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("\n-- TEST memccpy --\n\n");
	
	printf("TEST original function\n");
	// error - abort
	//str_a = str_b + 5;
	//printf("%s\n", memccpy(str_a, str_b, 42, 6));
	//printf("%s\n", str_b);
	printf("%s\n", memccpy(str_s, str_i, 97, 3));
	printf("%s\n", str_s);
	printf("%s\n", memccpy(str_m, str_u, 42, 5));
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// gcc error - overflow
	//printf("%s\n", memccpy(str_n, str_u, 42, 3));
	printf("%s\n", memccpy(str_u, str_b, 42, 0));
	printf("%s\n", str_u);
	printf("%s\n", memccpy(str_u, str_b, 97, 0));
	printf("%s\n", str_u);

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("TEST ft function\n");
	// no error
	//str_a = str_b + 5;
	//printf("%s\n", ft_memccpy(str_a, str_b, 42, 6));
	//printf("%s\n", str_b);
	printf("%s\n", ft_memccpy(str_s, str_i, 97, 3));
	printf("%s\n", str_s);
	printf("%s\n", ft_memccpy(str_m, str_u, 42, 5));
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// no error - overflow
	//printf("%s\n", ft_memccpy(str_n, str_u, 42, 3));
	printf("%s\n", ft_memccpy(str_u, str_b, 42, 0));
	printf("%s\n", str_u);
	printf("%s\n", ft_memccpy(str_u, str_b, 97, 0));
	printf("%s\n", str_u);

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);

	printf("\n-- TEST memmove --\n\n");
	
	printf("TEST original function\n");
	str_a = str_b + 5;
	printf("%s\n", memmove(str_a, str_b, 6));
	printf("%s\n", memmove(str_s, str_i, 3));
	printf("%s\n", memmove(str_m, str_u, 5));
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// gcc error - overflow
	//printf("%s\n", memmove(str_n, str_u, 3));
	printf("%s\n", memmove(str_u, str_b, 0));
	printf("%s\n", memmove(str_n, str_u, 1));
	printf("%s\n", memmove((void *)0, (void *)0, 5));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("TEST ft function\n");
	str_a = str_b + 5;
	printf("%s\n", ft_memmove(str_a, str_b, 6));
	printf("%s\n", ft_memmove(str_s, str_i, 3));
	printf("%s\n", ft_memmove(str_m, str_u, 5));
	write(1, &str_m, 6);
	write(1, "\n", 1);
	// no error - overflow
	//printf("%s\n", ft_memmove(str_n, str_u, 3));
	printf("%s\n", ft_memmove(str_u, str_b, 0));
	printf("%s\n", ft_memmove(str_n, str_u, 1));
	printf("%s\n", ft_memmove((void *)0, (void *)0, 5));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("\n-- TEST memchr --\n\n");
	
	printf("TEST original function\n");
	printf("%s\n", memchr(str_n, 116, 7));
	printf("%s\n", memchr(str_n, 0, 1));
	printf("%s\n", memchr(str_b, 0, 28));
	printf("%s\n", memchr(str_b, 116, 7));
	printf("%s\n", memchr(str_b, 116, 20));
	
	printf("TEST ft function\n");
	printf("%s\n", ft_memchr(str_n, 116, 7));
	printf("%s\n", ft_memchr(str_n, 0, 1));
	printf("%s\n", ft_memchr(str_n, 0, 28));
	printf("%s\n", ft_memchr(str_b, 116, 7));
	printf("%s\n", ft_memchr(str_b, 116, 20));
	
	printf("\n-- TEST strchr --\n\n");

	printf("TEST original function\n");
	/* Not found  - B */
	printf("%p\n",strchr(str_n, 66));
	printf("%s\n",strchr(str_n, 66));
	/* null character  */
	printf("%p\n",strchr(str_s, 0));
	printf("%s\n",strchr(str_s, 0));
	/* last character - o  */
	printf("%p\n",strchr(str_s, 111));
	printf("%s\n",strchr(str_s, 111));
	/* first character - c */
	printf("%p\n",strchr(str_m, 99));
	printf("%s\n",strchr(str_m, 99));
	/* third character - a  */
	printf("%p\n",strchr(str_s, 97));
	printf("%s\n",strchr(str_s, 97));
	/* penultimate character - t */
	printf("%p\n",strchr(str_b, 116));
	printf("%s\n",strchr(str_b, 116));
	/* int not in ascii - loop */
	//printf("%p\n",ft_strchr(str_b, 242));
	//printf("%s\n",ft_strchr(str_b, 242));
	
	printf("TEST ft function\n");
	/* Not found  - B */
	printf("%p\n",ft_strchr(str_n, 66));
	printf("%s\n",ft_strchr(str_n, 66));
	/* null character  */
	printf("%p\n",ft_strchr(str_s, 0));
	printf("%s\n",ft_strchr(str_s, 0));
	/* last character - o  */
	printf("%p\n",ft_strchr(str_s, 111));
	printf("%s\n",ft_strchr(str_s, 111));
	/* first character - c */
	printf("%p\n",ft_strchr(str_m, 99));
	printf("%s\n",ft_strchr(str_m, 99));
	/* third character - a  */
	printf("%p\n",ft_strchr(str_s, 97));
	printf("%s\n",ft_strchr(str_s, 97));
	/* penultimate character - t */
	printf("%p\n",ft_strchr(str_b, 116));
	printf("%s\n",ft_strchr(str_b, 116));
	/* int not in ascii - null */
	//printf("%p\n",ft_strchr(str_b, 242));
	//printf("%s\n",ft_strchr(str_b, 242));

	printf("\n-- TEST isalpha --\n\n");

	printf("TEST original function\n");
	printf("%d\n", isalpha(65));
	printf("%d\n", isalpha(64));
	printf("%d\n", isalpha(121));
	printf("%d\n", isalpha(123));
	printf("%d\n", isalpha(500));
	
	printf("TEST ft function\n");
	printf("%d\n", ft_isalpha(65));
	printf("%d\n", ft_isalpha(64));
	printf("%d\n", ft_isalpha(121));
	printf("%d\n", ft_isalpha(122));
	printf("%d\n", ft_isalpha(500));

	printf("\n-- TEST isdigit --\n\n");

	printf("TEST original function\n");
	printf("%d\n", isdigit(48));
	printf("%d\n", isdigit(47));
	printf("%d\n", isdigit('\71'));
	printf("%d\n", isdigit('\72'));
	printf("%d\n", isdigit(500));
	
	printf("TEST ft function\n");
	printf("%d\n", ft_isdigit(48));
	printf("%d\n", ft_isdigit(47));
	printf("%d\n", ft_isdigit('\71'));
	printf("%d\n", ft_isdigit('\72'));
	printf("%d\n", ft_isdigit(500));

	printf("\n-- TEST isalnum --\n\n");

	printf("TEST original function\n");

	printf("%d\n", isalnum('\100'));
	printf("%d\n", isalnum('\101'));
	printf("%d\n", isalnum('\72'));
	printf("%d\n", isalnum('\71'));
	printf("%d\n", isalnum(500));

	printf("TEST ft function\n");

	printf("%d\n", ft_isalnum('\100'));
	printf("%d\n", ft_isalnum('\101'));
	printf("%d\n", ft_isalnum('\72'));
	printf("%d\n", ft_isalnum('\71'));
	printf("%d\n", ft_isalnum(500));

	printf("\n-- TEST isascii --\n\n");

	printf("TEST original function\n");

	printf("%d\n", isascii(-60));
	printf("%d\n", isascii(90));
	printf("%d\n", isascii('\177'));
	printf("%d\n", isascii(127));
	printf("%d\n", isascii(128));
	printf("%d\n", isascii(0));
	printf("%d\n", isascii(500));
	
	printf("TEST ft function\n");

	printf("%d\n", ft_isascii(-60));
	printf("%d\n", ft_isascii(90));
	printf("%d\n", ft_isascii('\177'));
	printf("%d\n", ft_isascii(127));
	printf("%d\n", ft_isascii(128));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", ft_isascii(500));
	
	printf("\n-- TEST isprint --\n\n");

	printf("TEST original function\n");

	printf("%d\n", isprint(-60));
	printf("%d\n", isprint('\40'));
	printf("%d\n", isprint('\41'));
	printf("%d\n", isprint(90));
	printf("%d\n", isprint('\177'));
	printf("%d\n", isprint(126));
	printf("%d\n", isprint(128));
	printf("%d\n", isprint('\115'));

	printf("TEST ft function\n");

	printf("%d\n", ft_isprint(-60));
	printf("%d\n", ft_isprint('\40'));
	printf("%d\n", ft_isprint('\41'));
	printf("%d\n", ft_isprint(90));
	printf("%d\n", ft_isprint('\177'));
	printf("%d\n", ft_isprint(126));
	printf("%d\n", ft_isprint(128));
	printf("%d\n", ft_isprint('\115'));

	printf("\n-- TEST toupper --\n\n");

	printf("TEST original function\n");

	printf("%d\n", toupper(-60));
	printf("%d\n", toupper('\40'));
	printf("%d\n", toupper('\41'));
	printf("%d\n", toupper(90));
	printf("%d\n", toupper('\177'));
	printf("%d\n", toupper(126));
	printf("%d\n", toupper(128));
	printf("%d\n", toupper('\115'));
	printf("%d\n", toupper(97));
	printf("%d\n", toupper(122));

	printf("TEST ft function\n");

	printf("%d\n", ft_toupper(-60));
	printf("%d\n", ft_toupper('\40'));
	printf("%d\n", ft_toupper('\41'));
	printf("%d\n", ft_toupper(90));
	printf("%d\n", ft_toupper('\177'));
	printf("%d\n", ft_toupper(126));
	printf("%d\n", ft_toupper(128));
	printf("%d\n", ft_toupper('\115'));
	printf("%d\n", ft_toupper(97));
	printf("%d\n", ft_toupper(122));

	printf("\n-- TEST tolower --\n\n");

	printf("TEST original function\n");

	printf("%d\n", tolower(-60));
	printf("%d\n", tolower(97));
	printf("%d\n", tolower(100));
	printf("%d\n", tolower(64));
	printf("%d\n", tolower(65));
	printf("%d\n", tolower(91));
	printf("%d\n", tolower(90));
	printf("%d\n", tolower('\122'));
	printf("%d\n", tolower(500));

	printf("TEST ft function\n");

	printf("%d\n", ft_tolower(-60));
	printf("%d\n", ft_tolower(97));
	printf("%d\n", ft_tolower(100));
	printf("%d\n", ft_tolower(64));
	printf("%d\n", ft_tolower(65));
	printf("%d\n", ft_tolower(91));
	printf("%d\n", ft_tolower(90));
	printf("%d\n", ft_tolower('\122'));
	printf("%d\n", ft_tolower(500));

	printf("\n-- TEST memcmp --\n\n");

	printf("TEST original function\n");

	printf("%d\n", memcmp("ciao", "ciaot", 4));
	printf("%d\n", memcmp("ciao", "ciaot", 5));
	printf("%d\n", memcmp("ciao\0", "ciao\0t", 42));
	printf("%d\n", memcmp("ciao\0f", "ciao\0a", 42));
	// seg fault
	//printf("%d\n", memcmp((void *)0, "", 4));
	//printf("%d\n", memcmp("", (void *)0, 4));
	//printf("%d\n", memcmp((void *)0,(void *)0, 4));
	printf("%d\n", memcmp("", (void *)0, 0));
	// bus error
	//printf("%d\n", memcmp("ciao", "ciao", -1));
	
	printf("TEST ft function\n");

	printf("%d\n", ft_memcmp("ciao", "ciaot", 4));
	printf("%d\n", ft_memcmp("ciao", "ciaot", 5));
	printf("%d\n", ft_memcmp("ciao\0", "ciao\0t", 42));
	printf("%d\n", ft_memcmp("ciao\0f", "ciao\0a", 42));
	// seg fault
	//printf("%d\n", ft_memcmp((void *)0, "", 4));
	//printf("%d\n", ft_memcmp("", (void *)0, 4));
	//printf("%d\n", ft_memcmp((void *)0,(void *)0, 4));
	printf("%d\n", ft_memcmp("", (void *)0, 0));
	// bus error
	//printf("%d\n", ft_memcmp("ciao", "ciao", -1));
	
	printf("\n-- TEST strlcpy --\n\n");

	printf("TEST original function\n");

	printf("%lu\n", strlcpy(str_i, str_s, 0));
	printf("%s\n", str_i);
	printf("%lu\n", strlcpy(str_i, str_s, 1));
	printf("%s\n", str_i);
	printf("%lu\n", strlcpy(str_n, str_u, 0));
	printf("%s\n", str_n);
	printf("%lu\n", strlcpy(str_u, str_b, 2));
	printf("%s\n", str_u);
	printf("%lu\n", strlcpy(str_b, str_v, 3));
	printf("%s\n", str_b);
	// seg fault
	//printf("%lu\n", strlcpy(NULL, NULL, 1));
	// gcc error overflow
	//printf("%lu\n", strlcpy(str_m, str_s, -1));
	//printf("%lu\n", strlcpy(str_n, str_b, 42));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("TEST ft function\n");

	printf("%lu\n", ft_strlcpy(str_i, str_s, 0));
	printf("%s\n", str_i);
	printf("%lu\n", ft_strlcpy(str_i, str_s, 1));
	printf("%s\n", str_i);
	printf("%lu\n", ft_strlcpy(str_n, str_u, 0));
	printf("%s\n", str_n);
	printf("%lu\n", ft_strlcpy(str_u, str_b, 2));
	printf("%s\n", str_u);
	printf("%lu\n", ft_strlcpy(str_b, str_v, 3));
	printf("%s\n", str_b);
	//no seg fault
	//printf("%lu\n", ft_strlcpy(NULL, NULL, 1));
	// no error (write all the source)
	//printf("%lu\n", ft_strlcpy(str_m, str_s, -1));
	//printf("%s\n", str_m);
	//printf("%lu\n", ft_strlcpy(str_n, str_m, 42));
	//printf("%s\n", str_n);

	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("\n-- TEST strlcat --\n\n");

	printf("TEST original function\n");

	printf("%lu\n", strlcat(str_i, str_s, 0));
	printf("%s\n", str_i);
	printf("%lu\n", strlcat(str_i, str_s, 1));
	printf("%s\n", str_i);
	printf("%lu\n", strlcat(str_n, str_u, 0));
	printf("%s\n", str_n);
	printf("%lu\n", strlcat(str_u, str_b, 2));
	printf("%s\n", str_u);
	printf("%lu\n", strlcat(str_b, str_v, 3));
	printf("%s\n", str_b);
/*
	write(1, "*--SP TEST--*\n", 14);	
	char test1[42] = "\0q\0due";
	write(1, test1, 42);
	write(1, "\n", 1);
	char test3[]="ciao2";
	printf("%lu\n", strlcat(test1, test3, 4));
	printf("%s\n", test1);
	write(1, test1, 42);
	write(1, "\n", 1);
	write(1, "*--SP TEST--*\n", 14);	
*/
/*
 *	test is not empty, there is some data in the memory	
 *
	char test[42];
	write(1, test, 42);
	write(1, "\n", 1);
	char test2[]="ciao2";
	printf("%lu\n", strlcat(test, test2, 3));
	printf("%s\n", test);
	write(1, test, 42);
	write(1, "\n", 1);
*/
	// seg fault
	//printf("%lu\n", strlcat(NULL, NULL, 1));
	// gcc error overflow
	//printf("%lu\n", strlcat(str_m, str_s, -1));
	//printf("%lu\n", strlcat(str_n, str_b, 42));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("TEST ft function\n");

	printf("%lu\n", ft_strlcat(str_i, str_s, 0));
	printf("%s\n", str_i);
	printf("%lu\n", ft_strlcat(str_i, str_s, 1));
	printf("%s\n", str_i);
	printf("%lu\n", ft_strlcat(str_n, str_u, 0));
	printf("%s\n", str_n);
	printf("%lu\n", ft_strlcat(str_u, str_b, 2));
	printf("%s\n", str_u);
	printf("%lu\n", ft_strlcat(str_b, str_v, 3));
	printf("%s\n", str_b);
/*
	write(1, "*--SP TEST--*\n", 14);	
	char test1[42] = "\0q\0due";
	write(1, test1, 42);
	write(1, "\n", 1);
	char test3[]="ciao2";
	printf("%lu\n", ft_strlcat(test1, test3, 4));
	printf("%s\n", test1);
	write(1, test1, 42);
	write(1, "\n", 1);
	write(1, "*--SP TEST--*\n", 14);	
*/
/*
 *	test is not empty, there is some data in the memory	
*/
/*
	char test[42];
	write(1, test, 42);
	write(1, "\n", 1);
	char test2[]="ciao2";
	printf("%lu\n", ft_strlcat(test, test2, 3));
	printf("%s\n", test);
	write(1, test, 42);
	write(1, "\n", 1);
*/
	// seg fault
	//printf("%lu\n", ft_strlcat(NULL, NULL, 1));
	// no error overflow
	//printf("%lu\n", ft_strlcat(str_m, str_s, -1));
	//printf("%lu\n", ft_strlcat(str_n, str_b, 42));
	
	rebuild(str_n, str_u, str_s, str_m, str_b, str_i);
	
	printf("\n-- TEST strnstr --\n\n");

	printf("TEST original function\n");

	printf("%s\n", strnstr("ciao", "c", 0));
	printf("%s\n", strnstr("ciao", "d", 42));
	printf("%s\n", strnstr("ciao", "i", 1));
	printf("%s\n", strnstr("ciao", "a", 42));
	// seg fault
	//printf("%s\n", strnstr("ciao", NULL, 0));
	//printf("%s\n", strnstr(NULL, "ciao", 42));
	printf("%s\n", strnstr("ciao", "ia\0j", 42));
	printf("%s\n", strnstr("ciao", "iaj", 42));
	printf("%s\n", strnstr("ciao", "o", -1));
	printf("%s\n", strnstr("cia", "", 1));
	
	printf("TEST ft function\n");

	printf("%s\n", ft_strnstr("ciao", "c", 0));
	printf("%s\n", ft_strnstr("ciao", "d", 42));
	printf("%s\n", ft_strnstr("ciao", "i", 1));
	printf("%s\n", ft_strnstr("ciao", "a", 42));
	// seg fault
	//printf("%s\n", ft_strnstr("ciao", NULL, 0));
	//printf("%s\n", ft_strnstr(NULL, "ciao", 42));
	printf("%s\n", ft_strnstr("ciao", "ia\0j", 42));
	printf("%s\n", ft_strnstr("ciao", "iaj", 42));
	printf("%s\n", ft_strnstr("ciao", "o", -1));
	printf("%s\n", ft_strnstr("cia", "", 1));

	printf("\n-- TEST strdup --\n\n");

	printf("TEST original function\n");

	// seg fault
	//printf("%s\n", strdup(NULL));
	printf("%s\n", strdup(""));
	printf("%s\n", strdup("ciao\0atutti"));
	printf("%s\n", strdup("ciao_a_tutti"));
	printf("%s\n", strdup("\200"));

	printf("TEST ft function\n");
	
	// seg fault
	//printf("%s\n", strdup(NULL));
	printf("%s\n", ft_strdup(""));
	printf("%s\n", ft_strdup("ciao\0atutti"));
	printf("%s\n", ft_strdup("ciao_a_tutti"));
	printf("%s\n", ft_strdup("\200"));

	printf("\n-- TEST ft_substr --\n");

	printf("%s\n", ft_substr("", 0, 2));
	printf("%s\n", ft_substr(NULL, 0, 2));
	printf("%s\n", ft_substr("ciaoatutti", 0, 42));
	printf("%s\n", ft_substr("ciaoatutti", -0, -2));
	printf("%s\n", ft_substr("ciaoatutti", 0, -1));
	printf("%s\n", ft_substr("ciaoatutti", -42, 42));
	printf("%s\n", ft_substr("ciaoatutti", 0, 42));
	printf("%s\n", ft_substr("ciaoatutti", 10, 2));
	printf("%s\n", ft_substr("ciaoatutti", 9, 1));
	printf("%s\n", ft_substr("ciaoatutti", 9, 0));
	printf("%s\n", ft_substr("ciaoatutti", 5, 100));
	
	printf("\n-- TEST ft_strjoin --\n");

	printf("%s\n", ft_strjoin("ciao", "atutti"));
	printf("%s\n", ft_strjoin(NULL, "atutti"));
	printf("%s\n", ft_strjoin("ciao", NULL));
	printf("%s\n", ft_strjoin("", ""));
	printf("%s\n", ft_strjoin("", "c"));
	printf("%s\n", ft_strjoin("ciao", ""));

	printf("\n-- TEST ft_strtrim --\n");

	printf("%s\n", ft_strtrim("dciaod", "d"));
	printf("%s\n", ft_strtrim("\200dciao\200d", "d\200"));
	printf("%s\n", ft_strtrim("\0ciaod\0", "\0d"));
	printf("%s\n", ft_strtrim("ciao\0", "\0"));
	printf("%s\n", ft_strtrim("\0ciao\0a", "\0a"));
	printf("%s\n", ft_strtrim("\0ciao\na\0", "\0a"));
	printf("%s\n", ft_strtrim("ciaoatutti", ""));
	printf("%s\n", ft_strtrim(NULL, ""));
	printf("%s\n", ft_strtrim("", NULL));
	printf("%s\n", ft_strtrim("", ""));
	printf("%s\n", ft_strtrim("ciao", "ciao\0"));
	// correct behavoir
	printf("%s\n", ft_strtrim("ciao", "ci\0ao"));
	printf("%s\n", ft_strtrim("aaciaoaa", "a"));
	printf("%s\n", ft_strtrim("aaquiaaa", "a"));
	printf("%s\n", ft_strtrim("abdciaoabd", "dbaf"));
	
	printf("\n-- TEST ft_split --\n");

	printf("\n-- 1 --\n");
	print_split(ft_split(NULL, '1'));
	printf("\n-- 2 --\n");
	print_split(ft_split("ciao1ci1ao", '1'));
	printf("\n-- 3 --\n");
	print_split(ft_split("", '1'));
	printf("\n-- 4 --\n");
	print_split(ft_split("ciao", 0));
	printf("\n-- 5 --\n");
	print_split(ft_split("1ciao1", '1'));
	printf("\n-- 6 --\n");
	print_split(ft_split("ciao", 1));
	printf("\n-- 7 --\n");
	print_split(ft_split("", 0));
	printf("\n-- 8 --\n");
	print_split(ft_split("111111", '1'));
	printf("\n-- 9 --\n");
	print_split(ft_split("ci\0a1o", '1'));
	printf("\n-- 10 --\n");
	print_split(ft_split("xxxciaocxxcixaoxxcxxx", 'x'));
	printf("\n-- 11 --\n");
	print_split(ft_split("\n\nciao\n\nciao\n\n\n", '\n'));
	printf("\n-- 12 --\n");
	print_split(ft_split("wtf..?", -1));
	printf("\n-- 13 --\n");
	print_split(ft_split("\200", '\200'));
	printf("\n-- 14 --\n");
	print_split(ft_split("really?", '\200'));
	printf("\n-- 15 --\n");
	print_split(ft_split("please_stop\0", '\0'));
	printf("\n-- 16 --\n");
	print_split(ft_split("\0ok....", '\0'));
	
	printf("\n-- TEST ft_itoa --\n");

	printf("\n-- 1 --\n");
	printf("%s\n",ft_itoa(1234));
	printf("\n-- 2 --\n");
	printf("%s\n",ft_itoa(0));
	printf("\n-- 3 --\n");
	printf("%s\n",ft_itoa(-1));
	printf("\n-- 4 --\n");
	printf("%s\n",ft_itoa(9));
	printf("\n-- 5 --\n");
	printf("%s\n",ft_itoa(-324454));
	printf("\n-- 6 --\n");
	printf("%s\n",ft_itoa(2147483647));
	printf("\n-- 7 --\n");
	printf("%s\n",ft_itoa(-2147483648));
	
	printf("\n-- TEST ft_strmapi --\n");

	printf("\n-- 1 --\n");
	printf("%s\n",ft_strmapi("1234", add_i_to_char));
	printf("\n-- 2 --\n");
	printf("%s\n",ft_strmapi("00000", minus_i_to_char));

	printf("\n-- TEST ft_putchar_fd --\n");

	ft_putchar_fd('6', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('6', 2);
	ft_putchar_fd('\n', 1);
	
	printf("\n-- TEST ft_putstr_fd --\n");

	ft_putstr_fd("ciaociao", 1);
	ft_putchar_fd('\n', 1);
	// seg fault - correct behaviour
	//ft_putstr_fd((char *)'c', 2);
	ft_putstr_fd("si\0questo_no", 2);
	ft_putchar_fd('\n', 1);
	
	printf("\n-- TEST ft_putendl_fd --\n");

	ft_putendl_fd("ciaociao", 1);
	ft_putendl_fd("ciao\nciao", 2);
	ft_putendl_fd("the cake is a lie !\0I'm hidden lol\r\n", 2);
	
	printf("\n-- TEST ft_putnbr_fd --\n");

	ft_putnbr_fd(-12, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(+42, 2);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2147483648, 2);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2147483647, 2);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 2);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-0, 2);
	ft_putchar_fd('\n', 1);

	printf("\n___ BONUS ___\n");
	printf("\n-- TEST ft_lstnew --\n");

	char string[] = "eccomi qui!";
	t_list *elem = ft_lstnew(string);

	t_list *elem2 = ft_lstnew(NULL);

	print_elem(elem);
	print_elem(elem2);
	
	printf("\n-- TEST ft_lst_add_front --\n");

	t_list **lst;

	lst = &elem;
   
	printf("\n-- prima --\n");
	
	print_lst(lst);

	printf("\n-- dopo --\n");
	
	ft_lstadd_front(lst, elem2);

	print_lst(lst);

	printf("\n-- TEST ft_lstsize --\n");
	
	printf("size list = %d\n",ft_lstsize(*lst));

	char string42[] = "ciao";
	t_list *elem3 = ft_lstnew(string42);

	ft_lstadd_front(lst, elem3);

	printf("size list = %d\n\n",ft_lstsize(*lst));
	
	print_lst(lst);
	
	printf("\n-- TEST ft_lstlast --\n");
	
	print_elem(ft_lstlast(*lst));

	printf("\n-- TEST ft_lstadd_back --\n");
	
	printf("\n-- prima --\n");
	
	print_lst(lst);

	printf("\n-- dopo --\n");
	
	char string2[] = "ancora...";
	t_list *elem4 = ft_lstnew(string2);
	
	ft_lstadd_back(lst, elem4);

	print_lst(lst);

	printf("\n-- TEST 2 --\n");
	
	t_list *elem_null = NULL;

	t_list **lst2 = &elem_null;	

	printf("\n-- prima --\n");
	
	print_lst(lst2);

	printf("\n-- dopo --\n");
	
	ft_lstadd_back(lst2, elem4);

	print_lst(lst2);

	printf("\n-- TEST ft_lstdelone --\n");

	char test[]= "ciao";

	t_list *elem5 = ft_lstnew(test);

	print_elem(elem5);
	
	ft_lstdelone(elem5, delete_item_content);

	// the element is printed and accessible because free does'nt change in any way the memory allocated
	print_elem(elem5);
	
	printf("\n-- TEST ft_lstmap --\n");
	
	printf("\n-- lista originale --\n");
	
	print_lst(lst);
	
	printf("\n-- mapped list --\n");	

	t_list *lst4;

	lst4 = ft_lstmap(*lst, new_item_content, delete_item_content);

	print_lst(&lst4);

	printf("\n-- TEST ft_lstiter --\n");
	
	printf("\n-- prima --\n");
	
	print_lst(lst);
	
	printf("\n-- dopo --\n");	

	ft_lstiter(*lst, change_item_content);

	print_lst(lst);

	printf("\n-- TEST ft_lstclear --\n");

	printf("\n-- prima --\n");
	
	print_lst(lst);
	
	printf("\n-- dopo --\n");	

	ft_lstclear(lst, delete_item_content);

	print_lst(lst);
	
	return (0);
}
