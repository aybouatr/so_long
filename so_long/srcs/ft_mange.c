/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mange.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:25:04 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:25:07 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	manage_positions_coin(s_info_img img, s_info_coin *coin)
{
	static int	j;
	static int	i;

	if (coin->is_token == 0)
	{
		mlx_put_image_to_window(img.mlx, img.win, coin->arr[i], coin->y_pos * 58, coin->x_pos * 58);
		if (j++ % 10000 == 0)
			i++;
	}
	if (i == 8)
		i = 0;
}

void	manage_positions_enamy(s_info_img img, s_info_enamy *enamy)
{
	static int	j;
	static int	i;

	mlx_put_image_to_window(img.mlx, img.win, enamy->arr[i], enamy->y_pos * 58, enamy->x_pos * 58);
	if (j++ % 19887 == 0)
		i++;
	if (i == 9)
		i = 0;
}

s_info_img	specifique_direction(s_info_img img)
{
	if (img.last_directions == 'w' && img.map[img.player.pos_player_x
		- 1][img.player.pos_player_y] != '1')
	{
		img.map[img.player.pos_player_x - 1][img.player.pos_player_y] = 'P';
		img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
	}
	else if (img.last_directions == 'd'
			&& img.map[img.player.pos_player_x][img.player.pos_player_y
			+ 1] != '1')
	{
		img.map[img.player.pos_player_x][img.player.pos_player_y + 1] = 'P';
		img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
	}
	else if (img.last_directions == 's' && img.map[img.player.pos_player_x
			+ 1][img.player.pos_player_y] != '1')
	{
		img.map[img.player.pos_player_x + 1][img.player.pos_player_y] = 'P';
		img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
	}
	else if (img.last_directions == 'a'
			&& img.map[img.player.pos_player_x][img.player.pos_player_y
			- 1] != '1')
	{
		img.map[img.player.pos_player_x][img.player.pos_player_y - 1] = 'P';
		img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
	}
	img = manage_img(img);
	return (img);
}

s_info_img	manage_img(s_info_img img)
{
	drawing_backround_player(img, img.player.pos_player_x * 58,
			img.player.pos_player_y * 58);
	if (img.last_directions == 'w' && img.map[img.player.pos_player_x
		- 1][img.player.pos_player_y] != '1')
	{
		img.player.pos_player_x--;
		img.count_nbr_step++;
	}
	else if (img.last_directions == 'd'
			&& img.map[img.player.pos_player_x][img.player.pos_player_y
			+ 1] != '1')
	{
		img.player.pos_player_y++;
		img.count_nbr_step++;
	}
	else if (img.last_directions == 's' && img.map[img.player.pos_player_x
			+ 1][img.player.pos_player_y] != '1')
	{
		img.player.pos_player_x++;
		img.count_nbr_step++;
	}
	else if (img.last_directions == 'a'
			&& img.map[img.player.pos_player_x][img.player.pos_player_y
			- 1] != '1')
	{
		img.player.pos_player_y--;
		img.count_nbr_step++;
	}
	drawing_of_pixels(img, img.player.pos_player_x * 58, img.player.pos_player_y
			* 58);
	return (img);
}

s_info_img	specifique_img_put_player(s_info_img img)
{
	if (img.last_directions == 'd')
		img.player.xpm_current_put = img.player.xpm_left;
	else if (img.last_directions == 'w')
		img.player.xpm_current_put = img.player.xpm_back;
	else if (img.last_directions == 'a')
		img.player.xpm_current_put = img.player.xpm_rigth;
	else if (img.last_directions == 's')
		img.player.xpm_current_put = img.player.xpm_frond;
	return (img);
}
