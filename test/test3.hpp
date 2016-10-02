//
//  Copyright (c) 2000-2002
//  Joerg Walter, Mathias Koch
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//  The authors gratefully acknowledge the support of
//  GeNeSys mbH & Co. KG in producing this work.
//

#ifndef TEST3_H
#define TEST3_H

#ifdef _MSC_VER
# include <stdio.h>
# include <stdlib.h>
# include <crtdbg.h>

inline void myInvalidParameterHandler(const wchar_t* expression, const wchar_t* function, const wchar_t* file, unsigned int line, uintptr_t) {
   wprintf(L"\nInvalid parameter detected in function %s. File: %s Line: %d\nExpression: %s\n", function, file, line, expression);
   abort();
}

# define BOOST_UBLAS_NO_ERROR_POPUP \
  _set_invalid_parameter_handler(myInvalidParameterHandler); \
  _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE); \
  _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT); \
  _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE); \
  _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
#else
# define BOOST_UBLAS_NO_ERROR_POPUP
#endif

#include <iostream>

#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/vector_sparse.hpp>
#ifdef USE_GENERALIZED_VECTOR_OF_VECTOR
#include <boost/numeric/ublas/vector_of_vector.hpp>
#endif
#include <boost/numeric/ublas/io.hpp>

namespace ublas = boost::numeric::ublas;

#include "common/init.hpp"

void test_vector ();
void test_matrix_vector ();
void test_matrix ();

#endif
