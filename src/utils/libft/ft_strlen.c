/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:53 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:22 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *input)
{
	size_t	len;

	len = 0;
	while (*input != '\0')
	{
		len++;
		input++;
	}
	return (len);
}
