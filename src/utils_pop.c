/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:28:55 by linliu            #+#    #+#             */
/*   Updated: 2025/06/12 17:03:47 by linliu           ###   ########.fr       */
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
//for debug
void	print_stack(t_stack *stack)
{
	t_node *current;

	if (!stack || stack->size == 0)
	{
		printf("empty stack\n");
		return ;
	}
	printf("size=%i\n", stack->size);
	current = stack->top;
	while (current)
	{
		printf("->%d", current->data);
		current = current->next;
	}
	printf("\n");
}
