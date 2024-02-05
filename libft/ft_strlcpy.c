/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:14:13 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:28 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	wrd1[] = "alles";
// 	char	wrd2[] = "kan kapot";
// 	char	wrd3[] = "alles";
// 	char	wrd4[] = "kan kapot";
// 	int t = 8;
// 	ft_strlcpy(wrd1, wrd2, t);
// 	strlcpy(wrd3, wrd4, t);

// 	printf("\nzelf:\n%s\n%s\n\nfunctie:\n%s\n%s\n\n", wrd1, wrd2, wrd3, wrd4);

// 	return 0;
// }
