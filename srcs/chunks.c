/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:27:08 by jchene            #+#    #+#             */
/*   Updated: 2021/11/01 21:37:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_chunks(void)
{
	t_elem	*tmp;
	int		chunk_id;
	int		elem_id;

	tmp = smallest_elem(sta());
	chunk_id = 0;
	elem_id = 0;
	while (tmp != biggest_elem(sta()))
	{
		if (elem_id > chunk()->size - 1)
		{
			chunk_id++;
			elem_id = 0;
		}
		tmp->chunk_id = chunk_id;
		tmp = elem_addr(next_value(sta(), tmp->value), sta());
		elem_id++;
	}
	if (elem_id > chunk()->size - 1)
	{
		chunk_id++;
		elem_id = 0;
	}
	tmp->chunk_id = chunk_id;
}

t_elem	*get_first_in_chunk(t_start *stack, int chunk_id)
{
	t_elem	*tmp;

	if (stack->start == NULL)
		return (NULL);
	tmp = stack->start;
	while (tmp->next != NULL)
	{
		if (tmp->chunk_id == chunk_id)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->chunk_id == chunk_id)
		return (tmp);
	return (NULL);
}

t_elem	*get_last_in_chunk(t_start *stack, int chunk_id)
{
	t_elem	*tmp;
	t_elem	*last;

	if (stack->start == NULL)
		return (NULL);
	tmp = stack->start;
	last = NULL;
	while (tmp->next != NULL)
	{
		if (tmp->chunk_id == chunk_id)
			last = tmp;
		tmp = tmp->next;
	}
	if (tmp->chunk_id == chunk_id)
		last = tmp;
	return (last);
}

t_elem	*get_shortest(t_elem *first, t_elem *last)
{
	if (first == NULL && last == NULL)
		return (NULL);
	else if (moves_to_top(sta(), first->value)
		< moves_to_top(sta(), last->value))
		return (first);
	else
		return (last);
}

void	sort_chunks(void)
{
	int		chunk_id;
	t_elem	*first;
	t_elem	*last;
	t_elem	*shortest;

	chunk_id = 0;
	while (sta()->start != NULL)
	{
		first = get_first_in_chunk(sta(), chunk_id);
		last = get_last_in_chunk(sta(), chunk_id);
		shortest = get_shortest(first, last);
		if (first == NULL && last == NULL)
			chunk_id++;
		else
		{
			set_top(sta(), shortest->value);
			if (stb()->start != NULL)
				set_top(stb(), next_value(stb(), shortest->value));
			pb();
		}
	}
	return ;
}
