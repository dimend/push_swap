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
void	small_sort(t_list **stack);

#endif
