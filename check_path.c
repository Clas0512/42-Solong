/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:36:52 by anargul           #+#    #+#             */
/*   Updated: 2022/12/02 14:14:57 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_cordt(char **map, t_arg *arg)
{
	int		i;
	int		d;

	i = 0;
	while (i < arg->map.y)
	{
		d = 0;
		while (map[i][d] != '\n' && map[i][d] != '\0')
		{
			if (map[i][d] == 'P')
			{
				arg->p_x = i;
				arg->p_y = d;
			}
			if (map[i][d] == 'E')
			{
				arg->e_x = i;
				arg->e_y = d;
			}
			d++;
		}
		i++;
	}
}

void	ft_validmap_check(t_arg *arg, int x, int y)
{
	char	*p;

	p = &arg->tmp_map[x][y];
	if (*p == 'E')
		arg->valid_e = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			arg->map.collect_count--;
		*p = '.';
		if (arg->tmp_map[x][y + 1] != '1' &&
			arg->tmp_map[x][y + 1] != '.')
			ft_validmap_check(arg, x, y + 1);
		if (arg->tmp_map[x][y - 1] != '1' &&
			arg->tmp_map[x][y - 1] != '.')
			ft_validmap_check(arg, x, y - 1);
		if (arg->tmp_map[x - 1][y] != '1' &&
			arg->tmp_map[x - 1][y] != '.')
			ft_validmap_check(arg, x - 1, y);
		if (arg->tmp_map[x + 1][y] != '1' &&
			arg->tmp_map[x + 1][y] != '.')
			ft_validmap_check(arg, x + 1, y);
	}
}

int	check_path(t_arg *arg)
{
	int	i;

	i = 0;
	arg->valid_e = 0;
	find_cordt(arg->map.str, arg);
	ft_validmap_check(arg, arg->p_x, arg->p_y);
	while (arg->map.y > i)
	{
		free(arg->tmp_map[i]);
		i++;
	}
	if (arg->map.collect_count != 0 || arg->valid_e != 1)
		return (1);
	return (0);
}
