/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:05:15 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/30 18:24:30 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"
#include <limits.h>

static int	*proc(const char *str, va_list args, t_hint *loco, int *i)
{
	if (str[*i] == '#')
		*i = me_hash(args, loco, str, ++(*i));
	if (str[*i] == 'c' && loco->count++ && loco->processed == 0)
		me_char(args, loco);
	else if (str[*i] == 's' && loco->processed == 0)
		stringo(va_arg(args, char *), loco);
	else if (str[*i] == 'p' && loco->count++ && loco->processed == 0)
		ifpointer(va_arg(args, uintptr_t), loco);
	else if ((str[*i] == 'd' || str[*i] == 'i') && loco->processed == 0)
		number(va_arg(args, int), loco);
	else if (str[*i] == 'u' && loco->processed == 0)
		number_unsigned(va_arg(args, unsigned int), loco);
	else if ((str[*i] == 'x' || str[*i] == 'X') && loco->processed == 0)
		ifhex(va_arg(args, unsigned int), str[*i], loco);
	else if (str[*i] == '%' && loco->count++ && loco->processed == 0)
		write (1, "%", 1);
	else if (str[*i] == '\0')
		return (i);
	else if (loco->processed == 0)
	{
		width_percent(str, loco, i);
		loco->count++;
	}
	loco->processed = 0;
	return (i);
}

static void	proc_f(const char *str, int *i, t_hint *loco)
{
	if (str[*i] == '0')
		*i = leading_process(str, loco, (*i));
	else if (str[*i] == '.')
		*i = leading_process(str, loco, (*i));
	else if ((str[(*i) - 1] == '%') && (str[*i] == ' '))
		*i = me_space(str, loco, (*i));
	else if (str[*i] == '+')
		*i = me_plus(str, loco, (*i));
	else if (ft_isdigit(str[*i]) == 1)
		*i = width_process(str, loco, (*i));
	else if (str[*i] == '-')
		*i = left_process(str, loco, (*i));
}

