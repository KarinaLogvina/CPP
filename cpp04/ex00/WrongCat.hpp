/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:56 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/08 19:48:42 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal {
    WrongCat();
    WrongCat(WrongCat const & other);
    virtual ~WrongCat();  
    void makeSound() const;
    std::string getType(void) const;

    WrongCat & operator=(WrongCat const & rhs);
};

#endif
