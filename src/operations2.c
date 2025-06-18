/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:16 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 11:20:40 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char name)
{
	t_node *node;

	if (!stack || stack->size <= 1)
		return ;
	node = pop_top(stack);
	if (!node)
		return ;
	stack_push_bottom(stack, node);
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack *sa, t_stack *sb)
{
	if (!sa || !sb || sa->size <= 1 || sb->size <= 1)
		return ;
	rotate(sa, 'c');
	rotate(sb, 'c');
	write(1, "rr\n", 3);
}

void	rev_rotate(t_stack *stack, char name)
{
	t_node *node;

	if (!stack || stack->size <= 1)
		return ;
	node = pop_bottom(stack);
	if (!node)
		return ;
	if (!stack_push_top(stack, node))
	{
		free(node);
		return ;
	}
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || !b || b->size <= 1)
		return ;
	rev_rotate(a, 'c');
	rev_rotate(b, 'c');
	write(1, "rrr\n", 4);
}
