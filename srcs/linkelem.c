/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkelem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:46:29 by jchene            #+#    #+#             */
/*   Updated: 2021/10/30 02:33:25 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*last_elem(t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (stack->start);
	tmp = stack->start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_elem	*before_last_elem(t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (stack->start);
	if (stack->start->next == NULL)
		return (stack->start);
	tmp = stack->start;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_elem	*elem_addr(int value, t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (NULL);
	tmp = stack->start;
	while (tmp->value != value && tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->value == value)
		return (tmp);
	return (NULL);
}

t_elem	*smallest_elem(t_start *stack)
{
	int		smallest;
	t_elem	*tmp;

	if (stack->start == NULL)
		return (stack->start);
	tmp = stack->start;
	smallest = tmp->value;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (smallest > tmp->value)
			smallest = tmp->value;
	}
	return (elem_addr(smallest, stack));
}

t_elem	*biggest_elem(t_start *stack)
{
	int		biggest;
	t_elem	*tmp;

	if (stack->start == NULL)
		return (stack->start);
	tmp = stack->start;
	biggest = tmp->value;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (biggest < tmp->value)
			biggest = tmp->value;
	}
	return (elem_addr(biggest, stack));
}
