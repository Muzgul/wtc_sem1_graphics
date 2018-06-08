#include "libft/libft.h"
#include "minilibx/mlx.h"

#ifndef HEADER_H
#define HEADER_H

//Type Declerations

typedef struct		mlx_control
{
	void    *mlx_ptr;
    void    *mlx_win;
    char    **map;
    int     map_w;
    int     map_h;
    int     zoom;
    int     resX;
    int     resY;
    int     camX;
    int     camY;
}					mlx_ctrl;

//Function Declerations

char    **read_to_array(int fd);
char    **add_to_array(char **array, char *row);
int     row_count(char **array);
int     row_length(char **array);
void    print_array(char **array);
void    draw_array(mlx_ctrl *my_mlx);
void    draw_row(mlx_ctrl *my_mlx, int row);
void    draw_point(mlx_ctrl *my_mlx, int row, int point);
void    clear(mlx_ctrl *my_mlx);

void    new_window(mlx_ctrl *my_mlx, int res_x, int res_y, char *title);
int     key_hook(int keycode, mlx_ctrl *my_mlx);
int     mouse_hook(int button, int x, int y, void *param);
int     expose_hook(mlx_ctrl *my_mlx);
int     loop_hook(mlx_ctrl *my_mlx);
void    run_loop(mlx_ctrl *my_mlx);
void    initialise_mlx(mlx_ctrl **my_mlx);
void    initialise_map(mlx_ctrl *my_mlx, int fd);


#endif