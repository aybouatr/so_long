
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
    char* arr[8];
    int is_token;
    int x_pos;
    int y_pos;
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
    char* Wall;
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
    char* backround;
    int* xpm_backround;
}s_info_bg;

typedef struct s_info_img
{
    void* win;
    char* mlx;
    char** map;
    int last_directions;
    s_info_player player;
    s_info_bg bkrd;
    s_info_coin **arr_coin;
    int nbr_coin;
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



char	*get_than_line(char *s_str);
char	*get_read_str(int fd, char *s_str);
char	*ftt_strjoin(char *s1, char *s2);
char	*get_remminder(char *s_str);
char	*get_next_line(int fd);
int	    ftt_strchr(const char *str, char search_str);

char*    load_date_from_map(char* map);

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
void ft_free_arry(char* arr[]);

#endif