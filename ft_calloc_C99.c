/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_C99.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:07:04 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/11 17:07:08 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**DESCRIPTION:
**	This calloc function include the library stdint.h
**	with the value of the MACRO "SIZE_MAX", present in
**	the C99.
**	The check with SIZE_MAX is used to not go beyond 
**	the maximum value of the "size_t" type variable
*/

#include "libft.h"
#include "stdint.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = NULL;
	if (size != 0 && count > (SIZE_MAX / size))
		return (p);
	p = malloc(count * size);
	if (p)
		ft_bzero(p, count * size);
	return (p);
}
