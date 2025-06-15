/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:09:30 by linliu            #+#    #+#             */
/*   Updated: 2025/06/15 23:53:14 by linliu           ###   ########.fr       */
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
