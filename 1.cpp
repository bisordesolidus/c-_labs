template<long long a, unsigned long long n>
struct Pow
{
    static const long long value = a*Pow<a, n - 1>::value;
};

template<long long a>
struct Pow<a, 0>
{
    static const long long value = 1;
};

int main(){
    std::cout << Pow<3, 3>::value;
}
