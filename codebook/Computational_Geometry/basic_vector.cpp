template<typename T>
struct point{
    T x,y;
    point(){}
    point(const T&x,const T&y):x(x),y(y){}
    point operator+(const point &b)const{
        return point(x+b.x,y+b.y);
    }
    point operator-(const point &b)const{
        return point(x-b.x,y-b.y);
    }
    point operator*(const T &b)const{
        return point(x*b,y*b);
    }
    point operator/(const T &b)const{
        return point(x/b,y/b);
    }
    bool operator==(const point &b)const{
        return x==b.x&&y==b.y;
    }
    T dot(const point &b)const{
        return x*b.x+y*b.y;
    }
    T cross(const point &b)const{
        return x*b.y-y*b.x;
    }
    T abs2()const{//向量長度的平方
        return dot(*this);
    }
};