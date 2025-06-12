/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:17:57 by linliu            #+#    #+#             */
/*   Updated: 2025/06/12 17:02:31 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(void)
{
	t_stack a;
	init_stack(&a);

	stack_push_top(&a, 2);
	stack_push_bottom(&a, 3);
	print_stack(&a);
	t_node *n1 = pop_top(&a);
	t_node *n2 = pop_bottom(&a);

	printf("n1: %i\n", n1->data);
	printf("n2: %i\n", n2->data);
}
