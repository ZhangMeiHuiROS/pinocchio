//
// Copyright (c) 2017-2018 CNRS
//

#ifndef __pinocchio_eigen_macros_hpp__
#define __pinocchio_eigen_macros_hpp__

#include "pinocchio/utils/eigen-fix.hpp"

/// \brief Macro giving access to the equivalent plain type of D
#define EIGEN_PLAIN_TYPE(D) Eigen::internal::plain_matrix_type< typename pinocchio::helper::argument_type<void(D)>::type >::type

/// \brief Similar to macro EIGEN_PLAIN_TYPE but with guaranty to provite a column major type
#define EIGEN_PLAIN_COLUMN_MAJOR_TYPE(D) pinocchio::helper::handle_return_type_without_typename<D,Eigen::internal::plain_matrix_type_column_major>::type

/// \brief Similar to macro EIGEN_PLAIN_TYPE but with guaranty to provite a row major type
#define EIGEN_PLAIN_ROW_MAJOR_TYPE(D) pinocchio::helper::handle_return_type_without_typename<D,Eigen::internal::fix::plain_matrix_type_row_major>::type

/// \brief Macro giving access to the reference type of D
#define EIGEN_REF_CONSTTYPE(D) Eigen::internal::ref_selector<D>::type
#if EIGEN_VERSION_AT_LEAST(3,2,90)
#define EIGEN_REF_TYPE(D) Eigen::internal::ref_selector<D>::non_const_type
#else
#define EIGEN_REF_TYPE(D) \
Eigen::internal::conditional< \
bool(Eigen::internal::traits<D>::Flags & Eigen::NestByRefBit), \
D &, \
D \
>::type
#endif

/// \brief Macro giving access to the return type of the dot product operation
#if EIGEN_VERSION_AT_LEAST(3,3,0)
#define EIGEN_DOT_PRODUCT_RETURN_TYPE(D1,D2) \
Eigen::ScalarBinaryOpTraits< typename Eigen::internal::traits< D1 >::Scalar, typename Eigen::internal::traits< D2 >::Scalar >::ReturnType
#else
#define EIGEN_DOT_PRODUCT_RETURN_TYPE(D1,D2) \
Eigen::internal::scalar_product_traits<typename Eigen::internal::traits< D1 >::Scalar,typename Eigen::internal::traits< D2 >::Scalar>::ReturnType
#endif

/// \brief Macro for an automatic const_cast
#define EIGEN_CONST_CAST(TYPE,OBJ) const_cast<TYPE &>(OBJ.derived())

#endif // ifndef __pinocchio_eigen_macros_hpp__