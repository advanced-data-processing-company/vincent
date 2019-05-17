/**
 * @file    common_define.h
 * @author  tonghao.yuan (michael.19@163.com)
 * @brief   common define for vincent project of Advanced Data Processing Company(ADPC)
 *          many macros has ADPC prefix
 * @version 0.1
 * @date    2019-05-04
 *
 * @copyright Copyright (c) 2019
 *
 */

#pragma once

/**
 * @brief Unused mark, unused varable must be marked with this tag or will trigger an error
 * in compilling
 *
 */
#if (__cplusplus >= 201703L)  // since c++17
#    define ADPC_UNUSED [[maybe_unused]]
#elif (__GNUC__)
#    if (__cplusplus >= 201112L)  // since c++11
#        define ADPC_UNUSED [[gnu::unused]]
#    else
#        define ADPC_UNUSED __attribute__((unused))
#    endif
#else
#    define ADPC_UNUSED  // not defined
#endif

/**
 * @brief deprecated mark, unsed api should be marked by this for better documentation
 * if cpp compiler is c+=14 or newer, standard `deprecated` is used else gnu extension is used
 *
 */
#if (__cplusplus >= 201402L)  // since c++14
// clang-format off
#    define ADPC_DEPRECATED(msg) [[deprecated(#msg)]]
// clang-format on
#elif (__GNUC__)
#    define ADPC_DEPRECATED(msg) __attribute__((deprecated))
#else
#    define ADPC_DEPRECATED(msg)  // not defined
#endif

/**
 * @brief likey path
 *
 */
#if (__cplusplus > 201703L)  // since c++20
#    define ADPC_LIKELY(exp) [[likely]] exp
#elif (__GNUC__)
#    define ADPC_LIKELY(exp) __builtin_expect((exp), 1)
#else
#    define ADPC_LIKELY(exp)  // not defined
#endif

/**
 * @brief unlikey path
 *
 */
#if (__cplusplus > 201703L)  // since c++20
#    define ADPC_UNLIKELY(exp) [[unlikely]] exp
#elif (__GNUC__)
#    define ADPC_UNLIKELY(exp) __builtin_expect((exp), 0)
#else
#    define ADPC_UNLIKELY(exp)  // not defined
#endif

/**
 * @brief assertation
 *
 */
#ifndef NDEBUG
#    if (__GNUC__)
#        include <assert.h>
// clang-format off
#        define ADPC_ASSERT(condition, msg) assert(condition && msg)
// clang-format on
#    else
#        define ADPC_ASSERT(condition, msg)
#    endif
#endif
