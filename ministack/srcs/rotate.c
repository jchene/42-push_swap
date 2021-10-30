/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 00:53:49 by jchene            #+#    #+#             */
/*   Updated: 2021/10/20 00:59:55 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_start *stack)
{
	t_elem	*sec_elem;

	sec_elem = stack->start->next;
	last_elem(stack)->next = stack->start;
	stack->start->next = NULL;
	stack->start = sec_elem;
}

void	ra(void)
{
	ft_putstr("ra\n");
	rotate(sta());
}

void	rb(void)
{
	ft_putstr("rb\n");
	rotate(stb());
}

void	rr(void)
{
	ft_putstr("rr\n");
	rotate(sta());
	rotate(stb());
}
