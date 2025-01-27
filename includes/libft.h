/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:39:49 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/17 19:43:23 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct s_list
{
	int			content;
	int			index;
	int			closest;
	int			costtotop;
	int			reverse;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);
void	swapfirsttwo(t_list **lst, char listname);
void	pushfirst(t_list **srclst, t_list **destlst, char listname);
void	rotatelist(t_list **srclst, short int direction, char listname);
void	rotate_both(t_list **a, t_list **b, short int direction);
short int is_sorted(t_list *stack);
void	small_sort(t_list **stack);
void	sort_to_b(t_list **a, t_list **b);
void  	sort_to_a(t_list **a, t_list **b);
void	set_costtotop(t_list *a, t_list *b);
void	set_closest(t_list *a, t_list *b);
int    	find_cheapest(t_list *a, t_list *b);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
int		ft_printf(const char *s, ...);

#endif
