/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_compilation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:01 by k3ungy            #+#    #+#             */
/*   Updated: 2016/12/13 00:07:57 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		shader_compilation(GLuint *shader)
{
	GLint	compile_value;
	GLchar	info_log[512];

	glCompileShader(*shader);
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &compile_value);
	if (!compile_value)
	{
		glGetShaderInfoLog(*shader, 512, NULL, info_log);
		ft_putstr("Shader compilation failed !\n\n");
		ft_putstr(info_log);
		terminate(SHADER_BUILD_FAILURE, NULL);
	}
}
