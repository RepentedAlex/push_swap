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
CFLAGS	=	-Wall -Wextra -Werror -ILibft/include -Iinclude -lft -LLibft -Ift_printf/include -lftprintf -Lft_printf

#############
## SOURCES ##
#############

SOURCES = ./ft_printf/src/ft_printf ./ft_printf/src/ft_print_hex ./ft_printf/src/ft_print_pointer ./ft_printf/src/ft_print_string ./ft_printf/src/ft_print_unsigned_num ./ft_printf/src/ft_utils ./Libft/src/ft_atoi ./Libft/src/ft_bzero ./Libft/src/ft_calloc ./Libft/src/ft_is/ft_isalnum ./Libft/src/ft_is/ft_isalpha ./Libft/src/ft_is/ft_isascii ./Libft/src/ft_is/ft_isdigit ./Libft/src/ft_is/ft_isprint ./Libft/src/ft_itoa ./Libft/src/ft_lst/ft_lstadd_front_bonus ./Libft/src/ft_lst/ft_lstclear_bonus ./Libft/src/ft_lst/ft_lstdelone_bonus ./Libft/src/ft_lst/ft_lstsize_bonus ./Libft/src/ft_mem/ft_memchr ./Libft/src/ft_mem/ft_memcmp ./Libft/src/ft_mem/ft_memcpy ./Libft/src/ft_mem/ft_memmove ./Libft/src/ft_mem/ft_memset ./Libft/src/ft_put/ft_putchar_fd ./Libft/src/ft_put/ft_putendl_fd ./Libft/src/ft_put/ft_putnbr_fd ./Libft/src/ft_put/ft_putstr_fd ./Libft/src/ft_split ./Libft/src/ft_str/ft_strchr ./Libft/src/ft_str/ft_strdup ./Libft/src/ft_str/ft_striteri ./Libft/src/ft_str/ft_strjoin ./Libft/src/ft_str/ft_strlcat ./Libft/src/ft_str/ft_strlcpy ./Libft/src/ft_str/ft_strlen ./Libft/src/ft_str/ft_strmapi ./Libft/src/ft_str/ft_strncmp ./Libft/src/ft_str/ft_strnstr ./Libft/src/ft_str/ft_strrchr ./Libft/src/ft_str/ft_strtrim ./Libft/src/ft_str/ft_substr ./Libft/src/ft_to/ft_tolower ./Libft/src/ft_to/ft_toupper ./src/main ./src/parsing ./src/stacks ./src/utilities

SRC			=	$(addsuffix .c, $(SOURCES))
OBJ			=	$(addsuffix .o, $(SOURCES))


###########
## BONUS ##
###########

#############
## RECIPES ##
#############
	
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) ${OBJ} -o push_swap