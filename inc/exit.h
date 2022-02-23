/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:25:52 by coder             #+#    #+#             */
/*   Updated: 2022/02/23 16:25:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "../libft/inc/libft.h"
# include "so_long.h"

typedef enum e_errorcode
{
	SUCCESS,
	ERROR1,
	ERROR2,
	ERROR3,
	ERROR4,
	ERROR5,
	ERROR6,
	ERROR7,
	ERROR8,
	ERROR9,
	ERROR10,
	ERROR11,
	ERROR12,
	ERRORS,
}	t_errorcode;

void	exit_error(t_data *data, char *errorflag);
int		exit_program(t_data *data);
void	free_map(char **map);

#endif