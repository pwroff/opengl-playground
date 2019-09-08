#pragma once
#include "core/IObject.h"
#include "core/Moveable.h"
#include "core/Shader.h"

class BaseLighting :
	public IObject, public Moveable
{
	unsigned int VAO;
	Shader shaderProgram;

public:
	BaseLighting();
	glm::vec4 Color;
	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	~BaseLighting();
};
