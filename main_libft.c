/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:26:08 by emdi-mar          #+#    #+#             */
/*   Updated: 2024/11/18 20:46:37 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**DESCRIPTION:
**	Testing SIZE_MAX
*/

#include <stdio.h>
#include <stdint.h>

int	main(void)
{
	size_t	test;
	size_t	test2;
	size_t	test3;
	size_t	test4;

	test = SIZE_MAX;
	test2 = SIZE_MAX + 1;
	test3 = 35.9999999999999;
	test4 = SIZE_MAX + 5;
	printf("SIZE MAX= %lu\n", test);
	printf("SIZE MAX + 1 = %lu\n", test2);
	printf("SIZE MAX with decimals = %lu\n", test3);
	printf("SIZE MAX + 5 = %lu\n", test4);
	printf("SIZE_MAX * SIZE_MAX = %lu\n", test * test);
	printf("SIZE_MAX / SIZE_MAX = %lu\n", test / test);
	return (0);
}
