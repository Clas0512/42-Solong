/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcs_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 00:45:17 by anargul           #+#    #+#             */
/*   Updated: 2022/12/02 14:29:00 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_arg *arg, char point, int x, int y)
{
	mlx_put_image_to_window(arg->mlx, arg->win, arg->vi_background, x, y);
	if (point == '1')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->vi_wall, x, y);
	if (point == 'C')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->vi_collec, x, y);
	if (point == 'P' && arg->move_count == 0)
		mlx_put_image_to_window(arg->mlx, arg->win, arg->player.vi_l, x, y);
	if (point == 'P')
	{
		if (arg->vi_current == 1)
			mlx_put_image_to_window(arg->mlx, arg->win, arg->player.vi_b, x, y);
		if (arg->vi_current == 0)
			mlx_put_image_to_window(arg->mlx, arg->win, arg->player.vi_l, x, y);
		if (arg->vi_current == 13)
			mlx_put_image_to_window(arg->mlx, arg->win, arg->player.vi_f, x, y);
		if (arg->vi_current == 2)
			mlx_put_image_to_window(arg->mlx, arg->win, arg->player.vi_r, x, y);
	}
	if (point == 'E')
		mlx_put_image_to_window(arg->mlx, arg->win, arg->vi_exit, x, y);
}

void	ft_rplc(t_arg *arg, int px, int py, int keycode)
{
	if (keycode == 1 && arg->map.str[px + 1][py] != '1')
	{
		arg->map.str[px + 1][py] = 'P';
		arg->p_x++;
		arg->vi_current = 1;
	}
	if (keycode == 0 && arg->map.str[px][py - 1] != '1')
	{
		arg->map.str[px][py - 1] = 'P';
		arg->p_y--;
		arg->vi_current = 0;
	}
	if (keycode == 13 && arg->map.str[px - 1][py] != '1')
	{
		arg->map.str[px - 1][py] = 'P';
		arg->p_x--;
		arg->vi_current = 13;
	}
	if (keycode == 2 && arg->map.str[px][py + 1] != '1')
	{
		arg->map.str[px][py + 1] = 'P';
		arg->p_y++;
		arg->vi_current = 2;
	}
	arg->map.str[px][py] = '0';
}

int	ft_check_wall(t_arg *arg, int k)
{
	if (k == 13 && arg->map.str[arg->p_x - 1][arg->p_y] == '1')
		return (1);
	if (k == 0 && arg->map.str[arg->p_x][arg->p_y - 1] == '1')
		return (1);
	if (k == 1 && arg->map.str[arg->p_x + 1][arg->p_y] == '1')
		return (1);
	if (k == 2 && arg->map.str[arg->p_x][arg->p_y + 1] == '1')
		return (1);
	return (0);
}

int	ft_check_ext(t_arg *arg, int k)
{
	if (k == 13 && arg->map.str[arg->p_x - 1][arg->p_y] == 'E')
		return (1);
	if (k == 0 && arg->map.str[arg->p_x][arg->p_y - 1] == 'E')
		return (1);
	if (k == 1 && arg->map.str[arg->p_x + 1][arg->p_y] == 'E')
		return (1);
	if (k == 2 && arg->map.str[arg->p_x][arg->p_y + 1] == 'E')
		return (1);
	return (0);
}

int	ft_set_win(int keycode, t_arg *arg)
{
	int	k;

	k = keycode;
	if (k == 53)
		ft_exit();
	if (ft_check_ext(arg, k) && arg->map.collect_count == 0)
	{
		arg->move_count++;
		ft_printf("%d\n", arg->move_count);
		ft_frexit(arg);
	}
	if ((k == 13 || k == 0 || k == 1 || k == 2)
		&& !ft_check_ext(arg, k) && !ft_check_wall(arg, k))
	{
		ft_check_c(arg, k);
		ft_rplc(arg, arg->p_x, arg->p_y, keycode);
		arg->move_count++;
		mlx_clear_window(arg->mlx, arg->win);
		ft_render(arg);
		ft_printf("%d\n", arg->move_count);
	}
	return (0);
}
