/******************************************************************************/
/*!
\file	Vec2D.h
\author Tang Zhi Tern
\par	email: 155134X\@mymail.nyp.edu.sg
\brief Struct to store position
*/
/******************************************************************************/

#ifndef VEC_2D_H
#define VEC_2D_H

/****************************************************************************/
/*!
Struct Vec2D:
\brief	provides X,Y coordinate to indicate position
*/
/****************************************************************************/
struct Vec2D
{
	Vec2D(double x, double y);

	double x;
	double y;
};

#endif