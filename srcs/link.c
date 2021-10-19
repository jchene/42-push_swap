/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:25:13 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 02:08:53 by jchene           ###   ########.fr       */
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

t_start	*other_stack(t_start *stack)
{
	if (stack->start == sta()->start)
		return (stb());
	if (stack->start == stb()->start)
		return (sta());
	return (NULL);
}

void	disp_stack(t_start *stack)
{
	t_elem	*tmp;

	printf("-----------------------------------------\n");
	tmp = stack->start;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("v:%d - a:%p - n:%p\n", tmp->value, tmp, tmp->next);
			tmp = tmp->next;
		}
		printf("v:%d - a:%p - n:%p\n", tmp->value, tmp, tmp->next);
	}
	printf("-----------------------------------------\n\n");
}

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
