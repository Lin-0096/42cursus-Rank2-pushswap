/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:36:20 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 00:10:41 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if(!new)
		return (NULL);
	new->data = value;
	new->prev = NULL;
	new->next = NULL;
	return(new);
}

void	stack_push_bottom(t_stack *stack, int value)
{
	t_node	*new;

	if(!stack)
		return ;
	new = create_node(value);
	if(!new)
		return ;
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
}

void	stack_push_top(t_stack *stack, int value)
{
	t_node	*new;

	if(!stack)
		return ;
	new = create_node(value);
	if (!new)
		return ;
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
}
