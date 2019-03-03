#pragma once
#define GLEW_STATIC // This must be defined when statically linking to GLEW

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

class Object
{
public:
	Object(float posX = 0.0f, float posY = 0.0f, float width = 32.0f, float height = 32.0f);
	void Transformation(float X, float Y, float Angle);
	float GetModelWidth() { return width; }
	float GetModelHeigth() { return height; }
	float GetModelPosX() { return posX + lastX; }
	float GetModelPosY() { return posY + lastY; }
	const float * GetModelPtr();
	~Object();
	
private:
	float width, height;
	float posX, posY;
	const float Radians = 3.14159265f / 180.0f;
	bool modification;
	float lastX, lastY;
	float lastAngle;
	glm::mat4 model, lastModel;
	const float * lastModelPtr = glm::value_ptr(lastModel);
	const float * modelPtr = glm::value_ptr(model);
};

/*																										// Object Name / ID...
		model = glm::mat4(1.0f);																				// <-- Object
		model = glm::translate(model, glm::vec3(200.0f + x, 568.0f + y, 0.0f));									// <-- Object
		model = glm::rotate(model, 0 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));									// <-- Object
		model = glm::scale(model, glm::vec3(32.0f, 32.0f, 0.0f));												// <-- Object
																												// <-- Object
		glUniformMatrix4fv(ShaderList[0]->GetModelLocation() , 1, GL_FALSE, glm::value_ptr(model));				// <-- Object
		glUniformMatrix4fv(ShaderList[0]->GetProjectionLocation(), 1, GL_FALSE, glm::value_ptr(projection));    // <-- Object*/