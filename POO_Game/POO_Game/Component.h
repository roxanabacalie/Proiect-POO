#pragma once
/// <summary>
/// Base class for each component 
/// </summary>

class Component
{
protected:
	virtual ~Component() = default;
	virtual void init() = 0;
	virtual void draw() = 0;
};