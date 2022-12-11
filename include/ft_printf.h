/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:51:32 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 16:53:48 by naal-jen         ###   ########.fr       */
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

/* -------------------------------------------------------------------------- */
/*                            process_int_unsigned                            */
/* -------------------------------------------------------------------------- */
void		number(long int n, t_hint *loco);
void		number_unsigned(unsigned n, t_hint *loco);

/* ------------------------- process_int_unsigned_1 ------------------------- */
void		number_unsigned_else(unsigned n, t_hint *loco);
void		number_1(long int n, t_hint *loco);

void		ifhex_1(unsigned int number, int length, t_hint *loco);

void		str_five(char *string, t_hint *loco);
void		str_six(char *string, t_hint *loco);

void		width_seven(const char *str, t_hint *loco, int *i);
void		width_six(const char *str, t_hint *loco, int *i);

void		me_dot_str_1(char *string, t_hint *loco, size_t num, size_t wido);
void		stringo_1(char *string, t_hint *loco);
char		*stringo_2(char *string, t_hint *loco);
char		*stringo_3(char *string, t_hint *loco);
void		me_dot_stringo(char *string, t_hint *loco);

int			width_process_1(const char *str, t_hint *loco, int i);
int			left_process_1(const char *str, t_hint *loco, int i);
int			*me_dot_1(const char *str, t_hint *loco, int *i);

void		int_helper_four_1(long int n, int num, t_hint *loco);
void		int_helper_four_2(int num, t_hint *loco);
void		int_helper_four_3(int num, t_hint *loco);
void		int_helper_four_4(int num, t_hint *loco);
void		int_helper_four_5(int num, t_hint *loco);
void		int_helper_four_6(long int n, int num, t_hint *loco);
void		int_helper_1(t_hint *loco);
void		int_helper_2(t_hint *loco);
void		int_helper_3(t_hint *loco);
void		int_helper_4(t_hint *loco);
void		int_helper_5(t_hint *loco);

int			ft_printf(const char *str, ...);
void		ifpointer(uintptr_t number, t_hint *loco);
void		ifhex(unsigned int number, char cha, t_hint *loco);
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
void		fail(void);
void		handle_string_null(char *string, t_hint *loco);
int			count_digits(long int n);

#endif