static void	general_process(const char *str, int *i, va_list args, t_hint *loco)
{
	while (str[*i])
	{
		if (str[*i] != '%' && loco->count++)
			ft_putchar_fd(str[*i], 1);
		else if (str[(*i)++] == '%')
		{
			proc_f(str, i, loco);
			proc(str, args, loco, i);
			if (loco->type[1] == 'n')
				return ;
			loco->width = 0;
			loco->widthx = 0;
			loco->type[0] = 0;
			loco->type[1] = 0;
			loco->type[2] = 0;
			if (str[*i] == '\0')
				return ;
		}
		(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_hint	*loco;
	int		*i;
	int		result;

	result = 0;
	loco = my_struct();
	va_start(args, str);
	va_copy(loco->args2, args); // to be canceled with it flags
	i = new_i();
	general_process(str, i, args, loco);
	result = loco->count - 1;
	va_end(args);
	va_end(loco->args2);
	free(loco);
	free(i);
	return (result);
}

// int	main(void)
// {
// // 	s_hidden = "hi low\0don't print me lol\0"

// 	printf(" %d\n", printf("%5.x", 0));
// 	ft_printf("\n%5.x", 0);
// 	// ft_printf(" %d\n\n", ft_printf("%5.x", 0));
	
// 	// printf(" %d\n", printf("%5.0x", 0));
// 	// ft_printf(" %d\n\n", ft_printf("%5.0x", 0));
	
// 	// printf(" %d\n", printf("%5.0X", 0));
// 	// ft_printf(" %d\n\n", ft_printf("%5.0X", 0));
	
// // 	printf(" %d\n", printf("%197c" ,7));
// // 	ft_printf(" %d\n\n", ft_printf("%197c" ,7));
	
// // 	printf(" %d\n", printf("%12p" ,(void*)18229185041105221837lu));
// // 	ft_printf(" %d\n\n", ft_printf("%12p" ,(void*)18229185041105221837lu));
	
// // 	printf(" %d\n", printf("%013.i" ,-1488496170));
// // 	ft_printf(" %d\n\n", ft_printf("%013.i" ,-1488496170));
	
// // 	printf(" %d\n", printf("%--147.185x" ,703835510u));
// // 	ft_printf(" %d\n\n", ft_printf("%--147.185x" ,703835510u));
	
// // 	printf(" %d\n", printf("%-1c" ,120));
// // 	ft_printf(" %d\n\n", ft_printf("%-1c" ,120));
	
// // 	printf(" %d\n", printf("%197c%12p%013.i%--147.185x%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120));
// // 	ft_printf(" %d\n\n", ft_printf("%197c%12p%013.i%--147.185x%-1c" ,7,(void*)18229185041105221837lu,-1488496170,703835510u,120));
	
// // 	printf(" %d\n", printf("%00054.91x%-119.117s%.120s%-3.12X" ,2341589136u,"V0dP#8kjTEcV7&k(cX>QVDa","oUyFMC$9``PRmEAG|~@|`<^'Q@",198320040u));
// // 	ft_printf(" %d\n\n", ft_printf("%00054.91x%-119.117s%.120s%-3.12X" ,2341589136u,"V0dP#8kjTEcV7&k(cX>QVDa","oUyFMC$9``PRmEAG|~@|`<^'Q@",198320040u));
	
// // 	printf(" %d\n", printf("%08.3i", -8473));
// // 	ft_printf(" %d\n\n", ft_printf("%08.3i", -8473));
	
// // 	printf(" %d\n", printf("%07i", -54));
// // 	ft_printf(" %d\n\n", ft_printf("%07i", -54));
	
// // 	printf(" %d\n", printf("%020.5i", -1024));
// // 	ft_printf(" %d\n\n", ft_printf("%020.5i", -1024));
	
// // 	printf(" %d\n", printf("%020.5d", -1024));
// // 	ft_printf(" %d\n\n", ft_printf("%020.5d", -1024));
	
// // 	printf(" %d\n", printf("%00054.91x" ,2341589136u));
// // 	ft_printf(" %d\n\n", ft_printf("%00054.91x" ,2341589136u));
	
// // 	printf(" %d\n", printf("%-119.117s" ,"V0dP#8kjTEcV7&k(cX>QVDa"));
// // 	ft_printf(" %d\n\n", ft_printf("%-119.117s" ,"V0dP#8kjTEcV7&k(cX>QVDa"));
	
// // 	printf(" %d\n", printf("%.120s" ,"oUyFMC$9``PRmEAG|~@|`<^'Q@"));
// // 	ft_printf(" %d\n\n", ft_printf("%.120s" ,"oUyFMC$9``PRmEAG|~@|`<^'Q@"));
	
// // 	printf(" %d\n", printf("%-3.12X" ,198320040u));
// // 	ft_printf(" %d\n\n", ft_printf("%-3.12X", 198320040u));
	
// // 	printf(" %d\n", printf("%090.196X" ,905350113u));
// // 	ft_printf(" %d\n\n", ft_printf("%090.196X" ,905350113u));
	
// // 	printf(" %d\n", printf("%0197.108d", -1350090454));
// // 	ft_printf(" %d\n\n", ft_printf("%0197.108d", -1350090454));
	
// // 	printf(" %d\n", printf("%090.196X%0197.108d" ,905350113u,-1350090454));
// // 	ft_printf(" %d\n\n", ft_printf("%090.196X%0197.108d" ,905350113u,-1350090454));
	
// // 	printf(" %d\n", printf("%010.5i", -216));
// // 	ft_printf(" %d\n\n", ft_printf("%010.5i", -216));

// // 	printf(" %d\n", printf("%07i", -54));
// // 	ft_printf(" %d\n\n", ft_printf("%07i", -54));
	
// // 	printf(" %d\n", printf("%000132.141i" ,-1143516304));
// // 	ft_printf(" %d\n\n", ft_printf("%000132.141i" ,-1143516304));
	
// // 	printf(" %d\n", printf("%0163.109u" ,2109506632u));
// // 	ft_printf(" %d\n\n", ft_printf("%0163.109u" ,2109506632u));

// // 	printf(" %d\n", printf("%-140.69d" ,-1086209677));
// // 	ft_printf(" %d\n\n", ft_printf("%-140.69d" ,-1086209677));
	
// // 	printf(" %d\n", printf("%---91.148s" ,"\nmD^8<.q*'\rD"));
// // 	ft_printf(" %d\n\n", ft_printf("%---91.148s" ,"\nmD^8<.q*'\rD"));
	
// // 	printf(" %d\n", printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170x" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u));
// // 	ft_printf(" %d\n\n", ft_printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170x" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u));
	
// // 	printf(" %d\n", printf("%-45c%--157.185d" ,118,1175809301));
// // 	ft_printf(" %d\n\n", ft_printf("%-45c%--157.185d" ,118,1175809301));

// // 	printf(" %d\n", printf("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u));
// // 	ft_printf(" %d\n\n", ft_printf("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u));
	
// // 	printf(" %d\n", printf("%073.83x%00056.187d%-%%-78.56X%-104.170X" ,898043181u,1522753180,2837283853u,207713687u));
// // 	ft_printf(" %d\n\n", ft_printf("%073.83x%00056.187d%-%%-78.56X%-104.170X" ,898043181u,1522753180,2837283853u,207713687u));
	
// // 	printf(" %d\n", printf("%-16.3u%-8.0X" ,3421138903u,514939578u));
// // 	ft_printf(" %d\n\n", ft_printf("%-16.3u%-8.0X" ,3421138903u,514939578u));
	
// // 	printf(" %d\n", printf("%20.0X", -0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%20.0X", -0x1234abcdu));
	
// // 	printf(" %d\n", printf("%20.X", 0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%20.X", 0x1234abcdu));
	
// // 	printf(" %d\n", printf("%20.0x", -0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%20.0x", -0x1234abcdu));
	
// // 	printf(" %d\n", printf("%20.x", 0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%20.x", 0x1234abcdu));

// // 	printf(" %d\n", printf("%020.10X", -0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%020.10X", -0x1234abcdu));

// // 	printf(" %d\n", printf("%020.10x", -0x1234abcdu));
// // 	ft_printf(" %d\n\n", ft_printf("%020.10x", -0x1234abcdu));

// // 	printf(" %d\n", printf("%20.5d", -1024));
// // 	ft_printf(" %d\n\n", ft_printf("%20.5d", -1024));

// // 	printf(" %d\n", printf("t9 %2.2d", 10));
// // 	ft_printf(" %d\n\n", ft_printf("t9 %2.2d", 10));

// // 	printf(" %d\n", printf("t3 %10.0d", 10));
// // 	ft_printf(" %d\n\n", ft_printf("t3 %10.0d", 10));

// // 	printf(" %d\n", printf("%5.0s", "Hello"));
// // 	ft_printf(" %d\n\n", ft_printf("%5.0s", "Hello"));

// // 	printf(" %d\n", printf("%.09s", NULL));
// // 	ft_printf(" %d\n\n", ft_printf("%.09s", NULL));

// // 	printf(" %d\n", printf("p3 %.4s", NULL));
// // 	ft_printf(" %d\n\n", ft_printf("p3 %.4s", NULL));

// // 	printf(" %d\n", printf("%15.4d", -424242));
// // 	ft_printf(" %d\n\n", ft_printf("%15.4d", -424242));

// // 	printf(" %d\n", printf("%8.3i", 8375));
// // 	ft_printf(" %d\n\n", ft_printf("%8.3i", 8375));

// // 	printf(" %d\n", printf("%15.4d", 424242));
// // 	ft_printf(" %d\n\n", ft_printf("%15.4d", 424242));
	
// // 	printf(" %d\n", printf("%5.0u", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%5.0u", 0));

// // 	printf(" %d\n", printf("%8.3u", 8375));
// // 	ft_printf(" %d\n\n", ft_printf("%8.3u", 8375));

// // 	printf(" %d\n", printf("%5.i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%5.i", 0));

// // 	printf(" %d\n", printf("%5.0i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%5.0i", 0));

// // 	printf(" %d\n", printf(" %-4u ", 9));
// // 	ft_printf(" %d\n\n", ft_printf(" %-4u ", 9));

// // 	printf(" %d\n", printf("%08.5X", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%08.5X", 0));
	
// // 	printf(" %d\n", printf("%08.5X", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%08.5X", 34));
	
// // 	printf(" %d\n", printf("%-5.0x", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%-5.0x", 0));
	
// // 	printf(" %d\n", printf("%5.x", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%5.x", 0));
	
// // 	printf(" %d\n", printf("%5.0x", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%5.0x", 0));
	
// // 	printf(" %d\n", printf("%08.5x", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%08.5x", 34));
	
// // 	printf(" %d\n", printf("%2.7x", 3267));
// // 	ft_printf(" %d\n\n", ft_printf("%2.7x", 3267));

// // 	printf(" %d\n", printf("%8.5x", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%8.5x", 34));

// // 	printf(" %d\n", printf("%3.7u", 3267));
// // 	ft_printf(" %d\n\n", ft_printf("%3.7u", 3267));

// // 	printf(" %d\n", printf("%8.5u", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%8.5u", 0));

// // 	printf(" %d\n", printf("%8.5u", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%8.5u", 34));

// // 	printf(" %d\n", printf("%08.3d", 8375));
// // 	ft_printf(" %d\n\n", ft_printf("%08.3d", 8375));

// // 	printf(" %d\n", printf("%-5.i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%-5.i", 0));

// // 	printf(" %d\n", printf("%-5.0i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%-5.0i", 0));

// // 	printf(" %d\n", printf("%03.7i", -2375));
// // 	ft_printf(" %d\n\n", ft_printf("%03.7i", -2375));

// // 	printf(" %d\n", printf("%08.3i", -8473));
// // 	ft_printf(" %d\n\n", ft_printf("%08.3i", -8473));

// // 	printf(" %d\n", printf("%08.3i", 8375));
// // 	ft_printf(" %d\n\n", ft_printf("%08.3i", 8375));

// // 	printf(" %d\n", printf("%08.5i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%08.5i", 0));

// // 	printf(" %d\n", printf("%08.5i", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%08.5i", 34));

// // 	printf(" %d\n", printf("%-3.3i", -8462));
// // 	ft_printf(" %d\n\n", ft_printf("%-3.3i", -8462));

// // 	printf(" %d\n", printf("%3.3i", -8462));
// // 	ft_printf(" %d\n\n", ft_printf("%3.3i", -8462));

// // 	printf(" %d\n", printf("%-3.7i", -2375));
// // 	ft_printf(" %d\n\n", ft_printf("%-3.7i", -2375));

// // 	printf(" %d\n", printf("%-8.3i", -8473));
// // 	ft_printf(" %d\n\n", ft_printf("%-8.3i", -8473));

// // 	printf(" %d\n", printf("%-8.5i", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%-8.5i", 34));

// // 	printf(" %d\n", printf("%3.3i", 6983));
// // 	ft_printf(" %d\n\n", ft_printf("%3.3i", 6983));
	
// // 	printf(" %d\n", printf("%3.7i", -2375));
// // 	ft_printf(" %d\n\n", ft_printf("%3.7i", -2375));

// // 	printf(" %d\n", printf("%3.7i", 3267));
// // 	ft_printf(" %d\n\n", ft_printf("%3.7i", 3267));

// // 	printf(" %d\n", printf("%8.3i", -8473));
// // 	ft_printf(" %d\n\n", ft_printf("%8.3i", -8473));
	
// // 	printf(" %d\n", printf("%010.5i", -216));
// // 	ft_printf(" %d\n\n", ft_printf("%010.5i", -216));

// // 	printf(" %d\n", printf("%7i", -14));
// // 	ft_printf(" %d\n\n", ft_printf("%7i", -14));

// // 	printf(" %d\n", printf(" % d ", 0));
// // 	ft_printf(" %d\n\n", ft_printf(" % d ", 0));

// // 	printf(" %d\n", printf(" %.2d ", -1));
// // 	ft_printf(" %d\n\n", ft_printf(" %.2d ", -1));

// // 	printf(" %d\n", printf(" %-5d ", -15));
// // 	ft_printf(" %d\n\n", ft_printf(" %-5d ", -15));

// // 	printf(" %d\n", printf(" %-4d ", -14));
// // 	ft_printf(" %d\n\n", ft_printf(" %-4d ", -14));

// // 	printf(" %d\n", printf("%8.5i", 34));
// // 	ft_printf(" %d\n\n", ft_printf("%8.5i", 34));

// // 	printf(" %d\n", printf("%10.5i", -216));
// // 	ft_printf(" %d\n\n", ft_printf("%10.5i", -216));

// // 	printf(" %d\n", printf("%8.5i", 0));
// // 	ft_printf(" %d\n\n", ft_printf("%8.5i", 0));

// // 	printf(" %d\n", printf(" %d ", 0));
// // 	ft_printf(" %d\n\n", ft_printf(" %d ", 0));

// // 	printf(" %d\n", printf(" %02d ", -1));
// // 	ft_printf(" %d\n\n", ft_printf(" %02d ", -1));

// // 	printf(" %d\n", printf(" %04d ", -14));
// // 	ft_printf(" %d\n\n", ft_printf(" %04d ", -14));
// }