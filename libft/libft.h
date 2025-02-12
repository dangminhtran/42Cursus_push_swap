/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:06:47 by dangtran          #+#    #+#             */
/*   Updated: 2025/02/12 14:32:39 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	**ft_free(char **strs, int i);
int		tab_len(char **tab);

#endif
