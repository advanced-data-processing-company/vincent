/**
 * @brief Advanced Data Processing Company Template Library(ADPCTL)
 * 
 * adpctl is a template library designed for purpose use
 * 
 */

#pragma once

/**
 * Singleton template
 *
 * If you want to make your class a template, you can decalre your
 * default constructor to be `private`, and decalre `Singleton<T>` as frinend.
 *
 * example:
 * @code{.cpp}
 *
 * #include "adpctl/singleton.h"
 *
 * class singleton_example{
 *
 * friend class adpctl::Singleton<singleton_example>
 *
 * private:
 *  singleton_example(){// do something};
 * };
 *
 *
 * Singleton<singleton_example>::GetInstance
 *
 * @endcode
 *
 */

namespace adpctl {

template <typename T>
class Singleton{
    using Type = T;

   public:
    static Type& GetInstance(){
        static Type instance;
        return instance;
    }
};

}// namespace adpctl
