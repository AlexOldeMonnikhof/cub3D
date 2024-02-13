/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:57:27 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 11:03:49 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*make_output_line(char *raw_line);
char	*make_raw_line(char *line, char *buffer, int fd);
char	*make_leftover_line(char *return_line);
// utils
size_t	ft_strlen(const char *s);
char	*ft_strjoin_gnl(char *line, char *buff);
char	*ft_free(char **ptr);

#endif