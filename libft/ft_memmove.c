/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:05:43 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:17 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptr_dst;
	char	*ptr_src;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (!src && !dst)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			ptr_dst[len] = ptr_src[len];
		}
		return (dst);
	}
	while (i < len)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

// if (dst > src) because dst can be src + 1 and it will keep repeating itself.
// int	main(void)
// {

// 	char	src[] = "lorem ipsum dolor sit amet";
// 	char	*dest;

// 	dest = src + 1;
// 	// ptr1 = (char *)ft_memmove(((void *)0), ((void *)0), 5);
// 	// printf("%s\n", ptr1);
// 	// ptr2 = memmove(((void *)0), b, 5);
// 	// printf("%s\n", ptr2);
// }