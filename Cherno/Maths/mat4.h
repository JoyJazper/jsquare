#pragma once

#include "String.h"
#include "vec3.h"
#include "vec4.h"
#include "maths_func.h"

namespace JSquare{ namespace Maths {

	struct mat4
	{
		//float elements[4 * 4];

		union
		{
			// [row + col * 4]
			float elements[4 * 4];
			vec4 rows[4];
		};
		
		mat4();
		mat4(float diagonal);

		static mat4 Identity();

		mat4& Multiply(const mat4& other);
		friend   mat4 operator*(mat4 left, const mat4& right);
		mat4& operator*=(const mat4& other);

		vec4 Multiply(const vec4& other) const;
	
		static mat4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static mat4 LookAt(const vec3& camera, const vec3& object, const vec3& up);
		static mat4 Perspective(float fov, float aspectRatio, float near, float far);
	
		static mat4 Translate(const vec3& translation);
		static mat4 Rotate(float angle, const vec3& axis);

		static mat4 Scale(const vec3& scale);
	};
} }