/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:10:46 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:09 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char c1[] = "water";
// 	const char c2 = '\0';
// 	int len = 6;
// 	char *ptr1 = memchr(c1, c2, len);
// 	printf("%s\n", ptr1);
// 	char *ptr2 = memchr(c1, c2, len);
// 	printf("%s\n", ptr2);
// }