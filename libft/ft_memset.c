/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:13:08 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:22:58 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = b;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	char wrd1[] = "ALLES KAN KAPOT";
// 	char wrd2[] = "ALLES KAN KAPOT";

// 	ft_memset(wrd1, 'z', 10);
// 	memset(wrd2, 'z', 10);
// 	printf("eig: %s\norg: %s\n", wrd1, wrd2);
// }