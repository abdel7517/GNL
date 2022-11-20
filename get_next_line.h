/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchaban <abchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:14:28 by abchaban          #+#    #+#             */
/*   Updated: 2022/11/18 18:45:50 by abchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 65535
#endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char *get_next_line(int fd);

#endif