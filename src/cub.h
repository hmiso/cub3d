/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 08:20:32 by hmiso             #+#    #+#             */
/*   Updated: 2020/09/27 18:29:05 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx_mms_20200219/mlx.h"

typedef struct	s_skrin {
	char		*ptr;
	int			flag;
	int			count_str;
	int			count_mas;
	int			x;
	int			y;
}				t_skrin;

typedef struct	s_color {
	int			count_mas;
	int			count_str;
	int			flag;
	char		*ptr;
}				t_color;

typedef struct	s_sort {
	int			count;
	int			count2;
	int			count3;
	double		len_sprite1;
	double		len_sprite2;
	double		spr_x;
	double		spr_y;
}				t_sort;

typedef struct	s_events {
	int			i;
	int			j;
	int			ii;
	int			jj;
	int			iii;
	int			jjj;
	int			flag_wall;
	int			count_wall;
}				t_events;

typedef struct	s_sprite {
	double		sprite_dir;
	double		sprite_dist;
	double		sprite_screen_size;
	double		h_offset;
	double		v_offset;
	int			i;
	int			j;
	int			count;
	double		step;
	int			color;
}				t_sprite;

typedef struct	s_print {

	double		len;
	int			len_stolb;
	double		start;
	double		yyy;
	double		end;
	double		coef;
	double		count;
	int			color;
	int			count_y_pixel;
	int			count_x_pixel;
}				t_print;

typedef struct	s_raycast {
	double		xa;
	double		ya;
	double		px;
	double		py;
	double		ay;
	double		ax;
	double		bx;
	double		by;
	double		len_gor;
	double		len_ver;
	int			i;
	int			j;
	int			i1;
	int			j1;
	int			end_mas_y;
}				t_raycast;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_text {
	void		*img;
	char		*addr;
	char		*addr_n;
	char		*addr_e;
	char		*addr_w;
	char		*addr_s;
	char		*addr_spr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			widht;
	int			heith;
	char		*reletiv_path;
}				t_text;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	double		x;
	double		y;
	double		bx;
	double		len_sprite;
	char		**mas;
	double		alfa;
	double		start;
	t_data		img;
	int			flag_wall;
	int			count_plan;
	t_text		text;
	double		len_ray;
	int			count_sprite;
	int			*mas_sprite;
	double		mas_ray[3000];
	int			size_x;
	int			size_y;
	int			color_f;
	int			color_c;
	int			end_mas_y;
}				t_vars;

void			pars_texture(t_vars *vars, char *str, char **adr, char *str2);
void			skrinshot(t_vars *vars);
void			my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int				get_color(t_vars *data, int x, int y);
int				sp_get_color(t_vars *data, int x, int y);
void			print_stolb(t_vars *vars, double angle_ray);
double			count_rastoinie(char **mas, double pow, t_vars *vars);
double			resurs_ray_six(t_raycast *raycast, t_vars *vars, double pow);
double			resurs_ray_five(t_raycast *raycast, t_vars *vars, double pow);
void			resurs_ray_four(t_raycast *raycast, char **mas, t_vars *vars);
void			print_player(t_vars *vars);
void			print_sprite(double spr_x, double spr_y, t_vars *vars);
char			**save_map(int size, t_list **tmp);
int				events(int keycode, t_vars *vars);
void			sort_sprite(t_vars *vars);
void			events_res(t_events *events, t_vars *vars);
void			events_res_two(t_events *events, t_vars *vars);
void			events_res_three(t_events *events, t_vars *vars);
void			events_res_four(t_events *events, t_vars *vars);
void			events_res_five(t_events *events, t_vars *vars);
void			events_res_six(t_events *events, t_vars *vars);
void			pars_sprite(t_vars *vars);
void			pars_player(t_vars *vars);
void			pars_cub(char **argv, t_vars *vars);
void			pars_skrin_size(t_vars *vars, char *mas);
void			pars_flor_color(t_vars *vars, char *str);
void			pars_ceilling_color(t_vars *vars, char *str);
void			init_window(t_vars *vars);
void			pars_texture(t_vars *vars, char *str, char **adr, char *str2);
void			valid_mup(t_vars *vars, int count_mas, int count_str);
void			valid_mup_cub(t_vars *vars);
int				vl_mup_rs(t_vars *vars, int c_s, int c_m, int *flag_mas);
int				vl_mup_rs_two(t_vars *vars, int c_s, int c_m, int *flag_mas);
int				vl_mup_rs_three(t_vars *vars, int c_s, int c_m, int *flag_mas);
void			vl_mup_rs_four(t_vars *vars, int c_s, int i, int *flag_start);
void			vl_mup_rs_five(t_vars *vars, int c_s, int c_m, int *flag_mas);
void			null_funk(t_vars *vars);
void			ps_fl_color_five(t_color *color, t_vars *vars, char *str);
void			ps_cl_color_five(t_color *color, t_vars *vars, char *str);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *s1);
int				ft_isdigit(int c);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_calloc(size_t nam, size_t size);
char			*ft_strdup(const char *s1);
void			ft_lstclear(t_list **lst, void (*del)(void*));
int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
int				get_next_line(int fd, char **line);
#endif
