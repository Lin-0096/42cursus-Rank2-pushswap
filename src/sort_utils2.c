/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 23:10:42 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:31:42 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *a)
{
	t_node	*min_node;
	t_node	*cur;

	if (!a || a->size == 0)
		return (NULL);
	cur = a->top;
	min_node = cur;
	cur = cur->next;
	while (cur)
	{
		if (cur->data < min_node->data)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

int	get_pos(t_stack *a, int value)
{
	int pos;
	t_node *cur;

	if (!a || a->size == 0 )
		return (-1);
	pos = 0;
	cur = a->top;
	while (cur)
	{
		if (cur->data == value)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}

void	rot_to_top(t_stack *stack, int pos, char name)
{
	int	i;

	i = 0;
	if (pos <= stack->size / 2)
	{
		while (i++ < pos)
			rotate(stack, name, 1);
	}
	else
	{
		while (i++ < stack->size - pos)
			rev_rotate(stack, name, 1);
	}
}

void	set_cost_a_info(t_stack *a, t_cost_info *cost , int i, int val)
{
	cost->index_a[i] = get_pos(a, val);
	if (cost->index_a[i] == -1)
	{
		free_stack(a);
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	if (cost->index_a[i] <= a->size / 2)
	{
		cost->cost_a[i] = cost->index_a[i];
		cost->dir_a[i] = 1;
	}
	else
	{
		cost->cost_a[i] = a->size - cost->index_a[i];
		cost->dir_a[i] = -1;
	}
}

void	set_cost_b_info(t_stack *b, t_cost_info *cost , int i)
{
	if (i <= b->size / 2)
	{
		cost->cost_b[i] = i;
		cost->dir_b[i] = 1;
	}
	else
	{
		cost->cost_b[i] = b->size - i;
		cost->dir_b[i] = -1;
	}
}
