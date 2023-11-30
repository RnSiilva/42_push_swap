/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:24:59 by resilva           #+#    #+#             */
/*   Updated: 2023/11/29 01:39:08 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*last;
	
	len = stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a, bool check)
{
	rotate(a);
	if (!check)
		write (1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool check)
{
	rotate(b);
	if (!check)
		write (1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool	check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write (1, "rr\n", 3);
}