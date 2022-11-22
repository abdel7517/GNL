/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:11:40 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/22 15:09:35 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i_to_find;
	int	to_find_l;

	i = 0;
	i_to_find = 0;
	to_find_l = ft_strlen(to_find);
	if (*to_find == 0)
		return (str);
	while (str[i])
	{	
		while (str[i] == to_find[i_to_find])
		{
			if (i_to_find == (to_find_l - 1))
			{
				return (str + (i - i_to_find));
			}
			i_to_find++;
			i++;
		}
		i = i - i_to_find;
		i++;
		i_to_find = 0;
	}	
	return (0);
}