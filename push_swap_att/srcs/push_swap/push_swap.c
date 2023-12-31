/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:01:52 by resilva           #+#    #+#             */
/*   Updated: 2023/12/08 17:56:17 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	if (s[i] == c)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if ((ac == 2 && !av[1][0]))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	if (ac == 2 && ft_strchr(av[1], ' '))
		av = ft_split(av[1], ' ');
	init_stack_a(&a, av + 1, ac);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
}

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1)
// 		return (1);
// 	// if ((ac == 2 && !av[1][0]))
// 	if ((ac == 2 && !av[1][0]) || (ac == 2 && check_syntax(av)))
// 	{
// 		write (2, "Error\n", 6);
// 		return (1);
// 	}
// 	else if (ac == 2 && ft_strchr(av[1], ' '))
// 		av = ft_split(av[1], ' ');
// 	init_stack_a(&a, av + 1);
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// }

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1)
// 		return (1);
// 	if (ac == 2 && !av[1][0])
// 	{
// 		write (2, "Error\n", 6);
// 		return (1);
// 	}
// 	else if (ac == 2)
// 	{
// 		if(!check_syntax(av[1]))
// 		 	return (1);
// 		av = ft_split(av[1], ' ');
// 	}
// 	init_stack_a(&a, av + 1);
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// }
