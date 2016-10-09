#include "Camera.h"


Camera::Camera() : m_phi(0), m_theta(0), m_orientation(), m_verticalAxe(0, 0, 1), m_lateralMove(), m_position(), m_targetPoint()
{
}

Camera::Camera(glm::vec3 position, glm::vec3 targetPoint, glm::vec3 verticalAxe) : m_phi(0), m_theta(0), m_orientation(), m_lateralMove(), m_position(position), m_targetPoint(targetPoint), m_verticalAxe(verticalAxe)
{
	setTargetPoint(targetPoint);
}

void Camera::orientation(int xRel, int yRel)
{
	// On ajout l'angle (en négatif car dans le sens anti horaire)
	m_phi += -yRel * mouseSpeed;
	m_theta += -xRel * mouseSpeed;
	
	// Si Phi dépasse ou est en dessous de 89.0/-89.0, l'axe Y devient parralèle, c'est pas bon
	if (m_phi > 89.0)
		m_phi = 89.0;
	else if (m_phi < -89.0)
		m_phi = -89.0;

	float phiRadian = float(m_phi * M_PI / 180);
	float thetaRadian = float(m_theta * M_PI / 180);

	if (m_verticalAxe.x == 1.0)
	{
		m_orientation.x = sin(phiRadian);
		m_orientation.y = cos(phiRadian) * cos(thetaRadian);
		m_orientation.z = cos(phiRadian) * sin(thetaRadian);
	}

	else if (m_verticalAxe.y == 1.0)
	{
		m_orientation.x = cos(phiRadian) * sin(thetaRadian);
		m_orientation.y = sin(phiRadian);
		m_orientation.z = cos(phiRadian) * cos(thetaRadian);
	}
	else
	{
		m_orientation.x = cos(phiRadian) * cos(thetaRadian);
		m_orientation.y = cos(phiRadian) * sin(thetaRadian);
		m_orientation.z = sin(phiRadian);
	}

	m_lateralMove = cross(m_verticalAxe, m_orientation);
	m_lateralMove = normalize(m_lateralMove);

	m_targetPoint = m_position + m_orientation;
}

void Camera::move(Input* const &input)
{
	if (input->movedMouse())
	{
		orientation(input->getXRel(), input->getYRel());
	}

	if (input->getKey(SDL_SCANCODE_UP))
	{
		m_position = m_position + m_orientation * moveSpeed;
		m_targetPoint = m_position + m_orientation;
	}

	if (input->getKey(SDL_SCANCODE_DOWN))
	{
		m_position = m_position - m_orientation * moveSpeed;
		m_targetPoint = m_position + m_orientation;
	}

	if (input->getKey(SDL_SCANCODE_LEFT))
	{
		m_position = m_position + m_lateralMove * moveSpeed;
		m_targetPoint = m_position + m_orientation;
	}

	if (input->getKey(SDL_SCANCODE_RIGHT))
	{
		m_position = m_position - m_lateralMove * moveSpeed;
		m_targetPoint = m_position + m_orientation;
	}
}

void Camera::lookAt(glm::mat4 &modelview)
{
	modelview = glm::lookAt(m_position, m_targetPoint, m_verticalAxe);
}

void Camera::setTargetPoint(glm::vec3 targetPoint)
{
	m_orientation = m_targetPoint - m_position;
	m_orientation = normalize(m_orientation);

	if (m_verticalAxe.x == 1.0)
	{
		m_phi = asin(m_orientation.x);
		m_theta = acos(m_orientation.y / cos(m_phi));
		if (m_orientation.y < 0)
			m_theta *= -1;
	}
	else if (m_verticalAxe.y == 1.0) {
		m_phi = asin(m_orientation.y);
		m_theta = acos(m_orientation.z / cos(m_phi));
		if (m_orientation.z < 0)
			m_theta *= -1;
	} else {
		m_phi = asin(m_orientation.x);
		m_theta = acos(m_orientation.z / cos(m_phi));
		if (m_orientation.z < 0)
			m_theta *= -1;
	}

	m_phi = float(m_phi * 180 / M_PI);
	m_theta = float(m_theta * 180 / M_PI);
}

void Camera::setPosition(glm::vec3 position)
{
	m_position = position;

	m_targetPoint = m_position + m_orientation;
}

Camera::~Camera()
{
}
