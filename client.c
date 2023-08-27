/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:24:43 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/07 14:35:55 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(1000);
		if ((c >> i) & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;
	size_t	i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (i < ft_strlen(message))
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\n');
	return (0);
}
