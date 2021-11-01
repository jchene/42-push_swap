/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:52 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 18:33:44 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	else if (ft_lstlen(sta()) <= 50)
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
	sort_stack();
	return (munalloc(0));
}
