/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:52 by jchene            #+#    #+#             */
/*   Updated: 2021/10/30 17:25:37 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute(const char *instruction)
{
	if (strcmp(instruction, "ra") == 0)
		ra();
	else if (strcmp(instruction, "rb") == 0)
		rb();
	else if (strcmp(instruction, "rr") == 0)
		rr();
	else if (strcmp(instruction, "pa") == 0)
		pa();
	else if (strcmp(instruction, "pb") == 0)
		pb();
	else if (strcmp(instruction, "sa") == 0)
		sa();
	else if (strcmp(instruction, "sb") == 0)
		sb();
	else if (strcmp(instruction, "ss") == 0)
		ss();
	else if (strcmp(instruction, "rra") == 0)
		rra();
	else if (strcmp(instruction, "rrb") == 0)
		rrb();
	else if (strcmp(instruction, "rrr") == 0)
		rrr();
}

int	main(int argc, char **argv)
{
	char	instruction[4];

	if (argc < 2)
		return (-1);
	if (check_integers(argc, argv) == -1)
		return (munalloc(-2));
	if (check_duplicates() == -1)
		return (munalloc(-3));
	while (1)
	{
		system("clear");
		disp_debug();
		scanf("%s", instruction);
		execute(instruction);
	}
	return (munalloc(0));
}
