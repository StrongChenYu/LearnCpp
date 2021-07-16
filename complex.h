//
// Created by 86130 on 2021/7/16.
//

#ifndef C__CODE_COMPLEX_H
#define C__CODE_COMPLEX_H


class complex {
public:
    complex (double r = 0, double i = 0)
    : re(r), im(i) {}

    complex& operator += (const complex&);
    double real() const { return re;}
    double imag() const { return im;}

private:
    double re, im;
    friend complex& __doapl (complex*, const complex&);
    friend double real(const complex & ths);
    friend double imag(const complex & ths);
};

inline
double real(const complex & ths) { return ths.re; }

inline
double imag(const complex & ths) { return ths.im; }

inline
complex &__doapl(complex * ths, const complex &r) {
    ths->im += r.im;
    ths->re += r.re;
    return *ths;
}

inline
complex & complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

inline
complex operator + (const complex& x, const complex& y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

std::ostream & operator << (std::ostream& os, const complex& x) {
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

#endif //C__CODE_COMPLEX_H
