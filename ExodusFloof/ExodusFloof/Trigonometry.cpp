#include "Trigonometry.h"
#include <cmath>

const double Trigonometry::pi = 3.14159265;

Trigonometry::Trigonometry()
{
	Setup();
}


void Trigonometry::Setup()
{
	for (int i = 0; i < 360; i++)
	{
		sin[i] = std::sin(RadiansFromDegrees(i));
		cos[i] = std::cos(RadiansFromDegrees(i));
	}

}

int Trigonometry::DegreesInRange(int degrees) const
{
	while (degrees < 0)
		degrees += 360;

	return degrees % 360;
}

double Trigonometry::RadiansFromDegrees(int degrees) const
{
	return (degrees * (Pi() / 180));
}

double Trigonometry::Pi() const
{
	return pi;
}

double Trigonometry::Sin(int degrees) const
{
	return sin[DegreesInRange(degrees)];
}

double Trigonometry::Cos(int degrees) const
{
	return cos[DegreesInRange(degrees)];
}

int Trigonometry::ArcTan2(double x, double y) const
{
	return DegreesFromRadians(std::atan2(x, y));
}
 
int Trigonometry::ArcTan(double x) const
{
	return DegreesFromRadians(std::atan(x));
}

int Trigonometry::DegreesFromRadians(double radians) const
{
	return (radians * 180 / Pi());
}

double Trigonometry::DistanceBetween(double x1, double y1, double x2, double y2) const
{
	return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}