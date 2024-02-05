/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:11:06 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:18:44 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c1 = '%';
// 	char c2 = ']';
// 	printf("eig: %d, %d\n", ft_isalnum(c1), ft_isalnum(c2));
// 	printf("org: %d, %d\n", isalnum(c1), isalnum(c2));
// }