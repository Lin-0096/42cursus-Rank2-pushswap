/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/17 19:57:03 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr;
	int		min_pos;
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == ' ')
		{
			write(2, "Error\n", 6);
			return (1);
		}
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
	if (a.size == 2)
		sort_2(&a);
	else if (a.size == 3)
		sort_3(&a);
	else if (a.size == 4 || a.size == 5)
		sort_4_5(&a, &b);
	else
		sort_large(&a, &b);
	while (!is_sorted(&a))
	{
		min_pos = get_pos(&a, find_min(&a)->data);
		if (min_pos == -1)
			exit_error(&a ,&b);
		rot_to_top(&a, min_pos);
	}
	//print_stack(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
