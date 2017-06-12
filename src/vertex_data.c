/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:14:38 by k3ungy            #+#    #+#             */
/*   Updated: 2017/06/12 19:19:25 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void			vertex_data_init(GLuint *vbo, GLuint *ebo)
{
	GLfloat vertices[] =
	{	//Vertices				//Colors			//texture coords
		-0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,		//top right
		 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	0.0f, 1.0f,		//top left
		 0.5f,  0.5f, 0.0f,		1.0f, 0.0f, 1.0f,	0.0f, 0.0f,		//bottom right
		-0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f,	1.0f, 0.0f		//bottom left
	};
	GLint	data_index[] =
	{
		0, 4, 6,
		2, 4, 0
	};
	glGenBuffers(1, vbo);
	glGenBuffers(1, ebo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(data_index),
	data_index, GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
