/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongspa <seongspa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:36:47 by seongspa          #+#    #+#             */
/*   Updated: 2023/04/26 15:11:06 by seongspa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>

class Replacer
{
    public:
        Replacer(std::string infile);
        void replace(std::string from, std::string to);

    private:
        std::string _infile;
        std::string _outfile;
};

#endif