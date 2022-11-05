#ifndef TYPE_HPP
# define TYPE_HPP

/* Cond가 true일 때만 type이 정의된다.
 *
 * SFINAE(Substitution Failure Is Not An Error): 치환 실패 != Error
 *
 * 템플릿 선언 template <typename T, typename = typename std::enable_if<Cond>::type> 인 경우,
 * Cond가 true라면 template <typename T, typename U = void> 로 치환되어 이하의 템플릿 함수가 오버로딩 후보군에 들어간다.
 * Cond가 false라면 enable_if<>::type 은 존재하지 않으므로 치환에 실패하지만, 이것이 컴파일 오류로 해석되지는 않고 오버로딩 후보군에서 제외될 뿐.
 * enable_if<>의 두번째 인자를 템플릿함수의 return type 또는 argument type 로 활용하는 것도 가능.
 * template<InputIterator>에서 사용.
 */

/* is_integral<T> : 자료형 T가 정수형인지 판별하는 bool value를 멤버상수로 갖는다.
 * operator bool() : 객체 자신이 bool 로 암시적 형변환될 때 쓰임.
 * if (is_integral<int>::value) 또는 if (is_integral<int>() )
 * https://stackoverflow.com/questions/4600295/what-is-the-meaning-of-operator-bool-const
 *
 * const, volatile qualifier가 들어와도 정확한 작동을 보장하기 위해 remove_cv도 추가.
 * is_integral<T>는 is_integral_<T without cv> 를 상속받고,
 * T without cv 의 타입에 따라 true_type{} 또는 false_type{}으로 인스턴스화한다.
 */

namespace ft {

	/* mynullptr rbtree의 NIL(null leaf)로 사용됨 */
	const class
	{
		private:
			void operator&() const;
		public:
			template <class _Tp>
			operator _Tp* () const { return 0; }

			template <class _Tp, class _Up>
			operator _Tp _Up::* () const { return 0; }
	} NIL = {};

	/* enable_if */
	template <bool Cond, typename T = void>
	struct enable_if { };

	template <typename T>
	struct enable_if<true, T>
	{ typedef T type; };

	/* is_integral */
	template <class T, T v>
	struct integral_constant {
		static const T					value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;


	template <typename T>
	struct remove_cv 					{ typedef T	type;};

	template <typename T>
	struct remove_cv<const T>			{ typedef T	type;};

	template <typename T>
	struct remove_cv<volatile T>		{ typedef T	type;};

	template <typename T>
	struct remove_cv<const volatile T>	{ typedef T	type;};


	template <typename T>
	struct is_integral_ : public false_type { };

	template <>
	struct is_integral_<bool> : public true_type { };

	template <>
	struct is_integral_<char> : public true_type { };

	template <>
	struct is_integral_<wchar_t> : public true_type { };

	template <>
	struct is_integral_<signed char> : public true_type { };

	template <>
	struct is_integral_<short int> : public true_type { };

	template <>
	struct is_integral_<int> : public true_type { };

	template <>
	struct is_integral_<long int> : public true_type { };

	/* template <> char16_t & char32_t & long long & unsigned long long -> c++11
	struct is_integral_<long long int> : public true_type { };*/

	template <>
	struct is_integral_<unsigned char> : public true_type { };

	template <>
	struct is_integral_<unsigned short int> : public true_type { };

	template <>
	struct is_integral_<unsigned int> : public true_type { };

	template <>
	struct is_integral_<unsigned long int> : public true_type { };

	/* template <>
	struct is_integral_<unsigned long long int> : public true_type { };*/


	template <typename T>
	struct is_integral : public is_integral_< typename remove_cv<T>::type > { };

}

#endif
