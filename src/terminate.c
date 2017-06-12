/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:10:52 by k3ungy            #+#    #+#             */
/*   Updated: 2017/01/06 17:14:33 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		terminate(int error_type, const char *description)
{
	if (description)
	{
		ft_putstr("An error occured ! ID = ");
		ft_putnbr(error_type);
		ft_putstr("\nDescription : ");
		ft_putstr(description);
	}
	else if (error_type == GLFW_FAILURE)
		ft_putstr("GLFW failed to do something !\n");
	else if (error_type == GLEW_FAILURE)
		ft_putstr("GLEW failed to initialize !\n");
	else if (error_type == UNIFORM_ADDRESS_GET_FAILURE)
		ft_putstr("Couldn't fetch a uniform's address !\n");
	else if (error_type == SOIL_TEXTURE_LOADING_ERROR)
		ft_putstr("SOIL encountered an error during a texture loading !\n");
	ft_putstr("\nProgram Terminated\n");
	glfwTerminate();
	exit(0);
}
