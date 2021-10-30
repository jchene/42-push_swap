/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:36:35 by jchene            #+#    #+#             */
/*   Updated: 2021/10/18 22:43:17 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

long long	ft_atoi(char *str)
{
	long long	nb;
	int			i;
	int			neg;

	i = 0;
	nb = 0;
	neg = 0;
	if (str[i] == '-')
	{
		i++;
		neg = 1;
	}
	while (str[i])
	{
		nb *= 10;
		nb += (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nb *= -1;
	return (nb);
}

int	str_charset(const char *charset, char *str)
{
	int		is;
	int		ic;
	int		found;

	is = 0;
	while (str[is])
	{
		ic = 0;
		found = 0;
		while (charset[ic] && found == 0)
		{
			if (str[is] == charset[ic])
				found = 1;
			ic++;
		}
		if (found == 0)
			return (-1);
		is++;
	}
	return (0);
}

int	count_occur(const char c, char *str)
{
	int		i;
	int		occur;

	i = 0;
	occur = 0;
	while (str[i])
	{
		if (str[i] == c)
			occur++;
		i++;
	}
	return (occur);
}
