#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <algorithm>
# include "utils/iterator.hpp"
# include "utils/type.hpp"
# include "utils/algorithm.hpp"

/* std::allocator
 * 메모리 할당과 해제 클래스
 * std::allocator::allocate(n)			: n의 크기를 갖는 초기화 되지 않은 메모리블록 할당후 시작 주소 반환.
 * std::allocator::deallocate(p, n)		: p 부터 p+n 까지의 메모리블록을 해제.
 * std::allocator::construct(p, class)	: p가 가리키는 곳에 object class 생성
 * std::allocator::destroy(p)			: p가 가리키는 object의 소멸자 호출
 */

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 												value_type;
			typedef Alloc											allocator_type;
			typedef typename std::size_t							size_type;
			typedef typename std::ptrdiff_t							difference_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;

			typedef typename Alloc::pointer							pointer;
			typedef typename Alloc::const_pointer					const_pointer;

			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:
			pointer			_begin;
			pointer			_end;
			pointer			_capacity;
			allocator_type	_alloc;

		public:
			/* orthdox */
			vector(const allocator_type& alloc = allocator_type())
				: _begin(ft::NIL), _end(ft::NIL), _capacity(ft::NIL), _alloc(alloc) {}
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				: _alloc(alloc)
			{
				_vector_init(n);
				_alloc_construct(n, val);
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::NIL) : _alloc(alloc)
			{
				size_type n = std::distance(first, last);
				_vector_init(n);
				_alloc_construct(n);
				std::copy(first, last, _begin);
			}
			vector(const vector& v) : _alloc(v._alloc)
			{
				size_type n = v.size();
				_vector_init(v.capacity());
				_alloc_construct(n);
				std::copy(v._begin, v._end, _begin);
			}
			~vector()
			{
				if (_begin == NULL)
					return;
				size_type x_capacity = capacity();
				_alloc_destroy(_begin);
				_alloc.deallocate(_begin, x_capacity);
			}

			vector& operator=(const vector& v)
			{
				if (this != &v)
					assign(v._begin, v._end);
				return *this;
			}

			iterator begin()						{ return iterator(_begin); }
			iterator end()							{ return iterator(_end); }
			const_iterator begin() const			{ return const_iterator(_begin); }
			const_iterator end() const				{ return const_iterator(_end); }
			reverse_iterator rbegin()				{ return reverse_iterator(end()); }
			reverse_iterator rend()					{ return reverse_iterator(begin()); }
			const_reverse_iterator rbegin() const	{ return const_reverse_iterator(end()); }
			const_reverse_iterator rend() const	{ return const_reveres_iterator(begin()); }

			reference operator[](size_type n)				{ return _begin[n]; }
			const_reference operator[](size_type n) const	{ return _begin[n]; }

			/* operator[]와는 다르게 n 값이 element 범위를 넘어가는지 확인 후 throw 를 함. */
			reference at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("ft::vector::at");
				return _begin[n];
			}
			const_reference at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("ft::vector::at");
				return _begin[n];
			}

			reference front()				{ return *_begin; }
			reference back() 				{ return *(_end - 1); }
			const_reference front() const	{ return *_begin; }
			const_reference back() const	{ return *(_end - 1); }

			size_type size() const	{ return (_end - _begin); }
			size_type capacity() const	{ return (_capacity - _begin); }
			bool empty() const { return _begin == _end; }
			size_type max_size() const
			{
				return std::min<size_type>(std::numeric_limits<size_type>::max(),
					_alloc.max_size());
			}

			// vector.data() 형이 오는 test가 있어 추가
			T* data() throw() 				{ return reinterpret_cast<T*>(_begin); }
			const T* data() const throw()	{ return reinterpret_cast<const T*>(_begin); }

			/* 인자로 받을 n의 크기가 size 보다 작으면 나머지 공간은 삭제
			size 보다 크면 capacity와 비교 -> reserve로 늘릴지 판단 후 할당 */
			void resize(size_type n, value_type val = value_type())
			{
				if (size() > n)
				{
					size_type space = size() - n;
					_alloc_destroy(space);
				}
				else if (size() < n)
				{
					size_type space = n - size();
					if (capacity() < n)
						reserve(n);
					_alloc_construct(space, val);
				}
			}

			/* reserve >> insert , assign , push_back 등 각 함수에서 n 만큼 받을 인자를 매개변수로 취함
			받아올 인자 n이, capacity < n < capacity * 2 일경우 capacity를 2배로 늘려주고 각 멤버 값을 정리 후 재할당. */
			void reserve(size_type n)
			{
				if (n <= size() || n <= capacity())
					return;
				if (n < capacity() * 2)
					n = capacity() * 2;
				if (n > max_size())
					throw std::length_error("ft::vector::reserve");
				size_type x_size = size();
				size_type x_capacity = capacity();
				pointer _ptr = _alloc.allocate(n);
				std::uninitialized_copy(_begin, _end, _ptr);
				_alloc_destroy(_begin);
				_alloc.deallocate(_begin, x_capacity);
				_begin = _ptr;
				_end = _begin + x_size;
				_capacity = _begin + n;
			}
			// uninitialized_copy vs copy
			// 복사생성자 호출        vs 대입연산자 호출
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::NIL)
			{
				size_type n = std::distance(first, last);
				if (capacity() < n)
					reserve(n);
				std::copy(first, last, _begin);
				_end = _begin + n;
			}
			void assign(size_type n, const value_type& val)
			{
				if (capacity() < n)
					reserve(n);
				std::fill_n(_begin, n, val);
				_end = _begin + n;
			}
			void push_back(const value_type& val)
			{
				size_type n = size() + 1;
				if (capacity() < n)
					reserve(n);
				_alloc_construct(1);
				*(_end - 1) = val;
			}
			void pop_back() { _alloc_destroy(1); }
			// copy 차이 copy_backward
			// 0 1 2 3 4 5 6 7 8 9
			// lst   2 3 4 5 6    을 해당 위치에 대응되게 복사
			// 0 1 2 2 2 2 2 2 8 9 copy
			// 0 1 2 2 3 4 5 6 8 9 copy_backward
			// copy 는 원본이 복사가 이루어지기 전에 변함.
			// copy_backward 는 원본을 먼저 옮겨두고 복사.
			iterator insert(iterator _idx, const value_type& val)
			{
				difference_type space = _idx - begin();
				if (capacity() < size() + 1)
					reserve(size() + 1);
				pointer ptr = _begin + space;
				_alloc_construct(1);
				std::copy_backward(ptr, _end - 1, _end);
				*ptr = val;
				return iterator(ptr);
			}
			void insert(iterator _idx, size_type n, const value_type& val)
			{
				difference_type space = _idx - begin();
				if (capacity() < size() + n)
					reserve(size() + n);
				pointer ptr = _begin + space;
				_alloc_construct(n);
				std::copy_backward(ptr, _end - n, _end);
				for (size_type i = 0; i < n; i++)
					ptr[i] = val;
			}
			template <class InputIterator>
			void insert(iterator _idx, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = ft::NIL)
			{
				difference_type n = std::distance(first, last);
				difference_type space = _idx - begin();
				if (capacity() < size() + n)
					reserve(size() + n);
				pointer ptr = _begin + space;
				_alloc_construct(n);
				std::copy_backward(ptr, _end - n, _end);
				for (InputIterator it = first; it != last; )
					*ptr++ = *it++;
			}

			iterator erase(iterator _idx)
			{
				difference_type space = _idx - begin();
				pointer ptr = _begin + space;
				std::copy(ptr + 1, _end, ptr);
				_alloc_destroy(1);
				return iterator(ptr);
			}
			iterator erase(iterator first, iterator last)
			{
				difference_type n = std::distance(first, last);
				std::copy(last, end(), first);
				_alloc_destroy(n);
				return first;
			}
			void swap(vector& v)
			{
				std::swap(_begin, v._begin);
				std::swap(_end, v._end);
				std::swap(_capacity, v._capacity);
				std::swap(_alloc, v._alloc);
			}
			void clear() { _alloc_destroy(_begin); }

			allocator_type get_allocator() const { return _alloc; }

			void	_vector_init(size_type n)
			{
				if (n > max_size())
					{ throw std::length_error("ft::vector::_vector_init"); }
				_begin = _alloc.allocate(n);
				_end = _begin;
				_capacity = _begin + n;
			}

			void _alloc_construct(size_type n, T val)
			{
				for ( ; n > 0 ; _end++, n--)
				{
					_alloc.construct(_end);
					*_end = val;
				}
			}

			void _alloc_construct(size_type n)
			{
				for ( ; n > 0 ; _end++, n--)
					_alloc.construct(_end);
			}

			void _alloc_destroy(size_type n)
			{
				for ( ; n > 0 && _end-- ; n--)
					_alloc.destroy(_end);
			}

			void _alloc_destroy(pointer until)
			{
				for ( ; _end != until && _end-- ; )
					_alloc.destroy(_end);
			}
		};

		template <typename T, class Alloc>
		bool operator==(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()); }

		template <typename T, class Alloc>
		bool operator!=(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return !(x == y); }

		template <typename T, class Alloc>
		bool operator<(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()); }

		template <typename T, class Alloc>
		bool operator<=(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return !(y < x); }

		template <typename T, class Alloc>
		bool operator>(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return (y < x); }

		template <typename T, class Alloc>
		bool operator>=(const ft::vector<T, Alloc>& x, const ft::vector<T, Alloc>& y)
		{ return !(x < y); }

		template <typename T, class Alloc>
		void swap(ft::vector<T, Alloc>& x, ft::vector<T, Alloc>& y)
		{ x.swap(y); }
}

#endif
