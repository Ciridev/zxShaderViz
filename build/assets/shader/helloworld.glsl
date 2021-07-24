@vertex
#version 460 core

layout(location = 0) in vec2 a_Pos;

out vec4 other;

void main()
{
  gl_Position = vec4(a_Pos, 0.0f, 1.0f);
  other = vec4(1.0f, 0.0f, 1.0f, 1.0f);
}







































































@fragment
#version 460 core

uniform vec2 u_Resolution;
uniform vec2 u_Mouse;
uniform float u_Time;

in vec4 other;
out vec4 o_Color;

vec2 random2( vec2 p ) {
    return fract(sin(vec2(dot(p,vec2(127.1,301.7)),dot(p,vec2(209.5,183.3))))*43758.5453);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_Resolution.xy;
    st.x *= u_Resolution.x/u_Resolution.y;
    vec3 color = vec3(.0);

    // Scale
    st *= 3.;

    // Tile the space
    vec2 i_st = floor(st);
    vec2 f_st = fract(st);

    float m_dist = 1.;  // minimum distance

    for (int y= -1; y <= 1; y++) {
        for (int x= -1; x <= 1; x++) {
            // Neighbor place in the grid
            vec2 neighbor = vec2(float(x),float(y));

            // Random position from current + neighbor place in the grid
            vec2 point = random2(i_st + neighbor);

// Animate the point
            point = 0.5 + 0.5*sin(u_Time + 6.2831*point);

// Vector between the pixel and the point
            vec2 diff = neighbor + point - f_st;

            // Distance to the point
            float dist = length(diff);

            // Keep the closer distance
            m_dist = min(m_dist, dist);
        }
    }

    // Draw the min distance (distance field)
    color += m_dist;

    // Draw cell center
    color += 1.-step(.02, m_dist);

    // Draw grid
    //color.r += step(.98, f_st.x) + step(.98, f_st.y);

    // Show isolines
    color -= step(.7,abs(sin(27.0*m_dist)))*.5;

    o_Color = vec4(color,1.0) * other;
}












































