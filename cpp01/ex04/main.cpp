/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:48:12 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 17:11:50 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Replacer.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4 || argv[1] == NULL || argv[2] == NULL || argv[3] == NULL)
    {
        std::cerr << "Wrong arguments!" << std::endl;
        return (1);
    }
    try
    {
        Replacer rep(argv[1]);
        rep.replace(argv[2], argv[3]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}