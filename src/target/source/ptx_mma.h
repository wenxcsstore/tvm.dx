/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * \file ptx_mma.h
 * \brief MMA code generation with inlined PTX code.
 */
#ifndef TVM_TARGET_SOURCE_PTX_MMA_H_
#define TVM_TARGET_SOURCE_PTX_MMA_H_

#include <tvm/runtime/logging.h>

#include <string>
#include <tuple>

namespace tvm {
namespace codegen {

/*!
 * \brief Print MMA assembly string given parameters.
 * \param shape The shape string mMnNkK
 * \param A_layout The layout of multiplicand A, can be either "row" or "col".
 * \param B_layout The layout of multiplicand B, can be either "row" or "col".
 * \param A_dtype The data type of multiplicand A.
 * \param B_dtype The data type of multiplicand B.
 * \param C_dtype The data type of multiplicand C.
 * \param a_ref Pointer to buffer A.
 * \param a_offset The offset of element in A.
 * \param b_ref Pointer to buffer B.
 * \param b_offset The offset of element in B.
 * \param c_ref Pointer to buffer C.
 * \param c_offset The offset of element in C.
 * \param metadata Pointer to metadata buffer (only used for sparse mma).
 * \param metadata_offset The offset of element in metadata.
 * \param sparsity_selector The sparsity selector in sparse mma.
 * \param bit_op The bit operator used in 1-bit mma, can be either "xor" or "and".
 * \param sparse Whether it's sparse mma or not.
 * \param saturate Whether saturate output or not.
 */
std::string PrintMMAAssembly(const std::string& shape, const std::string& A_layout,
                             const std::string& B_layout, const std::string& A_dtype,
                             const std::string& B_dtype, const std::string& C_dtype,
                             const std::string& a_ref, const std::string& a_offset,
                             const std::string& b_ref, const std::string& b_offset,
                             const std::string& c_ref, const std::string& c_offset,
                             const std::string& metadata, const std::string& metadata_offset,
                             const std::string& sparsity_selector, const std::string& bit_op,
                             bool sparse, bool saturate);

}  // namespace codegen
}  // namespace tvm

#endif  // TVM_TARGET_SOURCE_PTX_MMA_H_
