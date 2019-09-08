#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <type_traits>
#include <string>
#include <vector>

typedef unsigned char uchar;
typedef unsigned int uint;

template<class T>
struct Vec2
{
	static_assert(std::is_arithmetic<T>::value, "Only arithmetic values supported");

	T x;
	T y;

	Vec2()
		:x(0), y(0)
	{}
	Vec2(T xv, T yv)
		:x(xv), y(yv)
	{}
	Vec2(T all)
		:x(all), y(all)
	{}

	uint Count() { return 2; }
	T * Members() { return { this->x, this->y }; }
};

template<class T>
struct Vec3 : public Vec2<T>
{
	Vec3()
		:Vec2<T>(), z(0)
	{ 
		
	}
	Vec3(T xv, T yv, T zv)
		:Vec2<T>(xv, yv), z(zv)
	{}
	Vec3(T all)
		:Vec2<T>(all), z(all)
	{}

	uint Count() { return 3; }
	T * Members() { return { this->x, this->y, this->z }; }

	T z;
};