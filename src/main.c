/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/17 22:51:02 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr;
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == ' ')
			exit_error(&a, &b);
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (1);
		if (!build_stack_from_args(&a, arr))
		{
			ft_free_arr(arr);
			exit_error(&a, &b);
		}
		ft_free_arr(arr);
	}
	else
	{
		if (!build_stack_from_args(&a, argv + 1))
			exit_error(&a, &b);
	}
	if (is_sorted(&a))
		return (0);
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
