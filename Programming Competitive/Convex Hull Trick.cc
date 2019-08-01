typedef long long ctype;

struct line {
    ctype m, b;
    line(ctype m, ctype b): m(m), b(b) {}
    line(): b(0), m(0) {}
};
 
struct convexHull {
    line sk[tam];
    int size, ptr;
    convexHull() {
        size = ptr = 0;
    }
    // b1 + m1x1 = b2 + m2x1 => (b1 - b2)/(m2 - m1) = x1
    // b1 + m1x2 = b3 + m3x2 => (b1 - b3)/(m3 - m1) = x2
    // if x2 < x1
    bool check(line l1, line l2, line l3) {
        return (long double)(l1.b - l3.b)/(l3.m - l1.m) < (long double)(l1.b - l2.b)/(l2.m - l1.m);
    }
 
    void add(line x) {
        while( size >= 2 && check(sk[size-2], sk[size-1], x) ) {
            size--;
        }
        sk[size++] = x;
    }
 
    ctype query(int x) {
        ptr = min(ptr, size-1);
        while(ptr + 1 < size && sk[ptr+1].b + x*sk[ptr+1].m < sk[ptr].b + x*sk[ptr].m) {
            ptr++;
        }
        return sk[ptr].b + x*sk[ptr].m;
    }
};