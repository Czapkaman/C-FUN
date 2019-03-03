#include "Mesh.h"



Mesh::Mesh()
{
}

void Mesh::CreateSquare()
{
	unsigned int indices[] = {

		0, 1, 2,
		0, 2, 3,
	};

	GLfloat vertices[] = {

		0.0f, 0.0f,		0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		0.0f, 1.0f,		1.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // top left 
		1.0f, 1.0f,		1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		1.0f, 0.0f,		0.0f, 1.0f, 0.0f,   1.0f, 0.0f // bottom right
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(&vertices[0]) * 7, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(&vertices[0]) * 7, (void *)(sizeof(&vertices[0]) * 2));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(&vertices[0]) * 7, (void *)(sizeof(&vertices[0]) * 5));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Mesh::RenderSquare()
{
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0); 
}

Mesh::~Mesh()
{
	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}

	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}
}
