/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:32:25 by linliu            #+#    #+#             */
/*   Updated: 2025/06/18 14:38:42 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_target(t_stack *a, t_stack *b, int *targets_val)
{
	t_node	*cur_b;
	t_node	*cur_a;
	int		target_val;
	int		i;
	int		j;

	cur_b = b->top;
	i = -1;
	while (++i < b->size)
	{
		cur_a = a->top;
		target_val = INT_MAX;//put it in while loop
		j = -1;
		while (++j < a->size)
		{
			if (cur_a->data > cur_b->data && cur_a->data < target_val)
				target_val = cur_a->data;
			cur_a = cur_a->next;
		}
		if (target_val == INT_MAX)
			targets_val[i] = find_min(a)->data;
		else
			targets_val[i] = target_val;
		cur_b = cur_b->next;
	}
}

static void	calculate_costs(t_stack *a, t_stack *b, t_cost_info *cost)
{
	int	i;
	int	*targets_val;

	targets_val = malloc(sizeof(int) * b->size);
	if (!targets_val)
		return ;
	find_target(a, b, targets_val);
	i = 0;
	while (i < b->size)
	{
		cost->index_a[i] = get_pos(a, targets_val[i]);
		if (cost->index_a[i] == -1)
			exit_error(a, b);
		if (cost->index_a[i] <= a->size / 2)
			cost->cost_a[i] = cost->index_a[i];
		else
			cost->cost_a[i] = a->size - cost->index_a[i];
		if (i <= b->size / 2)
			cost->cost_b[i] = i;
		else
			cost->cost_b[i] = b->size - i;
		i++;
	}
	free(targets_val);
}

static void	exe_min_cost(t_stack *a, t_stack *b, t_cost_info *cost)
{
	int	total_cost;
	int	i;
	int	min_cost;
	int	best_index;

	i = 0;
	best_index = 0;
	min_cost = INT_MAX;
	while (i < b->size)
	{
		total_cost = cost->cost_a[i] + cost->cost_b[i];
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			best_index = i;
		}
		i++;
	}
	rot_to_top(a, cost->index_a[best_index], 'a');
	rot_to_top(b, best_index, 'b');
	pa(a, b);
}

void	sort_large(t_stack *a, t_stack *b)
{
	t_cost_info	cost;
	int			min_pos;

	while (a->size > 3)
		pb(a, b);
	sort_3(a);
	cost.cost_a = malloc(sizeof(int) * b->size);
	cost.cost_b = malloc(sizeof(int) * b->size);
	cost.index_a = malloc(sizeof(int) * b->size);
	if (!cost.cost_a || !cost.cost_b || !cost.index_a)
		exit_error(a ,b);
	while (b->size > 0)
	{
		calculate_costs(a, b, &cost);
		exe_min_cost(a, b, &cost);
	}
	min_pos = get_pos(a, find_min(a)->data);
	if (min_pos == -1)
		exit_error(a ,b);
	rot_to_top(a, min_pos, 'a');
	free(cost.cost_a);
	free(cost.cost_b);
	free(cost.index_a);
}
