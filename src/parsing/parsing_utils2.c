/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:16 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/14 17:03:10 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

static void	skip_whitespace_and_sign(const char **str, int *sign)
{
	while (**str == ' ' || **str == '\n')
		(*str)++;
	*sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign = -1;
		(*str)++;
	}
}

long	convert_str_to_long(const char *str, int sign, char **endptr)
{
	int				digit;
	unsigned long	result;
	unsigned long	result_end;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = check_and_handle_overflow(result, digit);
		if (result == ULONG_MAX)
			break ;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	result_end = sign * result;
	return (result_end);
}

size_t	check_and_handle_overflow(unsigned long res, unsigned int d)
{
	size_t	return_value;

	if (res > ULONG_MAX / 10
		|| (res == ULONG_MAX / 10 && d > ULONG_MAX % 10))
		return (ULONG_MAX);
	return_value = res * 10 + d;
	return (return_value);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	int		sign;
	long	result;

	if (base != 10)
	{
		if (endptr != NULL)
			*endptr = (char *)str;
		return (0);
	}
	sign = 0;
	skip_whitespace_and_sign(&str, &sign);
	result = convert_str_to_long(str, sign, endptr);
	return (result);
}

int	check_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] < '0' || line[i] > '9')
		i++;
	while ((line[i] >= '0' && line[i] <= '9') || line[i] == ',')
	{
		if (line[i] == ' ')
			return (5);
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	return (5);
}
