/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:12:19 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:18:59 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c1 = '%';
// 	char c2 = '3';
// 	printf("eig: %d, %d\n", ft_isdigit(c1), ft_isdigit(c2));
// 	printf("org: %d, %d\n", isdigit(c1), isdigit(c2));
// }