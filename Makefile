# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 09:10:35 by hmiso             #+#    #+#              #
#    Updated: 2020/09/27 13:21:41 by hmiso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_LIB = libmlx.dylib

MLX = src/minilibx_mms_20200219

OBJ_FILES = src/pars_celling_color_res.o src/pars_flor_color_res.o src/null_funk.o \
src/valid_mup_cub_res.o src/valid_mup_cub.o src/valid_mup.o src/pars_texture.o src/init_window.o \
src/pars_celling_color.o src/pars_flor_color.o src/pars_skrin_size.o src/pars_cub.o src/pars_sprite.o \
src/pars_player.o src/save_map.o src/print_sprite.o src/print_player.o src/print_stolb.o src/count_rastoinie_res.o \
src/count_rastoinie.o src/pixel_put.o src/cub3d.o src/sort_sprite.o src/events.o src/events_res.o \
src/events_res_two.o src/skrinshoot.o src/get_next_line/get_next_line.o \
src/libft/ft_strlen.o \
src/libft/ft_strchr.o src/libft/ft_strjoin.o src/libft/ft_putstr_fd.o src/libft/ft_strncmp.o \
src/libft/ft_atoi.o src/libft/ft_isdigit.o src/libft/ft_itoa.o src/libft/ft_lstadd_back.o \
src/libft/ft_lstnew.o src/libft/ft_lstsize.o src/libft/ft_strtrim.o src/libft/ft_calloc.o \
src/libft/ft_strdup.o src/libft/ft_lstclear.o src/libft/ft_memcpy.o src/libft/ft_memset.o \
src/libft/ft_putchar_fd.o

CFLAGS = -Wall -Wextra -Werror

FLAG_LINK = libmlx.dylib -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_FILES) src/cub.h
	make -C $(MLX)
	mv $(MLX)/$(MLX_LIB) ./
	gcc $(FLAG_LINK) $(OBJ_FILES) -o $(NAME)

%.o: %.c 
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re