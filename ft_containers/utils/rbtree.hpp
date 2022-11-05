#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <algorithm>
# include <limits>
# include <memory>
# include "pair.hpp"
# include "iterator.hpp"
# include "type.hpp"

namespace ft {
	template <typename T>
	struct __tree_node
	{
		typedef T value_type;

		__tree_node*	__parent;
		__tree_node*	__left;
		__tree_node*	__right;
		value_type		__value;
		bool			__is_black;

		__tree_node(void) : __parent(ft::NIL), __left(ft::NIL), __right(ft::NIL), __value(value_type()), __is_black(bool()) {}
		__tree_node(const value_type& value) : __parent(ft::NIL), __left(ft::NIL), __right(ft::NIL), __value(value), __is_black(bool()) {}
		__tree_node(const __tree_node& n) : __parent(n.__parent), __left(n.__left), __right(n.__right), __value(n.__value), __is_black(n.__is_black) {}
		~__tree_node(void) {}

		__tree_node& operator=(const __tree_node& n)
		{
			if (this != &n)
			{
				__parent = n.__parent;
				__left = n.__left;
				__right = n.__right;
				__value = n.__value;
				__is_black = n.__is_black;
			}
			return *this;
		}
	};

	template <class NodePtr>
	bool __is_left_child(const NodePtr& ptr)
	{ return ptr == ptr->__parent->__left; }

	template <class NodePtr>
	bool __is_right_child(const NodePtr& ptr)
	{ return ptr == ptr->__parent->__right; }

	template <class NodePtr>
	bool __is_black_color(const NodePtr& ptr)
	{ return ptr->__is_black; }

	template <class NodePtr>
	bool __is_red_color(const NodePtr& ptr)
	{ return !ptr->__is_black; }

