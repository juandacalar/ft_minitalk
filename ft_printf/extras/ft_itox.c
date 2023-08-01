/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:32:22 by jucalder          #+#    #+#             */
/*   Updated: 2023/06/23 19:32:24 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itox(unsigned long int n, char format, int len)
{
	unsigned long int	temp;
	char				*s;

	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[len] = '\0';
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			s[len - 1] = temp + 48;
		else
		{
			if (format == 'x')
				s[len - 1] = temp + 87;
			else if (format == 'X')
				s[len - 1] = temp + 55;
		}
		n /= 16;
		len--;
	}
	return (s);
}
