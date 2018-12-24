/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:46:51 by lmeyer            #+#    #+#             */
/*   Updated: 2018/09/28 19:55:47 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_ARRAY_H
# define INT_ARRAY_H

typedef struct	s_int_array
{
	int			capacity;
	int			count;
	int			*data;
}				t_int_array;

int				int_first(t_int_array *array);
int				int_last(t_int_array *array);
int				int_min(t_int_array *array);
int				int_max(t_int_array *array);
int				int_min_index(t_int_array *array);
void			int_set(t_int_array *array, int position, int value);
void			int_unshift(t_int_array *array, int value);
void			int_push(t_int_array *array, int value);
int				int_pop(t_int_array *array);
int				int_index(t_int_array *array, int i);
void			int_insert(t_int_array *array, int index, int value);
int				int_remove(t_int_array *array, int index);
void			free_int_array(t_int_array *array);
void			reallocate(t_int_array *array);
t_int_array		*new_int_array(int capacity);
t_int_array		*copy_int_array(t_int_array *src);
t_int_array		*upper_percentile(t_int_array *src, int percent);
t_int_array		*int_values_to_ranks(t_int_array *array);
t_int_array		*int_not_in(t_int_array *src, t_int_array *exclude);
void			sort_int_array(t_int_array *array);

#endif
