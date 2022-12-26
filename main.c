/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:39:54 by anargul           #+#    #+#             */
/*   Updated: 2022/12/02 16:08:17 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char *map, t_arg *arg)
{
	ft_read_map(map, arg);
	if (!(arg->map.str)[0])
	{
		ft_printf("\n\x1B[31mERROR: Map couldn't read!\n");
		return (1);
	}
	else if (check_rect(arg->map.str, arg) || check_char(arg->map.str, arg))
	{
		perror("\n\x1B[31mERROR: Map Error!\n");
		return (1);
	}
	else if (check_diff(arg->map.str, arg))
	{
		perror("\n\x1B[31mERROR: Invalid Character\n");
		return (1);
	}
	else if (check_path(arg))
	{
		perror("\n\x1B[31mERROR: Invalid Path\n");
		return (1);
	}
	return (0);
}

void	ft_set_img(t_arg *arg)
{
	int	x;
	int	y;

	x = 64;
	y = x;
	arg->width = 64 * arg->map.x;
	arg->height = 64 * arg->map.y;
	arg->mlx = mlx_init();
	arg->win = mlx_new_window(arg->mlx, arg->width, arg->height, "Try2Survive");
	arg->player.vi_f = mlx_xpm_file_to_image(arg->mlx, "./textures/pf.xpm",
			&x, &y);
	arg->player.vi_b = mlx_xpm_file_to_image(arg->mlx, "./textures/pb.xpm",
			&x, &y);
	arg->player.vi_r = mlx_xpm_file_to_image(arg->mlx, "./textures/pr.xpm",
			&x, &y);
	arg->player.vi_l = mlx_xpm_file_to_image(arg->mlx, "./textures/pl.xpm",
			&x, &y);
	arg->vi_exit = mlx_xpm_file_to_image(arg->mlx, "./textures/exit.xpm",
			&x, &y);
	arg->vi_collec = mlx_xpm_file_to_image(arg->mlx, "./textures/col.xpm",
			&x, &y);
	arg->vi_wall = mlx_xpm_file_to_image(arg->mlx, "./textures/wall.xpm",
			&x, &y);
	arg->vi_background = mlx_xpm_file_to_image(arg->mlx, "./textures/fl.xpm",
			&x, &y);
}

void	ft_render(t_arg *arg)
{
	int	x;
	int	y;
	int	j;
	int	i;

	i = 0;
	y = 0;
	while (i < arg->map.y)
	{
		j = 0;
		x = 0;
		while (j < arg->map.x)
		{
			ft_put_img(arg, arg->map.str[i][j], x, y);
			j++;
			x += 64;
		}
		i++;
		y += 64;
	}
	ft_put_move(arg, ft_itoa(arg->move_count));
}

int	ft_exit(void)
{
	exit(1);
}

int	main(int arc, char **argv)
{
	t_arg	arg;

	if (arc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber"))
		{
			perror("\n\x1B[31mERROR: Invalid Extension\n");
			return (0);
		}
		if (!ft_check_map(argv[1], &arg))
		{
			check_char(arg.map.str, &arg);
			arg.move_count = 0;
			ft_set_img(&arg);
			ft_render(&arg);
			mlx_hook(arg.win, 2, 0, ft_set_win, &arg);
			mlx_hook(arg.win, 17, 0, ft_exit, 0);
			mlx_loop(arg.mlx);
			return (1);
		}
	}
	else
		perror("\n\x1B[31mERROR: Please Check Arguments\n");
	return (0);
}
