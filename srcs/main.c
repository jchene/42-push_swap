/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:52 by jchene            #+#    #+#             */
/*   Updated: 2021/10/30 18:43:21 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_top(t_start *stack, int value)
{
	int		pos;
	int		len;
	int		rotate;

	pos = elem_pos(value, stack);
	if (pos == -1)
		return ;
	len = ft_lstlen(stack);
	if (pos > len / 2)
	{
		rotate = len - (pos - 1);
		while (rotate-- > 0)
			rra();
	}
	else
	{
		rotate = pos - 1;
		while (rotate-- > 0)
			ra();
	}
	return ;
}

void	sort_stack(void)
{
	if (is_sorted(sta()) != -1)
		return ;
	else if (ft_lstlen(sta()) == 3)
		sort_three();
	else if (is_inverted(sta()) != -1)
		sort_inverted();
	else if (is_sort_bad_top(sta()) != -1)
		sort_top();
	else if (is_inv_bad_top(sta()) != -1)
	{
		sort_inverted();
		sort_top();
	}
	else if (ft_lstlen(sta()) <= 10000000)
		small_sort();
	else
		big_sort();
	return ;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (check_integers(argc, argv) == -1)
		return (munalloc(-2));
	if (check_duplicates() == -1)
		return (munalloc(-3));
	//disp_debug();
	//printf("xx\n");
	sort_stack();
	//disp_debug();
	return (munalloc(0));
}
