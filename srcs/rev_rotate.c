/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:51 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 13:56:28 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_start *stack, int display)
{
	t_elem	*last;

	if (ft_lstlen(stack) < 2)
		return ;
	if (display)
	{
		if (stack == sta())
			ft_putstr("rra\n");
		else
			ft_putstr("rrb\n");
	}
	last = last_elem(stack);
	before_last_elem(stack)->next = NULL;
	last->next = stack->start;
	stack->start = last;
}

void	rra(void)
{
	ft_putstr("rra\n");
	rev_rotate(sta(), 0);
}

void	rrb(void)
{
	ft_putstr("rrb\n");
	rev_rotate(stb(), 0);
}

void	rrr(void)
{
	ft_putstr("rrr\n");
	rev_rotate(sta(), 0);
	rev_rotate(stb(), 0);
}
