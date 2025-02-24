/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:22:13 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:22:16 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_arry(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	ft_free_struct_coin(t_info_coin *coin, void *mlx)
{
	int	i;

	i = 0;
	while (coin->arr && coin->arr[i] != NULL)
	{
		if (coin->arr[i] != NULL)
			mlx_destroy_image(mlx, coin->arr[i]);
		i++;
	}
	if (coin->arr)
		free(coin->arr);
}

void	ft_free_struct_to_array_coin(t_info_coin **arr_coin, void *mlx)
{
	int	i;

	i = 0;
	while (arr_coin && arr_coin[i] != NULL)
	{
		ft_free_struct_coin(arr_coin[i], mlx);
		free(arr_coin[i]);
		i++;
	}
	if (arr_coin)
		free(arr_coin);
}
