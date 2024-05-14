# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 16:24:07 by apetitco          #+#    #+#              #
#    Updated: 2024/05/14 17:41:28 by apetitco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############
## COLORS ##
############

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

###############
## VARIABLES ##
###############

NAME	=	push_swap
CC		=	gcc
IFLAGS	=	-Iinclude -Ift_printf/Libft/include -Ift_printf/include
LDFLAGS	=	-Lft_printf -lftprintf
CFLAGS	=	-Wall -Wextra -Werror $(IFLAGS)
SRC_DIR	=	src
BUILD_DIR	=	build

#############
## SOURCES ##
#############

SRC			=	$(wildcard $(SRC_DIR)/*.c)
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))


###########
## BONUS ##
###########

#############
## RECIPES ##
#############

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) -g3 $(CFLAGS) -c $< -o $@

all: $(NAME)

ft_printf/libftprintf.a:
	@make -C ft_printf

$(NAME): ${OBJ} ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)$(NAME) has been created$(DEF_COLOR)"

clean:
	@make clean -C ft_printf
	@rm -rf $(BUILD_DIR)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re