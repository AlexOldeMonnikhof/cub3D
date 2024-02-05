/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:47:31 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:23:17 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((s1[i] != s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char c1[] = "ÀÈÌÒ~";
// 	const char c2[] = "ÀÈÌÒÀ";
// 	int	s = 16;

// 	printf("%d\n", ft_strncmp(c1, c2, s));
// 	printf("%d\n", strncmp(c1, c2, s));
// }