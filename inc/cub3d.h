/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:38:02 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/12 15:16:43 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define NOWALL 0
# define WALL 1

# define WIDTH 1920
# define HEIGHT 1080

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_player
{
// position of player
	double		x_pos;
	double		y_pos;
// direction of ray
	double		x_dir;
	double		y_dir;
// the bigger the plane the bigger the POV
	double		x_plane;
	double		y_plane;
}				t_player;

typedef struct s_ray
{
// camera plane
	double		x_camera;
// the map position of the player
	int			x_map;
	int			y_map;
// side_dist is the distance TO the first wall hit
// from x or y from the starting position
	double		x_side_dist;
	double		y_side_dist;
// delta_dist is the distance FROM the first wall hit 
// to the next wall in the x or y axes
	double		x_delta_dist;
	double		y_delta_dist;
// dir the ray is going
	double		x_ray_dir;
	double		y_ray_dir;
// to calculate perpendicular distance to wall from camera pov
// we calculate from camera pov to avoid fisheye effect
	double		perp_wall_dist;
// negative or positive step direction
	int			x_step;
	int			y_step;
// on which x the ray hits the wall
	double		x_wall;
// x of the texture we should use
	int			x_texture;
// whether vertical wall is hit
	bool		vertical_wall_hit;
}				t_ray;

typedef enum e_movement
{
	LEFT,
	RIGHT,
	FORWARD,
	BACKWARD,
	ROTATE_LEFT,
	ROTATE_RIGHT,
}				t_movement;

typedef enum e_direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
}				t_direction;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		*player;
	t_ray			*ray;

	mlx_texture_t	**text_arr;
	uint32_t		**pixels;

	int				line_height;
	int				draw_start;
	int				draw_end;

	int				**map;
	int				firstline_map;
	char			*we;
	char			*no;
	char			*so;
	char			*ea;
	uint32_t		*f;
	uint32_t		*c;
	int				x_player;
	int				y_player;
	t_direction		start_direction;
}					t_data;

//main
int			main(int argc, char **argv);

//init
void		initialize(t_data *data);

//rayzzz
void		raycasting(t_data *data);
void		calculate_ray_direction(t_data *data, int x);
void		calculate_delta_distance(t_ray *ray);
void		calculate_side_distance(t_player *player, t_ray *ray);
void		dda(t_data *data, t_ray *ray);

//draw
void		draw_line(t_data *data, int x);
void		put_stripe(t_data *data, int x, int y, int dir);

//hooks
void		key_hook(void *param);
//exit
void		close_mlx(t_data *data);
void		cleanup(t_data *data);

//error
void		check_input(int argc, char **argv);
void		*ft_malloc(size_t size);
void		print_error(char *s);

//utils
int			find_dir(t_data *data);
void		calculate_draw_vars(t_data *data);
void		free_textures(t_data *data, int texture);
void		texture_to_doubleptr(t_data *data);
void		init_north_south(t_data *data);
void		init_east_west(t_data *data);

int			find_pixel(t_data *data, double tex_pos);

//error check
int			find_first_line_map(char **original_array);

//----------------------------- PARSING -----------------------------//
int			check_texture(char **cub, int i, char *texture);
int			find_first_line_mapp(char **original_a);
int			parsing(char **twod, t_data *data);

//----------------------------- PARSING START -----------------------------//
char		**resize_array(char **array, int *capacity, int num_rows);
char		**initialize_array(int *capacity);
char		**read_and_store_lines(int fd, char **array, int *n_r, int *cap);
char		**read_cub_file_to_2d_array(const char *filename, int *num_rows);

//------------------------------FINAL PARSE---------------------------//
void		calculate_map_dimensions(char **cub, int *rows, int *cols);
void		final_parse(t_data *data, char **cub);
void		parse_rgb_values(uint32_t *color_array, char *rgb_str);
int			parse_int(char **str);
uint32_t	rgb_to_uint32(char *rgb_str);

//----------------------------- ERROR CHECK -----------------------------//
int			find_first_line_map(char **orig_ar);
int			count_rows_in_file(const char *filename);

//----------------------------- CHECK TOP-----------------------------//
int			check_top_map(char **cub, int f_l);
int			check_position(char *line, char *dir);
int			check_colors(char *line, char *dir);
int			check_position_c(char *line, char *dir);
int			check_three_variables(char *line);

//----------------------------- CHECK TOP END -----------------------------//
int			is_valid_format(const char *str);
int			validate_numbers_in_range(const char *str);
void		process_wall_textures(t_data *data, char **cub);
int			char_to_int(char c);
void		process_floor_ceiling_colors(t_data *data, char **cub);

//----------------------------- MAP CHECK -----------------------------//
int			check_map(char **cub, int f_l, t_data *data);
int			check_first_line_map(char *line);
int			check_map_loop(char **cub, int f_l);
int			check_up_and_main(char *main, char *up);
int			check_endings_map(char **cub, int start);

//----------------------------- PLAYER CHECK -----------------------------//
void		get_coordinates(t_data *data, char **cub, int start, int i);
int			check_player(char **cub, int start, t_data *data);
void		get_start_direction(char c, t_data *data);

//----------------------------- UTILS PARSING -----------------------------//
char		*str_n_copy(const char *src, int start);
int			ft_isspace(int c);
int			check_ends_line(char *line);
int			check_last_line(char *line);
int			find_map_start(char **cub);

//----------------------------- ALLOCATE MAP -----------------------------//
void		process_map(t_data *data, char **cub);
void		populate_map(t_data *data, char **cub, int rows, int cols);
void		allocate_map_memory(t_data *data, int rows, int cols);
void		calc_map_dimension(char **cub, int map_start, int *rows, int *cols);
int			find_map_start(char **cub);
int			ft_strncmp_c(const char *s1, const char *s2, size_t n);
int			get_start_point(char *line);
int			check_valid_chars(char *line);
int			check_commas(char *line);

#endif