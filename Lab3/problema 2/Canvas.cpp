#include "Canvas.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	canvasDesen = new char* [height];

	for (int i = 0; i < height; i++)
	{
		canvasDesen[i] = new char[width];
		for (int j = 0; j < width; j++)
			 canvasDesen[i][j] = ' ';
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	if (x >= 0 && x <= width && y >= 0 && y <= height)
		canvasDesen[y][x] = ch;
	else
		return;
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray*(ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				SetPoint(i, j, ch);
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int i, j;
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				SetPoint(i, j, ch);

}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int error = dx + dy;
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;

	while (true)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x1 == x2)
				break;
			error = error + dy;
			x1 = x1 + sx;
		}

		if (e2 <= dx)
		{
			if (y1 == y2)
				break;
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, right, top, ch);
	DrawLine(right, top, right, bottom, ch);
	DrawLine(right, bottom, left, bottom, ch);
	DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int i, j;
	for (i = left+1; i < right; i++)
		for (j = top+1; j < bottom; j++)
			SetPoint(i, j, ch);
}
void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			printf("%c", canvasDesen[i][j]);
		printf("\n");
	}
}
void Canvas::Clear()
{
	int i, j;
	for (i = 0; i < height; i++)
		for (j = 0; j < width; j++)
			canvasDesen[i][j] = ' ';
}