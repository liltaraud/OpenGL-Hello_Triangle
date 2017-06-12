/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltaraud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:50:34 by ltaraud           #+#    #+#             */
/*   Updated: 2015/12/06 16:37:41 by ltaraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
	{
		str[ft_strlen(str) + 1] = '\0';
		while (str[i] != '\0')
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
