/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:32:25 by linliu            #+#    #+#             */
/*   Updated: 2025/06/16 22:43:41 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_insert_pos(t_stack *a, t_node *node)
{
	int		pos;
	t_node	*cur;

	if (!a->top)
		return (0);
	pos = 0;
	cur = a->top;
	while(cur && node->data > cur->data)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}
