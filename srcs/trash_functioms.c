/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    trash_functioms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:34:07 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:34:10 by aybouatr         ###   ########.fr       */
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

char	*ftt_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (free(s1), new);
}
