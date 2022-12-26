/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:48:46 by anargul           #+#    #+#             */
/*   Updated: 2022/11/30 15:15:16 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lstrchr(char **str, int c, t_arg *arg)
{
	int	i;
	int	d;
	int	res;

	i = 0;
	res = 0;
	while (i < arg->map.y)
	{
		d = 0;
		while (str[i][d] != '\n' && str[i][d] != '\0')
		{
			if (str[i][d] == (char)c)
				res++;
			d++;
		}
		i++;
	}
	return (res);
}

int	check_char(char **str, t_arg *arg)
{
	int	c;

	c = ft_lstrchr(str, 'C', arg);
	arg->map.collect_count = c;
	if (ft_lstrchr(str, 'P', arg) != 1 || ft_lstrchr(str, 'E', arg) != 1)
		return (1);
	else if (c == 0)
		return (1);
	return (0);
}

int	check_rect(char **str, t_arg *arg)
{
	int	i;
	int	j;
	int	l_len;
	int	h_len;

	l_len = ft_l_strlen(str[0]);
	h_len = arg->map.y;
	i = 0;
	while (i < h_len)
	{
		j = 0;
		while (j < l_len && str[i][j])
		{
			if ((j == 0 || j == (l_len - 1) || i == 0 || i == h_len - 1)
				&& str[i][j] != '1')
				return (1);
			j++;
		}
		if (ft_l_strlen(str[i]) != l_len)
			return (1);
		i++;
	}
	return (0);
}

int	check_diff(char **str, t_arg *arg)
{
	int		i;
	int		j;
	int		len;
	char	t;

	i = 0;
	len = arg->map.x;
	while (i < arg->map.y)
	{
		j = 0;
		while (j < len)
		{
			t = str[i][j];
			if (t != 'C' && t != 'P' && t != 'E' && t != '1' && t != '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
