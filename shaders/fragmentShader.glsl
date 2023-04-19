#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 FragPos; // Add this line to receive fragment position
in vec3 Normal;  // Add this line to receive the normal

uniform vec3 lightDirection; // Add this line for light direction uniform
uniform vec3 lightColor;     // Add this line for light color uniform

void main()
{
    // Normalize the normal vector and light direction
    vec3 N = normalize(Normal);
    vec3 L = normalize(-lightDirection); // Invert the light direction since we want it to point towards the light source

    // Calculate the diffuse intensity using the Lambertian shading model
    float diffuseIntensity = max(dot(N, L), 0.0);

    // Compute the final color
    vec3 diffuseColor = ourColor * lightColor * diffuseIntensity;

    FragColor = vec4(diffuseColor, 1.0);
}