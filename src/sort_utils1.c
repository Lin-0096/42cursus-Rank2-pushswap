/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:58:23 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:31:14 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b >0)
	{
		rr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rotate(a, 'a', 1);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rotate(b, 'b', 1);
		cost_b--;
	}
}

void	do_rev_rotations(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b >0)
	{
		rrr(a, b, 1);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rev_rotate(a, 'a', 1);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rev_rotate(b, 'b', 1);
		cost_b--;
	}
}

int	init_cost_info(t_cost_info *cost, int size)
{
	cost->cost_a = malloc(sizeof(int) * size);
	cost->cost_b = malloc(sizeof(int) * size);
	cost->index_a = malloc(sizeof(int) * size);
	cost->dir_a = malloc(sizeof(int) * size);
	cost->dir_b = malloc(sizeof(int) * size);
	if (!cost->cost_a || !cost->cost_b || !cost->index_a || !cost->dir_a || !cost->dir_b)
		return (0);
	return (1);
}

void	free_cost_info(t_cost_info *cost)
{
	free(cost->cost_a);
	free(cost->cost_b);
	free(cost->index_a);
	free(cost->dir_a);
	free(cost->dir_b);
}
