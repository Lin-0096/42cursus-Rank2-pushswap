/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:53:52 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 14:39:08 by linliu           ###   ########.fr       */
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
		if (cur->data == value) //find that exact node in the stack,not just a node with the same value.
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
			rotate(stack, name);
	}
	else
	{
		while (i++ < stack->size - pos)
			rev_rotate(stack, name);
	}
}
