/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:09:32 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 14:59:12 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	disp_stack(t_start *stack)
{
	t_elem	*tmp;

	printf("-----------------------------------------\n");
	tmp = stack->start;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("v:%d - a:%p - n:%p\n", tmp->value, tmp, tmp->next);
			tmp = tmp->next;
		}
		printf("v:%d - a:%p - n:%p\n", tmp->value, tmp, tmp->next);
	}
	printf("-----------------------------------------\n\n");
}

void	disp_debug(void)
{
	printf("Stack A:\n");
	disp_stack(sta());
	printf("Stack B:\n");
	disp_stack(stb());
	printf("*****************************************\n\n");
	push(stb());
	push(sta());
	printf("Stack A:\n");
	disp_stack(sta());
	printf("Stack B:\n");
	disp_stack(stb());
}
