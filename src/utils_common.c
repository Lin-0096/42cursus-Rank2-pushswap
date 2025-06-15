/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linliu <linliu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 00:09:05 by linliu            #+#    #+#             */
/*   Updated: 2025/06/15 22:32:16 by linliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	if (!stack)
		return ;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

//for debug!!
void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size == 0)
	{
		printf("empty stack\n");
		return ;
	}
	//printf("size=%i\n", stack->size);
	current = stack->top;
	while (current)
	{
		printf("->%d", current->data);
		current = current->next;
	}
	printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*next;

	if (!stack || stack->size == 0)
		return ;
	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

/*int	main(void)
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
	free(n1);
	free(n2);
	free_stack(&a);
}*/
