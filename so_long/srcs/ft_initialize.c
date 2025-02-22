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

void	initialize_coin_help(s_info_coin *coin, void *mlx, int *error)
{
	char	*path;
	int		i;

	i = 0;
	(coin)->arr[0] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/00.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[1] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/10.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[2] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/20.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[3] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/30.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[4] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/40.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[5] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/50.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[6] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/60.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[7] = mlx_xpm_file_to_image(mlx, "../so_long/img/img_Coin/70.xpm", &(coin)->y_coin,
			&(coin)->x_coin);
	(coin)->arr[8] = NULL;
	while (i < 8)
		if (coin->arr[i++] == NULL)
			*error = -1;
}

s_info_coin	*initialize_coin(char *mlx, int x, int y)
{
	s_info_coin	*coin;
	char		**arr;
	char		*path;
	int			error;

	error = 0;
	coin = malloc(sizeof(s_info_coin));
	if (!coin)
		return (NULL);
	coin->arr = malloc(sizeof(void *) * 9);
	if (!coin->arr)
		return (NULL);
	coin->x_coin = 42;
	coin->y_coin = 51;
	coin->x_pos = x;
	coin->y_pos = y;
	coin->is_token = 0;
	initialize_coin_help(coin, mlx, &error);
	if (error == -1)
		return (NULL);
	return (coin);
}

s_info_coin	**initialize_all_coin(char *mlx, char **arr, int nbr_coin,
		int *error)
{
	s_info_coin	**arr_coin;
	int			i;
	int			x;
	int			y;

	x = 0;
	i = 0;
	arr_coin = malloc(sizeof(s_info_coin *) * (nbr_coin + 1));
	if (!arr_coin)
		*error = -1;
	while (arr_coin && arr[x] != NULL)
	{
		y = 0;
		while (arr[x][y] != '\0')
		{
			if (arr[x][y] == 'C')
			{
				arr_coin[i] = initialize_coin(mlx, x, y);
				if (arr_coin[i] == NULL)
					*error = -1;
				i++;
			}
			y++;
		}
		x++;
	}
	arr_coin[i] = NULL;
	return (arr_coin);
}

void	initialize_enamy_help(s_info_enamy *enamy, void *mlx, int *error)
{
	char	*path;
	int		i;

	i = 0;
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/00.xpm";
	(enamy)->arr[0] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/10.xpm";
	(enamy)->arr[1] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/20.xpm";
	(enamy)->arr[2] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/30.xpm";
	(enamy)->arr[3] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/40.xpm";
	(enamy)->arr[4] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/50.xpm";
	(enamy)->arr[5] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/60.xpm";
	(enamy)->arr[6] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/70.xpm";
	(enamy)->arr[7] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	path = "/home/aybouatr/Desktop/so_long/img/img_enamy/80.xpm";
	(enamy)->arr[8] = mlx_xpm_file_to_image(mlx, path, &(enamy)->y_enamy,
			&(enamy)->x_enamy);
	(enamy)->arr[9] = NULL;
	while (i < 9)
		if (enamy->arr[i++] == NULL)
			*error = -1;
}

s_info_enamy	*initialize_enamy(char *mlx, int x, int y)
{
	s_info_enamy	*enamy;
	char			**arr;
	char			*path;
	int				error;

	error = 0;
	enamy = malloc(sizeof(s_info_enamy));
	if (!enamy)
		return (NULL);
	enamy->arr = malloc(sizeof(void *) * 10);
	if (!enamy->arr)
		return (NULL);
	enamy->x_enamy = 58;
	enamy->y_enamy = 48;
	enamy->x_pos = x;
	enamy->y_pos = y;
	initialize_enamy_help(enamy, mlx, &error);
	if (error == -1)
		return (NULL);
	return (enamy);
}

s_info_enamy	**initialize_all_enamys(char *mlx, char **arr, int nbr_enamy,
		int *error)
{
	s_info_enamy	**arr_enamy;
	int				i;
	int				x;
	int				y;

	x = 0;
	i = 0;
	arr_enamy = malloc(sizeof(s_info_enamy *) * (nbr_enamy + 1));
	if (!arr_enamy)
		*error = -1;
	while (arr_enamy && arr[x] != NULL)
	{
		y = 0;
		while (arr[x][y] != '\0')
		{
			if (arr[x][y] == 'N')
			{
				arr_enamy[i] = initialize_enamy(mlx, x, y);
				if (arr_enamy[i] == NULL)
					*error = -1;
				i++;
			}
			y++;
		}
		x++;
	}
	arr_enamy[i] = NULL;
	return (arr_enamy);
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
	char					*path;

	info = get_positions_player_wie_and_hei_windo_and_number_coin(arr);
	img->map = arr;
	img->mlx = mlx_init();
	if (!img->mlx)
		img->staus_error = -1;
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
	img->last_directions = 's';
}
