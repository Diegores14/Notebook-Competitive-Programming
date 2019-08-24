typedef double T;
struct cpx {
    T real, image;
    cpx( T real, T image ): real(real), image(image) {}
    cpx( T real ): real(real), image(0) {}
    cpx() { real = 0; image = 0; }
};

cpx operator +( const cpx &c1, const cpx &c2) {
    return cpx(c1.real + c2.real, c1.image + c2.image );
}
cpx operator -( const cpx &c1, const cpx &c2) {
    return cpx(c1.real - c2.real, c1.image - c2.image );
}
cpx operator *( const cpx &c1, const cpx &c2) {
    return cpx(c1.real*c2.real - c1.image*c2.image, c1.image*c2.real + c1.real*c2.image);
}
const double PI = acos(-1);

void fft( vector<cpx> & a, bool invert ) {
    int n = a.size();
    for( int i = 1, j = 0; i < n; i++ ) {
        int bit = (n>>1);
        for(; j & bit; bit >>= 1 ) 
            j ^= bit;
        j ^= bit;
        if ( i < j ) 
            swap( a[i], a[j] );
    }
    for( int len = 2; len <= n; len <<= 1 ) {
        double ang = 2*PI / len * (invert? -1 : 1 );
        cpx wlen(cos(ang), sin(ang));
        for( int i = 0; i < n; i += len ) {
            cpx w(1);
            for( int j = 0; j < len/2; j++ ) {
                cpx u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w*wlen;
            }
        }
    }
    if( invert ) {
        for( cpx &x : a ) {
            x.real /= n;
            x.image /= n;
        }
    }
}