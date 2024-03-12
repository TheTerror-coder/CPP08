# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:24:30 by TheTerror         #+#    #+#              #
#    Updated: 2024/03/12 15:49:21 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = exe

OBJ_PATH = ./.obj/

INCLUDE = Span.hpp

CC = 				c++
CPPFLAGS =			-std=c++98
CFLAGS=				$(CPPFLAGS) -Wall -Werror -Wextra
RM =				rm -rf

SRC = main.cpp Span.cpp

OBJ = $(SRC:%.cpp=$(OBJ_PATH)%.o)

all : $(NAME)

$(OBJ_PATH)%.o : %.cpp $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean :
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)
fclean : clean
	@$(RM) $(NAME)
re : fclean all