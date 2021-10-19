/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:21:12 by jchene            #+#    #+#             */
/*   Updated: 2021/10/19 16:02:00 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
}				t_elem;

typedef struct s_start
{
	int		init;
	t_elem	*start;
}				t_start;

//Multi purpose functions - Strings
int				ft_strlen(char *str);
void			ft_putstr(char *str);
long long		ft_atoi(char *str);
int				str_charset(const char *charset, char *str);
int				count_occur(const char c, char *str);

//Memory and error return functions
void			ft_bzero(void *b, size_t n);
int				error(void);
int				munalloc(int code);

//Linked list functions - Informations
t_start			*sta(void);
t_start			*stb(void);
t_elem			*last_elem(t_start *stack);
t_start			*other_stack(t_start *stack);
t_elem			*before_last_elem(t_start *stack);

//Linked list functions - Execution
void			insert_top(t_elem *elem, t_start *stack);
void			insert_bot(t_elem *elem, t_start *stack);
int				new_elem(int value, t_start *stack);
void			free_stack(t_elem *first_elem);
void			free_all(void);

//Actions functions
void			swap(t_start *stack);
void			push(t_start *dst_stack);
void			rotate(t_start *stack);

//Debug and display functions
void			disp_stack(t_start *stack);
void			disp_debug(void);
#endif