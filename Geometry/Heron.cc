long double heron(long long a, long long b, long long c) {
    long double p = (long double)(a+b+c)/2;
    return sqrt( p*(p-a)*(p-b)*(p-c) );
}