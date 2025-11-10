/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:32:25 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:38:52 by linliu           ###   ########.fr       */
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
		set_cost_a_info(a, cost , i, targets_val[i]);
		set_cost_b_info(b, cost , i);
		i++;
	}
	free(targets_val);
}

static void	exe_rotations(t_stack *a, t_stack *b, t_cost_info *cost, int i)
{
	if (cost->dir_a[i] == 1 && cost->dir_b[i] == 1)
		do_rotations(a, b, cost->cost_a[i], cost->cost_b[i]);
	else if (cost->dir_a[i] == -1 && cost->dir_b[i] == -1)
		do_rev_rotations(a, b, cost->cost_a[i], cost->cost_b[i]);
	else
	{
		rot_to_top(a, cost->index_a[i], 'a');
		rot_to_top(b, i, 'b');
	}
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
	exe_rotations(a, b, cost, best_index);
	pa(a, b, 1);
}

void	sort_large(t_stack *a, t_stack *b)
{
	t_cost_info	cost;
	int			min_pos;

	while (a->size > 3)
		pb(a, b, 1);
	sort_3(a);
	if (!init_cost_info(&cost, b->size))
		exit_error(a, b);
	while (b->size > 0)
	{
		calculate_costs(a, b, &cost);
		exe_min_cost(a, b, &cost);
	}
	min_pos = get_pos(a, find_min(a)->data);
	if (min_pos == -1)
		exit_error(a ,b);
	rot_to_top(a, min_pos, 'a');
	free_cost_info(&cost);
}
