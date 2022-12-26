/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:37:21 by anargul           #+#    #+#             */
/*   Updated: 2022/11/30 15:09:08 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_l_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	set_mapy_and_malloc(int fd, t_arg *arg)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		i++;
		tmp = get_next_line(fd);
	}
	if (i < 2)
	{
		ft_printf("\n\x1B[31mERROR: Please Make a Map at Min 3 Line!\n");
		exit(1);
	}
	arg->map.y = i;
	arg->map.str = malloc(sizeof(char *) * arg->map.y);
	arg->tmp_map = malloc(sizeof(char *) * arg->map.y);
	free(tmp);
}

void	ft_read_map(char *map, t_arg *arg)
{
	int		fd;
	int		i;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	set_mapy_and_malloc(fd, arg);
	close(fd);
	fd = open(map, O_RDONLY);
	i = 0;
	arg->map.str[i] = get_next_line(fd);
	arg->tmp_map[i] = ft_strdup(arg->map.str[i]);
	i++;
	while (i < arg->map.y)
	{
		arg->map.str[i] = get_next_line(fd);
		arg->tmp_map[i] = ft_strdup(arg->map.str[i]);
		i++;
	}
	arg->map.x = ft_l_strlen(arg->map.str[0]);
}
