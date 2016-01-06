#ifndef __vec3__h
#define __vec3__h

template <typename T>
class vec3 {
public:
	T x, y, z;

	vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	vec3(T i) : x(i), y(i), z(i) {}
	vec3(T xi, T yi, T zi) : x(xi), y(yi), z(zi) {}

	T dot(vec3 const& rhs) const { return x*rhs.x + y*rhs.y + z*rhs.z; }
	vec3<T> operator +(vec3<T> const& rhs) const { return vec3<T>(x + rhs.x, y + rhs.y, z + rhs.z); }
	vec3<T> operator -(vec3<T> const& rhs) const { return vec3<T>(x - rhs.x, y - rhs.y, z - rhs.z); }
	vec3<T> operator *(vec3<T> const& rhs) const { return vec3<T>(x * rhs.x, y * rhs.y, z * rhs.z); }
	vec3<T> operator *(T const& rhs) const { return vec3<T>(x * rhs, y * rhs, z * rhs); }
	vec3<T> operator -() const { return vec3<T>(-x, -y, -z); }
	vec3<T>& operator +=(vec3<T> const& rhs) { x += rhs.x, y += rhs.y, z += rhs.z; return *this; }
	vec3<T>& operator *=(vec3<T> const& rhs) { x *= rhs.x, y *= rhs.y, z *= rhs.z; return *this; }
	vec3<T>& operator -=(vec3<T> const& rhs) { x -= rhs.x, y -= rhs.y, z -= rhs.z; return *this; }

	T length() { return sqrt(x * x + y * y + z * z); }
	vec3<T>& normalize() {
		if (length > 0) {
			x = x / length;
			y = y / length;
			z = z / length;
		}
		return *this;
	}
};

typedef vec3<float> vec3f;

#endif