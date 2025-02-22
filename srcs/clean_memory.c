/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:24:12 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:24:15 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_struct_enamy(s_info_enamy *enamy, void *mlx)
{
	int	i;

	i = 0;
	while (enamy->arr && enamy->arr[i] != NULL)
	{
		if (enamy->arr[i] != NULL)
			mlx_destroy_image(mlx, enamy->arr[i]);
		i++;
	}
	if (enamy->arr)
		free(enamy->arr);
}

void	ft_free_struct_to_array_enamy(s_info_enamy **arr_enamy, void *mlx)
{
	int	i;

	i = 0;
	while (arr_enamy && arr_enamy[i] != NULL)
	{
		ft_free_struct_enamy(arr_enamy[i], mlx);
		free(arr_enamy[i]);
		i++;
	}
	if (arr_enamy)
		free(arr_enamy);
}

void	ft_free_struct_player(s_info_player player, void *mlx)
{
	if (player.img_frond)
		mlx_destroy_image(mlx, player.img_frond);
	if (player.img_back)
		mlx_destroy_image(mlx, player.img_back);
	if (player.img_rigth)
		mlx_destroy_image(mlx, player.img_rigth);
	if (player.img_left)
		mlx_destroy_image(mlx, player.img_left);
}

void	clean_memory(s_info_img *img)
{
	ft_free_arry(img->map);
	ft_free_struct_to_array_coin(img->arr_coin, img->mlx);
	ft_free_struct_to_array_enamy(img->arr_enamys, img->mlx);
	ft_free_struct_player(img->player, img->mlx);
	if (img->excit.exict)
		mlx_destroy_image(img->mlx, img->excit.exict);
	if (img->wall.Wall)
		mlx_destroy_image(img->mlx, img->wall.Wall);
	if (img->bkrd.backround)
		mlx_destroy_image(img->mlx, img->bkrd.backround);
	if (img->win && img->mlx)
		mlx_destroy_window(img->mlx, img->win);
	if (img->mlx)
	{
		mlx_destroy_display(img->mlx);
		free(img->mlx);
	}
}
