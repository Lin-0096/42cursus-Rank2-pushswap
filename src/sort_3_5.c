/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 09:53:52 by linliu            #+#    #+#             */
/*   Updated: 2025/06/16 10:06:05 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ra(a);
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)//213
		sa(a);
	else if (a1 < a2 && a2 > a3 && a1 > a3)//231
		rra(a);
	else if (a1 > a2 && a2 < a3 && a1 > a3)//312
		ra(a);
	else if (a1 > a2 && a2 > a3 && a1 > a3)//321
	{
		ra(a);
		sa(a);
	}
}
static t_node	*find_min(t_stack *a)
{
	int		min;
	t_node	*cur;

	cur = a->top;
	min = cur->data;
	while(cur)
	{
		if(cur->next->data < min)
			min = cur->next->data;
		cur = cur->next;
	}
	return (min);
}

void	sort_5(t_stack *a, t_stack *b)
{

}
