/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:51:32 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/30 12:43:51 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdint.h>// uintptr_t 
# include	<stdio.h>
# include	<unistd.h>// write
# include	<stdlib.h>// malloc free
# include	<stdarg.h>// va_start va_arg va_copy va_end va_list

typedef struct s_hint
{
	int		count;
	int		width;
	int		widthx;
	char	type[3];
	int		inc;
	int		processed;
	int		arg;
	va_list	args2;
}		t_hint;

int			ft_printf(const char *str, ...);
void		ifpointer(uintptr_t number, t_hint *loco);
void		ifhex(unsigned int number, char cha, t_hint *loco);
void		number(long int n, t_hint *loco);
void		number_unsigned(unsigned n, t_hint *loco);
void		stringo(char *string, t_hint *loco);
void		me_char(va_list args, t_hint *loco);
void		process_octal(unsigned int n, t_hint *loco);
void		process_hash_flag(va_list args, t_hint *loco);
t_hint		*my_struct(void);
int			*new_i(void);
int			width_process(const char *str, t_hint *loco, int i);
int			left_process(const char *str, t_hint *loco, int i);
int			leading_process(const char *str, t_hint *loco, int i);
int			me_space(const char *str, t_hint *loco, int i);
int			me_plus(const char *str, t_hint *loco, int i);
int			me_hash(va_list args, t_hint *loco, const char *str, int i);
void		width_percent(const char *str, t_hint *loco, int *i);
void		pointer_helper(t_hint *loco, char cha);
void		ifhex_helper(char cha, t_hint *loco);
void		me_dot_number(t_hint *loco);
void		hex(t_hint *loco);
void		pointer(t_hint *loco, char cha);
void		ifhex_helper_two(t_hint *loco);
void		ifhex_t(unsigned int number, char *string, int length, char cha);
void		ifp_help(t_hint *loco, size_t num);
void		ifp_help_one(char *string);
char		*numberlength(unsigned long number, int *length);
void		ifp_help_two(t_hint *loco, size_t num);
void		ifp_help_four(t_hint *loco, char *string);
void		hash_one(t_hint *loco, const char *str, int *i, int *modf);
void		hash_two(t_hint *loco, const char *str, int *i, int *modf);
void		hash_three(t_hint *loco, const char *str, int *i, int *modf);
void		hash_four(t_hint *loco, const char *str, int *i, int *modf);
int			hash_five(t_hint *loco, const char *str, int *i, int *modf);
void		str_one(size_t wido, char *string, t_hint *loco);
void		str_two(size_t num, char *string, t_hint *loco);
void		str_three(size_t num, char *string, t_hint *loco);
void		str_four(char *string, t_hint *loco);
void		int_helper(long int n, t_hint *loco);
void		int_helper_one(t_hint *loco);
void		int_helper_three(long int n, t_hint *loco);
void		int_helper_four(long int n, int num, t_hint *loco);
void		int_helper_five(long int n, t_hint *loco);
void		width_one(const char *str, t_hint *loco, int *i);
void		width_two(const char *str, t_hint *loco, int *i);
void		width_three(const char *str, t_hint *loco, int *i);
void		width_four(const char *str, t_hint *loco, int *i);
void		width_five(const char *str, t_hint *loco, int *i);
void		fail();
void		handle_string_null(char *string, t_hint *loco);
int			count_digits(long int n);

#endif