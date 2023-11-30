/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:48:25 by resilva           #+#    #+#             */
/*   Updated: 2023/11/29 02:18:39 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_push;

	if (!(*src))
		return ;
	node_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_push->prev = NULL;
	if (!(*dest))
	{
		*dest = node_push;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = node_push;
		node_push->next = *dest;
		*dest = node_push;
	}	
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if (!check)
		write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool check)
{
	push(b, a);
	if (!check)
		write (1, "pb\n", 3);
}
