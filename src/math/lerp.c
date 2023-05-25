#include "lerp.h"
#include "render/color.h"

int fdf_lerp(int t, int u, int a, int b)
{
	return (a + ((float)t / u) * (b - a));
}

t_fdf_color fdf_lerp_rgb(int t, int u, t_fdf_color a, t_fdf_color b)
{
	const float time = (float)t / u;
	t_fdf_color lerp;

	// TODO! this may not work, (b < a) may underflow
	lerp.r = a.r + time * (b.r - a.r);
	lerp.g = a.g + time * (b.g - a.g);
	lerp.b = a.b + time * (b.b - a.b);
	lerp.a = 255;
	return (lerp);
}

t_fdf_color fdf_lerp_rgb_gradient(int t, int u, t_fdf_color s[], size_t len)
{
	const float time = (float)t / u;
	t_fdf_color lerp;
	size_t i = 1;

	if (!len)
		return (t_fdf_color){.v = 0};
	lerp = s[0];
	while (len--)
	{
	}
}
