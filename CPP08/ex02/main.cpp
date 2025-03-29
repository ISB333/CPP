/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/03/29 12:11:02 by adesille         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "=== Testing with MutantStack ===" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "=== Testing with std::list ===" << std::endl;
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}
	return 0;
}
