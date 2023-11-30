/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:03:21 by resilva           #+#    #+#             */
/*   Updated: 2023/11/29 01:36:42 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **stack)
{
	int	len;

	len = stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, bool check)
{
	swap(a);
	if (!check)
		write (1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool check)
{
	swap(b);
	if (!check)
		write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool check)
{
	swap(a);
	swap(b);
	if (!check)
		write (1, "ss\n", 3);
}