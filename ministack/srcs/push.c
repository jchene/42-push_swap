/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:40 by jchene            #+#    #+#             */
/*   Updated: 2021/10/20 01:16:37 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_start *dst_stack)
{
	t_start	*src_stack;
	t_elem	*sec_elem;

	if (dst_stack->name == 'a')
		src_stack = stb();
	else
		src_stack = sta();
	sec_elem = src_stack->start->next;
	src_stack->start->next = dst_stack->start;
	dst_stack->start = src_stack->start;
	src_stack->start = sec_elem;
}

void	pa(void)
{
	ft_putstr("pa\n");
	push(sta());
}

void	pb(void)
{
	ft_putstr("pb\n");
	push(stb());
}