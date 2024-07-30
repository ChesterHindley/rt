#include "Camera.h"

Ray Camera::getRay(float u, float v) const {
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
