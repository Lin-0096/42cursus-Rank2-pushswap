/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pop_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:28:55 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 11:57:57 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	stack_push_bottom(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return (0);
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->bottom;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
	return (1);
}

int	stack_push_top(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return (0);
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->next = stack->top;
		stack->top->prev = new;
		stack->top = new;
	}
	stack->size++;
	return (1);
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*tmp;

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
	t_node	*tmp;

	if (!stack || stack->size == 0)
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
