#pragma once

#include "detail\functional_detail.hpp"

namespace leaves { namespace math 
{
	// unary 

	// operator positive 
	template <typename E>
	auto operator + (vector_expression<E> const& e)
		-> typename vector_unary_traits<E, scalar_positive>::result
	{
		typedef typename vector_unary_traits<E, scalar_positive>::result expression_type;
		return expression_type{ get_expression(e) };
	}
	
	// operator negative
	template <typename E>
	auto operator - (vector_expression<E> const& e)
		-> typename vector_unary_traits<E, scalar_negative>::result
	{
		typedef typename vector_unary_traits<E, scalar_negative>::result expression_type;
		return expression_type{ get_expression(e) };
	}

	// function abs
	template <typename E>
	auto abs(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, scalar_abs>::result
	{
		typedef typename vector_unary_traits<E, scalar_abs>::result expression_type;
		return expression_type{ get_expression(e) };
	}
	
	// function squre
	template <typename E>
	auto square(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, scalar_squre>::result
	{
		typedef typename vector_unary_traits<E, scalar_squre>::result expression_type;
		return expression_type{ get_expression(e) };
	}

	// function inverse
	template <typename E>
	auto inverse(vector_expression<E> const& e)
		-> typename vector_unary_traits<E, scalar_inverse>::result
	{
		typedef typename vector_unary_traits<E, scalar_inverse>::result expression_type;
		return expression_type{ get_expression(e) };
	}

	// binary
	// operator +
	template <typename E1, typename E2>
	auto operator + (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, scalar_add>::result
	{
		typedef typename vector_binary_traits<E1, E2, scalar_add>::result expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator -
	template <typename E1, typename E2>
	auto operator - (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, scalar_sub>::result
	{
		typedef typename vector_binary_traits<E1, E2, scalar_sub>::result expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator *
	template <typename E1, typename E2>
	auto operator * (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, scalar_mult>::result
	{
		typedef typename vector_binary_traits<E1, E2, scalar_mult>::result expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator *
	template <typename E, typename T,
		typename = std::enable_if_t<is_scalar<T>::value> >
	auto operator * (vector_expression<E> const& e, T t)
		-> typename vector_scalar_traits<E, T, scalar_mult>::result
	{
		typedef typename vector_scalar_traits<E, T, scalar_mult>::result expression_type;
		return expression_type{ get_expression(e), t };
	}

	// operator *
	template <typename T, typename E,
		typename = std::enable_if_t<is_scalar<T>::value > >
	auto operator * (T t, vector_expression<E> const& e)
		-> typename vector_scalar_traits<E, T, scalar_div>::result
	{
		typedef typename vector_scalar_traits<E, T, scalar_div>::result expression_type;
		return expression_type{ get_expression(e), t };
	}

	// operator /
	template <typename E1, typename E2>
	auto operator / (vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> typename vector_binary_traits<E1, E2, scalar_div>::result
	{
		typedef typename vector_binary_traits<E1, E2, scalar_div>::result expression_type;
		return expression_type{ get_expression(e1), get_expression(e2) };
	}

	// operator /
	template <typename E, typename T,
		typename = std::enable_if_t<is_scalar<T>::value> >
	auto operator / (vector_expression<E> const& e, T t)
		-> typename vector_scalar_traits<E, T, scalar_div>::result
	{
		typedef typename vector_scalar_traits<E, T, scalar_div>::result expression_type;
		return expression_type{ get_expression(e), t };
	}

	// dot product leads to evaluation
	template <typename E1, typename E2>
	auto dot(vector_expression<E1> const& e1, vector_expression<E2> const& e2)
		-> decltype(reduce<scalar_mult, scalar_add>(e1, e2))
	{
		return reduce<scalar_mult, scalar_add>(e1, e2);
	}
} }