/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesille <adesille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:13:05 by adesille          #+#    #+#             */
/*   Updated: 2025/08/26 10:48:55 by adesille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <ostream>

int main()
{
	{
		std::cout << YELLOW "=== Testing with MutantStack ===" RESET << std::endl;
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
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW "=== Testing with std::list ===" RESET << std::endl;
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
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mlist);
	}
	std::cout << std::endl;
	{
		std::cout << YELLOW "=== Additional MutantStack Tests ===" RESET << std::endl;
		
		MutantStack<int> empty_stack;
		std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
		std::cout << "Empty stack begin == end: " << ((empty_stack.begin() == empty_stack.end()) ? GREEN "true" : RED "false") << RESET << std::endl;
		std::cout << std::endl;
		
		MutantStack<int> stack1;
		stack1.push(42);
		stack1.push(84);
		
		MutantStack<int> stack2;
		stack2 = stack1;
		std::cout << "Stack2 values after assignment:" << std::endl;
		std::cout << "- same size: " << (stack2.size() == stack1.size() ? GREEN "true" : RED "false") << RESET << std::endl;
		std::cout << "- same top: " << (stack2.top() == stack1.top() ? GREEN "true" : RED "false") << RESET << std::endl;
		std::cout << std::endl;
		
		const MutantStack<int>& const_ref = stack1;
		std::cout << "Using const iterators: " << std::endl;
		for (MutantStack<int>::const_iterator it = const_ref.begin(); it != const_ref.end(); ++it)
			std::cout << *it << " " << std::endl;
		std::cout << std::endl;
		
		MutantStack<std::string> string_stack;
		string_stack.push("Hello");
		string_stack.push("World");
		string_stack.push("42");
		
		std::cout << "String stack contents: " << std::endl;
		for (MutantStack<std::string>::iterator it = string_stack.begin(); it != string_stack.end(); ++it)
			std::cout << *it << " " << std::endl;
	}
	return 0;
}
