/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:18:27 by linliu            #+#    #+#             */
/*   Updated: 2025/06/19 14:40:05 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	read_from_argv(int argc, char **argv, t_stack *a, t_stack *b)
{
	char	**arr;

	if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == ' ')
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

static void	do_operations(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "sa\n",3))
		sa(a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(a,b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(a,b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(a,b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		rotate(a, 'a', 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rotate(b, 'b', 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		rev_rotate(a, 'a', 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rev_rotate(b, 'b', 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(a, b, 0);
	else
		exit_error(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*next_line;

	init_stack(&a);
	init_stack(&b);
	if (argc == 1)
		return (0);
	read_from_argv(argc, argv, &a, &b);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		do_operations(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(&a) && b.size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
