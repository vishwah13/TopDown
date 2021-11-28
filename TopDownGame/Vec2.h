#pragma once

template <typename T>

class Vec2 {

public:
	T x;
	T y;
	Vec2() = default;
	Vec2(T x,T y)
		:
		x(x),
		y(y)
	{}
	T GetX() const { return x };
	T GetY() const { return y };
	void SetX(T x_in) { x = x_in };
	void SetY(T y_in) { y = y_in };

public:
	bool operator==(const Vec2& rhs) {
		return( x == rhs.x && y == rhs.y );
	}
	bool operator!=(const Vec2& rhs) {
		return !(*this == rhs);
	}
	Vec2 operator+(const Vec2& rhs) {
		return{ x + rhs.x,y + rhs.y };
	}
	Vec2& operator+=(const Vec2& rhs) {
		return *this = *this + rhs;
	}
	Vec2 operator-(const Vec2& rhs) {
		return{ x - rhs.x,y - rhs.y };
	}
	Vec2 operator*(const Vec2& rhs) {
		return{ x * rhs.x,y * rhs.y };
	}

private:
	

};
