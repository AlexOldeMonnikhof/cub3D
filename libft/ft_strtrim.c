/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:59:00 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:20:54 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count_bgn;
	size_t	count_end;
	char	*str;

	i = 0;
	count_bgn = 0;
	count_end = 0;
	if (s1[i])
	{
		while (ft_check_set(s1[i++], set))
			count_bgn++;
		i = ft_strlen(s1) - 1;
		while (ft_check_set(s1[i--], set))
			count_end++;
	}
	str = ft_substr(s1, count_bgn, ft_strlen(s1) - count_bgn - count_end);
	if (!str)
		return (0);
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "[];hallo;";
// 	char	set[] = ";][";
// 	ft_strtrim(str, set);
// }