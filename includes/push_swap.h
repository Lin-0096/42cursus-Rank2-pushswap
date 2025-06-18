/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:22:59 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 22:26:37 by linliu           ###   ########.fr       */
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

typedef struct s_cost_info
{
	int	*cost_a;
	int	*cost_b;
	int	*index_a;
	int	*dir_a;
	int	*dir_b;
}	t_cost_info;

//pop new node from and push it to stack
t_node	*create_node(int value);
int		stack_push_bottom(t_stack *stack, t_node *new);
int		stack_push_top(t_stack *stack, t_node *new);
t_node	*pop_bottom(t_stack *stack);
t_node	*pop_top(t_stack *stack);
//stack utils
void	print_stack(t_stack *stack); //delete?
void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
void	exit_error(t_stack *a, t_stack *b);
//parse
int		build_stack_from_args(t_stack *a, char **argv);
//op
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rotate(t_stack *stack, char name);
void	rr(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *stack, char name);
void	rrr(t_stack *a, t_stack *b);
//sort small
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4_5(t_stack *a, t_stack *b);
//sort large
void	sort_large(t_stack *a, t_stack *b);
//sort utils
t_node	*find_min(t_stack *a);
int		get_pos(t_stack *a, int value);
void	rot_to_top(t_stack *stack, int pos, char name);
//sort large utils
void	do_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b);
void	do_rev_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b);
void	free_cost_info(t_cost_info *cost);

#endif
