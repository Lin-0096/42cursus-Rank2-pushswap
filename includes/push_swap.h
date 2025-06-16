/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:22:59 by linliu            #+#    #+#             */
/*   Updated: 2025/06/16 22:07:50 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h> //for debug ,delete!!
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

//push new node to stack
t_node	*create_node(int value);
int		stack_push_bottom(t_stack *stack, t_node *new);
int		stack_push_top(t_stack *stack, t_node *new);

//get node from stack
t_node	*pop_bottom(t_stack *stack);
t_node	*pop_top(t_stack *stack);

//stack utils
void	print_stack(t_stack *stack); //delete?
void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);

//parse
int		build_stack_from_args(t_stack *a, char **argv);

//op
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//sort
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
t_node	*find_min(t_stack *a);
int		get_pos(t_stack *a, t_node *node);
void	rot_to_top(t_stack *a, int pos);
void	sort_4_5(t_stack *a, t_stack *b);
int		find_insert_pos(t_stack *a, t_node *node);

#endif
