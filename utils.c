/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:36:21 by anargul           #+#    #+#             */
/*   Updated: 2022/12/02 14:31:46 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_c(t_arg *arg, int k)
{
	if (k == 13 && arg->map.str[arg->p_x - 1][arg->p_y] == 'C')
		arg->map.collect_count--;
	if (k == 0 && arg->map.str[arg->p_x][arg->p_y - 1] == 'C')
		arg->map.collect_count--;
	if (k == 1 && arg->map.str[arg->p_x + 1][arg->p_y] == 'C')
		arg->map.collect_count--;
	if (k == 2 && arg->map.str[arg->p_x][arg->p_y + 1] == 'C')
		arg->map.collect_count--;
}

void	ft_put_move(t_arg *arg, char *mc)
{
	char	*str;

	str = ft_itoa(arg->map.collect_count);
	mlx_string_put(arg->mlx, arg->win, 50, 10,
		0x00BDFF, mc);
	mlx_string_put(arg->mlx, arg->win, 50, 20,
		0x00BDFF, str);
	free(str);
	free(mc);
}

void	ft_frexit(t_arg *arg)
{
	ft_printf("YOU WİN .d\n");
	mlx_destroy_window(arg->mlx, arg->win);
	exit(1);
}

int	ft_strnstr(const char *haystack, const char *needle)
{
	int	h;
	int	n;

	h = 0;
	if (haystack[0] == '\0')
		return (0);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && n < 5)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return (1);
			n++;
		}
		h++;
	}
	return (0);
}
