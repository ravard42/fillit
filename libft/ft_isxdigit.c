#include "libft.h"

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) ||
		(c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}
