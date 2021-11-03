/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:21:12 by jchene            #+#    #+#             */
/*   Updated: 2021/11/03 17:35:15 by jchene           ###   ########.fr       */
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
	int				chunk_id;
	struct s_elem	*next;
}				t_elem;

typedef struct s_start
{
	int		init;
	char	name;
	t_elem	*start;
}				t_start;

typedef struct s_chunk
{
	int		init;
	int		size;
}				t_chunk;

//Multi purpose functions - Strings
int				ft_strlen(char *str);
void			ft_putstr(char *str);
long long		ft_atoi(char *str);
int				str_charset(const char *charset, char *str);
int				count_occur(const char c, char *str);

//Memory and error return functions
void			ft_bzero(void *b, size_t n);
int				error(void);
void			free_stack(t_start *stack);
void			free_all(void);
int				munalloc(int code);

//Parsing functions
int				check_duplicates(void);
int				check_integers(int argc, char **argv);

//Stacks starting point addresses
t_start			*sta(void);
t_start			*stb(void);
t_chunk			*chunk(void);

//Linked list functions - Informations
int				is_sorted(t_start *stack);
int				is_inverted(t_start *stack);
int				is_sort_bad_top(t_start *stack);
int				is_inv_bad_top(t_start *stack);

//Linked list functions - Numbers
int				ft_lstlen(t_start *stack);
int				elem_pos(int value, t_start *stack);
int				next_value(t_start *stack, int value);
int				moves_to_top(t_start *stack, int value);

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
void			set_top(t_start *stack, int value);

//Linked list functions - Sorting
void			sort_top(void);
void			sort_inverted(void);
void			sort_three(void);
void			small_sort(void);
void			big_sort(void);

//Chunks and big sorting functions
void			set_chunks(void);
t_elem			*get_first_in_chunk(t_start *stack, int chunk_id);
t_elem			*get_last_in_chunk(t_start *stack, int chunk_id);
t_elem			*get_shortest(t_elem *first, t_elem *last);
void			sort_chunks(void);

//Main functions
void			sort_stack(void);

//Actions functions
void			swap(t_start *stack, int display);
void			sa(void);
void			sb(void);
void			ss(void);

void			rotate(t_start *stack, int display);
void			ra(void);
void			rb(void);
void			rr(void);

void			rev_rotate(t_start *stack, int display);
void			rra(void);
void			rrb(void);
void			rrr(void);

void			push(t_start *dst_stack, int display);
void			pa(void);
void			pb(void);

//Debug and display functions
void			disp_stack(t_start *stack);
void			disp_debug(void);
#endif