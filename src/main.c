/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 00:23:38 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**arr;
	t_stack	a;

	init_stack(&a);
	if(argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (0);
		bulid_stack_from_args(&a, arr);
	}
	else
		bulid_stack_from_args(&a, argv + 1);
	print_stack(&a);
	free_stack(&a);
}
