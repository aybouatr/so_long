#include "../includes/so_long.h"


int open_file(char* map)
{
	int fd;

	fd = open("map.ber", O_RDONLY,0777);
	if(fd == -1)
	{
		ft_putstr_fd("Error file",1);
		exit(1);
	}
	
	return (fd);
}

void ft_free_arry(char* arr[])
{
	int i;

	i = 0;
	if(arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		
	}
}

int count_newline(char* data)
{
	int i;

	i = 0;
	while (data && *data)
	{
		if (*data == '\n')
			i++;
		data++;
	}
	return (i);
}

void ft_error_map(char** arr)
{
	ft_free_arry(arr);
	ft_putstr_fd("Invalid MAP !\n",2);
	exit(1);
}

void assign_start(components_map* cmpnt)
{
	cmpnt->wall = 0;
	cmpnt->exit = 0;
	cmpnt->start_pos = 0;
	cmpnt->collectible = 0;
}

int is_found_e(char** arr)
{
	int x;
	int y;

	x = 0;
	while (arr[x])
	{
		y = 0;
		while (arr[x][y])
		{
			if (arr[x][y] == 'E')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}


s_info_img inissialize(char** arr,int len_w,int len_h)
{
	s_info_img img;
	char *path;

	img.map = arr;
	img.mlx = mlx_init();
	img.x_coin = 55;
	img.y_coin = 525;
	img.x_ex = 155;
	img.y_ex = 240;
	img.x_wall = 58;
	img.y_wall = 58;
	img.x_bg = 58 * len_h;
	img.y_bg = 58 * len_w;
    img.win = mlx_new_window(img.mlx,img.y_bg,img.x_bg, "./so_long");
	path = "/home/aybouatr/Desktop/so_long/img/back_round.xpm";
	img.backround = mlx_xpm_file_to_image(img.mlx,path,&img.x_bg,&img.y_bg);
	img.bg_player = (unsigned int*)mlx_get_data_addr(img.backround,&(int){0}, &(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/coins.xpm";
	img.coins = mlx_xpm_file_to_image(img.mlx,path,&img.x_coin,&img.y_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Exict/exict.xpm";
	img.ex = mlx_xpm_file_to_image(img.mlx,path,&img.x_ex,&img.y_ex);
	path = "/home/aybouatr/Desktop/so_long/img/img_wall/stone.xpm";
	img.Wall = mlx_xpm_file_to_image(img.mlx,path,&img.x_wall,&img.y_wall);
	return (img);
}

void Drwa_wall(s_info_img img,int x_p,int y_p)
{
	int* wall;
	int* bg;
	int x;
	int	y;

	wall = (int *)mlx_get_data_addr(img.Wall,&(int){0}, &(int){0}, &(int){0});
	bg = (int *)mlx_get_data_addr(img.backround,&(int){0}, &(int){0}, &(int){0});
	x = 0;
	y = 0;
	while (x < img.x_wall)
	{
		y = 0;
		while (y < img.y_wall)
		{
			if (wall[x * img.x_wall + y] != 0xFF000000 )
				mlx_pixel_put(img.mlx,img.win,x_p + x,y_p + y,wall[x * img.x_wall + y]);
			else
				mlx_pixel_put(img.mlx,img.win,x_p + x,y_p + y,bg[122]);
			y++;
		}
		x++;
	}
	
}

void draw_backroud_player(s_info_img img,int x_p,int y_p,int i)
{
	int x;
	int y;

	x = 0;
	while (x < (58))
	{
		y = 0;
		while (y < 18))
		{
			mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bg_player[122]);
			y++;
		}
		x++;
	}
}

void draw_pixels(s_info_img img,int x_p,int y_p,int i)
{
	int x;
	int y;

	x = 0;
	while (x < (58))
	{
		y = 0;
		while (y <  37)
		{
			if (img.walk_image_player[x * img.x + y] != 0xFF000000 )
				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.walk_image_player[x * img.x + y]);
			else
				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bg_player[122]);
			y++;
		}
		x++;
	}
}

void draw_player_back(s_info_img img,int x_p,int y_p,char* path)
{
	int i;
    char* palyer;

	i = 0;
	palyer = mlx_xpm_file_to_image(img.mlx, path, &img.x, &img.y);
	img.walk_image_player = (int *)mlx_get_data_addr(palyer,&(int){0}, &(int){0}, &(int){0});
	while (i < 4)
	{
		draw_pixels(img,x_p,y_p,i);
		i++;
	}
}

void Drwa_player(s_info_img img,int x_p,int y_p)
{
	char* path;

	if (img.dirctions == 'a')
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/rigth.xpm";
		draw_player_back(img,x_p,y_p,path);
	}
	else if (img.dirctions == 'w')
	{
		
		path = "/home/aybouatr/Desktop/so_long/img/img_player/back.xpm";
		draw_player_back(img,x_p,y_p,path);
	}
	else if (img.dirctions == 'd')
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/left.xpm";
		draw_player_back(img,x_p,y_p,path);
	}
	else
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/frond.xpm";
		draw_player_back(img,x_p,y_p,path);
	}

}

