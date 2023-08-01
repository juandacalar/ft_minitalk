/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:30:00 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:30:02 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_hexlen(unsigned long long int n);
char	*ft_uiptox(void *ptr);
char	*ft_itox(unsigned long int n, char format, int len);
void	ft_write(char *s, int *count);
size_t	ft_strcpy(char *dst, const char *src);
int		ft_printf(const char *str, ...);
int		ft_printf_args_char(va_list args, int *count);
int		ft_printf_args_int(va_list args, int *count);
int		ft_printf_args_pointer(va_list args, int *count);
int		ft_printf_args_string(va_list args, int *count);
int		ft_printf_args_unint(va_list args, int *count);
int		ft_printf_args_x(va_list args, char format, int *count);
size_t  ft_strlen(const char *str);
int     ft_atoi(const char *str);

#endif
