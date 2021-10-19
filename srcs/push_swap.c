/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:52 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 14:16:23 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicates(void)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = sta()->start;
	while (tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->value == tmp2->value)
				return (-1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_integers(int argc, char **argv)
{
	int			i;
	int			minus;
	long long	atoi;

	i = 1;
	while (i < argc)
	{
		if (str_charset("0123456789-", argv[i]) == -1)
			return (-1);
		minus = count_occur('-', argv[i]);
		if ((minus > 1) || (minus > 0 && argv[i][0] != '-'))
			return (-1);
		if (ft_strlen(argv[i]) > (10 + minus))
			return (-1);
		atoi = ft_atoi(argv[i]);
		if ((atoi > __INT_MAX__) || (atoi < ((__INT_MAX__ * -1) - 1)))
			return (-1);
		if (new_elem((int)atoi, sta()) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	if (check_integers(argc, argv) == -1)
		return (munalloc(-2));
	if (check_duplicates() == -1)
		return (munalloc(-3));
	disp_debug();
	return (munalloc(0));
}