	/* ptr 기준 sub-tree 중 가장 작은 노드 */
	template <class NodePtr>
	NodePtr __min_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->__left != nil)
			ptr = ptr->__left;
		return ptr;
	}

	/* ptr 기준 sub-tree 중 가장 큰 노드 */
	template <class NodePtr>
	NodePtr __max_node(NodePtr ptr, NodePtr nil)
	{
		while (ptr->__right != nil)
			ptr = ptr->__right;
		return ptr;
	}

	/* Red-Black Tree의 iterator(node) 중위 순회 */
	template <class NodePtr>
	NodePtr __next_node(NodePtr ptr, NodePtr nil)
	{
		if (ptr->__right != nil)
			return __min_node(ptr->__right, nil);
		while (!__is_left_child(ptr))
			ptr = ptr->__parent;
		return ptr->__parent;
	}

	template <class NodePtr>
	NodePtr __prev_node(NodePtr ptr, NodePtr nil)
	{
		if (ptr->__left != nil)
			return __max_node(ptr->__left, nil);
		while (!__is_right_child(ptr))
			ptr = ptr->__parent;
		return ptr->__parent;
	}

	template <typename T, typename U, class Comp>
	bool __is_equal(const T& t, const U& u, Comp comp)
	{ return !comp(t, u) && !comp(u, t); }

	/* Red-Black Tree */
	template <typename T, class Key, class Comp, class Alloc = std::allocator<T> >
	class __rbt{
		public:
			typedef T		value_type;
			typedef Key		key_type;
			typedef Comp	compare_type;

			typedef __tree_node<value_type>		node_type;
			typedef __tree_node<value_type>*	node_pointer;
			typedef ft::tree_iterator<value_type, node_type>			iterator;
			typedef ft::tree_iterator<const value_type, node_type>		const_iterator;

			typedef Alloc		allocator_type;
			typedef typename Alloc::template rebind<node_type>::other	node_allocator;
			typedef std::allocator_traits<node_allocator>				node_traits;

			typedef std::size_t		size_type;
			typedef std::ptrdiff_t	diffefence_type;

		private:
			node_pointer	__nil;
			node_pointer	__begin;
			node_pointer	__end;
			compare_type	__comp;
			node_allocator	__alloc;
			size_type		__size;

		public:
			/* orthodox */
			__rbt(const compare_type& comp, const allocator_type& alloc)
			: __comp(comp), __alloc(alloc), __size(size_type())
			{
				__nil = __alloc.allocate(1);
				__alloc.construct(__nil, value_type());
				__nil->__parent = __nil;
				__nil->__left = __nil;
				__nil->__right = __nil;
				__nil->__is_black = true;
				__end = make_node(value_type());
				__end->__is_black = true;
				__begin = __end;
			}
			__rbt(const __rbt& rbt)
			: __comp(rbt.__comp), __alloc(rbt.__alloc), __size(size_type())
			{
				__nil = __alloc.allocate(1);
				__alloc.construct(__nil, value_type());
				__nil->__parent = __nil;
				__nil->__left = __nil;
				__nil->__right = __nil;
				__nil->__is_black = true;
				__end = make_node(value_type());
				__end->__is_black = true;
				__begin = __end;
				insert(rbt.begin(), rbt.end());
			}
			~__rbt()
			{
				del_node_all(__end);
				del_node(__nil);
			}
			__rbt& operator=(const __rbt& rbt)
			{
				if (this != &rbt)
				{
					__rbt tmp(rbt);
					swap(tmp);
				}
				return *this;
			}
			/* iterator */
			iterator begin()				{ return iterator(__begin, __nil); }
			iterator end()					{ return iterator(__end, __nil); }
			const_iterator begin() const	{ return const_iterator(__begin, __nil); }
			const_iterator end() const		{ return const_iterator(__end, __nil); }

			size_type size() const	{ return __size; }
			size_type max_size() const
			{
				return std::min<size_type>(std::numeric_limits<size_type>::max(),
						node_traits::max_size(node_allocator()));
			}
			bool empty() const { return __size == 0; }

			ft::pair<iterator, bool> insert(const value_type& val)
			{
				node_pointer nd_ptr = __search_parent(val);
				if ( nd_ptr != __end && __is_equal(nd_ptr->__value, val, __comp))
					return ft::make_pair(iterator(nd_ptr, __nil), false);
				return ft::make_pair(iterator(__insert_tree(val, nd_ptr), __nil), true);
			}

			iterator	insert(iterator _idx, const value_type& val)
			{
				node_pointer nd_ptr = __search_parent(val, _idx.base());
				if (nd_ptr != __end && __is_equal(nd_ptr->__value, val, __comp))
					return iterator(nd_ptr, __nil);
				return iterator(__insert_tree(val, nd_ptr), __nil);
			}

			template <typename InputIterator>
			void	insert(InputIterator first, InputIterator last)
			{
				for ( ; first != last ; first++)
					insert(*first);
			}

			/* nullptr or ++iterator 반환 */
			iterator	erase(iterator _idx)
			{
				if (__size == 0)
					return iterator(__nil, __nil);
				iterator tmp(_idx);
				++tmp;
				if (_idx == begin())
					__begin = tmp.base();
				__remove(_idx.base());
				del_node(_idx.base());
				return tmp;
			}
			/* erase */
			size_type	erase(const key_type& val)
			{
				iterator it(__find(val), __nil);
				if (it == end())
					return 0;
				if (it == begin())
				{
					iterator tmp(it);
					++tmp;
					__begin = tmp.base();
				}
				__remove(it.base());
				del_node(it.base());
				return 1;
			}
			void	erase(iterator first, iterator last)
			{
				for ( ; first != last ;)
					first = erase(first);
			}
			void	swap(__rbt& rbt)
			{
				std::swap(__nil, rbt.__nil);
				std::swap(__begin, rbt.__begin);
				std::swap(__end, rbt.__end);
				std::swap(__comp, rbt.__comp);
				std::swap(__alloc, rbt.__alloc);
				std::swap(__size, rbt.__size);
			}
			/* C++ STL 에선 메모리를 완전히 해제하기 위해 swap을 이용해 기본생성자를 호출한 임시의 컨테이너 객체를 이용
			해당 지역에서의 호출이 종료되면 tmp에 옮겨진 tree는 삭제된다. */
			void	clear()
			{
				__rbt tmp(__comp, __alloc);
				swap(tmp);
			}

			iterator	find(const key_type& key)
			{ return iterator(__find(key), __nil); }

			const_iterator	find(const key_type& key) const
			{ return const_iterator(__find(key), __nil); }

			/* lower_bound k : 오른쪽 원소 중 k와 같거나 큰 값 중 가장 왼쪽의 iterator */
			iterator	lower_bound(const key_type& key)
			{ return iterator(__lower_bound(key), __nil); }

			const_iterator	lower_bound(const key_type& key) const
			{ return const_iterator(__lower_bound(key), __nil); }

			/* upper_bound k : 오른쪽 원소 중 k보다 큰 값 중 가장 왼쪽의 iterator */
			iterator upper_bound(const key_type& key)
			{ return iterator(__upper_bound(key), __nil); }

			const_iterator upper_bound(const key_type& key) const
			{ return const_iterator(__upper_bound(key), __nil); }

			/* pair<lower_bound iterator , upper_bound iterator> 객체로 반환*/
			ft::pair<iterator, iterator> equal_range(const key_type& key)
			{ return ft::make_pair(lower_bound(key), upper_bound(key)); }

			ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
			{ return ft::make_pair(lower_bound(key), upper_bound(key)); }

			allocator_type get_allocator() const
			{ return __alloc; }

			node_pointer	getRoot() const
			{ return __end->__left; }

			/* 해당 노드 포인터를 root 로 설정 */
			void	setRoot(const node_pointer nd_ptr)
			{
				nd_ptr->__parent = __end;
				__end->__left = nd_ptr;
			}

			node_pointer	make_node(const value_type& val)
			{
				node_pointer nd_ptr = __alloc.allocate(1);
				__alloc.construct(nd_ptr, val);
				nd_ptr->__parent = __nil;
				nd_ptr->__left = __nil;
				nd_ptr->__right = __nil;
				nd_ptr->__is_black = false;
				return nd_ptr;
			}
			void	del_node(node_pointer nd_ptr)
			{
				--__size;
				__alloc.destroy(nd_ptr);
				__alloc.deallocate(nd_ptr, 1);
			}
			void	del_node_all(node_pointer nd_ptr)
			{
				if (nd_ptr == __nil)
					return;
				del_node_all(nd_ptr->__left);
				del_node_all(nd_ptr->__right);
				del_node(nd_ptr);
			}
			node_pointer	__search_parent(const value_type& val, node_pointer _idx = ft::NIL)
			{
				if (_idx && _idx != __end)
				{
					if (__comp(val, _idx->__value) && _idx->__left == __nil)
					{
						iterator it_prev = iterator(_idx, __nil);
						if (it_prev == begin() || __comp(*--it_prev, val))
							return _idx;
					}
					else if (_idx->__right == __nil)
					{
						iterator it_next = iterator(_idx, __nil);
						if (it_next == end() || __comp(val, *++it_next))
							return _idx;
					}
				}
				node_pointer cur = getRoot();
				node_pointer tmp = __end;
				for ( ; cur != __nil ; )
				{
					tmp = cur;
					if (__comp(val, cur->__value))
						cur = cur->__left;
					else if (__comp(cur->__value, val))
						cur = cur->__right;
					else
						return cur;
				}
				/* 루트 노드의 leaf가 비어있을경우 그대로 반환 */
				return tmp;
			}
			/* parent value보다 작으면 왼쪽 크면 오른쪽 삽입 -> 해당 노드를 삽입 후 Tree 재정렬 */
			node_pointer	__insert_tree(const value_type& val, node_pointer parent)
			{
				node_pointer nd_ptr = make_node(val);
				if (parent == __end)
					setRoot(nd_ptr);
				else if (__comp(val, parent->__value))
					parent->__left = nd_ptr;
				else
					parent->__right = nd_ptr;
				nd_ptr->__parent = parent;
				__insert_fix(nd_ptr);
				__insert_init(nd_ptr);
				return nd_ptr;
			}
			/* 부모 컬러가 red 일 경우 !! double red !!
			-> parent 노드의 위치를 보고 fix_left or fix_right 실행 */
			void	__insert_fix(node_pointer nd_ptr)
			{
				while (__is_red_color(nd_ptr->__parent))
				{
					if (__is_left_child(nd_ptr->__parent))
					{
						node_pointer uncle = nd_ptr->__parent->__parent->__right;
						if (__is_red_color(uncle))
							__recoloring(nd_ptr, uncle);
						else
							__restructing_left(nd_ptr);
					}
					else
					{
						node_pointer uncle = nd_ptr->__parent->__parent->__left;
						if (__is_red_color(uncle))
							__recoloring(nd_ptr, uncle);
						else
							__restructing_right(nd_ptr);
					}
				}
				getRoot()->__is_black = true;
			}

			void	__recoloring(node_pointer& nd_ptr, node_pointer& uncle)
			{
				nd_ptr->__parent->__is_black = true;
				uncle->__is_black = true;
				uncle->__parent->__is_black = false;
				nd_ptr = uncle->__parent;
			}

			void	__restructing_left(node_pointer nd_ptr)
			{
				if (__is_right_child(nd_ptr))
				{
					nd_ptr = nd_ptr->__parent;
					__rot_left(nd_ptr);
				}
				nd_ptr->__parent->__is_black = true;
				nd_ptr->__parent->__parent->__is_black = false;
				__rot_right(nd_ptr->__parent->__parent);
			}
			void	__restructing_right(node_pointer nd_ptr)
			{
				if (__is_left_child(nd_ptr))
				{
					nd_ptr = nd_ptr->__parent;
					__rot_right(nd_ptr);
				}
				nd_ptr->__parent->__is_black = true;
				nd_ptr->__parent->__parent->__is_black = false;
				__rot_left(nd_ptr->__parent->__parent);
			}
			// /* insert로 변화된 트리 초기값 설정 */
			void	__insert_init(const node_pointer nd_ptr)
			{
				if (__begin == __end || __comp(nd_ptr->__value, __begin->__value))
					__begin = nd_ptr;
				__size++;
			}
			/* recoloring 노드 포인터설정 매개변수로 받은 노드 포인터를 nd_fix으로 설정
			nd_fix : 자식이 둘 일때 삭제될 자리로 바꿀 노드 포인터
			nd_recolor : recoloring(rebalancing)을 고려할 노드 포인터 */
			void	__remove(node_pointer nd_ptr)
			{
				node_pointer nd_recolor;
				node_pointer nd_fix = nd_ptr;
				bool origin_color = __is_black_color(nd_ptr);
				/* nd_ptr -> left leaf만 비어있을 경우 nd_ptr->right를 옮겨 link됨 */
				if (nd_ptr->__left == __nil)
				{
					nd_recolor = nd_ptr->__right;
					__transplant(nd_ptr, nd_ptr->__right);
				}
				/* nd_ptr -> right leaf만 비어있을 경우 */
				else if (nd_ptr->__right == __nil)
				{
					nd_recolor = nd_ptr->__left;
					__transplant(nd_ptr, nd_ptr->__left);
				}
				/* left & right 모두 있을 경우 */
				else
				{
					nd_fix = __min_node(nd_ptr->__right, __nil);
					origin_color = __is_black_color(nd_fix);
					/* nd_fix은 left가 없으므로 옮길때 고려할 nd_recolor은 right */
					nd_recolor = nd_fix->__right;
					if (nd_fix->__parent == nd_ptr)
						nd_recolor->__parent = nd_fix;
					else
					{
						/* 옮겨 심어질 경우 고려할 경우
						1. 부모가 end 인 경우 -> 고려할 색상 : nd_fix
						2. 오른쪽 자식이 없는 경우 -> 그냥 이어주면 됨
						3. 서브트리로 이어나가 오른쪽 자식이 있는경우
						-> nd_fix을 옮겨주고 right를 nd_fix 부모와 연결 하면 끝*/
						__transplant(nd_fix, nd_fix->__right);
						nd_fix->__right = nd_ptr->__right;
						nd_fix->__right->__parent = nd_fix;
					}
					__transplant(nd_ptr, nd_fix);
					nd_fix->__left = nd_ptr->__left;
					nd_fix->__left->__parent = nd_fix;
					nd_fix->__is_black = __is_black_color(nd_ptr);
				}
				/* 삭제한 노드가 red 색상이면 그냥 지워도 상관 없음.
				-> origin_color 가 black 이면 이를 지나는 모든 경로에서 black - 1이 됨
				-> 리밸런싱 */
				if (origin_color)
					__remove_fixup(nd_recolor);
			}
			/* nd_ptr이 새로운 root가 아니고 black 일 경우 fixup 반복문 */
			void	__remove_fixup(node_pointer nd_ptr)
			{
				while (nd_ptr != getRoot() && __is_black_color(nd_ptr))
				{
					if (__is_left_child(nd_ptr))
						__remove_fixup_left(nd_ptr);
					else
						__remove_fixup_right(nd_ptr);
				}
				nd_ptr->__is_black = true;
			}

			void	__remove_fixup_left(node_pointer& nd_ptr)
			{
				node_pointer sibling = nd_ptr->__parent->__right;
				/* case 1) 형제가 red 일 경우.
				-> 부모와 형제의 색을 바꾸고 부모기준 left_rotation */
				if (__is_red_color(sibling))
				{
					sibling->__is_black = true;
					nd_ptr->__parent->__is_black = false;
					__rot_left(nd_ptr->__parent);
					/* 새로운 sibling이 black이 됨. nd_ptr을 지나는 경로의 black - 1은 유지. */
					sibling = nd_ptr->__parent->__right;
				}
				/* case 2) S의 자식들이 모두 black인 경우.
				-> S를 red로 바꾸면 N-P 경로와 S-P 경로의 black - 1 이 됨.
				-> P를 기준으로 rebalancing */
				if (__is_black_color(sibling->__left) && __is_black_color(sibling->__right))
				{
					sibling->__is_black = false;
					nd_ptr = nd_ptr->__parent;
				}
				/* case 2-1) S와 S->right S가 black 인 경우 (case 1에 의해 S는 반드시 black)
				-> S->left를 black으로 만들고 S를 red로 만듬. -> S기준 right_rotation
				-> 모든 경로에서 black 노드 수는 변함 없음. */
				else if (__is_black_color(sibling->__right))
				{
					sibling->__left->__is_black = true;
					sibling->__is_black = false;
					__rot_right(sibling);
					sibling = nd_ptr->__parent->__right;
				}
				/* S는 black S->right가 red인 경우
				-> P와 S의 색을 바꾸고 (S는 반드시 black) S->right를 black 으로 바꿈.
				-> P 기준 left_rotation
				-> 짜잔 N-P 경로에서 black 경로가 + 1 되서 종료.(getRoot()를 추가하면서 종료 시그널을 보냄) */
				if (__is_red_color(sibling->__right))
				{
					sibling->__is_black = __is_black_color(nd_ptr->__parent);
					nd_ptr->__parent->__is_black = true;
					sibling->__right->__is_black = true;
					__rot_left(nd_ptr->__parent);
					nd_ptr = getRoot();
				}
			}
			/* fixup_left와 대칭 */
			void	__remove_fixup_right(node_pointer& nd_ptr)
			{
				node_pointer sibling = nd_ptr->__parent->__left;
				if (__is_red_color(sibling))
				{
					sibling->__is_black = true;
					nd_ptr->__parent->__is_black = false;
					__rot_right(nd_ptr->__parent);
					sibling = nd_ptr->__parent->__left;
				}
				if (__is_black_color(sibling->__right) && __is_black_color(sibling->__left))
				{
					sibling->__is_black = false;
					nd_ptr = nd_ptr->__parent;
				}
				else if (__is_black_color(sibling->__left))
				{
					sibling->__right->__is_black = true;
					sibling->__is_black = false;
					__rot_left(sibling);
					sibling = nd_ptr->__parent->__left;
				}
				if (__is_red_color(sibling->__left))
				{
					sibling->__is_black = __is_black_color(nd_ptr->__parent);
					nd_ptr->__parent->__is_black = true;
					sibling->__left->__is_black = true;
					__rot_right(nd_ptr->__parent);
					nd_ptr = getRoot();
				}
			}
			/* 삭제할 노드의 부모가 end 노드일 경우와 아닐경우의 link 함수 */
			void	__transplant(node_pointer before, node_pointer after)
			{
				/* __end 일 경우 nil만 존재. setRoot */
				if (before->__parent == __end)
					setRoot(after);
				/* 아닐경우 직접 옮김 */
				else if (__is_left_child(before))
					before->__parent->__left = after;
				else
					before->__parent->__right = after;
				/* link */
				after->__parent = before->__parent;
			}
			/* nd_ptr 기준으로 왼쪽 회전 BST 특성상 옮겨간 sub-tree도 특성을 유지하고 RBT의 규칙도 유지함. */
			void	__rot_left(node_pointer nd_ptr)
			{
				node_pointer ch = nd_ptr->__right;
				nd_ptr->__right = ch->__left;
				if (nd_ptr->__right != __nil)
					nd_ptr->__right->__parent = nd_ptr;
				node_pointer parent = nd_ptr->__parent;
				ch->__parent = parent;
				if (parent == __end)
					setRoot(ch);
				else if (__is_left_child(nd_ptr))
					parent->__left = ch;
				else
					parent->__right = ch;
				ch->__left = nd_ptr;
				nd_ptr->__parent = ch;
			}
			/* left랑 대칭 */
			void	__rot_right(node_pointer nd_ptr)
			{
				node_pointer ch = nd_ptr->__left;
				nd_ptr->__left = ch->__right;
				if (nd_ptr->__left != __nil)
					nd_ptr->__left->__parent = nd_ptr;
				node_pointer parent = nd_ptr->__parent;
				ch->__parent = parent;
				if (parent == __end)
					setRoot(ch);
				else if (__is_left_child(nd_ptr))
					parent->__left = ch;
				else
					parent->__right = ch;
				ch->__right = nd_ptr;
				nd_ptr->__parent = ch;
			}
			node_pointer __find(const key_type& val) const
			{
				node_pointer nd_ptr = getRoot();
				while (nd_ptr != __nil)
				{
					if (__comp(val, nd_ptr->__value))
						nd_ptr = nd_ptr->__left;
					else if (__comp(nd_ptr->__value, val))
						nd_ptr = nd_ptr->__right;
					else
						return nd_ptr;
				}
				return __end;
			}
			node_pointer	__lower_bound(const key_type& key) const
			{
				node_pointer nd_ptr = getRoot();
				node_pointer tmp = __end;
				while (nd_ptr != __nil)
				{
					if (!__comp(nd_ptr->__value, key))
					{
						tmp = nd_ptr;
						nd_ptr = nd_ptr->__left;
					}
					else
						nd_ptr = nd_ptr->__right;
				}
				return tmp;
			}
			node_pointer	__upper_bound(const key_type& key) const
			{
				node_pointer nd_ptr = getRoot();
				node_pointer tmp = __end;
				while (nd_ptr != __nil)
				{
					if (__comp(key, nd_ptr->__value))
					{
						tmp = nd_ptr;
						nd_ptr = nd_ptr->__left;
					}
					else
						nd_ptr = nd_ptr->__right;
				}
				return tmp;
			}
	};
}
#endif
