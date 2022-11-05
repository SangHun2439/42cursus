#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container						container_type;
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;

		protected:
			container_type	c;

		public:
			explicit stack(const container_type& __con = container_type()): c(__con){}
			stack(const stack& rhs): c(rhs.c){}
			~stack(){}
			stack& operator=(const stack& rhs)
			{
				if (this != &rhs)
					c = rhs.c;
				return *this;
			}

			bool				empty() const { return c.size() == 0; }
			size_type			size() const { return c.size(); }
			size_type			max_size() const { return c.max_size(); }
			value_type&			top() { return c.back(); }
			const value_type&	top() const {return c.back(); }
			void				push(const value_type& __val) { c.push_back(__val); }
			void				pop() { c.pop_back(); }

			template <typename Tp, typename Cnt>
			friend bool operator==(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);

			template <typename Tp, typename Cnt>
			friend bool operator!=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);

			template <typename Tp, typename Cnt>
			friend bool operator<(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);

			template <typename Tp, typename Cnt>
			friend bool operator<=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);

			template <typename Tp, typename Cnt>
			friend bool operator>(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);

			template <typename Tp, typename Cnt>
			friend bool operator>=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs);
		};

		template <typename Tp, typename Cnt>
		bool operator==(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c == rhs.c; }

		template <typename Tp, typename Cnt>
		bool operator!=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c != rhs.c; }

		template <typename Tp, typename Cnt>
		bool operator<(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c < rhs.c; }

		template <typename Tp, typename Cnt>
		bool operator<=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c <= rhs.c; }

		template <typename Tp, typename Cnt>
		bool operator>(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c > rhs.c; }

		template <typename Tp, typename Cnt>
		bool operator>=(const stack<Tp, Cnt>& lhs, const stack<Tp, Cnt>& rhs)
		{ return lhs.c >= rhs.c; }
}

#endif
