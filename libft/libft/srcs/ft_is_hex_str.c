/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_hex_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeyer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:44:24 by lmeyer            #+#    #+#             */
/*   Updated: 2016/12/03 17:46:04 by lmeyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_hex_str(char *s)
{
	return (s && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'));
}
