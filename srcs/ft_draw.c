/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:20:37 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:20:40 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawing_of_pixels(s_info_img img, int x_p, int y_p)
{
	int	x;
	int	y;

	x = 0;
	while (x < 58)
	{
		y = 0;
		while (y < 58)
		{
			if (img.player.xpm_current_put[x * img.player.y + y] != 0xFF000000
				&& y <= 37)
				mlx_pixel_put(img.mlx, img.win, y_p + y, x_p + x,
					img.player.xpm_current_put[x * img.player.y + y]);
			else
				mlx_pixel_put(img.mlx, img.win, y_p + y, x_p + x,
					img.bkrd.xpm_backround[0]);
			y++;
		}
		x++;
	}
}

void	drawing_backround_player(s_info_img img, int x_p, int y_p)
{
	int	x;
	int	y;

	x = 0;
	while (x < (58))
	{
		y = 0;
		while (y < 42)
		{
			mlx_pixel_put(img.mlx, img.win, y_p + y, x_p + x,
				img.bkrd.xpm_backround[122]);
			y++;
		}
		x++;
	}
}

void	drawing_component_game(s_info_img img, int derict)
{
	int	x;
	int	y;

	x = 0;
	img.last_directions = derict;
	mlx_put_image_to_window(img.mlx, img.win, img.bkrd.backround, 0, 0);
	while (img.map[x] != NULL)
	{
		y = 0;
		while (img.map[x][y] != '\0')
		{
			if (img.map[x][y] == '1')
				mlx_put_image_to_window(img.mlx, img.win, img.wall.Wall, 58 * y,
					58 * x);
			else if (img.map[x][y] == 'P')
			{
				img = specifique_img_put_player(img);
				drawing_of_pixels(img, x * 58, y * 58);
			}
			y++;
		}
		x++;
	}
}

int	count_newline(char *data)
{
	int	i;

	i = 0;
	while (data && *data)
	{
		if (*data == '\n')
			i++;
		data++;
	}
	return (i);
}
