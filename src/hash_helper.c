/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 21:21:24 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 17:17:08 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	hash_one(t_hint *loco, const char *str, int *i, int *modf)
{
	if (str[(*i) + 1] == '-')
		loco->type[0] = '-';
	(*i)++;
	while (ft_isdigit(str[(*i)]) == 0)
		(*i)++;
	while (ft_isdigit(str[(*i)]) == 1)
	{
		loco->width += str[(*i)] - '0';
		if (ft_isdigit(str[(*i) + 1]) == 1)
			loco->width *= 10;
		(*i)++;
	}
	(*i) = (*modf);
}

void	hash_two(t_hint *loco, const char *str, int *i, int *modf)
{
	(*modf) = (*i);
	loco->type[0] = '.';
	loco->type[1] = '-';
	loco->type[2] = '+';
	(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->widthx += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->widthx *= 10;
		(*modf)++;
	}
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->width += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->width *= 10;
		(*modf)++;
	}
	loco->widthx -= loco->width;
	(*i) = (*modf);
}

void	hash_three(t_hint *loco, const char *str, int *i, int *modf)
{
	(*modf) = (*i);
	loco->type[0] = '.';
	loco->type[1] = '-';
	(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->widthx += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->widthx *= 10;
		(*modf)++;
	}
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->width += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->width *= 10;
		(*modf)++;
	}
	loco->widthx -= loco->width;
	(*i) = (*modf);
}

void	hash_four(t_hint *loco, const char *str, int *i, int *modf)
{
	(*modf) = (*i);
	loco->type[0] = '.';
	loco->type[1] = '-';
	loco->type[2] = 'q';
	(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->widthx += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->widthx *= 10;
		(*modf)++;
	}
	while (ft_isdigit(str[(*modf)]) == 0)
		(*modf)++;
	while (ft_isdigit(str[(*modf)]) == 1)
	{
		loco->width += str[(*modf)] - '0';
		if (ft_isdigit(str[(*modf) + 1]) == 1)
			loco->width *= 10;
		(*modf)++;
	}
	loco->widthx -= loco->width;
	(*i) = (*modf);
}

int	hash_five(t_hint *loco, const char *str, int *i, int *modf)
{
	(*modf) = (*i);
	while (str[(*modf)] != '\0')
		(*modf)++;
	(*modf)--;
	if (str[(*modf)] == '%')
		return ((*modf));
	else if (str[(*modf)] == 'c' || str[(*modf)] == 's')
		hash_one(loco, str, i, modf);
	else if (str[(*modf)] == 'i' || str[(*modf)] == 'd')
		hash_two(loco, str, i, modf);
	else if (str[(*modf)] == 'u')
		hash_three(loco, str, i, modf);
	else if (str[(*modf)] == 'x' || str[(*modf)] == 'X')
	{
		loco->type[2] = 'm';
		if (str[(*i)] == '0' && ft_isdigit(str[(*i) + 1]) == 1)
			(*i) = leading_process(str, loco, (*i));
		else if (str[(*i)] == '-' && ft_isdigit(str[(*i) + 1]) == 1)
			(*i) = left_process(str, loco, (*i));
		else
			hash_four(loco, str, i, modf);
	}
	return ((*i));
}
