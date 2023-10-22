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

class Animal { 
    protected: 
        std::string type;
    public:
        Animal();
        Animal(Animal const & other);
        virtual void makeSound() const;
        std::string getType(void) const;
    
        Animal & operator=(Animal const & rhs);
        virtual ~Animal();
};


#endif
