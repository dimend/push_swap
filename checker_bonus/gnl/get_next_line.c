/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:26:24 by dimendon          #+#    #+#             */
/*   Updated: 2024/12/04 14:00:43 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	findnl(char *alldata)
{
	size_t	nl;

	nl = 0;
	while (alldata[nl])
	{
		if (alldata[nl] == '\n' || alldata[nl] == '\0')
			return (1);
		nl++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		grabdata[BUFFER_SIZE];
	static char	*alldata[2];
	ssize_t		bytes_read;

	if (fd < 0)
		return (NULL);
	bytes_read = 0;
	if (alldata[1] != NULL)
		alldata[0] = ft_strdup(alldata[1], '\0', 1);
	while (1)
	{
		bytes_read = read(fd, grabdata, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		grabdata[bytes_read] = '\0';
		alldata[0] = ft_new_strlcat(alldata[0], grabdata);
		if (findnl(alldata[0]))
			break ;
	}
	if (alldata[0] && alldata[0][0] != '\0')
		return (putstr_nlpos(alldata[0], &alldata[1]));
	free(*alldata);
	return (NULL);
}
