/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:13:03 by jchene            #+#    #+#             */
/*   Updated: 2021/10/18 23:08:20 by jchene           ###   ########.fr       */
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
