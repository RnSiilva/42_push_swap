/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 01:31:53 by resilva           #+#    #+#             */
/*   Updated: 2023/12/13 02:12:41 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// static void	set_cheapest(t_stack_node *stack)
// {
// 	long			cheapest_value;
// 	t_stack_node	*cheapest_node;

// 	if (!stack)
// 		return ;
// 	cheapest_value = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->push_cost < cheapest_value)
// 		{
// 			cheapest_value = stack->push_cost;
// 			cheapest_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	cheapest_node->cheapest = true;
// }

static void	cost_analysis(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - b->index;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - b->target_node->index;
		b = b->next;
	}
}

// static void	set_target_a(t_stack_node *a, t_stack_node *b)
// {
// 	t_stack_node	*current_b;	
// 	t_stack_node	*target_node;
// 	long			best_match_index;

// 	while (a)
// 	{
// 		best_match_index = LONG_MIN;
// 		current_b = b;
// 		while (current_b)
// 		{
// 			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
// 			{
// 				best_match_index = current_b->nbr;
// 				target_node = current_b;
// 			}
// 			current_b = current_b->next;
// 		}
// 		if (best_match_index == LONG_MIN)
// 			a->target_node = find_max(b);
// 		else
// 			a->target_node = target_node;
// 		a = a->next;
// 	}
// }

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
	cost_analysis(a, b);
	// set_cheapest(a);
}
