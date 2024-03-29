#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type first;
		second_type second;

		pair(): first(), second(){}

		template <typename U, typename V>
		pair(const pair<U,V>& pr): first(pr.first), second(pr.second) {}

		pair(const first_type& x, const second_type& y = second_type()): first(x), second(y) {}

		pair& operator=(const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};

	template <typename T1, typename T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const pair<T1,T2>& rhs){ return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <typename T1, typename T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const pair<T1,T2>& rhs){ return !(lhs == rhs); }

	template <typename T1, typename T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); }

	template <typename T1, typename T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){ return !(rhs > lhs); }

	template <typename T1, typename T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){ return (rhs < lhs); }

	template <typename T1, typename T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs){ return !(lhs < rhs); }

	template <typename T1, typename T2>
	ft::pair<T1,T2> make_pair(T1 t1, T2 t2){ return ft::pair<T1,T2>(t1, t2); }


}

#endif
