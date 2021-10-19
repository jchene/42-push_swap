/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:25:13 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 15:12:48 by jchene           ###   ########.fr       */
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
	elem->next = NULL;
	insert_bot(elem, stack);
	return (0);
}

void	free_stack(t_elem *first_elem)
{
	if (first_elem->next != NULL)
		free_stack(first_elem->next);
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