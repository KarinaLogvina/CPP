/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:57:53 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/21 15:08:28 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain * brain;
    public: 
        Dog();
        Dog(Dog const & other);
        ~Dog();  
        void makeSound() const;
        Brain * getBrain() const;

        Dog & operator=(Dog const & rhs);
};

#endif