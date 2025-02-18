#include "../includes/so_long.h"




int open_file(char* map)
{
	int fd;

	fd = open(map, O_RDONLY,0777);
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
		//free(arr);
		
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
			if (arr[x][y] == 'E' || arr[x][y] == 'C')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
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

void ft_free_struct_coin(s_info_coin* coin)
{
	ft_free_arry(coin->arr);
	free(coin->xpm_coin);
}

void ft_free_struct_to_array_coin(s_info_coin **arr_coin)
{
	int i;

	i = 0;
	while (arr_coin && arr_coin[i] != NULL)
	{
		ft_free_struct_coin(arr_coin[i]);
		free(arr_coin[i]);
		i++;
	}
	if(arr_coin)
		free(arr_coin);
	
}

void ft_free_struct_player(s_info_player player)
{
	free(player.xpm_frond);
	free(player.xpm_back);
	free(player.xpm_rigth);
	free(player.xpm_left);
}


void clean_memory(s_info_img img)
{
	ft_free_arry(img.map);
	ft_free_struct_to_array_coin(img.arr_coin);
	ft_free_struct_player(img.player);
	free(img.excit.exict);
	free(img.wall.Wall);
	free(img.wall.xpm_wall);
	free(img.bkrd.backround);
	free(img.bkrd.xpm_backround);
}

s_pos_player_and_w_h get_positions_player_wie_and_hei_windo_and_number_coin(char** arr)
{
	s_pos_player_and_w_h info;

	info.heigth = 0;
	info.nb_coin = 0;
	while (arr[info.heigth] != NULL)
	{
		info.wiedth = 0;
		while (arr[info.heigth][info.wiedth] != '\0')
		{
			if (arr[info.heigth][info.wiedth] == 'P')
			{
				info.x_pos = info.heigth;
				info.y_pos = info.wiedth;
			}
			if(arr[info.heigth][info.wiedth] == 'E')
			{
				info.x_pos_exi = info.heigth;
				info.y_pos_exi = info.wiedth;
			}
			if (arr[info.heigth][info.wiedth] == 'C')
					info.nb_coin++;
			info.wiedth++;
		}
		info.heigth++;
	}
	return (info);
}

s_info_player initialize_player(char* mlx)
{
	s_info_player player;
	void* imgs;
	char* path; 

	player.x = 58;
	player.y = 150;
	path = "/home/aybouatr/Desktop/so_long/img/img_player/back.xpm";
	imgs = mlx_xpm_file_to_image(mlx,path,  &player.y, &player.x);
	player.xpm_back = (int *)mlx_get_data_addr(imgs,&(int){0}, &(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/rigth.xpm";
	imgs = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_rigth = (int *)mlx_get_data_addr(imgs,&(int){0}, &(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/frond.xpm";
	imgs = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_frond = (int *)mlx_get_data_addr(imgs,&(int){0}, &(int){0}, &(int){0});
	path = "/home/aybouatr/Desktop/so_long/img/img_player/left.xpm";
	imgs = mlx_xpm_file_to_image(mlx, path, &player.y, &player.x);
	player.xpm_left = (int *)mlx_get_data_addr(imgs,&(int){0}, &(int){0}, &(int){0});
	player.xpm_current_put = player.xpm_frond;

	return (player);
}

s_info_bg initialize_bg(char* mlx)
{
	s_info_bg bg;
	char* path;

	bg.x_bg = 0;
	bg.y_bg = 0; 
	path = "/home/aybouatr/Desktop/so_long/img/back_round.xpm";
	bg.backround = mlx_xpm_file_to_image(mlx,path,&bg.y_bg,&bg.x_bg);
	bg.xpm_backround = (int *)mlx_get_data_addr(bg.backround,&(int){0}, &(int){0}, &(int){0});

	return (bg);
}

s_info_coin* initialize_coin(char* mlx,int x,int y)
{
	s_info_coin* coin;
	char* path;

	coin = malloc(sizeof(s_info_coin));
	if (!coin)
		return (NULL);
	coin->x_coin = 42;
	coin->y_coin = 51;
	coin->x_pos = x;
	coin->y_pos = y;
	coin->is_token = 0;
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/00.xpm";
	coin->arr[0] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/10.xpm";
	coin->arr[1] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/20.xpm";
	coin->arr[2] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/30.xpm";
	coin->arr[3] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/40.xpm";
	coin->arr[4] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/50.xpm";
	coin->arr[5] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/60.xpm";
	coin->arr[6] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);
	path = "/home/aybouatr/Desktop/so_long/img/img_Coin/70.xpm";
	coin->arr[7] = mlx_xpm_file_to_image(mlx,path,&coin->y_coin,&coin->x_coin);

	return (coin);
}

s_info_coin** initialize_all_coin(char* mlx,char** arr,int nbr_coin)
{
	s_info_coin** arr_coin;
	int 		  i;
	int 		  x;
	int 		  y;

	x = 0;
	i = 0;
	arr_coin = malloc(sizeof(s_info_coin *) * (nbr_coin * 1));
	if(!arr_coin)
		return (NULL);
	while (arr[x] != NULL)
	{
		y = 0;
		while (arr[x][y] != '\0')
		{
			if(arr[x][y] == 'C')
			{
				arr_coin[i] = initialize_coin(mlx,x,y);
				i++;
			}
			y++;
		}
		x++;
	}
	arr_coin[i] = NULL;
	return (arr_coin);
}

s_info_exict initialize_excit(char* mlx)
{
	s_info_exict exci;
	char* path;
	void *exx;

	exci.x_ex = 58;
	exci.y_ex = 47;
	path = "/home/aybouatr/Desktop/so_long/img/img_Exict/exict.xpm";
	exci.exict = mlx_xpm_file_to_image(mlx,path,&exci.y_ex,&exci.x_ex);
	//exci.xpm_exict = (int *)mlx_get_data_addr(exx,&(int){0}, &(int){0}, &(int){0});
	return (exci);
}

s_info_wall initialize_wall(char* mlx)
{
	s_info_wall wall;
	char* path;

	wall.x_wall = 58;
	wall.y_wall = 58;
	path = "/home/aybouatr/Desktop/so_long/img/img_wall/stone.xpm";
	wall.Wall = mlx_xpm_file_to_image(mlx,path,&wall.x_wall,&wall.y_wall);
	wall.xpm_wall = (int *)mlx_get_data_addr(wall.Wall,&(int){0}, &(int){0}, &(int){0});
	return (wall);
}

s_info_img initialize(char** arr)
{
	s_info_img img;
	s_pos_player_and_w_h info;
	char *path;

	info = get_positions_player_wie_and_hei_windo_and_number_coin(arr);
	img.map = arr;
	img.mlx = mlx_init();
	img.player = initialize_player(img.mlx);
	img.player.pos_player_x = info.x_pos;/////
	img.player.pos_player_y = info.y_pos;
	img.bkrd = initialize_bg(img.mlx);
	img.arr_coin = initialize_all_coin(img.mlx,arr,info.nb_coin);
	img.excit = initialize_excit(img.mlx);
	img.excit.pos_x = info.x_pos_exi;
	img.excit.pos_y = info.y_pos_exi;
	img.wall = initialize_wall(img.mlx);
	img.win = mlx_new_window(img.mlx,info.wiedth * 58,info.heigth * 58, "./so_long");
	img.last_directions = 's';
	return (img);
}

void drawing_of_pixels(s_info_img img,int x_p,int y_p)
{
	int x;
	int y;

	x = 0;
	while (x < 58)
	{
		y = 0;
		while (y <  58)
		{
			if (img.player.xpm_current_put[x * img.player.y + y] != 0xFF000000 && y <= 37)
				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.player.xpm_current_put[x * img.player.y + y]);
			else
				mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bkrd.xpm_backround[1337]);
			y++;
		}
		x++;
	}
}

s_info_img specifique_img_put_player(s_info_img img)
{
	if (img.last_directions == 'd')
		img.player.xpm_current_put = img.player.xpm_left;
	else if (img.last_directions == 'w')
		img.player.xpm_current_put = img.player.xpm_back;
	else if (img.last_directions == 'a')
		img.player.xpm_current_put = img.player.xpm_rigth;
	else if  (img.last_directions == 's')
		img.player.xpm_current_put = img.player.xpm_frond;
	
	return (img);
}

void drawing_backround_player(s_info_img img,int x_p,int y_p)
{
	int x;
	int y;

	x = 0;
	while (x < (58))
	{
		y = 0;
		while (y < 42)
		{
			mlx_pixel_put(img.mlx,img.win,y_p + y,x_p + x,img.bkrd.xpm_backround[122]);
			y++;
		}
		x++;
	}
}

s_info_img manage_img(s_info_img img)
{
	
	drawing_backround_player(img,img.player.pos_player_x * 58,img.player.pos_player_y * 58);
	if (img.last_directions == 'w' && img.map[img.player.pos_player_x - 1][img.player.pos_player_y] != '1') 
    {
       img.player.pos_player_x--;
    }
    else if (img.last_directions == 'd' && img.map[img.player.pos_player_x][img.player.pos_player_y + 1] != '1')
    {
        img.player.pos_player_y++;
    }
    else if (img.last_directions == 's' && img.map[img.player.pos_player_x + 1][img.player.pos_player_y] != '1') 
    {
		img.player.pos_player_x++;
        
    }
    else if (img.last_directions == 'a' && img.map[img.player.pos_player_x][img.player.pos_player_y - 1] != '1' )
    {
        img.player.pos_player_y--;
    }
	drawing_of_pixels(img,img.player.pos_player_x * 58,img.player.pos_player_y * 58);
	return (img);
	
}

void drawing_component_game(s_info_img img,int derict)
{
	int x;
	int y;

	x = 0;
	img.last_directions = derict;
	mlx_put_image_to_window(img.mlx,img.win,img.bkrd.backround,0,0);
	while (img.map[x] != NULL)
	{
		y = 0;
		while (img.map[x][y] != '\0')
		{
			if(img.map[x][y] == '1')
				mlx_put_image_to_window(img.mlx,img.win,img.wall.Wall, 58 * y,58 * x);
			else if (img.map[x][y] == 'P')
			{
				img = specifique_img_put_player(img);
				drawing_of_pixels(img,x * 58,y * 58);
			}
			y++;
		}
		x++;
	}
	
}

s_info_img specifique_direction(s_info_img img)
{
	if (img.last_directions == 'w' && img.map[img.player.pos_player_x - 1][img.player.pos_player_y] != '1') 
    {
        img.map[img.player.pos_player_x - 1][img.player.pos_player_y] = 'P';
        img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
       // img.player.pos_player_x--;
    }
    else if (img.last_directions == 'd' && img.map[img.player.pos_player_x][img.player.pos_player_y + 1] != '1')
    {
        img.map[img.player.pos_player_x][img.player.pos_player_y + 1] = 'P';
        img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
        //img.player.pos_player_y++;
    }
    else if (img.last_directions == 's' && img.map[img.player.pos_player_x + 1][img.player.pos_player_y] != '1') 
    {
        img.map[img.player.pos_player_x + 1][img.player.pos_player_y] = 'P';
        img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
		//img.player.pos_player_x++;
        
    }
    else if (img.last_directions == 'a' && img.map[img.player.pos_player_x][img.player.pos_player_y - 1] != '1' )
    {
       	img.map[img.player.pos_player_x][img.player.pos_player_y - 1] = 'P';
    	img.map[img.player.pos_player_x][img.player.pos_player_y] = '0';
       // img.player.pos_player_y--;
    }
	img = manage_img(img);
	return (img);///
}

void display_port(s_info_img img)
{
	mlx_put_image_to_window(img.mlx,img.win,img.excit.exict,img.excit.pos_y * 58,img.excit.pos_x * 58);
}

int count_coin(char** arr)
{
	int x;
	int y;
	int counter;

	x = 1;
	counter = 0;
	while (arr[x] != NULL)
	{
		y = 0;
		while (arr[x][y] != '\0')
		{
			if(arr[x][y] == 'C')
				counter++;
			y++;
		}
		x++;
	}
	return (counter);
}

int is_finish(s_info_img img)
{
	img.nbr_coin = count_coin(img.map);
	
	if(img.nbr_coin == 0)
		display_port(img);
	if (img.nbr_coin == 0 && img.player.pos_player_x == img.excit.pos_x && img.player.pos_player_y == img.excit.pos_y)
		return (1);
	return (0);	
}

int key_press(int keycode, s_info_img *im)
{
	s_info_img img;

	
	img = *im;
	img.last_directions = keycode;
    if (img.last_directions == 65307 )
    {
		clean_memory(img);
        mlx_clear_window(img.mlx, img.win);
        ft_free_arr(img.map);
        mlx_destroy_window(img.mlx, img.win);
        exit(0);
    }
    else
    {	
		img = specifique_img_put_player(img);
       *im = specifique_direction(img);
    }
    return 0;
}

void manage_positions_coin(s_info_img img,s_info_coin* coin)
{
	static int j = 1;
	static int i = 0;

	if (coin->is_token == 0)
	{	
		mlx_put_image_to_window(img.mlx,img.win,coin->arr[i],coin->y_pos * 58,coin->x_pos * 58);
		if (j++ % 10000 == 0)
			i++;
	}
	if(i == 8)
		i = 0;
}

int coin_found(s_info_img *mg)
{
	int x;
	int y;
	int i;
	s_info_img img;

	x = 0;
	i = 0;
	img = *mg;
	if(is_finish(img))
	{
		clean_memory(img);
		exit(1);
	}
	while (img.arr_coin[i] != NULL)
	{
		if (img.player.pos_player_x == img.arr_coin[i]->x_pos && img.player.pos_player_y == img.arr_coin[i]->y_pos)
			img.arr_coin[i]->is_token = 1;
		manage_positions_coin(img,img.arr_coin[i]);
		i++;
	}
	return (0);
	
}

void preprocessing_component_game(char* line)
{
	s_info_img img;
	char** arr;

	arr = ft_split(line,'\n');
	free(line);
	if(!arr)
		exit(-1);
	img = initialize(arr);

	drawing_component_game(img,'s');

	mlx_loop_hook(img.mlx,(int (*)(void*) )coin_found,&img);
	
	mlx_key_hook(img.win,key_press,&img);
	
	mlx_loop(img.mlx);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len);

int main(int ac, char *av[])
{
	char* line;

	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4],".ber",4))
	{	
		ft_putstr_fd("invalid map\n",1);
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
        perror("Usage: ./your_program <map_file>\n");
        return (1);
    }
    return (0);
}