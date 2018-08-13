#include "libft/libft.h"
#include "minilibx/mlx.h"

#ifndef HEADER_H
#define HEADER_H

//Type Declerations

typedef struct		mlx_control
{
	void    *mlx_ptr;
    void    *mlx_win;
    int     **map;
    int     map_w;
    int     map_h;
    int     zoom;
    int     resX;
    int     resY;
    int     camX;
    int     camY;
}					mlx_ctrl;

//Function Declerations

void    read_save(int fd, mlx_ctrl *my_mlx);
char    **read_to_array(int fd);
char    **add_to_array(char **array, char *row);
int     row_count(void **array);
int     split_and_count(char *line, char c);
int     *convert_row(char *row);
void    print_array(mlx_ctrl *my_mlx);
void    draw_array(mlx_ctrl *my_mlx);
void    draw_row(mlx_ctrl *my_mlx, int row);
void    draw_point(mlx_ctrl *my_mlx, int row, int point);
int     calculate_x(mlx_ctrl *my_mlx, int row, int point);
int     calculate_y(mlx_ctrl *my_mlx, int row, int point);
void    clear(mlx_ctrl *my_mlx);

void    new_window(mlx_ctrl *my_mlx, int res_x, int res_y, char *title);
int     key_hook(int keycode, mlx_ctrl *my_mlx);
int     mouse_hook(int button, int x, int y, void *param);
int     expose_hook(mlx_ctrl *my_mlx);
int     loop_hook(mlx_ctrl *my_mlx);
void    run_loop(mlx_ctrl *my_mlx);
void    initialise_mlx(mlx_ctrl **my_mlx);
void    initialise_map(mlx_ctrl *my_mlx, int fd);

//NEW

int     temp_draw_point(mlx_ctrl *my_mlx, int *point);
int     *make_point(int x, int y, int z);
int     temp_draw_line(mlx_ctrl *my_mlx, int *p1, int *p2);

#endif