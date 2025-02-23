/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:41 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:24:44 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_coin_help(s_info_coin *coin, void *mlx, int *error)
{
	char	*path;
	int		i;

	i = 0;
	(coin)->arr[0] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/00.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[1] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/10.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[2] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/20.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[3] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/30.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[4] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/40.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[5] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/50.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[6] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/60.xpm", &(coin)->y_coin, &(coin)->x_coin);
	(coin)->arr[7] = mlx_xpm_file_to_image(mlx,
			"../so_long/img/img_Coin/70.xpm", &(coin)->y_coin, &(coin)->x_coin);
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

s_info_coin	**initialize_all_coin(char *mlx, char **arr, int nbr_c, int *e)
{
	s_info_coin	**arr_coin;

	int (i), (x), (y);
	x = -1;
	i = -1;
	arr_coin = malloc(sizeof(s_info_coin *) * (nbr_c + 1));
	if (!arr_coin)
		*e = -1;
	while (arr_coin && arr[++x] != NULL)
	{
		y = -1;
		while (arr[x][++y] != '\0')
		{
			if (arr[x][y] == 'C')
			{
				arr_coin[++i] = initialize_coin(mlx, x, y);
				if (arr_coin[i] == NULL)
					*e = -1;
			}
		}
	}
	arr_coin[++i] = NULL;
	return (arr_coin);
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

s_info_enamy	**initialize_all_enamys(char *mlx, char **arr, int n, int *e)
{
	s_info_enamy	**arr_enamy;
	int				i;
	int				x;
	int				y;

	x = -1;
	i = -1;
	arr_enamy = malloc(sizeof(s_info_enamy *) * (n + 1));
	if (!arr_enamy)
		*e = -1;
	while (arr_enamy && arr[++x] != NULL)
	{
		y = -1;
		while (arr[x][++y] != '\0')
		{
			if (arr[x][y] == 'N')
			{
				arr_enamy[++i] = initialize_enamy(mlx, x, y);
				if (arr_enamy[i] == NULL)
					*e = -1;
			}
		}
	}
	arr_enamy[++i] = NULL;
	return (arr_enamy);
}
