/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:48:29 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/07 17:59:22 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    public: 
        Cat();
        Cat(Cat const & other);
        ~Cat();  
        void makeSound() const;

        Cat & operator=(Cat const & rhs);
};

#endif