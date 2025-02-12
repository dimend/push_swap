/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:26 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/29 16:26:57 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_delimiter(const char *input, const char delimiter)
{
	size_t	len;

	len = 0;
	while (input[len] != '\0')
	{
		if (input[len] == delimiter)
		{
			len++;
			break ;
		}
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src, const char delimiter, short flag)
{
	char	*dupe;
	size_t	size;
	size_t	i;

	if (src == NULL)
		return (NULL);
	else
		size = ft_strlen_delimiter(src, delimiter);
	dupe = malloc(size + 1);
	if (!dupe)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dupe[i] = src[i];
		i++;
	}
	dupe[i] = '\0';
	if (flag == 1)
		free(src);
	return (dupe);
}

char	*newstrcat(char *alldata, const char *grabdata, size_t dest, size_t src)
{
	char	*newdata;
	size_t	i;

	newdata = NULL;
	i = 0;
	newdata = malloc(dest + src + 1);
	if (!newdata)
		return (NULL);
	while (i < dest)
	{
		newdata[i] = alldata[i];
		i++;
	}
	i = 0;
	while (i < src)
	{
		newdata[dest + i] = grabdata[i];
		i++;
	}
	newdata[dest + src] = '\0';
	free(alldata);
	return (newdata);
}

char	*ft_new_strlcat(char *alldata, const char *grabdata)
{
	size_t	src_len;
	size_t	dest_len;
	char	*newdata;

	src_len = 0;
	dest_len = 0;
	newdata = NULL;
	if (alldata != NULL)
		dest_len = ft_strlen_delimiter(alldata, '\0');
	if (grabdata != NULL)
		src_len = ft_strlen_delimiter(grabdata, '\0');
	newdata = newstrcat(alldata, grabdata, dest_len, src_len);
	return (newdata);
}

char	*putstr_nlpos(char *s, char **remains)
{
	char	*ret;
	size_t	size;

	ret = NULL;
	size = ft_strlen_delimiter(s, '\n');
	if (s[size - 1] == '\n')
	{
		ret = ft_strdup(s, '\n', 0);
		*remains = ft_strdup(s + size, '\0', 0);
	}
	else if (s[size] == '\0')
	{
		ret = ft_strdup(s, '\0', 0);
		*remains = ft_strdup("", '\0', 0);
	}
	free(s);
	return (ret);
}
