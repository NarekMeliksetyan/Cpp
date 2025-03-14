/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphyliss <dphyliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:06:09 by dphyliss          #+#    #+#             */
/*   Updated: 2021/01/05 11:06:11 by dphyliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	cut_word(t_asm *asm_parsing, char *line, char *substring, int start)
{
	substring = take_word(asm_parsing->symbol, line, start);
	if (check_for_instruction(substring))
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
																INSTRUCTION));
	else if (check_for_register(substring))
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
																REGISTER));
	else if (check_for_number(substring))
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
																INDIRECT_ARG));
	else
		error_word(asm_parsing, substring);
}

void	cut_other(t_asm *asm_parsing, char *line)
{
	int		start;
	char	*substring;

	start = 0;
	substring = NULL;
	start = asm_parsing->symbol;
	if (line[asm_parsing->symbol] == '-')
		asm_parsing->symbol++;
	if (!ft_strchr(LABEL_CHARS, line[asm_parsing->symbol]))
		ft_error(asm_parsing);
	while (line[asm_parsing->symbol] && ft_strchr(LABEL_CHARS,
													line[asm_parsing->symbol]))
		asm_parsing->symbol++;
	if (line[asm_parsing->symbol] == LABEL_CHAR)
		check_label(asm_parsing, substring, line, start);
	else
		cut_word(asm_parsing, line, substring, start);
}

void	cut_doubles_s(t_asm *asm_parsing, char *line, int start,
															char *substring)
{
	start = asm_parsing->symbol++;
	while (line[asm_parsing->symbol] && line[asm_parsing->symbol] != '"')
		asm_parsing->symbol++;
	if (line[asm_parsing->symbol] != '"')
		cut_doubles(asm_parsing, line, start);
	else
	{
		substring = take_word(++asm_parsing->symbol, line, start);
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
																DOUBLES));
	}
}

void	parse_word(t_asm *asm_parsing, char *line)
{
	int		start;
	char	*substring;

	start = 0;
	substring = NULL;
	if (line[asm_parsing->symbol] == '.')
		cut_command(asm_parsing, line);
	else if (line[asm_parsing->symbol] == '"')
		cut_doubles_s(asm_parsing, line, start, substring);
	else if (line[asm_parsing->symbol] == LABEL_CHAR)
		cut_label(asm_parsing, line);
	else if (line[asm_parsing->symbol] == DIRECT_CHAR)
		cut_direct(asm_parsing, line);
	else if (line[asm_parsing->symbol] == ',')
	{
		start = asm_parsing->symbol++;
		substring = take_word(asm_parsing->symbol, line, start);
		add_word_to_list(asm_parsing, create_word(asm_parsing, substring,
																SEPARATOR));
	}
	else if (line[asm_parsing->symbol])
		cut_other(asm_parsing, line);
}

void	parse_line(t_asm *asm_parsing, char *line)
{
	while (line[asm_parsing->symbol])
	{
		while (ft_isspace(line[asm_parsing->symbol]))
			asm_parsing->symbol++;
		ignore_comment(asm_parsing, line);
		parse_word(asm_parsing, line);
	}
}
