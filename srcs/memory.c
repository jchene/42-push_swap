/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:35:27 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 03:14:48 by jchene           ###   ########.fr       */
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

void	free_stack(t_start *stack)
{
	int		len;
	t_elem	*last;

	len = ft_lstlen(stack) - 1;
	last = last_elem(stack);
	while (len-- > 0)
	{
		last = last_elem(stack);
		before_last_elem(stack)->next = NULL;
		free(last);
	}
	free(stack->start);
}

void	free_all(void)
{
	if (sta()->start != NULL)
		free_stack(sta());
	if (stb()->start != NULL)
		free_stack(stb());
	sta()->start = NULL;
	stb()->start = NULL;
}

int	munalloc(int code)
{
	if (code < 0)
		error();
	if (code <= -3 || code == 0)
		free_all();
	return (code);
}
