#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "./utils/iterator.hpp"
# include "./utils/pair.hpp"
# include "./utils/rbtree.hpp"
# include "./utils/algorithm.hpp"
# include "./utils/type.hpp"

namespace ft {

	template <typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T								key_type;
			typedef T								value_type;
			typedef Compare							key_compare;
			typedef Compare							value_compare;
			typedef Compare							compare_type;
			typedef Alloc							allocator_type;

			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;

			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::size_t						size_type;

			/* iterator */
			typedef typename ft::__rbt<const value_type, key_type, value_compare, allocator_type>::iterator			iterator;
			typedef typename ft::__rbt<const value_type, key_type, value_compare, allocator_type>::const_iterator	const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			compare_type	__comp;
			allocator_type	__alloc;
			ft::__rbt<const value_type, key_type, value_compare, allocator_type>	__rbt;

		public:
			/* orthdox */
			explicit set(const compare_type& comp = compare_type(), const allocator_type& alloc = allocator_type())
			: __comp(comp), __alloc(alloc), __rbt(comp, alloc) {}

			template <typename InputIterator>
			set(InputIterator first, InputIterator last, const compare_type& comp = compare_type(), const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::NIL)
			: __comp(comp), __alloc(alloc), __rbt(comp, alloc)
			{
				insert(first, last);
			}
			set(const set& rhs): __comp(rhs.__comp), __alloc(rhs.__alloc), __rbt(rhs.__rbt) {}
			~set(){}
			set& operator=(const set& rhs)
			{
				set tmp(rhs);
				swap(tmp);
				return *this;
			}

			iterator				begin()			{ return __rbt.begin(); }
			iterator				end()			{ return __rbt.end(); }
			const_iterator			begin() const	{ return __rbt.begin(); }
			const_iterator			end() const		{ return __rbt.end(); }
			reverse_iterator		rbegin()		{ return reverse_iterator(end()); }
			reverse_iterator		rend()			{ return reverse_iterator(begin()); }
			const_reverse_iterator	rbegin() const	{ return const_reverse_iterator(end()); }
			const_reverse_iterator	rend() const	{ return const_reverse_iterator(begin()); }

			bool		empty()		const { return __rbt.empty(); }
			size_type	size()		const { return __rbt.size(); }
			size_type	max_size()	const { return __rbt.max_size(); }

			ft::pair<iterator, bool>	insert(const value_type& val)
			{ return __rbt.insert(val); }

			iterator	insert(iterator _idx, const value_type& val)
			{ return __rbt.insert(_idx, val); }

			template <class InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{ __rbt.insert(first, last); }

			void		erase(iterator _idx)					{ __rbt.erase(_idx); }
			size_type	erase(const value_type& val)			{ return __rbt.erase(val); }
			void		erase(iterator first, iterator last)	{ __rbt.erase(first, last); }

			void	swap(set& s)	{ __rbt.swap(s.__rbt); }

			void	clear()	{ __rbt.clear(); }

			key_compare		key_comp() const	{ return __comp; }
			value_compare	value_comp() const	{ return __comp; }

			iterator		find(const value_type& val) const	{ return __rbt.find(val); }

			size_type	count(const value_type& val) const { return !(find(val) == end()); }

			iterator		lower_bound(const value_type& val) const
			{ return __rbt.lower_bound(val); }

			iterator		upper_bound(const value_type& val) const
			{ return __rbt.upper_bound(val); }

			ft::pair<iterator, iterator>	equal_range(const value_type& val) const
			{ return __rbt.equal_range(val); }

			allocator_type	get_allocator() const	{ return __rbt.get_allocator(); }
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin()); }

	template <class T, class Compare, class Alloc>
	bool operator!=(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return !(__x == __y); }

	template <class T, class Compare, class Alloc>
	bool operator<(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end()); }

	template <class T, class Compare, class Alloc>
	bool operator<=(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return !(__y < __x); }

	template <class T, class Compare, class Alloc>
	bool operator>(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return (__y < __x); }

	template <class T, class Compare, class Alloc>
	bool operator>=(const ft::set<T, Compare, Alloc>& __x,
		const ft::set<T, Compare, Alloc>& __y)
	{ return !(__x < __y); }

	/* non-member function */
	template <class T, class Compare, class Alloc>
	void	swap(ft::set<T, Compare, Alloc>& __x,
		ft::set<T, Compare, Alloc>& __y)
	{ __x.swap(__y); }

}

#endif
