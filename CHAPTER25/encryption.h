#include <type_traits>

//  type alias to replace long with int (which is 4 bytes, as needed by the algorhitm)
template<typename T>
using replace_long_with_int = typename std::conditional<
    std::is_same<T,long>::value,
    int,
    T
>::type;

#define long int

void encipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{
    static_assert(sizeof(long)==4,"size of long wrong for TEA");

    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0;
    unsigned long delta = 0x9E3779B9;
    
    for(unsigned long n = 32; n-->0;) {
        y += (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
        sum += delta;
        z += (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
    }
    w[0]=y; 
    w[1]=z;
}

void decipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{ 
    static_assert(sizeof(long)==4,"size of long wrong for TEA");

    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xC6EF3720;
    unsigned long delta = 0x9E3779B9;
    // sum = delta<<5, in general sum = delta * n
    for(unsigned long n = 32; n-->0;) {
        z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
        sum -= delta;
        y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
    }
    w[0]=y; 
    w[1]=z;
}

#undef long