/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:38:18 by resilva           #+#    #+#             */
/*   Updated: 2023/11/29 02:20:21 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*last;

	len = stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	ra(t_stack_node **a, bool check)
{
	reverse_rotate(a);
	if (!check)
		write (1, "rra\n", 4);
}

void	rb(t_stack_node **b, bool check)
{
	reverse_rotate(b);
	if (!check)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!check)
		write (1, "rrr\n", 4);
}