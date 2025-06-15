/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:08 by linliu            #+#    #+#             */
/*   Updated: 2025/06/15 22:36:18 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;

	first->next = second->next;
	if(second->next) // if stack-size > 2
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	a->top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;

	first->next = second->next;
	if(second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	b->top = second;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	sa(a);
	sa(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node *node;

	if (!b || b->size == 0)
		return ;
	node = pop_top(b);
	if (!node)
		return ;
	if (!stack_push_top(a, node)) //free the node that pop from the stack if push failed
	{
		free(node);
		return ;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node *node;

	if (!a || a->size == 0)
		return ;
	node = pop_top(a);
	if (!node)
		return ;
	if (!stack_push_top(b, node))
	{
		free(node);
		return ;
	}
	write(1, "pb\n", 3);
}
