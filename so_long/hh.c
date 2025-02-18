#include "../includes/so_long.h"


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

void drawing_of_pixels(s_info_img img,int x_p,int y_p)
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

void drawing_part_exact_of_pixels(s_info_img img,int x_p,int y_p,int i)
{
	int x;
	int y;

	x = 0;
	while (x < (58))
	{
		y = (i * 37);
		while (y <  ((i + 1) * 37))
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


void drawing_palayer(s_info_img img,int x_p,int y_p,char* path)
{
	int i;
    char* palyer;

	i = 0;
	palyer = mlx_xpm_file_to_image(img.mlx, path, &img.x, &img.y);
	img.walk_image_player = (int *)mlx_get_data_addr(palyer,&(int){0}, &(int){0}, &(int){0});
	drawing_of_pixels(img,x_p,y_p);

}

void load_img_player(s_info_img img,int x_p,int y_p)
{
	char* path;

	if (img.dirctions == 'a')
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/rigth.xpm";
		drawing_palayer(img,x_p,y_p,path);
	}
	else if (img.dirctions == 'w')
	{
		
		path = "/home/aybouatr/Desktop/so_long/img/img_player/back.xpm";
		drawing_palayer(img,x_p,y_p,path);
	}
	else if (img.dirctions == 'd')
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/left.xpm";
		drawing_palayer(img,x_p,y_p,path);
	}
	else
	{
		path = "/home/aybouatr/Desktop/so_long/img/img_player/frond.xpm";
		drawing_palayer(img,x_p,y_p,path);
	}

}

void drawing_backround_player(s_info_img img,int x_p,int y_p)
{
	int x;
	int y;

	x = 0;
	while (x < (58))
	{
		y = 0;
		while (y < 9))
		{
			mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bg_player[122]);
			y++;
		}
		x++;
	}
}


void Draw_just_palayer(s_info_img img,int derict)
{
	int x;
	int y;

	x = 0;
	img.dirctions = derict;
	if(derict == 'w' && img.map[img.pos_player_x - 1] != '1')
	{
		drawing_backround_player(img,(img.pos_player_x * 58) - 27,img.pos_player_y * 58);
		drawing_part_exact_of_pixels(img,(img.pos_player_x * 58) - 27,img.pos_player_y * 58,0)
		drawing_backround_player(img,(img.pos_player_x * 58) - 18,img.pos_player_y * 58);
		drawing_part_exact_of_pixels(img,(img.pos_player_x * 58) - 18,img.pos_player_y * 58,0)

	}
	
	

}

void drawing_component_game(s_info_img img,int derict)
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
				load_img_player(img,58*x,58*y);

			y++;
		}
		x++;
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
	Draw_just_palayer(*img,keycode);
}

int key_press(int keycode, s_info_img *img)
{
    if (keycode == 65307)
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

void preprocessing_component_game(char* line)
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
	
	drawing_component_game(img,'s');
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
		preprocessing_component_game(line);
    }
    else
    {
        perror("Usage: ./your_program <map_file>\n");
        return 1;
    }

    return -1;
}