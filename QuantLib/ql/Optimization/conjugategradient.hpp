/*
 Copyright (C) 2001, 2002 Nicolas Di C�sar�

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
/*! \file conjugategradient.hpp
    \brief Conjugate gradient optimization method

    \fullpath
    ql/Optimization/%conjugategradient.hpp
*/

#ifndef quantlib_optimization_conjugate_gradient_h
#define quantlib_optimization_conjugate_gradient_h

#include "ql/Optimization/armijo.hpp"

namespace QuantLib {

    namespace Optimization {

        //! Multi-dimensionnal Conjugate Gradient class
        /*! User has to provide line-search method and
            optimization end criteria

            search direction \f$ d_i = - f'(x_i) + c_i*d_{i-1} \f$
            where \f$ c_i = ||f'(x_i)||^2/||f'(x_{i-1})||^2 \f$
            and \f$ d_1 = - f'(x_1) \f$
        */
        class ConjugateGradient: public Method {
          public:
            //! default constructor
            ConjugateGradient() : Method(),
              lineSearch_(Handle<LineSearch>(new ArmijoLineSearch())) {}

            ConjugateGradient(const Handle<LineSearch>& lineSearch)
            : Method(), lineSearch_ (lineSearch) {}

            //! destructor
            virtual ~ConjugateGradient() {}

            //! minimize the optimization problem P
            virtual void minimize(Problem& P);
          private:
            //! line search
            Handle<LineSearch> lineSearch_;
        };

    }

}


#endif
