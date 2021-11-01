/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:45 by jchene            #+#    #+#             */
/*   Updated: 2021/10/31 20:25:14 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_start *stack, int display)
{
	t_elem	*sec_elem;

	if (display)
	{
		if (stack == sta())
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
	sec_elem = stack->start->next;
	stack->start->next = stack->start->next->next;
	sec_elem->next = stack->start;
	stack->start = sec_elem;
}

void	sa(void)
{
	ft_putstr("sa\n");
	swap(sta(), 0);
}

void	sb(void)
{
	ft_putstr("sb\n");
	swap(stb(), 0);
}

void	ss(void)
{
	ft_putstr("ss\n");
	swap(sta(), 0);
	swap(stb(), 0);
}
