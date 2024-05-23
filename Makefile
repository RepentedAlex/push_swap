# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 16:24:07 by apetitco          #+#    #+#              #
#    Updated: 2024/05/23 14:03:29 by apetitco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############
## COLORS ##
############

DEF_COLOR	=	\033[0m
GRAY		=	\033[0;90m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
MAGENTA		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[0;97m

###############
## VARIABLES ##
###############

NAME		=	push_swap
CC			?=	cc
IFLAGS		=	-Iinclude -Ift_printf/Libft/include -Ift_printf/include
LDFLAGS		=	-Lft_printf -lftprintf
FFLAG		=	-fsanitize=address
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS) 
CFLAGS 		+=	$(FFLAG) 
CFLAGS 		+= 	-Weverything -Wno-padded -Wno-newline-eof -Wno-missing-prototypes -Wno-shorten-64-to-32 -Wno-sign-conversion
CFLAGS		+=	-MMD -MP
SRC_DIR		=	src/
BUILD_DIR	=	build/

#############
## SOURCES ##
#############


SRC_FILES	=	algo/algo_first \
				algo/algo_second \
				algo/algo_utils \
				algo/algo_utils_2 \
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
	@make -C ft_printf --no-print-directory

clean:
	@make clean -C ft_printf --no-print-directory
	@rm -rf $(BUILD_DIR) $(OBJF)

fclean: clean
	@make fclean -C ft_printf --no-print-directory
	@rm -f $(NAME)

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean re