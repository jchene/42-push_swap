/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:11:46 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 15:58:13 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_start	*sta(void)
{
	static t_start	a_start;

	if (a_start.init != 1)
	{
		ft_bzero(&a_start, sizeof(t_start));
		a_start.init = 1;
		a_start.start = NULL;
	}
	return (&a_start);
}

t_start	*stb(void)
{
	static t_start	b_start;

	if (b_start.init != 1)
	{
		ft_bzero(&b_start, sizeof(t_start));
		b_start.init = 1;
		b_start.start = NULL;
	}
	return (&b_start);
}

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

t_elem	*before_last_elem(t_start *stack)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (stack->start);
	if (stack->start->next == NULL)
		return (stack->start);
	tmp = stack->start;
	while (tmp->next->next != NULL)
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
