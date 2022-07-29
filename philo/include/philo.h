/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:04:04 by mtavares          #+#    #+#             */
/*   Updated: 2022/07/29 00:52:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef unsigned long	t_lu;
typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;

struct s_data
{
	int		philo_num;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		have_last_arg;
	long	num_time_to_eat;
};

struct s_philo
{
	int				id;
	int				*is_dead;
	pthread_t		philo;
	t_data			*data;
	t_table			*table;
};

struct s_table
{
	int				have_fork;
	pthread_mutex_t	mutex_fork;
};

void	exit_free(t_table **table, t_philo **philo, int i, char *str);
int		have_last_arg(int ac);
t_data	intit_data(int ac, char **av);
t_table	*init_table(t_data *data);
t_philo	*init_philo(t_data *data, t_table **table, int	*is_dead);
void	thread_creation(t_philo	**philo);
int		ft_atoi(char *str);

#endif
