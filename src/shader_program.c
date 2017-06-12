/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:58:18 by k3ungy            #+#    #+#             */
/*   Updated: 2016/12/13 00:18:44 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"


void	shader_program_build(GLuint *shader_prog, GLuint *vertex_shader,
GLuint *fragment_shader)
{
	GLint	compile_value;
	GLchar	info_log[512];

	if ((*shader_prog = glCreateProgram()) == 0)
		terminate(SHADER_BUILD_FAILURE, NULL);
	glAttachShader(*shader_prog, *vertex_shader);
	glAttachShader(*shader_prog, *fragment_shader);
	glLinkProgram(*shader_prog);
	glGetProgramiv(*shader_prog, GL_LINK_STATUS, &compile_value);
	glDeleteShader(*vertex_shader);
	glDeleteShader(*fragment_shader);
	if (!compile_value)
	{
		glGetProgramInfoLog(*shader_prog, 512, NULL, info_log);
		ft_putstr("Shader program linking failed !\n\n");
		ft_putstr(info_log);
		terminate(SHADER_BUILD_FAILURE, NULL);
	}
}
