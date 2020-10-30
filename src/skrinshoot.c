/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skrinshoot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:05:30 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/26 20:08:08 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				my_get_color(t_vars *data, int x, int y)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length
	+ x * (data->img.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static void		init_heder(unsigned char *mas_heder, int size, t_vars *vars)
{
	mas_heder[0] = (unsigned char)'B';
	mas_heder[1] = (unsigned char)'M';
	mas_heder[2] = (unsigned char)size;
	mas_heder[3] = (unsigned char)(size >> 8);
	mas_heder[4] = (unsigned char)(size >> 16);
	mas_heder[5] = (unsigned char)(size >> 24);
	mas_heder[10] = (unsigned char)54;
	mas_heder[14] = (unsigned char)40;
	mas_heder[18] = (unsigned char)vars->size_x;
	mas_heder[19] = (unsigned char)(vars->size_x >> 8);
	mas_heder[20] = (unsigned char)(vars->size_x >> 16);
	mas_heder[21] = (unsigned char)(vars->size_x >> 24);
	mas_heder[22] = (unsigned char)vars->size_y;
	mas_heder[23] = (unsigned char)(vars->size_y >> 8);
	mas_heder[24] = (unsigned char)(vars->size_y >> 16);
	mas_heder[25] = (unsigned char)(vars->size_y >> 24);
	mas_heder[26] = (unsigned char)1;
	mas_heder[28] = (unsigned char)24;
}

static void		put_img_skrin(t_vars *vars, int fd)
{
	int color;
	int x;
	int y;
	int size_x;

	color = 0;
	x = 0;
	y = vars->size_y - 1;
	size_x = vars->size_x;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = my_get_color(vars, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

void			skrinshot(t_vars *vars)
{
	int				fd;
	unsigned char	mas_heder[54];
	int				count;
	int				size;

	if (vars->size_x % 4)
		vars->size_x = vars->size_x - (vars->size_x % 4);
	size = vars->size_x * vars->size_y + 54;
	count = 0;
	fd = open("./scrinshot.bmp", O_RDWR | O_CREAT, 0666);
	while (count < 54)
	{
		mas_heder[count] = (unsigned char)0;
		count++;
	}
	init_heder(mas_heder, size, vars);
	write(fd, mas_heder, 54);
	put_img_skrin(vars, fd);
	close(fd);
	exit(0);
}
