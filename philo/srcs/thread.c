/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:42:21 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/04 03:06:22 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/* Ask about the timestamp, if counts since the beguining of the program or if
it is since the last thing they did */

void	*routine(void *args)
{
	int		i;
	t_philo	*p;

	p = (t_philo *)args;
	p->time.start = get_actual_time();
	p->time.last_action = p->time.start;
	p->time.last_meal = p->time.start;
	i = 0;
	while (++i * (p->data->have_last_arg != 0) <= \
	(p->data->have_last_arg != 0) * p->data->num_time_to_eat)
	{
		if (is_dead(p))
		{
			print_message(p, "is dead", 0);
			break ;
		}
		eat(p);
		print_message(p, "is sleeping", 0);
		if (is_dead(p))
		{
			print_message(p, "is dead", 0);
			break ;
		}
		usleep(p->data->time_to_sleep);
		print_message(p, "is thinking", 0);
		if (is_dead(p))
		{
			print_message(p, "is dead", 0);
			break ;
		}
	}
	return (NULL);
}

void	thread_creation(t_philo	**philo)
{
	int	i;

	i = -1;
	while (++i < (*philo)->data->philo_num)
	{
		pthread_mutex_init(&(*philo)[i].table[i].mutex_fork, NULL);
		pthread_create(&(*philo)[i].philo, NULL, &routine, (*philo + i));
	}
	i = -1;
	while (++i < (*philo)->data->philo_num)
	{
		pthread_mutex_destroy(&(*philo)[i].table[i].mutex_fork);
		pthread_join((*philo)[i].philo, NULL);
	}
}
