/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:16:59 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:12 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	if (ptr1[i] == 0 && ptr2[i] == 0)
	{
		if (n == 0)
			return (0);
		i++;
	}
	while (ptr1[i] == ptr2[i] && i + 1 < n)
		i++;
	return (((unsigned char)(ptr1[i]) - (unsigned char)(ptr2[i])));
}

// int	main(void)
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	printf("%d\n", ft_memcmp(s2, s3, 4));
// 	printf("%d\n", memcmp(s2, s3, 4));
// }