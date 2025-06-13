/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:16 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 16:43:53 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node *node;

	if (!a || a->size <= 1)
		return ;
	node = pop_top(a);
	if (!node)
		return ;
	stack_push_bottom(a, node);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node *node;

	if (!b || b->size == 0)
		return ;
	node = pop_top(b);
	if (!node)
		return ;
	stack_push_bottom(b, node);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size <= 1 || b->size <= 1)
		return ;
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
