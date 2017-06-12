/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltaraud <ltaraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:35:48 by ltaraud           #+#    #+#             */
/*   Updated: 2016/05/30 17:59:34 by ltaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <unistd.h>
# include "stdlib.h"

# define BUFF_SIZE 500

int					get_next_line(int const fd, char **line);

typedef struct		s_gnl
{
	int				fd;
	char			*stock;
	int				ret;
	struct s_gnl	*next;
}					t_gnl;

#endif
