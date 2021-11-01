/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:49 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 13:56:24 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_start *stack, int display)
{
	t_elem	*sec_elem;

	if (ft_lstlen(stack) < 2)
		return ;
	if (display)
	{
		if (stack == sta())
			ft_putstr("ra\n");
		else
			ft_putstr("rb\n");
	}
	sec_elem = stack->start->next;
	last_elem(stack)->next = stack->start;
	stack->start->next = NULL;
	stack->start = sec_elem;
}

void	ra(void)
{
	ft_putstr("ra\n");
	rotate(sta(), 0);
}

void	rb(void)
{
	ft_putstr("rb\n");
	rotate(stb(), 0);
}

void	rr(void)
{
	ft_putstr("rr\n");
	rotate(sta(), 0);
	rotate(stb(), 0);
}
