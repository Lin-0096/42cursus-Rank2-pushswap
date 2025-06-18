/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:45:56 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 13:04:06 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (!a || a->size == 0)
		return ;
	if (a->top->data > a->bottom->data)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int a1;
	int a2;
	int a3;

	a1 = a->top->data;
	a2 = a->top->next->data;
	a3 = a->top->next->next->data;
	if (a1 < a2 && a2 < a3 && a1 < a3)//123
		return ;
	else if (a1 < a2 && a2 > a3 && a1 < a3)//132
	{
		sa(a);
		rotate(a, 'a');
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)//213
		sa(a);
	else if (a1 < a2 && a2 > a3 && a1 > a3)//231
		rev_rotate(a, 'a');
	else if (a1 > a2 && a2 < a3 && a1 > a3)//312
		rotate(a, 'a');
	else if (a1 > a2 && a2 > a3 && a1 > a3)//321
	{
		rotate(a, 'a');
		sa(a);
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
	if (!a || a->size == 0)
		return ;
	while (i < count)
	{
		min_node = find_min(a);
		pos = get_pos(a, min_node->data);
		if (pos == -1)
			return ;
		rot_to_top(a, pos, 'a');
		pb(a, b);
		i++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
