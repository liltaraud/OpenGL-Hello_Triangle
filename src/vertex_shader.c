/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_shader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:37:37 by k3ungy            #+#    #+#             */
/*   Updated: 2017/01/06 18:01:15 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static const GLchar	*vertex_shader_src_get(void)
{
	GLchar	*vertex_shader_source ="#version 330 core\n"
	"layout (location = 0) in vec3 position;\n"
	"layout (location = 1) in vec3 color;\n"
	"layout (location = 2) in vec2 texture_in;\n"

	"out vec3	vcolor;\n"
	"out vec2	texture_coordinates;\n"

	"void main()\n"
	"{\n"
	"	vcolor = color;\n"
	"	gl_Position = vec4(position, 1.0f);\n"
	"	texture_coordinates = texture_in;\n"
	"}\0";

	return (vertex_shader_source);
}

void	vertex_shader_build(GLuint *vertex_shader)
{
	const GLchar *vertex_shader_source = vertex_shader_src_get();

	*vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertex_shader, 1, &vertex_shader_source, NULL);
	shader_compilation(vertex_shader);
}
