#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "libft.h"
# include "display.h"
# include "geometry.h"
# include "object.h"
# include "raytracer.h"
# include "scene.h"
# include "color.h"
# include "parsing.h"

# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE !FALSE

typedef struct		s_ram
{
	t_parsing		parsing;
	t_display		*display;
	t_scene			*scene;
}					t_ram;

typedef int			(*t_parse_f)(t_ram *ram);

void				t_parse_file(t_ram *ram);
int					parse_object(t_ram *ram);
int					parse_camera(t_ram *ram);
int					parse_light(t_ram *ram);
int					main_loop(t_ram *ram);
t_ram				*init_ram_pre_parsing(void);
void				init_ram_post_parsing(t_ram *ram);
void				free_ram(t_ram *ram);
void				init_display(t_ram *ram);
void				free_display(t_display *display);
void				init_scene(t_ram *ram);
void 				free_scene(t_scene *scene);
void				free_parsing(t_parsing *parsing);
int					init_hooks(t_ram *ram);
void				pixel_put(t_image *img, int x, int y, unsigned int color);
int					render_scene(t_ram *ram);
void				exit_message(t_ram *ram, int exit_code, char *message);
int					intersection(t_scene *scene, t_ray * const ray, double epsilon);
int					closest_intersection(t_scene *scene, t_ray * const ray, t_hit *dst);
void				shade_pixel(t_ram *ram, t_hit *h, t_ray *ray, t_color *color);

#endif
