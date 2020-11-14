//Геометрия из лекций Mike Mirzayanov muscat bootcamp 2019
typedef long double dbl;
const dbl EPS = 1E-9;
dbl a = asin(min(max(sina, -1.0L), 1.0L)); // crop to [-1, 1] значение арксинуса
dbl root = sqrtl(max(x, 0.0L)); // square root

inline int cmp(dbl a, dbl b) { return a + EPS < b ? -1
    : b + EPS < a ? +1 : 0;
}
inline bool zero(dbl x) { return cmp(x, 0) == 0;
}

struct pt { dbl X, Y; };

inline bool operator <(const pt& a, const pt& b) {
    return cmp(a.X, b.X)<0 || (cmp(a.X, b.X) == 0 && cmp(a.Y,b.Y)<0);
}
inline bool operator ==(const pt& a, const pt& b) {
    return !(a < b) && !(b < a);
}

len2(p) {return p.X * p.X + p.Y * p.Y;} // square length
len(p) {return sqrtl(p.X * p.X + p.Y * p.Y);} // length (avoid hypot)
norm(p) {lenp = len(p); return {p.X/lenp, p.Y/lenp} }; // Normalize (scale to of length 1):
rotate(p, a) { return {cos(a)*p.X-sin(a)*p.Y,
    sin(a)*p.X+cos(a)*p.Y};} // rotate(p, a):

p·q=dot(p,q)=p.X*q.X + p.Y*q.Y=cos(pq)*|p|*|q| // dot product

p⨯q=cross(p,q)=p.X*q.Y-p.Y*q.X=sin(pq)*|p|*|q| // cross product
cross(p,q)=det(p.X,p.Y,q.X,q.Y) // cross product
    
Angles
● Good idea to operate only with normalized angles, say, in [-PI, PI) or [0, 2PI). Code: norm(&a) {while (a<-PI) a+=2*PI; while (a>=PI) a-=2*PI;}
● Use atan2(y,x) to return polar angle (point (x,y) is not an origin!)
● Rotate point p over a: {cos(a)*p.X-sin(a)*p.Y, sin(a)*p.X+cos(a)*p.Y}
● To find unoriented angle: acos(dot(p,q)/|p|/|q|)
● To find oriented angle from p to q: atan2(cross(p, q), dot(p, q))
                                                                          

Vector normalization: transform vectors to be equal if and only if they have the same direction:
● for floating point calculations: divide vector by its length
● for integer calculations: find d=gcd(|p.X|,|p.Y|), divide both coordinates by d
                                                                          
                                                                          

                                                                          
                                                                          


