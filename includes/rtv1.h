#ifndef RTV1_H
# define RTV1_H
# include "mlx.h"
# include "libft.h"
# include "display.h"
# include "geometry.h"
# include "object.h"
# include "raytracer.h"
# include "scene.h"

# define ERROR -1
# define SUCCESS 0
# define FALSE 0
# define TRUE !FALSE

typedef struct		s_ram
{
	t_display		*display;
	t_scene			*scene;
}					t_ram;

int					main_loop(t_ram *ram);
t_ram				*init_ram(void);
void				free_ram(t_ram *ram);
void				init_display(t_ram *ram);
void				free_display(t_display *display);
void				init_scene(t_ram *ram);
void 				free_scene(t_scene *scene);
t_object			*new_object(int type);
void				destroy_object(t_object *obj);
int					init_hooks(t_ram *ram);
void				pixel_put(t_image *img, int x, int y, unsigned int color);
int					render_scene(t_ram *ram);
void				exit_message(t_ram *ram, int exit_code, char *message);

#endif