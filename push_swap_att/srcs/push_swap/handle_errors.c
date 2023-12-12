/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:06:52 by resilva           #+#    #+#             */
/*   Updated: 2023/12/08 19:11:51 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	free(current);
	*stack = NULL;
}

void	free_av(char **av)
{
	int	i;

	if (!av || !(*av))
		return ;
	i = -1;
	while (av[i])
		free(av[i++]);
	free(av - 1);
}

void	free_errors(t_stack_node **a, char **av, int ac)
{
	if (ac == 2 && av[1])
		free_av(av);
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

// int	check_syntax(char **av)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	j = 0;
// 	while (av[i])
// 	{
// 		if (!(av[i][j] == '+' || av[i][j] == '-' || (av[i][j] >= '0' && av[i][j] <= '9')))
// 			return (1);
// 		if ((av[i][j] == '+' || av[i][j] == '-') && !(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
// 			return (1);
// 		while (av[i][j])
// 		{
// 			if (!(av[i][j] >= '0' && av[i][j++] <= '9'))
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
