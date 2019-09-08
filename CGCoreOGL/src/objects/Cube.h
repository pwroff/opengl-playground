#pragma once

#include "core/IObject.h"
#include "core/Moveable.h"
#include "core/Texture2D.h"
#include "core/Shader.h"
#include "BaseLighting.h"

class Cube :
	public IObject, public Moveable
{
private:
	Shader shaderProgram;
	
	unsigned int VBO, VAO;
public:
	Cube();
	BaseLighting * light;
	glm::vec4 Color;
	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	static uint GetBuffer();
	~Cube();
};

