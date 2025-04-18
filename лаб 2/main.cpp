#include <iostream>
using namespace std;

class vect {
public:
    int dim;
    double* d;
    static int count;
    int num;

    vect(int dim = 0) : dim(dim), num(++count) {
        d = new double[dim];
        for (int i = 0; i < dim; ++i) d[i] = 0; 
        cout << "Создан вектор" << num << endl;
    }

    ~vect() {
        delete[] d;
        cout << "Удалён вектор" << num << endl;
    }

    vect& operator=(const vect& v) {
        if (this != &v) {
            delete[] d;
            dim = v.dim;
            d = new double[dim];
            for (int i = 0; i < dim; ++i) {
                d[i] = v.d[i];
            }
            cout << "v=v" << endl;
        }
        return *this;
    }

    vect operator+(const vect& v) const {
        vect res(dim);
        for (int i = 0; i < dim; ++i) {
            res.d[i] = d[i] + v.d[i];
        }
        cout << "v+v" << endl;
        return res;
    }

    vect operator-(const vect& v) const {
        vect res(dim);
        for (int i = 0; i < dim; ++i) {
            res.d[i] = d[i] - v.d[i];
        }
        cout << "v-v" << endl;
        return res;
    }

    vect operator-() const {
        vect res(dim);
        for (int i = 0; i < dim; ++i) {
            res.d[i] = -d[i];
        }
        cout << "-v" << endl;
        return res;
    }

    vect operator*(double k) const {
        vect res(dim);
        for (int i = 0; i < dim; ++i) {
            res.d[i] = d[i] * k;
        }
        cout << "k*v" << endl;
        return res;
    }

    double operator*(const vect& v) const {
        double res = 0;
        for (int i = 0; i < dim; ++i) {
            res += d[i] * v.d[i];
        }
        cout << "v*v" << endl;
        return res;
    }
};
int vect::count = 0;

class matr {
public:
    int dim;
    double* a;
    static int count;
    int num;

    matr(int dim = 0) : dim(dim), num(++count) {
        a = new double[dim * dim];
        for (int i = 0; i < dim * dim; ++i) a[i] = 0; 
        cout << "Создана матрица" << num << endl;
    }

    ~matr() {
        delete[] a;
        cout << "Удалена матрица" << num << endl;
    }

    matr& operator=(const matr& m) {
        if (this != &m) {
            delete[] a;
            dim = m.dim;
            a = new double[dim * dim];
            for (int i = 0; i < dim * dim; ++i) {
                a[i] = m.a[i];
            }
            cout << "m=m" << endl;
        }
        return *this;
    }

    matr operator+(const matr& m) const {
        matr res(dim);
        for (int i = 0; i < dim * dim; ++i) {
            res.a[i] = a[i] + m.a[i];
        }
        cout << "m+m" << endl;
        return res;
    }

    matr operator-(const matr& m) const {
        matr res(dim);
        for (int i = 0; i < dim * dim; ++i) {
            res.a[i] = a[i] - m.a[i];
        }
        cout << "m-m" << endl;
        return res;
    }

    matr operator-() const {
        matr res(dim);
        for (int i = 0; i < dim * dim; ++i) {
            res.a[i] = -a[i];
        }
        cout << "-m" << endl;
        return res;
    }

    matr operator*(double k) const {
        matr res(dim);
        for (int i = 0; i < dim * dim; ++i) {
            res.a[i] = a[i] * k;
        }
        cout << "k*m" << endl;
        return res;
    }

    matr operator*(const matr& m) const {
        matr res(dim);
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                res.a[i * dim + j] = 0;
                for (int k = 0; k < dim; ++k) {
                    res.a[i * dim + j] += a[i * dim + k] * m.a[k * dim + j];
                }
            }
        }
        cout << "m*m" << endl;
        return res;
    }

    vect operator*(const vect& v) const {
        vect res(dim);
        for (int i = 0; i < dim; ++i) {
            res.d[i] = 0;
            for (int j = 0; j < dim; ++j) {
                res.d[i] += a[i * dim + j] * v.d[j];
            }
        }
        cout << "m*v" << endl;
        return res;
    }
};
int matr::count = 0;

int main() {
    vect v1(3), v2(3); 
    matr m1(3), m2(3); 

    vect v3 = v1 + v2; 
    vect v4 = v1 - v2; 
    vect v5 = -v1;     
    double dot = v1 * v2; 

    matr m3 = m1 + m2; 
    matr m4 = m1 - m2;
    matr m5 = -m1;     
    matr m7 = m1 * m2; 
    m1 = m2;           
    vect v7 = m1 * v1; 

    return 0;
}
