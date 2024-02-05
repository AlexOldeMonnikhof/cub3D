/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:11:28 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/17 16:18:49 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char c1 = 'Q';
// 	char c2 = ']';

// 	printf("\neig:\n%d, %d\n", ft_isalpha(c1), ft_isalpha(c2));
// 	printf("\norg:\n%d, %d\n", isalpha(c1), isalpha(c2));
// }