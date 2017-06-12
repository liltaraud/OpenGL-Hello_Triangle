/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltaraud <ltaraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:09:11 by ltaraud           #+#    #+#             */
/*   Updated: 2016/06/02 03:56:24 by ltaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*manipulate_struct(int fd, t_gnl *prv)
{
	t_gnl			*new;

	new = NULL;
	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->stock = NULL;
	new->fd = fd;
	new->ret = 1;
	new->next = NULL;
	if (prv != NULL)
		prv->next = new;
	return (new);
}

static t_gnl		*get_struct(t_gnl **data, int fd)
{
	t_gnl			*tmp;
	t_gnl			*prv;

	tmp = NULL;
	prv = NULL;
	if (*data == NULL)
	{
		*data = manipulate_struct(fd, NULL);
		return (*data);
	}
	tmp = *data;
	if (*data != NULL)
	{
		while (tmp != NULL && fd != tmp->fd)
		{
			prv = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			tmp = manipulate_struct(fd, prv);
	}
	return (tmp);
}

static int			fill_stock(t_gnl *cur)
{
	char			reader[BUFF_SIZE + 1];
	char			*tmp;

	tmp = NULL;
	ft_bzero(reader, BUFF_SIZE + 1);
	if (ft_strchr(cur->stock, '\n'))
		return (1);
	while (!ft_strchr(reader, '\n') && cur->ret != -1 && cur->ret != 0)
	{
		ft_bzero(reader, BUFF_SIZE + 1);
		cur->ret = read(cur->fd, reader, BUFF_SIZE);
		if (cur->ret == -1)
			return (-1);
		if (!(tmp = ft_strjoin(cur->stock, reader)))
			return (-1);
		free(cur->stock);
		cur->stock = tmp;
	}
	if (cur->ret == 0 && *cur->stock == '\0')
	{
		cur->ret = 1;
		return (0);
	}
	return (1);
}

int					assign_to_line(t_gnl *cur, char **line)
{
	char			*chr;
	char			*tmp;

	chr = NULL;
	tmp = NULL;
	chr = ft_strchr(cur->stock, '\n');
	if (chr == NULL && cur->ret == 0)
	{
		*line = ft_strdup(cur->stock);
		cur->stock = NULL;
	}
	else
	{
		*line = ft_strsub(cur->stock, 0, (chr - cur->stock));
		tmp = ft_strsub(cur->stock, (chr - cur->stock) + 1,
		(ft_strlen(cur->stock) - (chr - cur->stock)));
		free(cur->stock);
		cur->stock = tmp;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*data;
	t_gnl			*cur;
	int				fillst_ret;

	if (fd < 0 || !line)
		return (-1);
	cur = get_struct(&data, fd);
	if (!cur)
		return (-1);
	if (cur->stock == NULL && cur->ret == 0)
	{
		cur->ret = 0;
		return (0);
	}
	fillst_ret = fill_stock(cur);
	if (cur->ret == -1)
		return (-1);
	if (fillst_ret == 0)
		return (0);
	return (assign_to_line(cur, line));
}
