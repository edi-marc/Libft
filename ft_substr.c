/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:23:31 by edi-marc          #+#    #+#             */
/*   Updated: 2021/01/21 14:32:40 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	len_s;

	p = NULL;
	if (s)
		p = ft_calloc(len + 1, sizeof(*p));
	if (p)
	{
		len_s = ft_strlen(s);
		i = 0;
		while (start < len_s && i < len)
		{
			p[i] = s[start];
			start++;
			i++;
		}
	}
	return (p);
}
