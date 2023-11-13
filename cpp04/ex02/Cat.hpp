/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:48:29 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/21 15:08:06 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain * brain;
    public: 
        Cat();
        Cat(Cat const & other);
        ~Cat();  
        void makeSound() const;
        Brain * getBrain() const;

        Cat & operator=(Cat const & rhs);
};

#endif