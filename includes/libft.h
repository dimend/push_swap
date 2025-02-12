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
	int				content;
	int				index;
	int				closest;
	int				costtotop;
	int				reverse;
	struct s_list	*next;
}	t_list;

//Libft
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
size_t	ft_strlen(const char *input);
//Printf
int		ft_printf(const char *s, ...);
//Calculations
int		get_min_diff(t_list *a, t_list *b);
void	calc_costtotop(t_list *lst, int lstsize);
t_list 	*find_cheapest(t_list *a, t_list *b);
int is_avg(t_list *a);
//Push Swap Controls
void	swapfirsttwo(t_list **lst, char listname);
void	pushfirst(t_list **srclst, t_list **destlst, char listname);
void	rotatelist(t_list **srclst, short int direction, char listname);
void	rotate_both(t_list **a, t_list **b, short int direction);
//Push Swap
void 	initialize_list(char *args, t_list **a);
void 	set_closest(t_list *a, t_list *b);
void 	set_index(t_list *lst);
void 	set_costtotop(t_list *a, t_list *b);
void 	final_sort(t_list **a);
//Rotation handler
void 	rotate_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b);
void	send_to_top(t_list *node, t_list **stack, char listname);
//Sorting
short int	is_sorted(t_list *stack);
void	small_sort(t_list **stack);
void	sort_to_b(t_list **a, t_list **b);
void	sort_to_a(t_list **a, t_list **b);
//Validations
short int	check_duplicates(t_list *list);
short int validate_args(char *args_str);
char 	*ft_strtok(char *str, const char delim);
char *concat_args(char *argV[], int argC);

#endif
