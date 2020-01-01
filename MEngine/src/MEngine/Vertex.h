#pragma once

struct Pos
{
	float m_x;
	float m_y;
	float m_z;
	Pos(float x, float y, float z) :m_x(x), m_y(y), m_z(z) {}
	Pos() {};
};

struct Color
{
	float m_r;
	float m_g;
	float m_b;
	float m_a;
	Color(float r, float g, float b, float a) : m_r(r), m_g(g), m_b(b), m_a(a) {}
	Color() {}
};

struct TexCord
{
	float m_x;
	float m_y;
	TexCord(float x, float y) :m_x(x), m_y(y) {}
	TexCord(float x, float y, float z) :m_x(x), m_y(y) {}
	TexCord() {}
};

struct PosColVertex 
{
	Pos m_pos;
	Color m_color;
	PosColVertex(Pos pos, Color color) : m_pos(pos), m_color(color) {}
	PosColVertex() {}
};

struct PosTexVertex
{
	Pos m_pos;
	TexCord m_texCoord;
	PosTexVertex(Pos pos, TexCord texCoord) : m_pos(pos), m_texCoord(texCoord) {}
	PosTexVertex() {}
};

