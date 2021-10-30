/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:45 by jchene            #+#    #+#             */
/*   Updated: 2021/10/21 03:44:09 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_start *stack)
{
	t_elem	*sec_elem;

	sec_elem = stack->start->next;
	stack->start->next = stack->start->next->next;
	sec_elem->next = stack->start;
	stack->start = sec_elem;
}

void	sa(void)
{
	ft_putstr("sa\n");
	swap(sta());
}

void	sb(void)
{
	ft_putstr("sb\n");
	swap(stb());
}

void	ss(void)
{
	ft_putstr("ss\n");
	swap(sta());
	swap(stb());
}