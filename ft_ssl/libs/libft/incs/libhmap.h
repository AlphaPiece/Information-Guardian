/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 13:49:41 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/06 15:57:33 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHMAP_H
# define LIBHMAP_H

# include "libft.h"

# define HASH_SPACE 512

typedef struct		s_pair
{
	char			*key;
	char			*val;
	struct s_pair	*next;
}					t_pair;

typedef struct		s_hmap
{
	int				count;
	t_pair			**pairs;
}					t_hmap;

unsigned int		ft_hashstr(const char *s, unsigned int hashsize);
t_hmap				*ft_hmapnew(void);
t_pair				*ft_hmapsearch(t_hmap *hmap, char *key);
void				ft_hmapset(t_hmap *hmap, char *key, char *value);
char				*ft_hmapget(t_hmap *hmap, char *key);
void				ft_hmapremove(t_hmap *hmap, char *key);
void				ft_hmapclear(t_hmap *hmap);
void				ft_hmapdel(t_hmap **hmap);

#endif
