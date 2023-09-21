/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:58:01 by jofilipe          #+#    #+#             */
/*   Updated: 2023/09/21 18:26:59 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PHILO_H
# define	PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long long		last_meal;
	pthread_t		philos;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	arceus;
	t_data			*data;
}				t_philos;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_to_eat;
	int				all_ate;
	int				died;
	long long		time_start;
	pthread_t		doc;
	pthread_mutex_t	mutex;
	pthread_mutex_t	error_print;
	pthread_mutex_t	*forks;
	t_philos		*philos;
}				t_data;


/* ------ft_fnctns------ */
static int			ft_see_spaces(const char *str, int *ptr_i);
int					ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_isdigit(int c);
int					check_num(char **argv);


/* ------ft_fnctns2------ */
long long			get_time();


/* ------inits------ */
t_philos			*philo_init(t_data *data);
int					structs_init(t_data *data, int argc, char **argv);
pthread_mutex_t		*forks_init(int num_philo);


/* ------mutex------ */
int					mutex_init(pthread_mutex_t *mutex);
int					mutex_destroy(pthread_mutex_t *mutex);
int					mutex_lock(pthread_mutex_t *mutex);
int					mutex_unlock(pthread_mutex_t *mutex);

/* ------utils------ */
int					error_message(char c);
int					verifs(t_data *data);
int					verifs2(t_data *data);

/* ------routine------ */
void				*ft_routine(void);
void				*ft_doc_watch(void);


/* ------thread------ */
int					ft_thread(t_data *data);


#endif
