  ////////////////  ShaderTarg2  ////////////////  

uniform sampler2D Texture0;
uniform sampler2D Texture1;
varying vec2 TexCoord0;

$

void main() {

        TexCoord0 = gl_MultiTexCoord0.xy;// = ;//TexCoord0 = gl_MultiTexCoord0;
        gl_Position = gl_Vertex;

}

$

void main() {
        
        vec4 tex0 = texture2D(Texture0, TexCoord0.xy);
        vec4 tex1 = texture2D(Texture1, TexCoord0.xy);

        float tot = tex0.r + tex0.g + tex0.b + tex0.a;

        if (tot == 0.0) {
            discard;
        }

        gl_FragData[0] = tex0;
        gl_FragData[1] = tex1;

}


