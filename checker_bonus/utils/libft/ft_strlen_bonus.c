/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:53 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/17 15:30:33 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../checker_bonus.h"

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
