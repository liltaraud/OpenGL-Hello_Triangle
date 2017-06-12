# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltaraud <ltaraud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 16:17:39 by ltaraud           #+#    #+#              #
#    Updated: 2017/01/10 14:45:06 by k3ungy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# To link .so library:
# flags= -L /path_to_library -Wl,-rpath=/path_to_library -lft
#

NAME = libSOIL.so
SRC_PATH = src
OBJ_PATH = obj
SRCS =	image_helper.c\
		SOIL.c\
		stb_image_aug.c\
		image_DXT.c\

HEADER = SOIL.h

OBJS = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJS))
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))
CC = gcc
INC = $(addprefix $(SRC_PATH)/,$(HEADER))
CFLAGS =  -fpic

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) -c $< -o $@ $(CFLAGS) -I$(SRC_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

clean:
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all
