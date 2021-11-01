/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:25:13 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 00:34:08 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert_top(t_elem *elem, t_start *stack)
{
	if (stack->start == NULL)
		stack->start = elem;
	else
	{
		elem->next = stack->start;
		stack->start = elem;
	}
}

void	insert_bot(t_elem *elem, t_start *stack)
{
	if (stack->start == NULL)
		stack->start = elem;
	else
		last_elem(stack)->next = elem;
}

int	new_elem(int value, t_start *stack)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (-1);
	elem->value = value;
	elem->chunk_id = -1;
	elem->next = NULL;
	insert_bot(elem, stack);
	return (0);
}

void	set_top(t_start *stack, int value)
{
	int		pos;
	int		len;
	int		rot;

	pos = elem_pos(value, stack);
	if (pos == -1)
		return ;
	len = ft_lstlen(stack);
	if (pos > (len / 2) + (len % 2))
	{
		rot = len - (pos - 1);
		while (rot-- > 0)
			rev_rotate(stack, 1);
	}
	else
	{
		rot = pos - 1;
		while (rot-- > 0)
			rotate(stack, 1);
	}
	return ;
}
