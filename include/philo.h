/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: restevez <restevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 07:57:04 by restevez          #+#    #+#             */
/*   Updated: 2025/04/26 05:10:37 by restevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define PHILO_H

/* Helpers */
# define FALSE			0
# define TRUE			0
/* Possible Actions */
# define THINK					'T'
# define EAT					'E'
# define SLEEP					'S'
/* States */
# define ALIVE					"alive"
# define DEAD					"deceased"
/* Messages */
# ifdef ALTERNATIVE_VERSION
#  define IS_DEAD_MSG			"was deemed worthless and died of starvation."
#  define EATING_MSG			"is eating"
#  define BECOMING_WORTHY_MSG	"has taken a fork"
#  define THINKING_MSG			"is eating"
#  define SLEEPING_MSG			"is sleeping"
# else
#  define IS_DEAD_MSG			"died"
#  define EATING_MSG			"is eating"
#  define BECOMING_WORTHY_MSG	"has taken a fork"
#  define THINKING_MSG			"is eating"
#  define SLEEPING_MSG			"is sleeping"
# endif

/* A magic table.
Holds the list of forks (table->forks),
and the list of knights (table->knights).
Also, is responsible for making the decisions
of who's worthy enough to pick up the forks. */
typedef struct s_table	t_table;
struct s_table
{
	t_forks				**forks;
	t_forks				**knights;
};

typedef struct s_knight	t_knight;
struct s_knight
{
	size_t				hungry_status;
	size_t				is_worthy;
	t_knight			*left;
	t_knight			*right;
};

typedef struct s_forks	t_forks;
struct s_forks
{
	pthread_mutex_t		available;
	t_knight			*knight_l;
	t_knight			*knight_r;
};

/* Allowed Functions:

void *memset(void *s, int c, size_t n);

int printf(const char *format, ...);

void *malloc(size_t size);

void free(void *ptr);

ssize_t write(int fildes, const void *buf, size_t nbyte);

int usleep(useconds_t usec);

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
							void *(*start_routine) (void *), void *arg);

int pthread_detach(pthread_t thread);

int pthread_join(pthread_t thread, void **retval);

int pthread_mutex_init(pthread_mutex_t *restrict mutex,
			const pthread_mutexattr_t *restrict attr);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);
*/

/* Created functions prototypes */
long long	get_current_time(void);

#endif
