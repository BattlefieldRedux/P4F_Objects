#version 120

uniform vec3 eyeposworld;
uniform vec3 eyevecworld;
uniform vec3 sundirworld;

varying vec2 uv0;
varying vec2 uv1;
varying vec2 uv2;
varying vec2 uv3;
varying vec2 uv4;
varying vec3 norm;
varying vec3 upvec;
varying vec3 sunvec;
varying vec3 eyesurfvec;         // eye to surface vector
varying vec3 eyepos;
varying vec3 fragpos;

void main()
{
 // UVs
 uv0 = gl_MultiTexCoord0.st;
 uv1 = gl_MultiTexCoord1.st;
 uv2 = gl_MultiTexCoord2.st;
 uv3 = gl_MultiTexCoord3.st;
 uv4 = gl_MultiTexCoord4.st;
 
 // normal
 norm = gl_Normal;
 
 // transform sunvec
 sunvec = sundirworld;
 
 // eye to surface vector in world space
 eyesurfvec = eyeposworld - gl_Vertex.xyz;
 
 eyepos = eyeposworld;
 fragpos = gl_Vertex.xyz;
 
 // compute tangents
 vec3 tan1 = gl_MultiTexCoord5.xyz;
 vec3 tan2 = cross(norm,-tan1) * gl_MultiTexCoord5.w;
 
 // create tangent space rotation matrix
 mat3 rotmat = mat3( tan1, tan2, norm );
 //mat3 rotmat = mat3( normalize(tan1), normalize(tan2), normalize(norm) );
 
 // rotate local space sun vector to tangent space
 sunvec = sunvec * rotmat;
 
	// up vector
	upvec = vec3(0.0, 1.0, 0.0) * rotmat;
	
 // rotate local eye-to-surface to tangent space
 eyesurfvec = eyesurfvec * rotmat;
 
 // vertex position
 //gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
 gl_Position = ftransform(); // HACK: fixes face selection overdraw z-fighting
}
