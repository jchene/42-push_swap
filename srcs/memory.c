/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:35:27 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 02:08:31 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_elem *first_elem)
{
	if (first_elem->next != NULL)
		free_stack(first_elem->next);
	//printf("Freeing: %d\n", first_elem->value);
	free(first_elem);
}

void	free_all(void)
{
	if (sta()->start != NULL)
		free_stack(sta()->start);
	if (stb()->start != NULL)
		free_stack(stb()->start);
	sta()->start = NULL;
	stb()->start = NULL;
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

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (n-- > 0)
		*(ptr++) = 0;
}
