/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 11:05:25 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*ft_strjoin_gnl(char *line, char *buff)
{
	char	*new_str;
	size_t	new_str_length;
	size_t	i;
	size_t	j;

	new_str_length = ft_strlen(line) + ft_strlen(buff);
	new_str = (char *)malloc((new_str_length + 1) * sizeof(char));
	if (!new_str)
		return (free(line), NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		new_str[i] = line[i];
		i++;
	}
	while (buff[j])
		new_str[i++] = buff[j++];
	new_str[new_str_length] = '\0';
	return (free(line), new_str);
}

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}