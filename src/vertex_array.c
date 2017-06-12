/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:17:23 by k3ungy            #+#    #+#             */
/*   Updated: 2017/01/06 17:51:47 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void		vertex_array_build(const int data_size,
			const int vao_index_attribute, /*GLint offset,*/
			const int vec_component_number)
{
	glVertexAttribPointer(vao_index_attribute, vec_component_number,
	GL_FLOAT, GL_FALSE, data_size * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(vao_index_attribute);
	glVertexAttribPointer(1, vec_component_number, GL_FLOAT,
	GL_FALSE, data_size * sizeof(GL_FLOAT), (GLvoid *)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid *)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0);
}
