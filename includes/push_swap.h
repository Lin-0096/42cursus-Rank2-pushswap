/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:22:59 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 00:11:30 by linliu           ###   ########.fr       */
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
	int		data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

//push new node to stack
t_node	*create_node(int value);
void	stack_push_bottom(t_stack *stack, int value);
void	stack_push_top(t_stack *stack, int value);

//get node from stack
t_node	*pop_bottom(t_stack *stack);
t_node	*pop_top(t_stack *stack);


//stack utils
void	print_stack(t_stack *stack); //delete?
void	free_stack(t_stack *stack);
void	init_stack(t_stack *stack);

//parse
int	bulid_stack_from_args(t_stack *a, char **argv);

#endif
