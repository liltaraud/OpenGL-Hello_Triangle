/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:02:31 by k3ungy            #+#    #+#             */
/*   Updated: 2017/06/12 19:18:41 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# define GLEW_STATIC
# define OP_SUCCESS 1
# define OP_FAILURE -1
# define SHADER_BUILD_FAILURE -2
# define LIBRARY_FAILURE -3
# define GRAPHICS_LOOP_FAILURE -4
# define ERROR_CALLBACK_FAILURE -5
# define GLFW_FAILURE -6
# define GLEW_FAILURE -7
# define UNIFORM_ADDRESS_GET_FAILURE -8
# define SOIL_TEXTURE_LOADING_ERROR -9
# include <stdio.h>
# include <stdlib.h>
# include <GL/glew.h>
# include "glfw3.h"
# include "libft.h"
# include "kazmath.h"
# include "SOIL.h"

typedef struct		s_data_set
{
	GLuint			vao;
	GLuint			vbo;
	GLuint			ebo;
}					t_data_set;

typedef struct		s_ogl
{
	GLFWwindow		*window;
	int				win_height;
	int				win_width;
}					t_ogl;

int					main(void);
void				key_callback(GLFWwindow *w, int key, int scancode, int action, int mod);
void				vertex_data_init(GLuint *vbo, GLuint *ebo);
void				shader_program_build(GLuint *shader_prog, GLuint *vertex_shader, GLuint *fragment_shader);
void				shader_compilation(GLuint *shader);
void				vertex_shader_build(GLuint *vertex_shader);
void				vertex_array_build(const int data_size, const int vao_index_attribute, const int vec_component_number);
void				fragment_shader_build(GLuint *fragment_shader);
void				terminate(int error_type, const char *description);

#endif