void draw_wall_and_backroud(s_info_img img,int derict)
{
	int x;
	int y;

	x = 0;
	img.dirctions = derict;
	mlx_put_image_to_window(img.mlx,img.win,img.backround,0,0);
	while (img.map[x] != NULL)
	{
		y = 0;
		while (img.map[x][y] != '\0')
		{
			if(img.map[x][y] == '1')
				mlx_put_image_to_window(img.mlx,img.win,img.Wall, 58 * y,58 * x);
			else if (img.map[x][y] == 'P')
				Drwa_player(img,58*x,58*y);

			y++;
		}
		x++;
	}
	
}

void Draw_just_palayer_coin(s_info_img img,int derict)
{
	int x;
	int y;

	x = 0;
	img.dirctions = derict;
	if(derict == 'w')
	{

		draw_backroud_player(img,(img.pos_player_x - 1) * 58,img.pos_player_y * 58,);

	}
	
	

}

void hepl_key_press(int keycode,s_info_img* img)
{
	if (keycode == 'w' && img->map[img->pos_player_x - 1][img->pos_player_y] != '1') 
    {
        img->map[img->pos_player_x - 1][img->pos_player_y] = 'P';
        img->map[img->pos_player_x][img->pos_player_y] = '0';
        img->pos_player_x--;
    }
    else if (keycode == 'd' && img->map[img->pos_player_x][img->pos_player_y + 1] != '1')
    {
        img->map[img->pos_player_x][img->pos_player_y + 1] = 'P';
        img->map[img->pos_player_x][img->pos_player_y] = '0';
        img->pos_player_y++;
    }
    else if (keycode == 's' && img->map[img->pos_player_x + 1][img->pos_player_y] != '1') 
    {
        img->map[img->pos_player_x + 1][img->pos_player_y] = 'P';
        img->map[img->pos_player_x][img->pos_player_y] = '0';
        img->pos_player_x++;
    }
    else if (keycode == 'a' && img->map[img->pos_player_x][img->pos_player_y - 1] != '1' )
    {
        img->map[img->pos_player_x][img->pos_player_y - 1] = 'P';
        img->map[img->pos_player_x][img->pos_player_y] = '0';
        img->pos_player_y--;
    }
	Draw_just_palayer_coin(*img,keycode);
}

void ft_free_arr(char** arr)
{
	int x;

	x = 0;
	while (arr && arr[x] != NULL)
	{
		free(arr[x]);
		x++;
	}
	if(!arr)
		free(arr);
	
}

int if_finish(s_info_img img)
{
	int x;
	int y;
	int nbr_coin;

	x = 1;
	nbr_coin = 0;
	while (img.map[x + 1] != NULL)
	{
		y = 1;
		while (img.map[x][y + 2] != '\0')
		{
			if (img.map[x][y] == 'C')
				nbr_coin++;
			y++;
		}
		x++;
	}
	if (!nbr_coin && img.excit.x_ex == img.player.pos_player_x && img.excit.y_ex == img.player.pos_player_y)
		return (1);
	return (0);
}

