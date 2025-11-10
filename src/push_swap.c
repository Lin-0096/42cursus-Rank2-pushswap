/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 13:32:55 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	read_from_argv(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**arr;

	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit_error(a, b);
		arr = ft_split(argv[1], ' ');
		if (!arr)
			exit_error(a, b);
		if (!build_stack_from_args(a, arr))
		{
			ft_free_arr(arr);
			exit_error(a, b);
		}
		ft_free_arr(arr);
	}
	else
	{
		if (!build_stack_from_args(a, argv + 1))
			exit_error(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (argc == 1)
		return (0);
	read_from_argv(argc, argv, &a, &b);
	if (is_sorted(&a))
	{
		free_stack(&a);
		return (0);
	}
	if (a.size == 2)
		sort_2(&a);
	else if (a.size == 3)
		sort_3(&a);
	else if (a.size == 4 || a.size == 5)
		sort_4_5(&a, &b);
	else
		sort_large(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
