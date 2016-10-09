#ifndef DEF_CAMERA
#define DEF_CAMERA

#include "Input.h"
#include "glm.hpp"
#include "gtc\type_ptr.hpp"
#include "gtx\transform.hpp"

class Camera
{
public:
	Camera();
	Camera(glm::vec3 position, glm::vec3 targetPoint, glm::vec3 verticalAxe);
	void orientation(int xRel, int yRel);
	void move(Input* const &input);
	void lookAt(glm::mat4 &modelview);
	void setTargetPoint(glm::vec3 targetPoint);
	void setPosition(glm::vec3 position);
	~Camera();
private:
	float m_phi;
	float m_theta;
	glm::vec3 m_orientation;
	glm::vec3 m_verticalAxe;
	glm::vec3 m_lateralMove;
	glm::vec3 m_position;
	glm::vec3 m_targetPoint;
	float moveSpeed = 0.5f;
	float mouseSpeed = 0.2f;
};
#endif