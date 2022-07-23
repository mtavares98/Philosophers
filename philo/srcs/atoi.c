/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:24:02 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/18 15:42:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	long	num;
	int		signal;
	int		i;

	signal = 1;
	num = 0;
	i = -1;
	while ((str[++i] > 8 && str[i] < 14) || str[i] == 32)
		;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signal = -1;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + signal * (str[i++] - '0');
	return (num);
}
