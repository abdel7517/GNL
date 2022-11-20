/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:31 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/20 13:26:27 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	get_len_before_new_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == 0)
			break ;
		i++;
	}
	return (i);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == 0)
			break ;
		i++;
	}
	return (i);
}

// fill str with buf as long as the line or the file isn t finish
void	fill_str(char *buf, char *str, char *end_buf, int *i_end_last_buf)
{
	int	i;
	int	j;

	j = 0;
	i = 0;

	while (end_buf != 0 && end_buf[i])
	{
		str[i] = end_buf[i];
		i++;
	}
	while (buf[j] && buf != 0 )
	{
		if (buf[j] == '\n' || buf[j] == 0)
			break ;
		str[i] = buf[j];
		i++;
		j++;
	}
	str[i] = 0;
}

int	len_end_buf(char *buf, int len)
{
	int	i;

	i = 0;
	while (buf[len + i])
		i++;
	return (i);
}


// if we found new line before end of str, save the end of buff on end_buf
void	save_end_buf(int len, char *end_buf, char *buf)
{
	int	i;

	i = 0;
	if (BUFFER_SIZE < len)
		return ;
	len++;
	i = 0;
	while (buf[len + i])
	{
		end_buf[i] = buf[len + i];
		i++;
	}
	end_buf[i+1] = 0;
}

char	*get_next_line(int fd)
{
	static char	*end_buf;
	static int	i_end_last_buf;
	char		buf[8888];
	int			len;
	char		*str;

	read(fd, buf, BUFFER_SIZE);
	printf("buf = %s -- \n", buf);
	len = get_len_before_new_line(buf);
	str = malloc(sizeof(char) * (len + get_len(end_buf) + 1));
	fill_str(buf, str, end_buf, &i_end_last_buf);
	end_buf = malloc( sizeof(char) * ( len_end_buf(buf, len) + 1));
	save_end_buf(len, end_buf, buf);
	return (end_buf);
}
