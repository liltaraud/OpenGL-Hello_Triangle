/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:50:44 by ltaraud           #+#    #+#             */
/*   Updated: 2015/12/08 22:19:48 by ltaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*p;

	p = (void *)malloc((sizeof(*p) * size));
	if (p != NULL)
		ft_memset((void *)p, '\0', size);
	return ((void *)(p));
}
