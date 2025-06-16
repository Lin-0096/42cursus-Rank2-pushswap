/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:53:52 by linliu            #+#    #+#             */
/*   Updated: 2025/06/16 13:46:45 by linliu           ###   ########.fr       */
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
	while(cur)
	{
		if(cur->data < min_node->data)
			min_node = cur;
		cur = cur->next;
	}
	return (min_node);
}

int	get_pos(t_stack *a, t_node *node)
{
	int pos;
	t_node *cur;

	if (!a || a->size == 0 || !node)
		return (-1);
	pos = 0;
	cur = a->top;
	while (cur)
	{
		if (cur == node) //find that exact node in the stack,not just a node with the same value.
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
void	rot_to_top(t_stack *a, int pos)
{
	int	i;

	i = 0;
	if (pos <= a->size / 2)
	{
		while (i++ < pos)
			ra(a);
	}
	else
	{
		while (i++ < a->size - pos)
			rra(a);
	}
}

void	sort_4_5(t_stack *a, t_stack *b)
{
	t_node	*min_node;
	int		pos;
	int		i;
	int		count;

	count = a->size - 3;
	i = 0;
	if(!a || a->size <= 3) //if size==3, just do sort3
		return ;
	while (i < count)
	{
		min_node = find_min(a);
		pos = get_pos(a, min_node);
		if (pos == -1)
			return ;
		rot_to_top(a, pos);
		pb(a, b);
		i++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
