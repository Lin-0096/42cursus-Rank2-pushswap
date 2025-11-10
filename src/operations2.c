/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:16 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:38:22 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char name, int checker)
{
	t_node *node;

	if (!stack || stack->size <= 1)
		return ;
	node = pop_top(stack);
	if (!node)
		return ;
	stack_push_bottom(stack, node);
	if (checker == 1)
	{
		if (name == 'a')
			write(1, "ra\n", 3);
		else if (name == 'b')
			write(1, "rb\n", 3);
	}

}

void	rr(t_stack *sa, t_stack *sb, int checker)
{
	if (!sa || !sb || sa->size <= 1 || sb->size <= 1)
		return ;
	rotate(sa, 'c', 1);
	rotate(sb, 'c', 1);
	if (checker == 1)
		write(1, "rr\n", 3);
}

void	rev_rotate(t_stack *stack, char name, int checker)
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
	if (checker == 1)
	{
		if (name == 'a')
			write(1, "rra\n", 4);
		else if (name == 'b')
			write(1, "rrb\n", 4);
	}

}

void	rrr(t_stack *a, t_stack *b, int checker)
{
	if (!a || a->size <= 1 || !b || b->size <= 1)
		return ;
	rev_rotate(a, 'c', 1);
	rev_rotate(b, 'c', 1);
	if (checker == 1)
		write(1, "rrr\n", 4);
}
