/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:03:51 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 13:14:04 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

t_hint	*my_struct(void)
{
	t_hint	*loco;

	loco = (t_hint *)malloc(sizeof(t_hint));
	if (!loco)
		return (NULL);
	loco->count = 1;
	loco->inc = 0;
	loco->width = 0;
	loco->type[0] = 0;
	loco->type[1] = 0;
	loco->processed = 0;
	return (loco);
}

int	*new_i(void)
{
	int	*i;

	i = (int *)malloc(sizeof(int));
	if (!i)
		return (NULL);
	*i = 0;
	return (i);
}
