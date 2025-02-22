/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:23:38 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:23:44 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_nbr_step(s_info_img img)
{
	char	*str;

	str = ft_itoa(img.count_nbr_step);
	mlx_put_image_to_window(img.mlx, img.win, img.wall.Wall, 58 * 2, 58 * 0);
	mlx_string_put(img.mlx, img.win, 30, 30, 0x00FFDD, "N' of steps : ");
	mlx_string_put(img.mlx, img.win, 120, 30, 0x00FFDD, str);
	free(str);
}

int	open_file(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY, 0777);
	if (fd == -1)
	{
		ft_putstr_fd("Error file", 1);
		exit(1);
	}
	return (fd);
}

void	ft_error_map(char **arr)
{
	ft_free_arry(arr);
	ft_putstr_fd("Invalid MAP !\n", 2);
	exit(1);
}

int	key_press(int keycode, s_info_img *im)
{
	s_info_img	img;

	img = *im;
	img.last_directions = keycode;
	if (img.last_directions == 65307)
	{
		clean_memory(im);
		exit(0);
	}
	else
	{
		*im = manage_img(img);
		img = specifique_img_put_player(img);
		*im = specifique_direction(img);
	}
	return (0);
}

int	coin_found(s_info_img *mg)
{
	int			i;
	s_info_img	img;
	int			ret;

	i = 0;
	img = *mg;
	ret = enamy_found(&img);
	if (is_finish(img))
	{
		clean_memory(mg);
		exit(1);
	}
	while (img.arr_coin[i] != NULL)
	{
		if (img.player.pos_player_x == img.arr_coin[i]->x_pos && img.player.pos_player_y == img.arr_coin[i]->y_pos)
			img.arr_coin[i]->is_token = 1;
		manage_positions_coin(img, img.arr_coin[i]);
		i++;
	}
	return (0);
}

int	enamy_found(s_info_img *mg)
{
	int			i;
	s_info_img	img;

	i = 0;
	img = *mg;
	while (img.arr_enamys[i] != NULL)
	{
		if (img.player.pos_player_x == img.arr_enamys[i]->x_pos
			&& img.player.pos_player_y == img.arr_enamys[i]->y_pos)
		{
			clean_memory(mg);
			exit(0);
		}
		manage_positions_enamy(img, img.arr_enamys[i]);
		i++;
	}
}

void	preprocessing_component_game(char *line)
{
	s_info_img	img;
	char		**arr;

	arr = NULL;
	arr = ft_split(line, '\n');
	free(line);
	if (!arr)
		exit(-1);
	img.staus_error = 0;
	initialize(&img, arr);
	if (img.staus_error == -1)
	{
		clean_memory(&img);
		ft_putstr_fd("faild at alcotions !! \n", 2);
		exit(-1);
	}
	drawing_component_game(img, 's');
	mlx_loop_hook(img.mlx, (int (*)(void *))coin_found, &img);
	mlx_key_hook(img.win, key_press, &img);
	mlx_loop(img.mlx);
}

int	main(int ac, char *av[])
{
	char	*line;

	if (ac == 2 && ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4))
	{
		ft_putstr_fd("invalid map\n", 1);
		return (-1);
	}
	if (ac == 2)
	{
		line = load_date_from_map(av[1]);
		check_map(line);
		preprocessing_component_game(line);
	}
	else
	{
		ft_putstr_fd("Usage: ./your_program <map_file>\n", 1);
		return (1);
	}
	return (0);
}
