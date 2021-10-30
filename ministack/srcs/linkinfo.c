/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:11:46 by jchene            #+#    #+#             */
/*   Updated: 2021/10/30 02:18:38 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (0);
	tmp = stack->start;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_inverted(t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (0);
	tmp = stack->start;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_sort_bad_top(t_start *stack)
{
	t_elem	*tmp;
	int		top;

	tmp = smallest_elem(stack);
	top = elem_pos(tmp->value, stack) - 1;
	if (stack->start == NULL)
		return (-1);
	if (is_sorted(stack) != -1)
		return (-1);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	tmp = stack->start;
	while (top > 1)
	{
		if (tmp->value > tmp->next->value)
			return (-1);
		tmp = tmp->next;
		top--;
	}
	return (0);
}

int	is_inv_bad_top(t_start *stack)
{
	t_elem	*tmp;
	int		top;

	tmp = biggest_elem(stack);
	top = elem_pos(tmp->value, stack) - 1;
	if (stack->start == NULL)
		return (-1);
	if (is_inverted(stack) != -1)
		return (-1);
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (-1);
		tmp = tmp->next;
	}
	tmp = stack->start;
	while (top > 1)
	{
		if (tmp->value < tmp->next->value)
			return (-1);
		tmp = tmp->next;
		top--;
	}
	return (0);
}
