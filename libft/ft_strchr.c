/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:56:01 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:12 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!(char)c)
		return ((char *)s + ft_strlen(s));
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char ch = 'e';
// 	char wrd[] = "wat gaan we doen";
// 	printf("%s\n", ft_strchr(wrd, ch));
// 	printf("%s\n", strchr(wrd, ch));
// }