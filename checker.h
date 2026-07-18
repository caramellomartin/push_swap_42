/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzaquina <jzaquina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:29:58 by jzaquina          #+#    #+#             */
/*   Updated: 2026/07/18 10:31:36 by jzaquina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
// GNL
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif
