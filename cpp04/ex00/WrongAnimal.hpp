/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:47:49 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/08 19:48:24 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal : public Animal {
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const & other);
        std::string getType(void) const;
        
        virtual ~WrongAnimal();  
        void makeSound() const;

        WrongAnimal & operator=(WrongAnimal const & rhs);
};

#endif
