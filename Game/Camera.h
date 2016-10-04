#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Input.h"
#include "glm.hpp"
#include "gtc\type_ptr.hpp"
#include "gtx\transform.hpp"
using namespace glm;

class Camera
{
public:
	Camera();
	Camera(vec3 position, vec3 targetPoint, vec3 verticalAxe);
	void orientation(int xRel, int yRel);
	void move(Input* const &input);
	void lookAt(mat4 &modelview);
	void setTargetPoint(vec3 targetPoint);
	void setPosition(vec3 position);
	~Camera();
private:
	float m_phi;
	float m_theta;
	vec3 m_orientation;
	vec3 m_verticalAxe;
	vec3 m_lateralMove;
	vec3 m_position;
	vec3 m_targetPoint;
	float moveSpeed = 0.5f;
	float mouseSpeed = 0.2f;
};
#endif