/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:26:20 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/08 16:49:09 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			signe;
	long int	nb;

	i = 0;
	nb = 0;
	signe = 1;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\t') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			signe = -signe;
		if ((str[i - 1] == '-') || (str[i - 1] == '+'))
			return (0);
		i++;
	}
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(nb * signe));
}

void	convert_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

int	main( int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			convert_char(argv[2][i], pid);
			i++;
		}
		convert_char('\0', pid);
		return (EXIT_SUCCESS);
	}
	else
	{
		write (1, &"enter 2 arguments : the PID of the server and the message\n",
			68 * sizeof(char));
		return (EXIT_FAILURE);
	}
}
