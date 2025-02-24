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

s_pos_player_and_w_h	get_positions_player_and_nother_info(char **arr)
{
	s_pos_player_and_w_h	info;

	info.heigth = -1;
	info.nb_coin = 0;
	while (arr[++info.heigth] != NULL)
	{
		info.wiedth = -1;
		while (arr[info.heigth][++info.wiedth] != '\0')
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
		}
	}
	return (info);
}

s_info_player	initialize_player(void *mlx, int *status_error)
{
	s_info_player	p;
	char			*path;

	p.x = 58;
	p.y = 150;
	path = "/home/aybouatr/Desktop/so_long/img/img_player/back.xpm";
	p.img_back = mlx_xpm_file_to_image(mlx, path, &p.y, &p.x);
	p.xpm_back = (unsigned int *)mlx_get_data_addr(p.img_back, &(int){0}, &(int){0},
			&(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/rigth.xpm";
	p.img_rigth = mlx_xpm_file_to_image(mlx, path, &p.y, &p.x);
	p.xpm_rigth = (unsigned int *)mlx_get_data_addr(p.img_rigth, &(int){0}, &(int){0},
			&(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/frond.xpm";
	p.img_frond = mlx_xpm_file_to_image(mlx, path, &p.y, &p.x);
	p.xpm_frond = (unsigned int *)mlx_get_data_addr(p.img_frond, &(int){0}, &(int){0},
			&(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/left.xpm";
	p.img_left = mlx_xpm_file_to_image(mlx, path, &p.y, &p.x);
	p.xpm_left = (unsigned int *)mlx_get_data_addr(p.img_left, &(int){0}, &(int){0},
			&(int){0});
	p.xpm_current_put = p.xpm_frond;
	if (!p.xpm_left || !p.xpm_frond || !p.xpm_rigth || !p.xpm_back)
		*status_error = -1;
	return (p);
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
