char	***split_to_words(char *data)
{
	size_t	i;
	char	***words;
	char	*nl;

	cnt = ft_strcnt(data, '\n');
	words = ft_calloc(cnt + 1, sizeof(char **));
	i = 0;
	while (words)
	{
		nl = ft_strchr(data, '\n');
		if (nl)
			*nl = '\0';
		words[i] = ft_split(line_start);
		if (!words[i])
		{
			free_tarr_char(char ***words);
			return (NULL);
		}
		if (!nl)
			return (words);
		data = nl + 1;
		i++;
	}
	return (NULL);
}

void	free_tarr_char(char ***words)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (words[i])
	{
		j = 0;
		while (words[j])
		{
			free(words[i][j]);
			j++;
		}
		free(words[i]);
		i++;
	}
	free(words);
}
