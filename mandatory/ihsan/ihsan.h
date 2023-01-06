#ifndef IHSAN_H
#define IHSAN_H

#include "../../Lib/cub_lib.h"
#include "../includes/global_includes.h"
#include <fcntl.h>

char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
int     check_maps_name(char *name);
void	free_double_array(char **arr);


#endif
