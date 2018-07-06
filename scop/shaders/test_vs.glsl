#version 410

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 vertex_color;

// Output data ; will be interpolated for each fragment.
out vec2 UV;
out vec3 base_color;

uniform float timer;
uniform vec3 trans;

void main() {

	const mat4 projection = mat4(
        vec4(0.75, 0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 0.5, 0.5),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

	mat4 rotationX = mat4(
        vec4(1.0, 0.0, 0.0, 0.0),
        vec4(0.0, cos(timer), -sin(timer), 0.0),
        vec4(0.0, sin(timer), cos(timer), 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

	mat4 rotationY = mat4(
        vec4(cos(timer), 0.0, sin(timer), 0.0),
        vec4(0.0, 1.0,  0.0, 0.0),
        vec4(-sin(timer), 0.0, cos(timer), 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

	mat4 rotationZ = mat4(
        vec4(cos(timer), -sin(timer), 0.0, 0.0),
        vec4(sin(timer), cos(timer),  0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

    mat4 translation = mat4(
        vec4(1.0, 0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(trans.x,trans.y,trans.z, 1.0)
    );

	mat4 scale = mat4(
        vec4(0.5, 0.0, 0.0, 0.0),
        vec4(0.0, 0.5, 0.0, 0.0),
        vec4(0.0, 0.0, 0.5, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );

    UV = vertexUV;
    base_color = vertex_color;
	gl_Position = projection * translation * rotationY * scale * vec4(vertex_position, 1.0);
}