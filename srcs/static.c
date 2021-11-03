/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 01:33:16 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 21:36:48 by jchene           ###   ########.fr       */
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
		a_start.name = 'a';
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
		b_start.name = 'b';
		b_start.start = NULL;
	}
	return (&b_start);
}

t_chunk	*chunk(void)
{
	static t_chunk	s_chunk;

	if (s_chunk.init != 1)
	{
		ft_bzero(&s_chunk, sizeof(t_chunk));
		s_chunk.init = 1;
		s_chunk.size = 2;
	}
	return (&s_chunk);
}
