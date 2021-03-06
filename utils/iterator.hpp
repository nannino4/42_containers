#pragma once

namespace ft
{
	struct random_access_iterator_tag { };
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag { };
	struct bidirectional_iterator_tag{ };

	/*
	**	class iterator:
	**		basic class used for iterator_traits and random_access_iterator
	*/
	template<class Category, class T, class Distance = long int, class Pointer = T*, class Reference = T&>
	class iterator
	{
	public:
		typedef T					value_type;
		typedef Distance			difference_type;
		typedef Pointer				pointer;
		typedef Reference			reference;
		typedef Category			iterator_category;
	};
	
	/*
	**	struct iterator_traits:
	**		determines the traits of the iterator
	*/

	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	/*
	**	distance:
	*/
	
	template<class InputIt>
	typename ft::iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last) {

		typename ft::iterator_traits<InputIt>::difference_type count;

		count = 0;
		while (first != last)
		{
			first++;
			count++;
		}
		return (count);
	};
}

