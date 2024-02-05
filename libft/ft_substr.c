/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 22:51:58 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/16 14:42:06 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	count;

	i = 0;
	if (!len || !ft_strlen(s) || ft_strlen(s) <= start)
		count = 0;
	else if (len > ft_strlen(s) - start)
		count = ft_strlen(s) - start;
	else
		count = len;
	sub = ft_calloc(count + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (i < count && count)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

// int main()
// {
// 	char *str = "i just want this part #############";
//         size_t size = 3;

//         ft_substr("hola", 2, size);
// }