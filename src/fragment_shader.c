/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment_shader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 23:36:50 by k3ungy            #+#    #+#             */
/*   Updated: 2017/06/12 19:22:03 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static const GLchar	*fragment_shader_src_get(void)
{
	GLchar	*fragment_shader_source ="#version 330 core\n"
	"in		vec3	vcolor;\n"

	"out	vec4	color;\n"
	"void main()\n"
	"{\n"
	"	color = vec4(vcolor, 1.0);\n"
	"}\0";

	return (fragment_shader_source);
}

void	fragment_shader_build(GLuint *fragment_shader)
{
	const GLchar *fragment_shader_source = fragment_shader_src_get();

	*fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(*fragment_shader, 1, &fragment_shader_source, NULL);
	shader_compilation(fragment_shader);
}
