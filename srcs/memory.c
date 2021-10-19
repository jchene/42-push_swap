/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:35:27 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 15:26:41 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n-- > 0)
		*(ptr++) = 0;
}

int	error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	munalloc(int code)
{
	if (code < 0)
		error();
	if (code <= -3 || code == 0)
		free_all();
	return (code);
}
