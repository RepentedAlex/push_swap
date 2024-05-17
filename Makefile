# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 16:24:07 by apetitco          #+#    #+#              #
#    Updated: 2024/05/17 12:06:10 by apetitco         ###   ########.fr        #
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

NAME		=	push_swap
CC			=	gcc
IFLAGS		=	-Iinclude -Ift_printf/Libft/include -Ift_printf/include
LDFLAGS		=	-Lft_printf -lftprintf
FFLAG		=	-fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS) $(FFLAG)
SRC_DIR		=	src/
BUILD_DIR	=	build/

#############
## SOURCES ##
#############


SRC_FILES	=	algo/algo_first \
				algo/algo_second \
				algo/algo_utils \
				algo/true_algo \
				operations/rotations_op \
				operations/translations_op \
				stack/stack_initializer \
				stack/stack_utils \
				statistics/med_qua \
				statistics/mq_calc \
				utilities/check_args \
				utilities/debug \
				push_swap
				
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(BUILD_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		= .cache_exists

###########
## BONUS ##
###########

#############
## RECIPES ##
#############

all: $(NAME)

$(NAME): $(OBJ) ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)$(NAME) has been created$(DEF_COLOR)"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@$(CC) -g3 $(CFLAGS) -c $< -o $@

$(OBJF):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(addprefix $(BUILD_DIR), $(dir $(SRC_FILES)))
	@touch $(OBJF)
	@echo "$(GREEN)Object directory created!$(DEF_COLOR)"

ft_printf/libftprintf.a:
	@make -C ft_printf

clean:
	@make clean -C ft_printf
	@rm -rf $(BUILD_DIR) $(OBJF)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re