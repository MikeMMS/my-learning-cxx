#include "../exercise.h"

template <uintmax_t n> struct fib
{
    enum : uintmax_t
    {
        result = fib<n - 1>::result + fib<n - 2>::result
    };
};
template <> struct fib<0>
{
    enum : uintmax_t
    {
        result = 0
    };
};
template <> struct fib<1>
{
    enum : uintmax_t
    {
        result = 1
    };
};

// constexpr uintmax_t fibonacci(int i) {

//     return fib<i>::result;
// }

int main(int argc, char **argv)
{
    constexpr auto FIB20 = fib<20>::result;
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    constexpr auto ANS_N = 94;
    constexpr auto ANS = fib<ANS_N>::result;
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
