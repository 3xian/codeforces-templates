const double EPS = 1E-8;
const double PI = acos(-1.0);
const double INF = std::numeric_limits<double>::max();
inline int sign(double x) { return x<-EPS ? -1 : x>EPS; }

class Point {
public:
    double x, y;
	Point(double x=0.0, double y=0.0) : x(x), y(y) { }
	bool operator <(const Point& rs) const { return x+EPS<rs.x || (x<rs.x+EPS && y+EPS<rs.y); }
	bool operator ==(const Point& rs) const { return sign(x-rs.x)==0 && sign(y-rs.y)==0; }
	Point operator +(const Point& rs) const { return Point(x+rs.x, y+rs.y); }
	Point operator -(const Point& rs) const { return Point(x-rs.x, y-rs.y); }
	Point operator *(double k) const { return Point(x*k, y*k); }
	double norm() const { return sqrt(square_norm()); }
	double square_norm() const { return x*x + y*y; }
	Point turn_left() const { return Point(-y, x); }
	Point turn_right() const { return Point(y, -x); }
	Point rotate(double arc) const { double c=cos(arc), s=sin(arc); return Point(x*c-y*s, x*s+y*c); }
};
typedef std::vector<Point> Points;
typedef std::pair<Point, Point> Line;
typedef std::pair<Point, Point> Segment;
double cross_prod(const Point& a, const Point& b) { return a.x*b.y - b.x*a.y; }
double cross_prod(const Point& a, const Point& b, const Point& o) {return cross_prod(a-o, b-o); }

namespace Triangle {
double area(const Point& p1, const Point& p2, const Point& p3) {
	return fabs(cross_prod(p1, p2, p3)) * 0.5;
}
}
