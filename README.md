# 👇 About FDF
>The representation in 3D of a landscape is a critical aspect of modern mapping. For
example, in these times of spatial exploration, to have a 3D representation of Mars is a
prerequisite condition to its conquest. As another example, comparing various 3D representations of an area of high tectonic activity will allow you to better understand these
phenomenon and their evolution, and as a result be better prepared.

FDF (also known as "fil de fer") is a software renderer that takes a set of vertices and renders a wireframe map. 
It involves recreating the entire graphic pipeline: Project points in space, connect the vertices and rasterize the segments,
applying shaders and perform depth testing. 
![screenrecord](screenrecord.gif)

## Features
- Supports .fdf map format.
- Realtime rendering of large environements.
- Multiple color palettes.
- Intuitive camera navigation system and multiple camera projections (isometric, orthographic, perspective).

## Getting started
🚨 Requires libft, ft_printf and minilibx libraries
```shell
git clone https://github.com/Douidik/fdf
cd fdf
make
./fdf <fdf_map>
```
