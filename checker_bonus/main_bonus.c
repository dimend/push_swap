/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:36:09 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 17:02:05 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "utils/gnl/get_next_line_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

void	execute_command(char *command, t_list **a, t_list **b)
{
	if (ft_strncmp(command, "sa", 2) == 0)
		swapfirsttwo(a);
	else if (ft_strncmp(command, "sb", 2) == 0)
		swapfirsttwo(b);
	else if (ft_strncmp(command, "pa", 2) == 0)
		pushfirst(b, a);
	else if (ft_strncmp(command, "pb", 2) == 0)
		pushfirst(a, b);
	else if (ft_strncmp(command, "ra", 2) == 0)
		rotatelist(a, 0);
	else if (ft_strncmp(command, "rb", 2) == 0)
		rotatelist(b, 0);
	else if (ft_strncmp(command, "rra", 3) == 0)
		rotatelist(a, 1);
	else if (ft_strncmp(command, "rrb", 3) == 0)
		rotatelist(b, 1);
	else if (ft_strncmp(command, "rr", 2) == 0)
		rotate_both(a, b, 0);
	else if (ft_strncmp(command, "rrr", 3) == 0)
		rotate_both(a, b, 1);
}

void	free_all(t_list **a, t_list **b, char *args, char *command)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(args);
}

int	main(int argC, char *argV[])
{
	t_list	*a;
	t_list	*b;
	char	*args_str;
	char	*command;

	a = NULL;
	b = NULL;
	args_str = concat_args(argV, argC);
	if (validate_args(args_str) == 1 || initialize_list(args_str, &a) == 1)
		write(1, "Error\n", 7);
	else
	{
		command = get_next_line(0);
		while (command != NULL)
		{
			execute_command(command, &a, &b);
			command = get_next_line(0);
		}
		if (is_sorted(a) && b == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_all(&a, &b, args_str, command);
	return (0);
}
