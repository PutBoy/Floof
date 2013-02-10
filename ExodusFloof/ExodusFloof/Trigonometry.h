#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

class Trigonometry
{
public:
	Trigonometry();

	double Sin(int degrees) const;
	double Cos(int degrees) const;

	int ArcTan2(double a, double b) const;
	int ArcTan(double x) const;

	double Pi() const;

	double DistanceBetween(double x1, double y1, double x2, double y2) const;
private:
	void Setup();

	double sin[360];
	double cos[360];

	int DegreesInRange(int degrees) const;

	double RadiansFromDegrees(int degrees) const;
	int DegreesFromRadians(double radians) const;
	const static double pi;
};

#endif