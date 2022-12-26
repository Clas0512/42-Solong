/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:30 by anargul           #+#    #+#             */
/*   Updated: 2022/12/02 18:48:36 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./minilibx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_player
{
	void	*vi_f;
	void	*vi_b;
	void	*vi_r;
	void	*vi_l;
}				t_pc;

typedef struct s_map
{	
	char	**str;
	int		x;
	int		y;
	int		collect_count;
}				t_map;

typedef struct s_arg
{
	t_map	map;
	t_pc	player;
	void	*mlx;
	void	*win;
	void	*vi_background;
	void	*vi_collec;
	void	*vi_exit;
	void	*vi_wall;
	int		vi_current;
	int		width;
	int		height;
	int		action_count;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		valid_e;
	int		move_count;
	char	**tmp_map;
}				t_arg;

void	ft_put_move(t_arg *arg, char *mc);
char	*ft_itoa(int n);
void	ft_check_c(t_arg *arg, int k);
int		ft_exit(void);
void	ft_frexit(t_arg *arg);
void	ft_rplc(t_arg *arg, int px, int py, int keycode);
int		ft_strnstr(const char *haystack, const char *needle);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_check_ext(t_arg *arg, int k);
int		ft_set_win(int keycode, t_arg *arg);
void	ft_set_img(t_arg *arg);
void	ft_render(t_arg *arg);
void	ft_put_img(t_arg *arg, char point, int x, int y);
int		ft_l_strlen(char *str);
int		ft_lstrchr(char **str, int c, t_arg *arg);
int		check_char(char **str, t_arg *arg);
int		check_rect(char **str, t_arg *arg);
int		check_diff(char **str, t_arg *arg);
int		check_path(t_arg *arg);
void	ft_read_map(char *str, t_arg *arg);
int		ft_check_map(char *map, t_arg *arg);
void	find_cordt(char **map, t_arg *arg);
#endif
