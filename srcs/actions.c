/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 00:47:46 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 16:03:06 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_start *dst_stack)
{
	t_start	*src_stack;
	t_elem	*sec_elem;

	src_stack = other_stack(dst_stack);
	sec_elem = src_stack->start->next;
	src_stack->start->next = dst_stack->start;
	dst_stack->start = src_stack->start;
	src_stack->start = sec_elem;
}

void	swap(t_start *stack)
{
	t_elem	*sec_elem;

	sec_elem = stack->start->next;
	stack->start->next = stack->start->next->next;
	sec_elem->next = stack->start;
	stack->start = sec_elem;
}

void	rotate(t_start *stack)
{
	t_elem	*sec_elem;

	sec_elem = stack->start->next;
	last_elem(stack)->next = stack->start;
	stack->start->next = NULL;
	stack->start = sec_elem;
}

void	rev_rotate(t_start *stack)
{
	t_elem	*last;

	last = last_elem(stack);
	before_last_elem(stack)->next = NULL;
	last->next = stack->start;
	stack->start = last;
}
