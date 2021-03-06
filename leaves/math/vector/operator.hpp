#pragma once

namespace leaves { namespace math 
{
	// unary 

	// operator positive 
	template <typename E>
	auto operator + (vector_expression<E> const& e)
		-> typename vector_unary_traits<E, vector_unary_positive>::type
	{
		typedef typename vector_unary_traits<E, vector_unary_positive>::type expression_type;
		return expression_type{ get_expression(e) };
	}
	
	// operator negative
	template <typename E>
	auto operator - (vector_expression<E> const& e)
		-> typename vector_unary_traits<E, vector_unary_negative>::type
	{
		typedef typename vector_unary_traits<E, vector_unary_negative>::type expression_type;
		return expression_type{ get_expression(e) };
	}

	// function abs
	template <typename E>
	auto abs(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, vector_unary_abs>::type
	{
		typedef typename vector_unary_traits<E, vector_unary_abs>::type expression_type;
		return expression_type{ get_expression(e) };
	}
	
	// function squre
	template <typename E>
	auto square(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, vector_unary_square>::type
	{
		typedef typename vector_unary_traits<E, vector_unary_square>::type expression_type;
		return expression_type{ get_expression(e) };
	}

	// function inverse
	template <typename E>
	auto inverse(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, vector_unary_inverse>::type
	{
		typedef typename vector_unary_traits<E, vector_unary_inverse>::type expression_type;
		return expression_type{ get_expression(e) };
	}

	// binary
	// operator +
	template <typename E1, typename E2>
	auto operator + (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, vector_binary_add>::type
	{
		typedef typename vector_binary_traits<E1, E2, vector_binary_add>::type expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator -
	template <typename E1, typename E2>
	auto operator - (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, vector_binary_sub>::type
	{
		typedef typename vector_binary_traits<E1, E2, vector_binary_sub>::type expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator *
	template <typename E1, typename E2>
	auto operator * (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, vector_binary_mult>::type
	{
		typedef typename vector_binary_traits<E1, E2, vector_binary_mult>::type expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator *
	template <typename E, typename T,
		typename = std::enable_if_t<is_scalar<T>::value> >
	auto operator * (vector_expression<E> const& e, T t)
		-> typename vector_scalar_traits<E, T, vector_scalar_mult>::type
	{
		typedef typename vector_scalar_traits<E, T, vector_scalar_mult>::type expression_type;
		return expression_type{ get_expression(e), t };
	}
	
	// operator *
	template <typename T, typename E,
		typename = std::enable_if_t<is_scalar<T>::value > >
	auto operator * (T t, vector_expression<E> const& e)
		-> typename vector_scalar_traits<E, T, vector_scalar_div>::type
	{
		typedef typename vector_scalar_traits<E, T, vector_scalar_div>::type expression_type;
		return expression_type{ get_expression(e), t };
	}

	// operator /
	template <typename E1, typename E2>
	auto operator / (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, vector_binary_div>::type
	{
		typedef typename vector_binary_traits<E1, E2, vector_binary_div>::type expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator /
	template <typename E, typename T,
		typename = std::enable_if_t<is_scalar<T>::value> >
	auto operator / (vector_expression<E> const& e, T t)
		-> typename vector_scalar_traits<E, T, vector_scalar_div>::type
	{
		typedef typename vector_scalar_traits<E, T, vector_scalar_div>::type expression_type;
		return expression_type{ get_expression(e), t };
	}
	
	template <typename E>
	auto sum(vector_expression<E> const& e)
		-> typename vector_to_scalar_traits<E, vector_sum>::return_type
	{
		typedef typename vector_to_scalar_traits<E, vector_sum>::type expression_type;
		return expression_type{ get_expression(e) };
	}

	template <typename E>
	auto magnitude(vector_expression<E> const& e)
		-> typename vector_to_scalar_traits<E, vector_magnitude>::return_type
	{
		typedef typename vector_to_scalar_traits<E, vector_magnitude>::type expression_type;
		return expression_type{ get_expression(e) };
	}
	
	template <typename E1, typename E2>
	auto dot(vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_to_scalar_traits<E1, E2, vector_binary_dot>::return_type
	{
		typedef vector_binary_to_scalar_traits<E1, E2, vector_binary_dot>::type expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}
} }