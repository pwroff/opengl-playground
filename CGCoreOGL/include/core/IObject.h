#pragma once

class IObject
{
public:
	virtual void Init() = 0;

	virtual void Render()
	{
		return;
	}

	virtual void Update(float deltaTime)
	{
		return;
	}
};
