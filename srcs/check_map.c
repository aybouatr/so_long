/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:34:07 by aybouatr          #+#    #+#             */
/*   Updated: 2025/02/22 18:34:10 by aybouatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_help(char **arr)
{
	int				i;
	int				j;
	components_map	component;

	i = 0;
	j = 0;
	component = count_nbr_component(arr, i, j);
	if (component.exit != 1 || component.start_pos != 1
		|| component.collectible < 1)
		ft_error_map(arr);
	floodfill(arr, component.x, component.y);
	if (is_found_e(arr))
		ft_error_map(arr);
	ft_free_arry(arr);
}

void	check_map(char *data)
{
	char	**arr;

	int(i), (j), (len_line), (x);
	i = 0;
	arr = ft_split(data, '\n');
	while (arr && arr[i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][0] != '1' || arr[i][ft_strlen(arr[i]) - 1] != '1'
				|| arr[0][j] != '1' || ft_strlen(arr[0]) != ft_strlen(arr[i]))
				ft_error_map(arr);
		}
		i++;
	}
	x = j;
	j = 0;
	while (arr[i - 1][j])
	{
		if (arr[i - 1][j] != '1' || (i - 1) != count_newline(data) || 1920 < (x
				* 58) || 1080 < (i * 58))
			ft_error_map(arr);
		j++;
	}
	check_map_help(arr);
}

components_map	count_nbr_component(char **arr, int i, int j)
{
	components_map	cmpnt;

	j = 0;
	assign_start(&cmpnt);
	while (arr && arr[j])
	{
		i = 0;
		while (arr[j][i] != '\0')
		{
			if (arr[j][i] == 'E')
				cmpnt.exit++;
			else if (arr[j][i] == 'P')
			{
				cmpnt.start_pos++;
				cmpnt.x = j;
				cmpnt.y = i;
			}
			else if (arr[j][i] == 'C')
				cmpnt.collectible++;
			else if (arr[j][i] != '0' && arr[j][i] != '1' && arr[j][i] != 'N')
				ft_error_map(arr);
			i++;
		}
		j++;
	}
	return (cmpnt);
}

char	*load_date_from_map(char *map)
{
	char	*temp;
	int		fd;
	char	*line;
	char	*stock_line;

	fd = open_file(map);
	stock_line = NULL;
	temp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			temp = ft_strjoin(stock_line, line);
			free(line);
			if (stock_line != NULL)
				free(stock_line);
			stock_line = temp;
			temp = NULL;
		}
		else
			break ;
	}
	return (stock_line);
}

void	floodfill(char **arr, int x, int y)
{
	if (x < 0 || y < 0 || arr[x][y] == '\0' || arr[x][y] == '1'
		|| arr[x][y] == '#' || arr[x][y] == 'N')
		return ;
	arr[x][y] = '#';
	floodfill(arr, x + 1, y); // Left
	floodfill(arr, x - 1, y); // Right
	floodfill(arr, x, y + 1); // Up
	floodfill(arr, x, y - 1); // Down
	return ;
}
