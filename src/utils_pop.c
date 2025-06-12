/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:28:55 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 00:12:36 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_top(t_stack *stack)
{
	t_node *tmp;

	if (!stack || stack->size == 0)
		return (NULL);
	tmp = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = NULL;
	}
	tmp->next = NULL;
	stack->size--;
	return (tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node *tmp;

	if(!stack || stack->size == 0)
		return (NULL);
	tmp = stack->bottom;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->bottom = stack->bottom->prev;
		stack->bottom->next = NULL;
	}
	tmp->prev = NULL;
	stack->size--;
	return (tmp);
}
