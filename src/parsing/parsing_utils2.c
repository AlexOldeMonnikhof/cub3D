/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:31:16 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 15:35:27 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// Function declarations
void			skip_whitespace_and_sign(const char **str, int *sign);
long			convert_str_to_long(const char *str, int sign, char **endptr);
unsigned long	handle_overflow(unsigned long result, int digit, int sign);

void	skip_whitespace_and_sign(const char **str, int *sign)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
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
	unsigned long	result;
	int				digit;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = handle_overflow(result, digit, sign);
		if (result == ULONG_MAX)
			break ;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (sign * result);
}

unsigned long	handle_overflow(unsigned long result, int digit, int sign)
{
	if (result > ULONG_MAX / 10
		|| (result == ULONG_MAX / 10 && digit > ULONG_MAX % 10))
		return (ULONG_MAX);
	return (result * 10 + digit);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	int	sign;

	sign = 0;
	if (base != 10)
	{
		if (endptr)
			*endptr = (char *)str;
		return (0);
	}
	skip_whitespace_and_sign(&str, &sign);
	return (convert_str_to_long(str, sign, endptr));
}
