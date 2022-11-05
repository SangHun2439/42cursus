#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <list>

#ifdef STD
	#include <vector>
	#include <map>
	#include <stack>
	#include <set>
	namespace ft = std;
#else
	#include "vector.hpp"
	#include "map.hpp"
	#include "stack.hpp"
	#include "set.hpp"
#endif

void prn_vec(ft::vector<int> &v) {
	std::cout << "(" << v.size() << "/" << v.capacity() << ") ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << "\n\n";
}

void prn_map(ft::map<char,int> &m) {
	ft::map<char,int>::iterator it;
	std::cout << "size= " << m.size() << "      ";
	for (it = m.begin(); it != m.end(); it++)
		std::cout << it->first << ":" << it->second << "   ";
	std::cout << "\n";

}

int main() {
	#ifdef STD
		std::cout << "===  STD  ===\n";
	#else
		std::cout << "=== FT ===\n";
	#endif

	// 	std::cout << "v : ";
	// 	ft::vector<int> v;
	// 	std::cout << "size, capacity = (" << v.size() << " / " << v.capacity() << ")\n";
	// 	std::cout << "max_size of v<int>: " << v.max_size() << "\n\n";

	// 	std::cout << "v2(5,42) fill : ";
	// 	ft::vector<int> v2(5, 42);
	// 	prn_vec(v2);

	// 	std::cout << "copy constructor v3(v2) : ";
	// 	ft::vector<int> v3(v2);
	// 	prn_vec(v3);

	// 	std::cout << "assign v = v3 : ";
	// 	v = v3;
	// 	prn_vec(v);


	// 	std::cout << "10회 push_back()\n";
	// 	for (size_t i = 1; i <= 10; i++)
	// 		v.push_back(i);
	// 	prn_vec(v);

	// 	std::cout << "n < size | resize(n) - v.resize(3)\n";
	// 	v.resize(3);
	// 	prn_vec(v);
	// 	std::cout << "n > size | resize(5,2) - v.resize(5, 21)\n";
	// 	v.resize(5,21);
	// 	prn_vec(v);
	// 	std::cout << "n > capacity | resize(30) - v.resize(30)\n";
	// 	v.resize(30);
	// 	prn_vec(v);
	// 	std::cout << "n > capacity | reserve(50) - v.reserve(50)\n";
	// 	v.reserve(50);
	// 	prn_vec(v);
	// 	std::cout << "n < capacity |  reserve(3) - v.reserve(3)\n";
	// 	v.reserve(3);
	// 	prn_vec(v);
	// 	std::cout << "20회 pop_back()\n";
	// 	for (int i = 0; i < 20; i++)
	// 		v.pop_back();
	// 	prn_vec(v);
	// 	std::cout << "clear (size = 0 | capacity not changed)\n";
	// 	v.clear();
	// 	prn_vec(v);

	// 	std::cout << "=== swap test ===\n";
	// 	for (int i = 0; i < 10; i++)
	// 		v.push_back(i);
	// 	std::cout << "=== before\n";
	// 	prn_vec(v);
	// 	prn_vec(v2);
	// 	std::cout << "=== after v.swap(v2) ---\n";
	// 	v.swap(v2);
	// 	prn_vec(v);
	// 	prn_vec(v2);
	// 	std::cout << "=== non-member swap ===\n";
	// 	ft::swap(v, v2);
	// 	prn_vec(v);
	// 	prn_vec(v2);

	// 	std::cout << "at() assign\n";
	// 	for (int i = 0; i < 10; i++)
	// 		v.at(i) = 9 - i;
	// 	prn_vec(v);

	// 	std::cout << "boundary check : out_of_range throw\n";
	// 	try {
	// 		v.at(100) = 20;
	// 	} catch (std::out_of_range &e) { std::cout << "out_of_range error: " << e.what() << "\n"; }

	// 	std::cout << "\n\nft::vector<int>::iterator\n";
	// 	ft::vector<int>::iterator it = v.begin();
	// 	ft::vector<int>::iterator ite = v.end();
	// 	for (; it != ite; it++)
	// 		std::cout << *it << " ";
	// 	std::cout << '\n';
	// 	it = v.begin();
	// 	std::cout << "\n *(v.begin() + 3)     = " << *(v.begin() + 3);
	// 	std::cout << "\n *(3 + v.begin())     = " << *(3 + v.begin());
	// 	std::cout << "\n *(v.end() - 3)       = " << *(ite - 3);
	// 	std::cout << "\n v.end() - v.begin()  = " << v.end() - v.begin() << std::endl;

	// 	std::cout << "get_allocator = ";
	// 	std::cout << typeid(v.get_allocator()).name() << "\n\n";


	// 	std::cout << "iterator_traits of vector<int>::iterator\n";
	// 	typedef ft::vector<int>::iterator itType;
	// 	std::cout << "typename of iterator: " << typeid(itType).name() << std::endl;
	// 	std::cout << "valuetype of iterator: " << typeid(ft::iterator_traits<itType>::value_type).name() << std::endl;
	// 	std::cout << "pointer of iterator: " << typeid(ft::iterator_traits<itType>::pointer).name() << std::endl;
	// 	std::cout << "reference of iterator: " << typeid(ft::iterator_traits<itType>::reference).name() << std::endl;
	// 	std::cout << "differencetype of iterator: " << typeid(ft::iterator_traits<itType>::difference_type).name() << std::endl;
	// 	std::cout << "category of iterator: " << typeid(ft::iterator_traits<itType>::iterator_category).name() << std::endl;


	// {
	// 	std::cout << "test for reverse iterator\n";
	// 	for (int i =0; i<10; i++)
	// 		v[i] = i;
	// 	prn_vec(v);
	// 	ft::vector<int>::reverse_iterator rev_begin = v.rbegin();
	// 	ft::vector<int>::reverse_iterator rev_end = v.rend();
	// 	std::cout << "*rbegin()	= " << *rev_begin << "\n";
	// 	std::cout << "*(rend()-2)	= " << *(rev_end-2) << "\n";
	// 	std::cout << "size		= " << v.size() << "\n";
	// 	std::cout << "end  -  begin	= " << v.end() - v.begin() << "\n";
	// 	std::cout << "rend - rbegin	= " << v.rend() - v.rbegin() << "\n";
	// 	while (rev_begin != rev_end)
	// 		std::cout << ' ' << *rev_begin++;
	// 	std::cout << "\n\n";
	// }

	// 	// std::is_integral 은 -std=c++98옵션으로 테스트 불가
	// 	std::cout << "===== is_integral test =====\n";
	// 	// std::cout << "int: " << std::boolalpha << ft::is_integral<int>() << "\n";
	// 	std::cout << "float: " << ft::is_integral<float>::value << "\n";
	// 	std::cout << "const int: " << ft::is_integral<const int>::value << "\n\n";


	// {
	// 	std::cout << " === initialize by iterator ===\n";
	// 	ft::vector<int> v2(v.begin() + 3, v.end() - 4);
	// 	prn_vec(v2);
	// }

	// {
	// 	std::cout << " === initialize by std::list<>::iterator ===\n";
	// 	std::list<int> tmp(5, 42);
	// 	ft::vector<int> v2(tmp.begin(), tmp.end());
	// 	prn_vec(v2);
	// }

	// {
	// 	std::cout << "=== assign(fill) ===\n";
	// 	ft::vector<int> tmp(10, 0);
	// 	tmp.assign(3, 42);
	// 	prn_vec(tmp);
	// }

	// {
	// 	std::cout << "=== assign(range) by std::list<>::iterator ===\n";
	// 	ft::vector<int> tmp(10, 0);
	// 	std::list<int> lst(15, 42);
	// 	tmp.assign(lst.begin(), lst.end());
	// 	prn_vec(tmp);
	// }
	// 	std::cout << "=== erase ===\n";
	// 	//ft::vector<int>::iterator it = v.erase(v.end() - 3);
	// 	it = v.erase(v.end() - 3);
	// 	std::cout << "return value points to " << *it << " ";
	// 	prn_vec(v);

	// 	std::cout << "=== erase range ===\n";
	// 	v.erase(v.begin()+3, v.begin()+5);
	// 	prn_vec(v);

	// 	std::cout << "=== insert(fill) ===\n";
	// 	v.insert(v.begin() + 3, 3, 42);
	// 	prn_vec(v);

	// {
	// 	std::cout << "=== insert(range) by std::list<>::iterator ===\n";
	// 	ft::vector<int> tmp;
	// 	std::list<int> lst(15, 42);
	// 	tmp.insert(tmp.begin(), lst.begin(), lst.end());
	// 	prn_vec(tmp);
	// }

	// 	std::cout << "=== compare two vectors ===\n";
	// 	{
	// 		ft::vector<int> foo(3, 100);
	// 		ft::vector<int> bar(2, 200);
	// 		std::cout << (foo < bar) << "\n";
	// 	}
	// 	{
	// 		int a1[] = {1,2,3,4,5};
	// 		int a2[] = {1,2,3,4,5};
	// 		ft::vector<int> v1(a1, a1 + 5);
	// 		ft::vector<int> v2(a2, a2 + 6);
	// 		std::cout << (v1==v2) << "\n";
	// 		std::cout << (v1!=v2) << "\n";
	// 		std::cout << (v1<v2) << "\n";
	// 		std::cout << (v1<=v2) << "\n";
	// 		std::cout << (v1>v2) << "\n";
	// 		std::cout << (v1>=v2) << "\n";
	// 	}
	// 	{
	// 		int a1[] = {1,2,3,4,5};
	// 		int a2[] = {1,2,3,4,6};
	// 		ft::vector<int> v1(a1, a1 + 5);
	// 		ft::vector<int> v2(a2, a2 + 6);
	// 		std::cout << (v1==v2) << "\n";
	// 		std::cout << (v1!=v2) << "\n";
	// 		std::cout << (v1<v2) << "\n";
	// 		std::cout << (v1<=v2) << "\n";
	// 		std::cout << (v1>v2) << "\n";
	// 		std::cout << (v1>=v2) << "\n";
	// 	}
	// 	{
	// 		int a1[] = {1,2,3,4,5};
	// 		int a2[] = {1,2,3,4,5,6};
	// 		ft::vector<int> v1(a1, a1 + 5);
	// 		ft::vector<int> v2(a2, a2 + 6);
	// 		std::cout << (v1==v2) << "\n";
	// 		std::cout << (v1!=v2) << "\n";
	// 		std::cout << (v1<v2) << "\n";
	// 		std::cout << (v1<=v2) << "\n";
	// 		std::cout << (v1>v2) << "\n";
	// 		std::cout << (v1>=v2) << "\n";
	// 	}
	// 	{
	// 		int a1[] = {1,2,3,4,5};
	// 		int a2[] = {1,2,3,4};
	// 		ft::vector<int> v1(a1, a1 + 5);
	// 		ft::vector<int> v2(a2, a2 + 4);
	// 		std::cout << (v1==v2) << "\n";
	// 		std::cout << (v1!=v2) << "\n";
	// 		std::cout << (v1<v2) << "\n";
	// 		std::cout << (v1<=v2) << "\n";
	// 		std::cout << (v1>v2) << "\n";
	// 		std::cout << (v1>=v2) << "\n";
	// 	}

		{
			std::cout << "=== pair ===\n";
			ft::pair<int,char> foo(10, 'a');
			ft::pair<int,char> bar(10, 'z');
			std::cout << "foo = (" << foo.first << ", " << foo.second << ")\n";
			std::cout << "bar = (" << bar.first << ", " << bar.second << ")\n";
			std::cout << "foo == bar : " << (foo == bar) << "\n";
			std::cout << "foo < bar : " << (foo < bar) << "\n";
			ft::pair<std::string, double> p1;
			ft::pair<std::string, double> p2("tomatoes", 2.3);
			ft::pair<std::string, double> p3(p2);
			p1 = ft::make_pair("lightbulbs", 0.99);
			p2.first = "shoes"; p2.second = 49;
			std::cout << "p1 = (" << p1.first << ", " << p1.second << ")\n";
			std::cout << "p2 = (" << p2.first << ", " << p2.second << ")\n";
			std::cout << "p3 = (" << p3.first << ", " << p3.second << ")\n";
		}


		std::cout << "\n\n=== map ===\n";
		ft::map<char,int> m;
		ft::map<char,int>::iterator it_m;
		std::cout << "(begin==end) : " << (m.begin() == m.end()) << "     size= " << m.size() << "\n";
		m.insert(ft::pair<char,int>('a',1));
		m.insert(ft::pair<char,int>('b',2));
		m.insert(ft::pair<char,int>('c',3));
		m.insert(ft::pair<char,int>('c',8));
		m.insert(ft::pair<char,int>('c',9));
		m.insert(ft::pair<char,int>('d',4));
		m.insert(ft::pair<char,int>('e',5));
		std::cout << "empty : " << m.empty() << "           size= " << m.size() << "\n";

		std::cout << "\nvalue of 'b' : " << m.find('b')->second << "\n";
		m['b'] = 42;
		std::cout << "\nchange value of 'b' by idx : " << m.find('b')->second << "\n";


		prn_map(m);

		std::cout << "\n erase 'c'\n";
		m.erase('c');
		prn_map(m);

		std::cout << "\n erase 'a'\n";
		m.erase('a');
		prn_map(m);

		std::cout << "\n erase 'b'\n";
		m.erase('b');
		prn_map(m);

		std::cout << "\n add 'c' by idx\n";
		m['c'] = 42;
		prn_map(m);


		std::cout << "\n insert by range\n";
		ft::pair<char,int> arr[] = {
			ft::pair<char,int>('a', 9),
			ft::pair<char,int>('b', 8),
			ft::pair<char,int>('c', 7),
			ft::pair<char,int>('x', 6),
			ft::pair<char,int>('y', 5),
			ft::pair<char,int>('z', 4) };
		m.insert(arr, arr+6);
		prn_map(m);

		std::cout << "\n return value of single element\n";
		ft::pair<ft::map<char,int>::iterator, bool> ret;
		ret = m.insert( ft::pair<char,int>('z', 500));
		if (ret.second == false) {
			std::cout << "'z' : " << ret.first->first << ", already existed with a value of " << ret.first->second << "\n";
		}
		prn_map(m);

		std::cout << "\n erase by iterator\n";
		it_m = m.find('z');
		m.erase(it_m);
		prn_map(m);

		std::cout << "\n erase by range\n";
		it_m = m.find('x');
		m.erase(it_m, m.end());
		prn_map(m);

		{
			std::cout << "\n swap\n";
			ft::map<char,int> foo,bar;
			foo['x']=100;
			foo['y']=200;

			bar['a']=11;
			bar['b']=22;
			bar['c']=33;

			foo.swap(bar);

			std::cout << "foo contains:\n";
			for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

			std::cout << "bar contains:\n";
			for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
				std::cout << it->first << " => " << it->second << '\n';

		}


		std::cout << "\n ===== stack =====\n";
		ft::stack<int> st;

		std::cout << "size=" << st.size() << "      is_empty=" << st.empty() << "\n";
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		std::cout << "size=" << st.size() << " , is_empty=" << st.empty() << "\n";
		while (st.size()) {
			std::cout << st.top() << "\n";
			st.pop();
		}

		std::cout << "size=" << st.size() << " , is_empty=" << st.empty() << "\n";




		std::cout << "\n=== set ===\n";

		{
			ft::set<int> s;
			std::cout << "0 ~ 10000 insert\n";
			for (int i = 0; i < 10000; i++)
				s.insert(i);
			std::cout << "size = " << s.size() << "\n";

			std::cout << "2000 ~ 3000 erase\n";
			for (int i = 2000; i < 3000; i++)
				s.erase(i);
			std::cout << "size = " << s.size() << "\n";
			std::cout << "set clear\n";
			s.clear();
			std::cout << "after clear: size = " << s.size() << "\n";
		}

		system("leaks ft_container.out");
	return 0;
}