int key_press(int keycode, s_info_img *img)
{
    if (keycode == 65307 || if_finish(*img))
    {
        mlx_clear_window(img->mlx, img->win);
        ft_free_arr(img->map);
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
    else
    {
        hepl_key_press(keycode, img);
    }
    return 0;
}

void draw_map(char* line)
{
	s_info_img img;
	int y;
	int x;
	char** arr;
	int i;
	int j;

	x = 0;
	arr = ft_split(line,'\n');
	free(line);
	if(!arr)
		exit(-1);
	while (arr[x] != NULL)
	{	
		y = 0;
		while (arr[x][y] != '\0')
		{
			if(arr[x][y] == 'P')
			{
				j = x;
				i = y;
			}
			y++;
		}
		x++;
	}
	img = inissialize(arr,y,x);
	img.pos_player_x = j;
	img.pos_player_y = i;
	
	draw_wall_and_backroud(img,'s');
	mlx_key_hook(img.win,key_press,&img);
	mlx_loop(img.mlx);
}


int main(int ac, char *av[])
{
	char* line;
    if (ac != 1)
    {
        line = load_date_from_map(av[1]);
		check_map(line);
		draw_map(line);
    }
    else
    {
        perror("Usage: ./your_program <map_file>\n");
        return 1;
    }

    return -1;
}



// void drawing_coin(s_info_img img,int y_p,int x_p,int i)
// {
// 	int x;
// 	int y;
// 	int j = 0;
// 	x = 0;
// 	//mlx_put_image_to_window(img.mlx,img.win,img.coin.back_coin,y_p + y,x_p + x);
// 	while (x < 54)
// 	{
// 		y = 52 * i;
// 		j = 0;
// 		while (y <=  ((i + 1) * 52))
// 		{
// 			if (img.coin.xpm_coin[x * img.coin.y_coin + y ] != 0xFF000000 )
// 				mlx_pixel_put(img.mlx,img.win,y_p + j,x_p + x,img.coin.xpm_coin[x * img.coin.y_coin + y]);
// 			else
// 				mlx_pixel_put(img.mlx,img.win,y_p + j,x_p + x,img.bkrd.xpm_backround[122]);
// 			y++;
// 			j++;
// 		}
// 		x++;
		
// 	}
	
// }


// void drawing_backround_coin(s_info_img img,int y_p,int x_p,int i)
// {
// 	int x;
// 	int y;
// 	int j = 52 * i;

// 	x = 0;
// 	while (x < 55)
// 	{
// 		y = 0;
// 		while (y <  52)
// 		{
// 			mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bkrd.xpm_backround[122]);
// 			y++;
// 		}
// 		x++;
		
// 	}
// }

// void drawing_part_exact_of_pixels(s_info_img img,int x_p,int y_p,int i)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	while (x < (58))
// 	{
// 		y = (i * 37);
// 		while (y <  ((i + 1) * 37))
// 		{
// 			if (img.player.xpm_current_put[x * img.player.y + y] != 0xFF000000 )
// 				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.player.xpm_current_put[x * img.player.y + y]);
// 			else
// 				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bkrd.xpm_backround[122]);
// 			y++;
// 		}
// 		x++;
// 	}
// }

// void Draw_just_palayer(s_info_img img)
// {
// 	int x;
// 	int y;
// 	int y_p;
// 	int x_p;

// 	x = 0;
// 	y_p = img.player.pos_player_y * 58;
// 	x_p = img.player.pos_player_x * 58;
// 	while (x < 58)
// 	{
// 		y = 0;
// 		while (y <  37 )
// 		{
// 			if (img.player.xpm_current_put[x * img.player.y + y] != 0xFF000000 )
// 				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.player.xpm_current_put[x * img.player.y + y]);
// 			else
// 				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bkrd.xpm_backround[1337]);
// 			y++;
// 		}
// 		x++;
// 	}

// }