#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesille <adesille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 11:33:14 by adesille          #+#    #+#              #
#    Updated: 2025/01/31 06:23:58 by adesille         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

######################## ARGUMENTS ########################

NAME = megaphone 
CFLAGS += -Wall -Wextra -Werror -std=c++98
CXX = c++

DEFAULT = \033[0;39m
BLUE = \033[0;34m
DARK_GREEN =\033[0;3;32m
RED = \033[31;1m
WHITE = \033[0;37m
YELLOW = \033[0;33m

######################## SOURCES ########################

SRCS = ./Megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

######################## RULES ########################

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)
	@echo "$(DARK_GREEN)\nEvery files are cleaned$(DEFAULT)"

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
