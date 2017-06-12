/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:58:35 by k3ungy            #+#    #+#             */
/*   Updated: 2017/06/12 19:19:06 by k3ungy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	intitialize_libs_and_window(t_ogl *g)
{
	if (!glfwInit())
    	terminate(GLFW_FAILURE, NULL);
	/*if (OSX)
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3.3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3.3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwSetErrorCallback(terminate);
	g->window = glfwCreateWindow(g->win_width, g->win_height, "OpenGL", NULL, NULL);
	if (!g->window)
		terminate(GLFW_FAILURE, NULL);
	glfwSetKeyCallback(g->window, key_callback);
	glfwGetFramebufferSize(g->window, &g->win_width, &g->win_height);
	glViewport(0, 0, g->win_width, g->win_height);
	/* Make the window's context current */
	glfwMakeContextCurrent(g->window);
	glfwSwapInterval(1);
	/* GLEW Initialization */
	glewExperimental = GL_TRUE;
	if ((glewInit()) != GLEW_OK)
		terminate(GLEW_FAILURE, NULL);
}

int         main(void)
{
	t_ogl			g;
	t_data_set		d1;
	GLuint			vertex_shader;
	GLuint			fragment_shader;
	GLuint			shader_prog;

	g.win_width = 1280;
	g.win_height = 720;
	intitialize_libs_and_window(&g);
	glGenVertexArrays(1, &d1.vao);
	glBindVertexArray(d1.vao);
	vertex_data_init(&d1.vbo, &d1.ebo);
	vertex_shader_build(&vertex_shader);
	fragment_shader_build(&fragment_shader);
	shader_program_build(&shader_prog ,&vertex_shader, &fragment_shader);
	vertex_array_build(12, 0, 3);
	while (!glfwWindowShouldClose(g.window))
	{
		glfwPollEvents();
		/* Render here */
		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shader_prog);

		glBindVertexArray(d1.vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		/* Swap front and back buffers */
		glfwSwapBuffers(g.window);
	}
	glfwTerminate();
	return 0;
}
