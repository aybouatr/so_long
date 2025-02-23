/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:02 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:21:06 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_enamy_help(s_info_enamy *e, void *mlx, int *error)
{
	int	i;

	i = 0;
	e->arr[0] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/00.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[1] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/10.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[2] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/20.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[3] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/30.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[4] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/40.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[5] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/50.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[6] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/60.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[7] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/70.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[8] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_enamy/80.xpm",
			&e->y_enamy, &e->x_enamy);
	e->arr[9] = NULL;
	while (i < 9)
		if (e->arr[i++] == NULL)
			*error = -1;
}

s_info_exict	initialize_excit(char *mlx, int *error)
{
	s_info_exict	exci;
	char			*path;
	void			*exx;

	exci.x_ex = 58;
	exci.y_ex = 47;
	path = "/home/aybouatr/Desktop/so_long/img/img_Exict/exict.xpm";
	exci.exict = mlx_xpm_file_to_image(mlx, path, &exci.y_ex, &exci.x_ex);
	if (!exci.exict)
		*error = 1;
	return (exci);
}

s_info_wall	initialize_wall(char *mlx, int *error)
{
	s_info_wall	wall;
	char		*path;

	wall.x_wall = 58;
	wall.y_wall = 58;
	path = "/home/aybouatr/Desktop/so_long/img/img_wall/stone.xpm";
	wall.Wall = mlx_xpm_file_to_image(mlx, path, &wall.x_wall, &wall.y_wall);
	if (!wall.Wall)
		*error = -1;
	return (wall);
}

int	count_what_do_you_want(char **arr, char c)
{
	int	counter;
	int	x;
	int	y;

	counter = 0;
	x = 0;
	while (arr && arr[x])
	{
		y = 0;
		while (arr[x][y] != '\0')
		{
			if (arr[x][y] == c)
				counter++;
			y++;
		}
		x++;
	}
	return (counter);
}

void	initialize(s_info_img *img, char **arr)
{
	s_pos_player_and_w_h	info;

	info = get_positions_player_and_nother_info(arr);
	img->map = arr;
	img->mlx = mlx_init();
	img->count_nbr_step = 0;
	img->nbr_enamy = count_what_do_you_want(arr, 'N');
	img->player = initialize_player(img->mlx, &img->staus_error);
	img->player.pos_player_x = info.x_pos;
	img->player.pos_player_y = info.y_pos;
	img->bkrd = initialize_bg(img->mlx, &img->staus_error);
	img->arr_coin = initialize_all_coin(img->mlx, arr, info.nb_coin,
			&img->staus_error);
	img->arr_enamys = initialize_all_enamys(img->mlx, arr, img->nbr_enamy,
			&img->staus_error);
	img->excit = initialize_excit(img->mlx, &img->staus_error);
	img->excit.pos_x = info.x_pos_exi;
	img->excit.pos_y = info.y_pos_exi;
	img->wall = initialize_wall(img->mlx, &img->staus_error);
	img->win = mlx_new_window(img->mlx, info.wiedth * 58, info.heigth * 58,
			"./so_long");
	if (!img->win)
		img->staus_error = -1;
	img->las_d = 's';
}
