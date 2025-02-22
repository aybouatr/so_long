/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:40 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:22:45 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	assign_start(components_map *cmpnt)
{
	cmpnt->wall = 0;
	cmpnt->exit = 0;
	cmpnt->start_pos = 0;
	cmpnt->collectible = 0;
}

int	is_found_e(char **arr)
{
	int	x;
	int	y;

	x = 0;
	while (arr[x])
	{
		y = 0;
		while (arr[x][y])
		{
			if (arr[x][y] == 'E' || arr[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

s_pos_player_and_w_h	get_positions_player_wie_and_hei_windo_and_number_coin(char **arr)
{
	s_pos_player_and_w_h	info;

	info.heigth = 0;
	info.nb_coin = 0;
	while (arr[info.heigth] != NULL)
	{
		info.wiedth = 0;
		while (arr[info.heigth][info.wiedth] != '\0')
		{
			if (arr[info.heigth][info.wiedth] == 'P')
			{
				info.x_pos = info.heigth;
				info.y_pos = info.wiedth;
			}
			if (arr[info.heigth][info.wiedth] == 'E')
			{
				info.x_pos_exi = info.heigth;
				info.y_pos_exi = info.wiedth;
			}
			if (arr[info.heigth][info.wiedth] == 'C')
				info.nb_coin++;
			info.wiedth++;
		}
		info.heigth++;
	}
	return (info);
}

s_info_player	initialize_player(void *mlx, int *status_error)
{
	s_info_player	player;
	char			*path;

	player.x = 58;
	player.y = 150;
	path = "/home/aybouatr/Desktop/so_long/img/img_player/back.xpm";
	player.img_back = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_back = (int *)mlx_get_data_addr(player.img_back, &(int){0},
			&(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/rigth.xpm";
	player.img_rigth = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_rigth = (int *)mlx_get_data_addr(player.img_rigth, &(int){0},
			&(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/frond.xpm";
	player.img_frond = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_frond = (int *)mlx_get_data_addr(player.img_frond, &(int){0},
			&(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/left.xpm";
	player.img_left = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_left = (int *)mlx_get_data_addr(player.img_left, &(int){0},
			&(int){0}, &(int){0});
	player.xpm_current_put = player.xpm_frond;
	if (!player.xpm_left || !player.xpm_frond || !player.xpm_rigth
		|| !player.xpm_back)
		*status_error = -1;
	return (player);
}

s_info_bg	initialize_bg(char *mlx, int *error)
{
	s_info_bg	bg;
	char		*path;

	bg.x_bg = 0;
	bg.y_bg = 0;
	path = "/home/aybouatr/Desktop/so_long/img/back_round.xpm";
	bg.backround = mlx_xpm_file_to_image(mlx, path, &bg.y_bg, &bg.x_bg);
	bg.xpm_backround = (int *)mlx_get_data_addr(bg.backround, &(int){0},
			&(int){0}, &(int){0});
	if (!bg.xpm_backround)
		*error = 0;
	return (bg);
}
