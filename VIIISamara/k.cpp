#include <bits/stdc++.h>
using namespace std;

class rational {
public:
	// constructors
	rational	();
	rational	(int);
	rational	(int, int);
	rational	(const rational &);

	// accessor functions
	int 	numerator	() const;
	int 	denominator	() const;

	// assignments
	void 	operator =  	(const rational &);
	void 	operator += 	(const rational &);
	void 	operator -= 	(const rational &);
	void 	operator *= 	(const rational &);
	void 	operator /= 	(const rational &);

	// comparison
	int 	compare		(const rational &) const;

	// conversions
	operator float	() const;

private:
	// data areas
	int 	top;
	int 	bottom;

	// operations used internally
	void 	normalize	();
};

//
//	function prototypes
//

rational operator + (const rational &, const rational &);
rational operator - (const rational &, const rational &);
rational operator * (const rational &, const rational &);
rational operator / (const rational &, const rational &);
rational operator - (const rational &);

// comparison operations
int operator == (const rational &, const rational &);
int operator != (const rational &, const rational &);
int operator < (const rational &, const rational &);
int operator <= (const rational &, const rational &);
int operator > (const rational &, const rational &);
int operator >= (const rational &, const rational &);

// input and output functions
ostream & operator << (ostream &, const rational &);
istream & operator >> (istream &, rational &);

int floor(const rational &);

unsigned int gcd(unsigned int, unsigned int);

//
//	inline functions
//

inline rational::rational() : top(0), bottom(1)
{
	// no further initialization required
}

inline rational::rational(int numerator) : top(numerator), bottom(1)
{
	// no further initialization required
}

inline rational::rational(const rational & value)
	: top(value.top), bottom(value.bottom)
{
	// no further initialization required
}

inline int rational::numerator() const
{
	// return numerator field of rational number
	return top;
}

inline int rational::denominator() const
{
	// return denominator field of rational number
	return bottom;
}

rational::rational(int numerator, int denominator)
	: top(numerator), bottom(denominator)
{
	// normalize the numerator and denominator values
	normalize();
}

//
//	normalization
//

void rational::normalize()
{	// normalize rational by:
	// a) move sign to numerator
	// b) make sure numerator and denominator have no common divisors
	int sign = 1;	// sign is 1 if positive, -1 if negative
	if (top < 0) {
		sign = -1;
		top = - top;
		}
	if (bottom < 0) {
		sign = - sign;
		bottom = - bottom;
		}

	// make sure we are not dividing by zero
	assert(bottom != 0);

	// find greatest common divisor
	int d = gcd(top, bottom);

	// move sign to top and divide by gcd
	top = sign * (top / d);
	bottom = bottom / d;
}

//
//	assignments
//

void rational::operator = (const rational & right)
{	// simply copy values from right hand side of assignment
	top = right.top;
	bottom = right.bottom;
}

void rational::operator += (const rational & right)
{	// modify by adding right hand side
	top = top * right.bottom + bottom * right.top;
	bottom *= right.bottom;

	// normalize the result, insuring lowest denominator form
	normalize();
}

void rational::operator -= (const rational & right)
{	// modify by subtracting right hand side
	top = top * right.bottom - bottom * right.top;
	bottom *= right.bottom;

	// normalize the result, insuring lowest denominator form
	normalize();
}

void rational::operator *= (const rational & right)
{	// modify by multiplying by right hand side
	top *= right.top;
	bottom *= right.bottom;

	// normalize the result, insuring lowest denominator form
	normalize();
}

void rational::operator /= (const rational & right)
{	// modify by dividing by right hand side
	// (same as multiplying by reciprocol)
	top *= right.bottom;
	bottom *= right.top;

	// normalize the result, insuring lowest denominator form
	normalize();
}

//
//	comparison
//

int rational::compare (const rational & right) const
{	// return negative if value is less than right
	// zero if value is equal to right
	// and positive if value is greater than right
	return numerator() * right.denominator() -
		right.numerator() * denominator();
}

int operator == (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) == 0);
}

int operator != (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) != 0);
}

int operator < (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) < 0);
}

int operator <= (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) <= 0);
}

int operator > (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) > 0);
}

int operator >= (const rational & r1, const rational & r2)
{
  return (r1.compare(r2) >= 0);
}



//
//	arithmetic operations
//

rational operator + (const rational & left, const rational & right)
{	// return addition of two rational numbers
	rational result(
		left.numerator() * right.denominator() +
		right.numerator() * left.denominator(),
			left.denominator() * right.denominator());
	return result;
}

rational operator - (const rational & left, const rational & right)
{	// return difference of two rational numbers
	rational result(
		left.numerator() * right.denominator() -
		right.numerator() * left.denominator(),
			left.denominator() * right.denominator());
	return result;
}

rational operator * (const rational & left, const rational & right)
{	// return product of two rational numbers
	rational result(
		left.numerator() * right.numerator(),
		left.denominator() * right.denominator());
	return result;
}

rational operator / (const rational & left, const rational & right)
{	// return quotent of two rational numbers
	rational result(
		left.numerator() * right.denominator(),
		left.denominator() * right.numerator());
	return result;
}

rational operator - (const rational & value)
{
	// return negation of a rational number
	rational result( - value.numerator(), value.denominator());
	return result;
}

//
//	converions
//

rational::operator float() const
{	// convert rational number into single-precision floating point
	return (float) top / (float) bottom;
}

//
//	misc functions
//

int floor(rational & value)
{	// return the smallest integer less than rationa number
	// integer division returns the floor automatically
	return value.numerator() / value.denominator();
}

ostream & operator << (ostream & out, const rational & value)
{	// stream output of rational number
	out << value.numerator() << " / " << value.denominator();
	return out;
}

istream & operator >> (istream & in, rational & r)
{	// stream input of rational number
	int t, b;

	// read the top
	in >> t;

	// if there is a slash, read the next number
	char c;
	in >> c;
	if (c == '/')
		in >> b;	// read bottom part
	else {
		in.putback(c);
		b = 1;
		}

	// do the assignment
	rational newValue(t, b);
	r = newValue;

	// return the stream
	return in;
}

// unsigned int gcd(unsigned int u, unsigned int v)
// {
//   // gcd of two non-negative numbers:  Euclid's algorithm.
//   do {
//     if (u < v) {
//       int temp = u;
//       u = v;
//       v = temp;
//     }
//     u = u - v;
//   } while (u);
//   return v;
// }

unsigned int gcd(unsigned int a, unsigned int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int inf = 1e9;
const int maxn = 1000005;

int n;
int x[maxn], y[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	rational lef = rational(-10000, 1);
	rational rig = rational(10000, 1);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i + 1 < n; i++) {
		int j = i + 1;
		int xi = x[i], yi = y[i];
		int xj = x[j], yj = y[j];
		double up = yj - yi;
		double down = xi - yi - xj + yj;
		if (down < 0) {
			rational frac = rational(up, down);
			if (frac < rig) rig = frac;
		}
		else if (down > 0) {
			rational frac = rational(up, down);
			if (lef < frac) lef = frac;
		}
	}

	if (lef <= rig && lef <= rational(1, 1) && rational(0, 1) <= rig) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
