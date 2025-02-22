
#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  // For open() and O_RDONLY
#include <unistd.h> // For close() and other system calls
#include <stdio.h>  // For standard I/O functions

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <stddef.h>

// #define  img_width = 600;
// #define img_height = 1066 ;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 165
#endif

typedef struct s_info_player
{
    int pos_player_x;
    int pos_player_y;
    int* xpm_current_put;
    void * img_frond;
    void * img_left;
    void * img_rigth;
    void * img_back;
    int * xpm_frond;
    int * xpm_left;
    int * xpm_rigth;
    int * xpm_back;
    int x;
    int y;

}s_info_player;

typedef struct s_info_coin
{
    int x_coin;
    int y_coin;
    int x_back;
    int y_back;
    int x_pos;
    int y_pos;
    void** arr;
    int is_token;
    int* xpm_coin;

}s_info_coin;

typedef struct s_pos_player_and_w_h
{
    int wiedth;
    int heigth;
    int x_pos;
    int y_pos;
    int x_pos_exi;
    int y_pos_exi;
    int nb_coin;
}s_pos_player_and_w_h;

typedef struct s_info_wall
{
    int x_wall;
    int y_wall;
    void* Wall;
    int* xpm_wall;

}s_info_wall;

typedef struct s_info_exict
{
    void* exict;
    int pos_x;
    int pos_y;
    int x_ex;
    int y_ex;

}s_info_exict;

typedef struct s_info_bg
{
    int x_bg;
    int y_bg;
    void* backround;
    int* xpm_backround;
}s_info_bg;

typedef struct s_info_enamy
{
    int x_enamy;
    int y_enamy;
    int x_pos;
    int y_pos;
    void** arr;
    void* enamy;
}s_info_enamy;

typedef struct s_info_img
{
    void* win;
    void * mlx;
    char** map;
    int last_directions;
    s_info_player player;
    s_info_bg bkrd;
    s_info_coin **arr_coin;
    s_info_enamy **arr_enamys;
    int nbr_coin;
    int nbr_enamy;
    int count_nbr_step;
    int staus_error;
    s_info_exict excit;
    s_info_wall wall;
   
   
}s_info_img;



typedef struct components
{
    int wall;
    int exit;
    int collectible;
    int start_pos;
    int x;
    int y;

}components_map;

void manage_positions_enamy(s_info_img img,s_info_enamy* enamy);
void  initialize(s_info_img *img,char** arr);
s_info_wall initialize_wall(char* mlx,int* error);
s_info_exict initialize_excit(char* mlx,int* error);
s_info_coin** initialize_all_coin(char* mlx,char** arr,int nbr_coin,int* error);
s_info_coin* initialize_coin(char* mlx,int x,int y);
s_pos_player_and_w_h get_positions_player_wie_and_hei_windo_and_number_coin(char** arr);
s_info_player initialize_player(void* mlx,int* status_error);
s_info_bg initialize_bg(char* mlx,int* error);
void initialize_coin_help(s_info_coin* coin,void *mlx,int* error);

s_info_enamy** initialize_all_enamys(char* mlx,char** arr,int nbr_enamy,int* error);
s_info_enamy *initialize_enamy(char* mlx,int x,int y);
void initialize_enamy_help(s_info_enamy* enamy,void *mlx,int* error);
void clean_memory(s_info_img* img);
void ft_free_struct_player(s_info_player player,void* mlx);
void ft_free_struct_to_array_coin(s_info_coin **arr_coin,void* mlx);
void ft_free_struct_coin(s_info_coin* coin,void* mlx);
void ft_free_arr(char** arr);
int	ft_strncmp(const char *s1, const char *s2, size_t len);
int count_what_do_you_want(char** arr,char c);
int enamy_found(s_info_img *mg);

int coin_found(s_info_img *mg);
int is_finish(s_info_img img);
void ft_free_arry(char** arr);
void print_nbr_step(s_info_img img);
void drawing_component_game(s_info_img img,int derict);
void drawing_backround_player(s_info_img img,int x_p,int y_p);
void drawing_of_pixels(s_info_img img,int x_p,int y_p);
s_info_img manage_img(s_info_img img);

void manage_positions_coin(s_info_img img,s_info_coin* coin);
s_info_img specifique_direction(s_info_img img);
s_info_img specifique_img_put_player(s_info_img img);
char	*get_than_line(char *s_str);
char	*get_read_str(int fd, char *s_str);
char	*ftt_strjoin(char *s1, char *s2);
char	*get_remminder(char *s_str);
char	*get_next_line(int fd);
int	    ftt_strchr(const char *str, char search_str);

char*    load_date_from_map(char* map);
char*	 ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int     open_file(char* map);
char	**ft_split(char const *str, char c);
int     count_newline(char* data);
void    ft_error_map(char** arr);
components_map count_nbr_component(char** arr,int i,int j);
void    floodfill(char** arr, int x, int y);
void    check_map_help(char** arr);
void	check_map(char *data);
void    assign_start(components_map* cmpnt);
int     is_found_e(char** arr);


#endif