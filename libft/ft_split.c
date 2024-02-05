/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:57:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2022/11/20 14:10:16 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	ft_wrd_count(const char *s, char c)
{
	size_t	wrd_count;
	size_t	i;

	wrd_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			wrd_count++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (wrd_count);
}

static char	**ft_make_arr(char **str, char const *s, char c, size_t wrd_count)
{
	size_t	wrd_len;
	size_t	i;

	i = 0;
	while (i < wrd_count)
	{
		wrd_len = 0;
		while (*s == c)
			s++;
		while (s[wrd_len] != c && s[wrd_len])
			wrd_len++;
		str[i] = ft_substr(s, 0, wrd_len);
		if (!str[i])
		{
			ft_free(str);
			return (NULL);
		}
		s += wrd_len;
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char	const *s, char c)
{
	char	**str;
	size_t	wrd_count;

	if (!s)
		return (NULL);
	wrd_count = ft_wrd_count(s, c);
	str = (char **)malloc((wrd_count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_make_arr(str, s, c, wrd_count);
	return (str);
}

// int	main(void)
// {
// 	char	s[] = "asdiasdiu";
// 	char	c = '\0';
// 	char	**str = ft_split(s, c);
// 	printf("%s\n", str[1]);
// }