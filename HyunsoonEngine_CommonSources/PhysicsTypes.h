#pragma once

struct Position
{
	float x;
	float y;

	Position(float x, float y) : x(x), y(y) {}
};

struct Velocity
{
	float x;
	float y;

	Velocity(float x, float y) : x(x), y(y) {}
};

struct Acceleration
{
	float x;
	float y;

	Acceleration(float x, float y) : x(x), y(y) {}
};