/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:05:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/01/18 12:06:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# define KEY_PRESS_EVENT 2
# define KEY_RELEASE_EVENT 3
# define CLOSE_WIN_EVENT 17
# define CLOSE_WIN_MASK 1L << 17
# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1
# define ESC_KEY 0x35

#endif
