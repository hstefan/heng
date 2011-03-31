#ifndef HSTEFAN_COLOR_TRANSFORM_H
#define HSTEFAN_COLOR_TRANSFORM_H

struct color;

void RGBtoLHS(float r, float g, float b, float hls[]);
color HLStoRGB(float h, float l, float s);
float RGB(float q1, float q2, float hue);
float RGBtoMono(float r, float g, float b);

#endif