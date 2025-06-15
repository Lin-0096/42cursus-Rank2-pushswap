/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/15 23:25:40 by linliu           ###   ########.fr       */
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
		return (1);
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
			free_stack(&a); //always free it for safety, and because i check NULL in free, no need worry about free wrong stuff.
			return (1);
		}
	}
	print_stack(&a);
	sort_3(&a);
	print_stack(&a);
	free_stack(&a);
	return (0);
}
