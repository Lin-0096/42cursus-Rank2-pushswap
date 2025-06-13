/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:24:53 by linliu            #+#    #+#             */
/*   Updated: 2025/06/13 11:47:42 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_digits(char *str, int *i, int sign, int *error)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i]<= '9')//pass in the address
	{
		result = result * 10 + (str[*i] - '0');
		if (result * sign < INT_MIN || result * sign > INT_MAX)
		{
			*error = 1;
			return (0);
		}
		(*i)++;
	}
	*error = 0;
	return ((int)(result * sign));
}

static int	read_number(char *str, int *error)
{
	int	result;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
		sign = -1;
	if (!str[i]) //check for both space and +-
	{
		*error = 1;
		return (0);
	}
	result = get_digits(str, &i, sign, error);
	if (*error == 1)
		return (0);
	if (str[i] != '\0')
	{
		*error = 1;
		return (0);
	}
	return (result);
}

static int	is_dup(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->data == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	build_stack_from_args(t_stack *a, char **argv)
{
	int		i;
	int		value;
	int		error;
	t_node	*node;

	i = 0;
	while (argv[i])
	{
		value = read_number(argv[i], &error);
		if (error)
			return (0);
		if (is_dup(a, value))
			return (0);
		node = create_node(value);
		if (!node)
			return (0);
		stack_push_bottom(a, node);
		i++;
	}
	return (1);
}
