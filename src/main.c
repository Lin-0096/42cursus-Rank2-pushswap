/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 11:37:56 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr;
	t_stack	a;

	init_stack(&a);
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (1);
		if (!build_stack_from_args(&a, arr))
		{
			write(2, "Error\n", 6);
			ft_free_arr(arr);
			free_stack(&a);
			return (1);
		}
		ft_free_arr(arr);
	}
	else
	{
		if (!build_stack_from_args(&a, argv + 1))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			return (1);
		}
	}
	print_stack(&a);
	free_stack(&a);
	return (0);
}
