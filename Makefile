# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 19:05:26 by ybouddou          #+#    #+#              #
#    Updated: 2022/06/04 19:08:46 by ybouddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Containers
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp

INC =	vector.hpp\
		map.hpp\
		stack.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
