#pragma once
#include <list>
#include <vector>
template <class T>

class Rect
{
public:
	Rect() {}
	Rect(T x, T y, T width, T height)
		:
		x(x),
		y(y),
		width(width),
		height(height)
	{}
	Rect(const Rect& rect)
		:
		x(rect.x),
		y(rect.y),
		width(rect.width),
		height(rect.height)
	{}
	void translate(float x, float y)
	{
		this->x += x;
		this->y += y;
	}
	void clip(Rect rect)
	{
		T right = x + width;
		T bottom = y + height;

		T rightR = rect.x + rect.width;
		T bottomR = rect.y + rect.height;

		y = max(y, rect.y);
		x = max(x, rect.x);

		right = min(right, rightR);
		bottom = min(bottom, bottomR);

		width = right - x;
		height = bottom - y;
		/*if(width <= (T)0 || height <= (T)0 )
		{
			x = y = height = width = (T)0;
		}*/
	}
	template < class T2 >



	operator const Rect< T2 >()
	{
		return Rect< T2 >((T2)x, (T2)y, (T2)width, (T2)height);
	}
	bool operator == (const Rect< T > rect)
	{
		return (x == rect.x &&
			y == rect.y &&
			width == rect.width &&
			height == rect.height);
	}

public:
	T x;
	T y;
	T width; //  actually dont need width and height is on the Texture
	T height; // 

};
typedef Rect< float > RectF;
typedef std::list< Rect<float> > RectFList;
typedef Rect < int > RectI;

