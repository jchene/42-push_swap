/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linknum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:38:59 by jchene            #+#    #+#             */
/*   Updated: 2021/10/31 23:20:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstlen(t_start *stack)
{
	int		nb;
	t_elem	*tmp;

	if (stack->start == NULL)
		return (0);
	nb = 1;
	tmp = stack->start;
	while (tmp->next != NULL)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

int	elem_pos(int value, t_start *stack)
{
	int		i;
	t_elem	*tmp;

	if (stack->start == NULL)
		return (-1);
	i = 1;
	tmp = stack->start;
	while (tmp->value != value && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->value == value)
		return (i);
	return (-1);
}

int	next_value(t_start *stack, int value)
{
	t_elem	*tmp;
	int		next;

	tmp = stack->start;
	next = biggest_elem(stack)->value;
	if (value > next)
		return (smallest_elem(stack)->value);
	while (tmp->next != NULL)
	{
		if (tmp->value > value && tmp->value < next)
			next = tmp->value;
		tmp = tmp->next;
	}
	if (tmp->value > value && tmp->value < next)
		next = tmp->value;
	return (next);
}

int	moves_to_top(t_start *stack, int value)
{
	int		pos;
	int		len;
	int		rot;

	pos = elem_pos(value, stack);
	if (pos == -1)
		return (-1);
	len = ft_lstlen(stack);
	if (pos > (len / 2) + (len % 2))
		rot = len - (pos - 1);
	else
		rot = pos - 1;
	return (rot);
}
