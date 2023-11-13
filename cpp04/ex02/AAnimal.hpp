/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:56:33 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 16:28:15 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal {
    protected: 
        std::string type;
    public:
        AAnimal();
        AAnimal(AAnimal const & other);
        virtual void makeSound() const = 0;
        std::string getType(void) const;
    
        AAnimal & operator=(AAnimal const & rhs);
        virtual ~AAnimal();
};

#endif
