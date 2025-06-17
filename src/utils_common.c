/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:09:05 by linliu            #+#    #+#             */
/*   Updated: 2025/06/17 11:00:29 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

//for debug!! delete??
void	print_stack(t_stack *stack)
{
	t_node	*current;

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

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	if (!stack || stack->size == 0)
		return ;
	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	t_node *cur;

	if (!stack || stack->size == 0)
		return (1);
	cur = stack->top;
	while (cur && cur->next) //if don't check cur->next, the if would cause segfault
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}
