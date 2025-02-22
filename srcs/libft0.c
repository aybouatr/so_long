/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:25:49 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:25:51 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_finish(s_info_img img)
{
	img.nbr_coin = count_what_do_you_want(img.map, 'C');
	print_nbr_step(img);
	if (img.nbr_coin == 0)
		mlx_put_image_to_window(img.mlx, img.win, img.excit.exict,
				img.excit.pos_y * 58, img.excit.pos_x * 58);
	if (img.nbr_coin == 0 && img.player.pos_player_x == img.excit.pos_x
		&& img.player.pos_player_y == img.excit.pos_y)
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	e;

	e = 0;
	while (str[e])
		e++;
	return (e);
}

void	ft_putchar_fd(char c, int fd)
{
	ssize_t	ret;

	ret = 0;
	if (fd >= 0)
		ret = write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}
