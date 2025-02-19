/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:46:04 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 15:46:05 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				closest;
	int				costtotop;
	int				reverse;
	struct s_list	*next;
}					t_list;

// Libft
long				ft_atoi(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int content);
size_t				ft_strlen(const char *input);
// Push Swap
short int			initialize_list(char *args, t_list **a);
// Sorting
short int			is_sorted(t_list *stack);
// Push Swap Controls
void				swapfirsttwo(t_list **lst);
void				pushfirst(t_list **srclst, t_list **destlst);
void				rotatelist(t_list **srclst, short int direction);
void				rotate_both(t_list **a, t_list **b, short int direction);
// Validations
short int			check_duplicates(t_list *list);
short int			validate_args(char *args_str);
char				*ft_strtok(char *str, const char delim);
char				*concat_args(char *argV[], int argC);

#endif
