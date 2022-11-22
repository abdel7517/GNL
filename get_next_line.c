/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:20:06 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/22 19:02:01 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (str == 0)
        return (0);
    while (str[i])
        i++;
    return (i);
}

// return length of buff before a \n + 1 to include \n
int count_before_new_line(char *buf)
{
    int i;

    i = 0;
    while (buf[i] && buf[i] != '\n')
        i++;
    if (buf[i] == '\n')
        i++;
    return (i);
}

void    fill_str(char *str, char *buf, char *end_buf)
{
    int i;
    int j;

    i = 0;
    j = 0;
    
    while (end_buf != 0 && end_buf[i])
    {
        str[i] = end_buf[i];
        i++;
    }
    while (buf[j] && buf[j] != '\n')
    {
        str[i] = buf[j];
        i++;
        j++;
    }
    if (buf[j] == '\n')
        str[i++] = '\n';
    str[i] = 0;
}
void    fill_end_buff(char *end_buf, char *buf, int len_buf)
{
    int i;

    i = 0;
    while (buf[len_buf])
    {
        end_buf[i] = buf[len_buf];
        len_buf++;
        i++;
    }
    end_buf[i] = 0;
}
char	*get_next_line(int fd)
{
    int count;
    char    buf[BUFFER_SIZE+1];
    char    *str;
    static char *end_buf;    
    int     len_buf;
    int     len_end_buf;
    static int  end;
    
    count = read(fd, buf, BUFFER_SIZE);
    buf[count] = '\0';
    // printf("buff = %s| \n", buf);
     if (count <= 0)
     {
        if (ft_strlen(end_buf) && end == 0)
        {
            end = 1;
            return (end_buf);
        }
        return (NULL);
     }
    len_buf = count_before_new_line(buf);
    len_end_buf = ft_strlen(end_buf);
    str = malloc(sizeof(char) * (len_buf + len_end_buf + 1));
    fill_str(str, buf, end_buf);
    end_buf = malloc(sizeof(char) * (len_end_buf + 1));
    fill_end_buff(end_buf, buf, len_buf);
    printf("endbuf = |%s| \n", (buf + len_buf));
    return (str);
}