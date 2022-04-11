#ifndef MY_EXCEPTIONS_HPP
#define MY_EXCEPTIONS_HPP

#include <exception>

class IllegalBalanceException: public std::exception {
public:
   IllegalBalanceException() noexcept = default;
   ~IllegalBalanceException() = default;
   virtual const char* what() const noexcept {
      return "XT_INFO: Illegal Balance Exception";
   }
};

class InsufficentFundsException: public std::exception {
public:
   InsufficentFundsException() noexcept = default;
   ~InsufficentFundsException() = default;
   virtual const char* what() const noexcept {
      return "XT_INFO: Insufficent Funds Exception";
   }
};

#endif /* MY_EXCEPTIONS_HPP */
