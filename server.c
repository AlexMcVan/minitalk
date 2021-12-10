/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:25:20 by amarie-c          #+#    #+#             */
/*   Updated: 2021/12/06 14:34:30 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_un_putnbr(int n)
{
	int		reste;
	char	c;

	if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, sizeof(char));
	}
	else
	{
		ft_un_putnbr(n / 10);
		reste = n % 10;
		c = '0' + reste;
		write(1, &c, sizeof(char));
	}
}

void	get_signal(int binaire)
{
	static int	position;
	static int	bit;

	if (binaire == SIGUSR1)
		bit += 1 << (7 - position);
	position++;
	if (position == 8)
	{
		if (bit == '\0')
			write(1, &"\n", sizeof(char));
		write(1, &bit, sizeof(char));
		position = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, &"the pid is : ", sizeof(char) * 13);
	ft_un_putnbr(pid);
	write(1, &"\n", sizeof(char));
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
