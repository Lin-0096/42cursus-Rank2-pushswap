/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:31:13 by linliu            #+#    #+#             */
/*   Updated: 2025/06/15 22:45:49 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node *node;

	if(!a || a->size <= 1)
		return ;
	node = pop_bottom(a);
	if (!node)
		return ;
	if(!stack_push_top(a, node))
	{
		free(node);
		return ;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node *node;

	if(!b || b->size <= 1)
		return ;
	node = pop_bottom(b);
	if (!node)
		return ;
	if(!stack_push_top(b, node))
	{
		free(node);
		return ;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if(!a || a->size <= 1 || !b || b->size <= 1)
		return ;
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
