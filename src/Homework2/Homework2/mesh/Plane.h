#pragma once
// 平面类Plane

#include "../Object.h"

class Plane : public Object
{
public:
	Vec3 C, N;	// 平面中心、法向量
	Vec3 texU, texV;	// 纹理坐标
	const static Vec3 DEFAULT_TEXU;
	const static Vec3 DEFAULT_TEXV;

public:
	Plane(const Vec3 &C_, const Vec3 &N_, const std::string &name_ = "")
		: Object(name_), C(C_), N(N_) {
			texU = DEFAULT_TEXU;
			texV = DEFAULT_TEXV;
		}
	virtual Intersection intersect(const Vec3 &ori, const Vec3 &dir, double &maxDist,
				/*output*/ Vec3 *P = NULL, Vec3 *N_ = NULL, Color *objectColor = NULL) const;
	Color texColor(const Vec3 &P) const;
};