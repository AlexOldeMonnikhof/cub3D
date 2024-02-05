/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:14:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:49 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)s + ft_strlen(s));
	if (!s)
		return (0);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// int main(void)fq
// {
// 	const char c1[] = "";
// 	char c2 = 'e';
// 	printf("%s\n", ft_strrchr(c1, c2));
// 	printf("%s\n", strrchr(c1, c2));
// }