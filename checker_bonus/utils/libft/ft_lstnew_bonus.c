/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:45:53 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/17 15:30:31 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->content = content;
	p->index = 0;
	p->closest = 0;
	p->costtotop = 0;
	p->reverse = 0;
	p->next = NULL;
	return (p);
}
