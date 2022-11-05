/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeson <jeson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:11:35 by jeson             #+#    #+#             */
/*   Updated: 2022/08/13 12:53:24 by jeson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>
# include "utils/pair.hpp"
# include "utils/iterator.hpp"
# include "utils/rbtree.hpp"
# include "utils/algorithm.hpp"

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef Compare					key_compare;
			typedef Alloc					allocator_type;
			typedef typename Alloc::template rebind<value_type>::other	type_allocator;
			typedef std::allocator_traits<type_allocator>	type_traits;
			typedef typename type_traits::pointer		pointer;
			typedef typename type_traits::const_pointer	const_pointer;
			typedef value_type&	reference;
			typedef const value_type&	const_reference;

			typedef std::size_t	size_type;
			typedef std::ptrdiff_t	difference_type;

			class value_compare
				: public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
					protected:
						key_compare comp;
					public:
						value_compare(key_compare c): comp(c){}
						~value_compare(){}

						bool operator()(const value_type& x, const value_type& y) const
						{ return comp(x.first, y.first); }

						bool operator()(const value_type& x, const key_type& y) const
						{ return comp(x.first, y); }

						bool operator()(const key_type& x, const value_type& y) const
						{ return comp(x, y.first); }
			};

		/* iterator */
		typedef typename ft::__rbt<value_type, key_type, value_compare, allocator_type>::iterator iterator;
		typedef typename ft::__rbt<value_type, key_type, value_compare, allocator_type>::const_iterator const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
				key_compare __key_comp;
				value_compare __value_comp;
				ft::__rbt<value_type, key_type, value_compare, allocator_type> __rbt;

		public:
			/* orthdox */
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: __key_comp(comp), __value_comp(comp), __rbt(__value_comp, alloc) {}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::NIL)
				: __key_comp(comp), __value_comp(comp), __rbt(__value_comp, alloc)
			{ insert(first, last); }
			map(const map& m) : __key_comp(m.__key_comp), __value_comp(m.__value_comp), __rbt(m.__rbt) {}
			~map(void) {}

			/* member function for util */
			map& operator=(const map& m)
			{
				if (this != &m)
				{
				__key_comp = m.__key_comp;
				__value_comp = m.__value_comp;
				__rbt = m.__rbt;
				}
				return *this;
			}

			iterator 				begin(void) 		{ return __rbt.begin(); }
			iterator				end(void)			{ return __rbt.end(); }
			const_iterator			begin(void) const	{ return __rbt.begin(); }
			const_iterator			end(void) const		{ return __rbt.end(); }
			reverse_iterator		rbegin(void)		{ return reverse_iterator(end()); }
			reverse_iterator		rend(void)			{ return reverse_iterator(begin()); }
			const_reverse_iterator	rbegin(void) const	{ return reverse_iterator(end()); }
			const_reverse_iterator	rend(void) const	{ return reverse_iterator(begin()); }

			bool	empty(void) const { return __rbt.empty(); }
			size_type	size(void) const { return __rbt.size(); }
			size_type	max_size(void) const { return __rbt.max_size(); }

			mapped_type& operator[](const key_type& key)
			{
				ft::pair<iterator, bool> p = insert(ft::make_pair(key, mapped_type()));
				return p.first->second;
			}
			mapped_type& at(const key_type& key)
			{
				iterator i = find(key);
				if (i == end())
					throw std::out_of_range("ft::map::at");
				return i->second;
			}
			const mapped_type& at(const key_type& key) const
			{
				const_iterator i = find(key);
				if (i == end())
					throw std::out_of_range("ft::map::at");
				return i->second;
			}

			ft::pair<iterator, bool> insert(const value_type& value)
			{ return __rbt.insert(value); }

			iterator insert(iterator _idx, const value_type& value)
			{ return __rbt.insert(_idx, value); }

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{ __rbt.insert(first, last); }

			void erase(iterator _idx)
			{ __rbt.erase(_idx); }

			size_type erase(const key_type& key)
			{ return __rbt.erase(key); }

			void erase(iterator first, iterator last)
			{ __rbt.erase(first, last); }

			void swap(map& m) { __rbt.swap(m.__rbt); }

			void clear(void)
			{ __rbt.clear(); }

			key_compare key_comp() const
			{ return __key_comp; }

			value_compare value_comp() const
			{ return __value_comp; }

			iterator find(const key_type& key)
			{ return __rbt.find(key); }

			const_iterator find(const key_type& key) const
			{ return __rbt.find(key); }

			size_type count(const key_type& key) const
			{ return !(find(key) == end()); }

			iterator lower_bound(const key_type& key)
			{ return __rbt.lower_bound(key); }

			const_iterator lower_bound(const key_type& key) const
			{ return __rbt.lower_bound(key); }

			iterator upper_bound(const key_type& key)
			{ return __rbt.upper_bound(key); }

			const_iterator upper_bound(const key_type& key) const
			{ return __rbt.upper_bound(key); }

			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{ return __rbt.equal_range(key); }

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{ return __rbt.equal_range(key); }

			allocator_type get_allocator() const
			{ return __rbt.get_allocator(); }

		};

		template <class Key, class T, class Compare, class Alloc>
		bool operator==(const ft::map<Key, T, Compare, Alloc>& x,
						const ft::map<Key, T, Compare, Alloc>& y)
		{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }

		template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const ft::map<Key, T, Compare, Alloc>& x, const ft::map<Key, T, Compare, Alloc>& y)
		{ return !(x == y); }

		template <class Key, class T, class Compare, class Alloc>
		bool operator<(const ft::map<Key, T, Compare, Alloc>& x, const ft::map<Key, T, Compare, Alloc>& y)
		{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

		template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const ft::map<Key, T, Compare, Alloc>& x, const ft::map<Key, T, Compare, Alloc>& y)
		{ return !(y < x); }

		template <class Key, class T, class Compare, class Alloc>
		bool operator>(const ft::map<Key, T, Compare, Alloc>& x, const ft::map<Key, T, Compare, Alloc>& y)
		{ return y < x; }

		template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const ft::map<Key, T, Compare, Alloc>& x, const ft::map<Key, T, Compare, Alloc>& y)
		{ return !(x < y); }

		/* non-member function */
		template <class Key, class T, class Compare, class Alloc>
		void swap(ft::map<Key, T, Compare, Alloc>& x, ft::map<Key, T, Compare, Alloc>& y)
		{ x.swap(y); }

}

#endif
