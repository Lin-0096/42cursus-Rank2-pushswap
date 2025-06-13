/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 16:31:13 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 16:43:53 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node *node;

	if(!a || a->size == 0)
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

	if(!b || b->size == 0)
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
	if(!a || !a->size == 0 ||!b || b->size == 0)
		return ;
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
