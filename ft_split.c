/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:17:11 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/22 19:23:17 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t count_words(char const *s, char c)
{
	size_t	i;
	int	trig;

	i = 0;
	trig = 0;
	while(*s)
	{	
		if (*s != c && !trig)
		{
			trig = 1;
			i++;
		}
		else if (*s == c)
			trig = 0;
		s++;
	}
	return (i);
}

static	size_t	count_symbols(char const *s, char c)
{
	size_t	i;
	
	i = 0;
	while(s[i] && s[i] != c)
		i++;
	return (i);
}

static	size_t	malloc_word(size_t len, char **p)
{

}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	*temp;
	size_t	i;

	p = NULL;
	if (s)
	{
		temp = ft_strtrim(s, (char *)c);
		p = ft_calloc(count_words(temp,c) + 1, sizeof(*p));
		if(p)
		{
			i = 0
			while (temp[i])
			{	
				if(temp[i] != c)
				{
					count_symbols(temp[i], c);
				}
				i++;
			}
		}
	}
	return (p);
}
