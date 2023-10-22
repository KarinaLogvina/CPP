/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tiiksii <Tiiksii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:42:56 by Tiiksii           #+#    #+#             */
/*   Updated: 2023/10/22 13:50:27 by Tiiksii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define SIZE 15

int main()
{
    {
		std::cout << "----Test 1----" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;

		delete j;
		delete i;
	}
    {
        std::cout << "----Test 2----" << std::endl;
        Animal* j = new Cat();
		Animal* i = new Cat();

		(*i) = (*j);
		
		delete j;//should not create a leak
		delete i;
    }
        {
        std::cout << "----Test 3----" << std::endl;
        Animal* j = new Dog();
		Animal* i = new Dog();

		(*i) = (*j);
		
		delete j;//should not create a leak
		delete i;
    }
    {
        std::cout << "----Test 4----" << std::endl;
        Dog a;
        Dog b;
        
        std::cout << "Dog b brain address: " << b.getBrain() << std::endl;
		a = b;
		std::cout << "Dog a brain address: " << a.getBrain() << std::endl;
    }
    {
        std::cout << "----Test 5----" << std::endl;
        Cat a;
        Cat b;
        
        std::cout << "Cat b brain address: " << b.getBrain() << std::endl;
		a = b;
		std::cout << "Cat a brain address: " << a.getBrain() << std::endl;
    }
    {
        std::cout << "----Test 6----" << std::endl;
        Cat def;
        
        std::cout << "Cat default a brain address: " << def.getBrain() << std::endl;
        {
            Cat tmp = def;
            std::cout << "Cat temp a brain address: " << tmp.getBrain() << std::endl;
        }
    }
    {
        std::cout << "----Test 7----" << std::endl;
        Dog def;
        
        std::cout << "Dog default a brain address: " << def.getBrain() << std::endl;
        {
            Dog tmp = def;
            std::cout << "Dog temp a brain address: " << tmp.getBrain() << std::endl;
        }
    }
    {
		std::cout << "----Test 8----" << std::endl;
        Animal * shelter[SIZE];
        for (int i = 0; i < SIZE; i++) {
			if (i < SIZE / 2)
				shelter[i] = new Cat();
			else
				shelter[i] = new Dog();
		std::cout << std::endl;
		}
		std::cout << std::endl;
		for (int i = 0; i < SIZE; i++)
			delete shelter[i];
    }
}
