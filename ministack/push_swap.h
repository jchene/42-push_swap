/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:21:12 by jchene            #+#    #+#             */
/*   Updated: 2021/10/30 03:31:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
}				t_elem;

typedef struct s_start
{
	int		init;
	char	name;
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

//Parsing functions
int				check_duplicates(void);
int				check_integers(int argc, char **argv);

//Stacks starting point addresses
t_start			*sta(void);
t_start			*stb(void);

//Linked list functions - Informations
int				is_sorted(t_start *stack);
int				is_inverted(t_start *stack);
int				is_sort_bad_top(t_start *stack);
int				is_inv_bad_top(t_start *stack);

//Linked list functions - Numbers
int				ft_lstlen(t_start *stack);
int				elem_pos(int value, t_start *stack);
int				next_value(t_start *stack, int value);

//Linked list functions - Elements
t_elem			*last_elem(t_start *stack);
t_elem			*before_last_elem(t_start *stack);
t_elem			*elem_addr(int value, t_start *stack);
t_elem			*smallest_elem(t_start *start);
t_elem			*biggest_elem(t_start *start);

//Linked list functions - Execution
void			insert_top(t_elem *elem, t_start *stack);
void			insert_bot(t_elem *elem, t_start *stack);
int				new_elem(int value, t_start *stack);
void			free_stack(t_elem *first_elem);
void			free_all(void);

//Linked list functions - Sorting
void			sort_top(void);
void			sort_inverted(void);
void			sort_three(void);
void			small_sort(void);
void			big_sort(void);

//Main functions
void			set_top(t_start *stack, int value);
void			sort_stack(void);

//Actions functions
void			swap(t_start *stack);
void			sa(void);
void			sb(void);
void			ss(void);

void			rotate(t_start *stack);
void			ra(void);
void			rb(void);
void			rr(void);

void			rev_rotate(t_start *stack);
void			rra(void);
void			rrb(void);
void			rrr(void);

void			push(t_start *dst_stack);
void			pa(void);
void			pb(void);

//Debug and display functions
void			disp_stack(t_start *stack);
void			disp_debug(void);
#endif