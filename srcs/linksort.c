/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:51:24 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 21:40:06 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_top(void)
{
	int		top;
	int		len;

	len = ft_lstlen(sta());
	top = elem_pos(smallest_elem(sta())->value, sta());
	if (top <= (len / 2))
		while (top-- > 1)
			ra();
	else
		while (top++ < len + 1)
			rra();
}

void	sort_inverted(void)
{
	int		len;
	int		push;

	len = ft_lstlen(sta());
	if (len >= 2)
		sa();
	if (len >= 3)
		rra();
	if (len >= 4)
	{
		push = len - 4;
		while (push-- > 0)
		{
			pb();
			rra();
		}
		rra();
		sa();
		push = len - 4;
		while (push-- > 0)
			pa();
	}
}

void	sort_three(void)
{
	if (is_sorted(sta()) != -1)
		return ;
	if (biggest_elem(sta())->next != smallest_elem(sta()))
		sa();
	if (is_sorted(sta()) != -1)
		return ;
	if (sta()->start->value < before_last_elem(sta())->value)
		rra();
	else
		ra();
}

void	small_sort(void)
{
	int		len;
	int		i;

	i = 0;
	len = ft_lstlen(sta());
	while (i++ < len - 3)
		pb();
	sort_three();
	while (stb()->start != NULL)
	{
		set_top(sta(), next_value(sta(), stb()->start->value));
		pa();
	}
	set_top(sta(), smallest_elem(sta())->value);
	return ;
}

void	big_sort(void)
{
	unsigned int	elements;

	if (ft_lstlen(sta()) > 250)
		chunk()->size = 38;
	else
		chunk()->size = 18;
	set_chunks();
	sort_chunks();
	set_top(stb(), biggest_elem(stb())->value);
	elements = ft_lstlen(stb());
	while (elements > 0)
	{
		pa();
		rrb();
		elements--;
	}
	return ;
}
