#include "Object.h"

Object::Object(float posX, float posY, float width, float height)
{
	this->width = width;
	this->height = height;
	this->posX = posX;
	this->posY = posY;
	lastModel = glm::mat4(1.0f);
	modification = true;

	model = glm::translate(glm::mat4(1.0f), glm::vec3(this->posX, this->posY, 0.0f));
	model = glm::rotate(model, 0.0f * Radians, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(this->width, this->height, 0.0f));
	lastModel = model;
}

void Object::Transformation(float X = 0.0f, float Y = 0.0f, float Angle = 0.0f)
{
	if ((X != 0.0f || Y != 0.0f || Angle != 0.0f)
		&&( X != lastX || Y != lastY || Angle != lastAngle))
	{
		model = glm::translate(glm::mat4(1.0f), glm::vec3(posX + X, posY + Y, 0.0f));
		if(Angle != 0.0f)
			model = glm::rotate(model, Angle * Radians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(width, height, 0.0f));
		lastModel = model;
		lastX = X;
		lastY = Y;
		lastAngle = Angle;
		modification = true;
	}
	else
		modification = false;
}

const float * Object::GetModelPtr()
{
	if (modification)
		return modelPtr;
	else
		return lastModelPtr;
}

Object::~Object()
{
}


/*																										// Object Name / ID...
model = glm::mat4(1.0f);																				// <-- Object
model = glm::translate(model, glm::vec3(200.0f + x, 568.0f + y, 0.0f));									// <-- Object
model = glm::rotate(model, 0 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));									// <-- Object
model = glm::scale(model, glm::vec3(32.0f, 32.0f, 0.0f));												// <-- Object
// <-- Object
glUniformMatrix4fv(ShaderList[0]->GetModelLocation() , 1, GL_FALSE, glm::value_ptr(model));				// <-- Object
glUniformMatrix4fv(ShaderList[0]->GetProjectionLocation(), 1, GL_FALSE, glm::value_ptr(projection));    // <-- Object*/