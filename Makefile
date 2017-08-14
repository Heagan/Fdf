# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 16:57:19 by gsferopo          #+#    #+#              #
#    Updated: 2017/06/30 16:57:30 by gsferopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = -o app

SRC = fdf.c draw_line.c

LIB = -L. -lft

FLAG = -lmlx -framework opengl -framework appkit

ERROR = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
		gcc $(NAME) $(SRC) $(LIB) $(FLAG) $(ERROR)

clean:
		rm -f $(NAME)
