/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:58:23 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 22:26:16 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b >0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rotate(a, 'a');
		cost_a--;
	}
	while (cost_b > 0)
	{
		rotate(b, 'b');
		cost_b--;
	}
}

void	do_rev_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b >0)
	{
		rrr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rev_rotate(a, 'a');
		cost_a--;
	}
	while (cost_b > 0)
	{
		rev_rotate(b, 'b');
		cost_b--;
	}
}

void	free_cost_info(t_cost_info *cost)
{
	free(cost->cost_a);
	free(cost->cost_b);
	free(cost->index_a);
	free(cost->dir_a);
	free(cost->dir_b);
}
