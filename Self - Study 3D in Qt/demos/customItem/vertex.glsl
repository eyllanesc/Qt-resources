attribute vec4 vertex;
attribute vec3 normal;
attribute vec2 a_texcoord;
varying vec3 vert;
varying vec3 vertNormal;
varying vec2 v_texcoord;
uniform mat4 projMatrix;
uniform mat4 mvMatrix;
uniform mat3 normalMatrix;

void main()
{
    vert = vertex.xyz;
    // v_texcoord = vec2(0.7, 0.8);
    v_texcoord = a_texcoord;
    vertNormal = normalMatrix * normal;
    gl_Position = projMatrix * mvMatrix * vertex;
}
