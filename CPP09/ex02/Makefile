#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesille <adesille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 11:33:14 by adesille          #+#    #+#              #
#    Updated: 2025/04/16 12:52:32 by adesille         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

######################## ARGUMENTS ########################

NAME = PMergeMe 
CFLAGS += -Wall -Wextra -Werror -std=c++98 -g3
CXX = c++

DEFAULT = \033[0;39m
BLUE = \033[0;34m
DARK_GREEN =\033[0;3;32m
RED = \033[31;1m
WHITE = \033[0;37m
YELLOW = \033[0;33m

######################## SOURCES ########################

SRCS = ./main.cpp ./PMergeMe.cpp
OBJD_DIR = .obj
OBJS = $(SRCS:%.cpp=$(OBJD_DIR)/%.o)

######################## RULES ########################

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJD_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	@if [ ! -z "$(wildcard .obj/*.o)" ]; then \
		echo "$(YELLOW)\nCompiling files...$(DEFAULT)"; \
	fi
	@$(CXX) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJD_DIR)
	@echo "$(DARK_GREEN)\nEvery files are cleaned$(DEFAULT)"

fclean : clean
	@rm -f $(NAME)

re : fclean all

x : all 
	@./$(NAME)

.PHONY : all clean fclean re
