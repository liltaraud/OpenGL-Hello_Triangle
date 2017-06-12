# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: k3ungy <k3ungy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 14:59:50 by k3ungy            #+#    #+#              #
#    Updated: 2017/06/12 19:17:16 by k3ungy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UBUNTU = yes
DEBUG = yes
NAME = test
CC = gcc
INC_PATH = include

# LIBFT
LIB_NAME =	libft
LIBFT_INC_PATH = libft/include
LIBFT_LR_PATH = -L./libft  -Wl,-rpath=./libft

# KAZMATH
KAZMATH_PATH = kazmath/build
KAZMATH_INC_PATH = kazmath/kazmath
KAZMATH_L_PATH = -L./kazmath/build/kazmath

# GLFW
GLFW_INC_PATH = glfw/include/GLFW
GLFW_LR_PATH = -L./glfw/src -Wl,-rpath=./glfw/src/
GLFW_PATH = glfw

# GLEW
GLEW_R_PATH = -Wl,-rpath=/usr/lib64/

# SOIL
SOIL_INC_PATH = SOIL/src
SOIL_LIB_PATH = -L ./SOIL/

SRC_PATH = src
OBJ_PATH = obj
SRC_NAME =	main.c\
			key_callback.c\
			shader_compilation.c\
			shader_program.c\
			vertex_shader.c\
			vertex_data.c\
			vertex_array.c\
			fragment_shader.c\
			terminate.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIBS =	libft/libft.so\
		glfw/src/libglfw.so\
		kazmath/build/kazmath\

CPPFLAGS = -I./$(INC_PATH) -I./$(LIBFT_INC_PATH) -I./$(GLFW_INC_PATH) -I./$(KAZMATH_INC_PATH) -I./$(SOIL_INC_PATH)
CLFLAGS = $(GLFW_LR_PATH) $(LIBFT_LR_PATH) $(KAZMATH_L_PATH) $(GLEW_R_PATH) $(SOIL_LIB_PATH)

ifeq ($(DEBUG), yes)
		CFLAGS = -Wall -Werror -Wextra -g3
else
		CFLAGS = -Wall -Werror -Wextra
endif

ifeq ($(UBUNTU), yes)
		LINK_FLAGS = -lft -lglfw -lm -lGL -lGLU -lpthread -lX11 -lGLEW -lXrandr -lXi -lSOIL
#		-lmlx -L/usr/include/../lib/ -lXext -lX11 -lm
#		 /mlx/libmlx.a -I/libmlx/includes
else
		LINK_FLAGS = -lft -framework OpenGL -framework AppKit
endif

.PHONY: all clean fclean re norme

all: $(NAME)

ifeq ($(DEBUG), yes)
		@echo "\x1B[01;91m -------------------------[DEBUG MODE ACTIVATED]------------------------- \x1B]0m"
else
		@echo "\x1B[01;93m ------------------------[RELEASE MODE ACTIVATED]------------------------ \x1B]0m"
endif

$(NAME): $(OBJ) $(LIBS)
#	@echo "\x1B[01;93m [Compiling FDF] \x1B]0m"
	$(CC) $(OBJ) $(CLFLAGS) $(LINK_FLAGS) -o $(NAME)
#	@echo "\x1B[01;92m ->[COMPLETE] \n\x1B]0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

$(LIBS):
#	@echo "\x1B[01;93m \n[Compiling LIBFT] \x1B]0m"
	make -C $(LIB_NAME) all
	make -C $(GLFW_PATH) all
	make -C $(KAZMATH_PATH) all
#	@echo "\x1B[01;92m ->[COMPLETE]\n \x1B]0m"

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIB_NAME) clean
#	@echo "\x1B[01;92m [CLEANED !] \x1B]0m"

fclean: clean
	rm -fv $(NAME)
	make -C $(LIB_NAME) fclean
	make -C $(GLFW_PATH) clean
	make -C $(KAZMATH_PATH) clean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h
