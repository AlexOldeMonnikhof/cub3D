/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:14:23 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:46 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && ft_strlen(needle) + i <= len)
		{
			if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

// int	main(void) 
// {
// 	const char c1[] = "allemaal hakken";
// 	const char c2[] = "maa";
// 	size_t len = 10;

// 	printf("%s\n", ft_strnstr(c1, c2, len));
// 	printf("%s\n", strnstr(c1, c2, len));
// }