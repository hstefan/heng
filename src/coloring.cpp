#include "coloring.hpp"
#include <iostream>
#include <cmath>


struct color
{
	float r, g, b;
};

float RGB(float q1, float q2, float hue) 
{ 
	if(hue > (float)360.0)
		hue-=(float)360.0; 
	if(hue < (float)0.0)
		hue+=(float)360.0; 
	if(hue < (float)60.0)
		return (q1+(q2-q1)*hue/(float)60.0); 
	else if 
		(hue < (float)180.0) return  q2; 
	else if 
		(hue < (float)240.0) return (q1 + (q2 - q1) * (240 - hue) / (float)60.0); 
	else return q1; 
}


void RGBtoHLS(float r, float g, float b, float hls[]) 
{ 
	float max, min,dif; 
	float r_dist, g_dist, b_dist; 
	r /= 255.0; 
	g /= 255.0; 
	b /= 255.0; 
	max = std::max(r, std::max(g,b)); 
	min = std::max(r, std::min(g,b)); 
	dif = max - min; 
	hls[1] = (max + min)/(float)2.0;

	if(abs(dif) < (float) 0.00000001) 
	{ 
		hls[2] = (float)0.0; 
		hls[0] = (float)0.0; 
		//std::cout << "erro na cor ..." << std::endl;
	} 
	else 
	{ 
		if(hls[1] <= (float)0.5) 
			hls[2] = dif/(max+min); 
		else  
			hls[2] = dif/(2-max-min); 
		r_dist = (max-r)/dif; 
		g_dist = (max-g)/dif; 
		b_dist = (max-b)/dif; 

		if(r == max)    
			hls[0] = b_dist-g_dist; 
		else if(g==max) 
			hls[0] = 2+r_dist-b_dist; 
		else if(b==max) 
			hls[0] = 4+g_dist-r_dist; 

		hls[0] *= 60.0; 

		if(hls[0] < (float)0.0) 
			hls[0] += (float)360.0; 

		hls[0]/=(float)360.0; 
	} 
} 

color HLStoRGB(float h, float l, float s) 
{ 
	float p1, p2, r, g, b, H; 
	H = h * 360; 
	if(l <= (float)0.5) 
		p2 = l * (1 + s); 
	else 
		p2 = l + s - l * s; 

	p1 = (float) 2.0 * l - p2; 

	if(s==0) 
	{
		r=l; g=l; b=l; 
	}
	else 
	{ 
		r = RGB(p1, p2, H + 120); 
		g = RGB(p1, p2, H); 
		b = RGB(p1, p2, H - 120); 
		if(r>1 || g>1 || b>1) 
			std::cout << r << " " << g << " " << b << std::endl;
	} 
	color c = { r, g, b };
	return c;
} 

float RGBtoMono(float r, float g, float b)
{
	return (0.2125f * r) + (0.7154f * g) + (0.0721f * b);
}