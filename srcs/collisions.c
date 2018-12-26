#include "geometry.h"
#include "rtv1.h"
#include "raytracer.h"
#include "object.h"

void	offset_ray(t_ray *ray, t_object *ob)
{
	t_v4	inverse_scale;

	inverse_scale = (t_v4){1 / ob->scale.x,
			1 / ob->scale.y, 1 / ob->scale.z, ob->scale.w};
	ray->origin = translate(ray->origin, (t_v4){- ob->position.x,
			- ob->position.y, - ob->position.z, ob->position.w});
	ray->origin = rotate_z(ray->origin, -(ob->rotation.z));
	ray->origin = rotate_y(ray->origin, -(ob->rotation.y));
	ray->origin = rotate_x(ray->origin, -(ob->rotation.x));
	ray->origin = scale(ray->origin, inverse_scale);
	ray->direction = rotate_z(ray->direction, -(ob->rotation.z));
	ray->direction = rotate_y(ray->direction, -(ob->rotation.y));
	ray->direction = rotate_x(ray->direction, -(ob->rotation.x));
	ray->direction = scale(ray->direction, inverse_scale);
}

void	get_collision(t_hit *out, t_ray ray, t_object *object)
{
	offset_ray(&ray, object);
	if (object->type == SPHERE)
		hit_sphere(out, &ray, object);
	else if (object->type == PLANE)
		hit_plane(out, &ray, object);
}