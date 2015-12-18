# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:47:23 by rmaury            #+#    #+#              #
#    Updated: 2015/12/16 17:06:51 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3d
CCLIB = -L mlx/ -lmlx -framework OpenGl -framework AppKit
CCFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src
OBJDIR = obj
INCDIR = includes/
LIBDIR = Libft/libft.a

SRC +=		main.c
SRC +=		hooks.c
SRC +=		map_select.c
SRC +=		draw_set.c
SRC +=		draw_map.c
SRC +=		move.c
SRC +=		rotations.c
SRC +=		map_tools.c
SRC +=		map_set.c
SRC +=		win.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C Libft
	@gcc $(CCLIB) $(CCFLAGS) -o $(NAME) $(OBJS) $(INCS) $(LIBDIR)
	@echo "Compilation Over"
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C Libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C Libft fclean
	@rm -f $(NAME)
	@rm -rf obj
re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c $(CCFLAGS) $(INCS) -I Libft/includes -I mlx -I /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/ -o $@ $<