#define CTEST_MAIN

#include "ctest.h"
#include "libgeometry/CircleRadius.h"
#include "libgeometry/isGoodCircle.h"
#include "libgeometry/PerimeterArea.h"

int main (int argc, const char** argv)
{
	return ctest_main(argc, argv);  
}

CTEST (CircleRadius, fractional_radius)
{
	//Given
	const string Figure = "circle (2 2, 3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 3.4;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, negative_radius)
{
	//Given
	const string Figure = "circle (2 2, -3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, fractional_center)
{
	//Given
	const string Figure = "circle (2.5 2.2, 6)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 6;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, fractional_integer_center_and_spaces)
{
	//Given
	const string Figure = "circle (   7   3.74, 5  )";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 5;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, spaces)
{
	//Given
	const string Figure = "circle(  2  2,   3.4 )   ";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 3.4;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, wrong_figure)
{
	//Given
	const string Figure = "circleå (2 2, 3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, a_dot_instead_of_a_comma)
{
	//Given
	const string Figure = "circle (2 2. 3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, comma_instead_of_dot)
{
	//Given
	const string Figure = "circle (2 2, 3,4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, incorrect_number_of_parameters)
{
	//Given
	const string Figure = "circle (3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (CircleRadius, incorrect_number_of_brackets)
{
	//Given
	const string Figure = "circle ((2 2, 3.4)";
	
	//When
	const float R = CircleRadius(Figure);
	
	//Then
	const float expected = 0;
	ASSERT_EQUAL (expected, R);	
}

CTEST (isGoodCircle, fractional_radius)
{
	//Given
	const string Figure = "circle (2 2, 3.4)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_TRUE(result);	
}

CTEST (isGoodCircle, fractional_center)
{
	//Given
	const string Figure = "circle (2.7 3.5, 7)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_TRUE(result);	
}

CTEST (isGoodCircle, fractional_integer_center_and_spaces)
{
	//Given
	const string Figure = "circle (    2.7  6   , 7 )";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_TRUE(result);	
}

CTEST (isGoodCircle, spaces)
{
	//Given
	const string Figure = "circle (   2.7    3.5   ,   7   )";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_TRUE(result);	
}

CTEST (isGoodCircle, wrong_figure)
{
	//Given
	const string Figure = "circleE (2.7 3.5, 7)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);	
}

CTEST (isGoodCircle, negative_radius)
{
	//Given
	const string Figure = "circle (2 2, -3.4)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);
}

CTEST (isGoodCircle, a_dot_instead_of_a_comma)
{
	//Given
	const string Figure = "circle (7 3. 3.4)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);	
}

CTEST (isGoodCircle, comma_instead_of_dot)
{
	//Given
	const string Figure = "circle (2 3, 7,4)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);	
}

CTEST (isGoodCircle, incorrect_number_of_parameters)
{
	//Given
	const string Figure = "circle (3.5)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);	
}

CTEST (isGoodCircle, incorrect_number_of_brackets)
{
	//Given
	const string Figure = "circle ((2 2, 3.4)";
	
	//When
	const bool result = isGoodCircle(Figure);
	
	//Then
	ASSERT_FALSE(result);	
}

CTEST (PerimeterArea, integer_radius_for_P)
{
	//Given
	const float R = 5;
	
	//When 
	const float P = Perimeter(R);
	
	//Then
	const float expected_P = 31.4;	
	ASSERT_EQUAL (expected_P, P);	
}

CTEST (PerimeterArea, integer_radius_for_S)
{
	//Given
	const float R = 5;
	
	//When 
	const float S = Area(R);
	
	//Then
	const float expected_S = 78.5;
	ASSERT_EQUAL (expected_S, S);	
}

CTEST (PerimeterArea, fractional_radius_for_P)
{
	//Given
	const float R = 3.6;
	
	//When 
	const float P = Perimeter(R);
	
	//Then
	const float expected_P = 22.608;	
	ASSERT_EQUAL (expected_P, P);	
}

CTEST (PerimeterArea, fractional_radius_for_S)
{
	//Given
	const float R = 3.6;
	
	//When 
	const float S = Area(R);
	
	//Then
	const float expected_S = 40.6944;
	ASSERT_EQUAL (expected_S, S);	
}

