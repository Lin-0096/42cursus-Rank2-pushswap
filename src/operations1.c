/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:52:08 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:38:06 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int checker)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;

	first->next = second->next;
	if (second->next) // if stack-size > 2
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	a->top = second;
	if (checker == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int checker)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	b->top = second;
	if (checker == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int checker)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	sa(a, 0);
	sb(b, 0);
	if (checker == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b, int checker)
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
	if (checker == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b, int checker)
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
	if (checker == 1)
		write(1, "pb\n", 3);
}
