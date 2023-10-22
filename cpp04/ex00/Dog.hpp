/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:57:53 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/08 19:49:02 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public: 
        Dog();
        Dog(Dog const & other);
        ~Dog();  
        void makeSound() const;

        Dog & operator=(Dog const & rhs);
};

#endif