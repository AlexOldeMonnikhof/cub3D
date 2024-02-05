/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:28:33 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:15 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dst;
	char	*ptr_src;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// 	char *ptr1 = memcpy(((void *)0), ((void *)0), 3);
// 	char *ptr2 = ft_memcpy(((void *)0), ((void *)0), 3);
// 	printf("%s\n", ptr1);
// 	printf("%s\n", ptr2);
// }