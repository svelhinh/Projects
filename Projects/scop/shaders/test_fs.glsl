#version 410

// Interpolated values from the vertex shaders
in vec2 UV;

in vec3 base_color;

// Ouput data
out vec3 color;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
uniform float textureAlpha;

void main(){

    // Output color = color of the texture at the specified UV
    color = mix(base_color, texture(myTextureSampler, UV).rgb, textureAlpha);
}