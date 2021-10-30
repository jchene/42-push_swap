/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:51 by jchene            #+#    #+#             */
/*   Updated: 2021/10/20 01:01:25 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_start *stack)
{
	t_elem	*last;

	last = last_elem(stack);
	before_last_elem(stack)->next = NULL;
	last->next = stack->start;
	stack->start = last;
}

void	rra(void)
{
	ft_putstr("rra\n");
	rev_rotate(sta());
}

void	rrb(void)
{
	ft_putstr("rrb\n");
	rev_rotate(stb());
}

void	rrr(void)
{
	ft_putstr("rrr\n");
	rev_rotate(sta());
	rev_rotate(stb());
}
