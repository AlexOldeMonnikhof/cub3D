/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:12:44 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:19:04 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_counter(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		count++;
	}
	if (n < 0)
		count++;
	return (count);
}

static	long int	ft_make_n_long(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int	ft_polarity(long int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	size_t	count;
	size_t	n_long;
	size_t	polarity;
	char	*str;

	count = ft_counter(n);
	polarity = ft_polarity(n);
	n_long = ft_make_n_long(n);
	str = (char *)malloc(count * sizeof(char) + 1);
	if (!str)
		return (0);
	str[count] = 0;
	if (n_long == 0)
		str[0] = '0';
	while (count > 0)
	{
		str[count - 1] = n_long % 10 + '0';
		n_long /= 10;
		count--;
	}
	if (polarity)
		str[count] = '-';
	return (str);
}

// int	main(void)
// {
// 	int n = 2147483647;
// 	printf("%s", ft_itoa(n));
// }