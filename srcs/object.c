#include "object.h"
#include "rtv1.h"
#include "geometry.h"
#include <stdlib.h>

t_object	*new_object(int type)
{
	t_object	*obj;
	
	if ((obj = (t_object *)malloc(sizeof(t_object))) != NULL)
	{
		ft_bzero(obj, sizeof(t_object));
		obj->type = type;
		obj->scale = (t_v3){1., 1., 1.};
	}
	return (obj);
}

t_light		*new_light(t_v3 direction)
{
	t_light		*light;
	
	if ((light = (t_light *)malloc(sizeof(t_light))) != NULL)
	{
		ft_bzero(light, sizeof(t_light));
		light->direction = normalize(direction);
	}
	return (light);
}

void		destroy_light(t_light *light)
{
	free(light);
}

void		destroy_object(t_object *obj)
{
	free(obj);
}