#include "constants.h"

int		ft_isspace(char ch)
{
	if (ch == ' ' || (9 <= ch && ch <= 13))
		return (TRUE);
	return (FALSE);
}
