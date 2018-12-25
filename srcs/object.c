#include "object.h"
#include "rtv1.h"
#include <stdlib.h>

t_object	*new_object(int type)
{
	t_object	*obj;
	
	if ((obj = (t_object *)malloc(sizeof(t_object))) != NULL)
	{
		ft_bzero(obj, sizeof(t_object));
		obj->type = type;
	}
	return (obj);
}

void		destroy_object(t_object *obj)
{
	free(obj);
}