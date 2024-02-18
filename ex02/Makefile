# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 10:24:30 by TheTerror         #+#    #+#              #
#    Updated: 2024/02/18 16:59:25 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = exe

OBJ_PATH = ./.obj/

INCLUDE = MutantStack.hpp MutantStack.tpp

CC = 				c++
CPPFLAGS =			-std=c++98
CFLAGS=				$(CPPFLAGS) -Wall -Werror -Wextra -g3
RM =				rm -rf

SRC = main.cpp

OBJ = $(SRC:%.cpp=$(OBJ_PATH)%.o)

all : $(NAME)

$(OBJ_PATH)%.o : %.cpp $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $@

run : all
	./$(NAME)

clean :
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_PATH)
fclean : clean
	@$(RM) $(NAME)
re : fclean all