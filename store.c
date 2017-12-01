


// char	**ft_pmalloc(char *str, int *piece)
// {
// 	char	**strs;

// 	if (!(ft_validblock(str)))
// 	{
// 		ft_putstr_fd("error\n", 1);
// 		exit(0);
// 	}
// 	strs = ft_connect(str, piece, 'A');
// 	return (strs);
// }

char	**ft_connect(char *str, int *piece, char letter)
{
	char *tmp;
	char **big;

	big = (char **)malloc(sizeof(char *) * 27);
	tmp = str;
	while (*tmp != '\0')
	{
		big[*piece] = ft_strnew(21);
		ft_strncpy(big[*piece], tmp, 21);
		ft_validpiece(big[*piece], letter++);
		*piece += 1;
		if (tmp[20] == '\0')
			break ;
		tmp += 21;
	}
	big[*piece] = NULL;
	return (big);
}