varying vec3 vert;
varying vec3 vertNormal;
uniform vec3 lightPos;
uniform sampler2D texture;
varying vec2 v_texcoord;

void main()
{
    vec3 L = normalize(lightPos - vert);
    float NL = max(dot(normalize(vertNormal), L), 0.0);
    vec3 color = vec3(0.39, 1.0, 0.0);
    vec3 col = clamp(color * 0.2 + color * 0.8 * NL, 0.0, 1.0);
    gl_FragColor = texture2D(texture, v_texcoord);
}
