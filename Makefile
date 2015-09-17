# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:47:23 by rmaury            #+#    #+#              #
#    Updated: 2015/09/17 16:52:37 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d
CCLIB = -L minilibx -lmlx -framework OpenGl -framework AppKit
CCFLAGS =
SRCDIR = src
OBJDIR = obj
INCDIR = includes

SRC +=

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS)
	@echo "Compilation Over"
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf obj
re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c -g $(CCFLAGS) $(INCS) -I includes/ -o $@ $<