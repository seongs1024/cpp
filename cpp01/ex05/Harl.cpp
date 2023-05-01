/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:38:42 by seongspa          #+#    #+#             */
/*   Updated: 2023/05/01 11:38:43 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	void (Harl::* const FUNC_TABLE[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string LEVELS[] = { "debug", "info", "warning", "error" };

	for (size_t i = 0; i < level.length(); i++)
	{
		level[i] = tolower(level[i]);
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (LEVELS[i] == level)
		{
			(this->*FUNC_TABLE[i])();
			break;
		}
	}
}

void Harl::debug(void)
{
	std::cout << "DEBUG: debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING: warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR: error" << std::endl;
}
