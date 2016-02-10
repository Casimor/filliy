# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchevali <bchevali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/25 18:16:27 by bchevali          #+#    #+#              #
#    Updated: 2016/02/10 16:35:46 by bchevali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fillit

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes
OBJ_DIR				=	objs

LIBFT				=	ft
LIBFT_DIR			=	libft
LIBFT_NAME			=	$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/includes

COMPILER			=	gcc
CFLAGS				=	-g3 -O3 -Wall -Wextra -Werror -c \
						-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT)

SRC					=	main.c				\
						fillit.c			\
						read_file.c			\
						check_file.c		\
						opt_check.c			\
						error.c

OBJ					=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all:
	@$(MAKE) $(LIBFT_NAME)
	@$(MAKE) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $^ -o $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJ)
	@rm -df $(OBJ_DIR)

fcleanlib:
	@(cd $(LIBFT_DIR) && $(MAKE) fclean)

fclean: clean fcleanlib
	@rm -f $(NAME)

re:
	@$(MAKE) fcleanlib
	@$(MAKE) fclean
	@$(MAKE) all
