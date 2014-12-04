V E C T O R B A L L S
=====================

* Add a ground plane and a road.
  + first, start with a flat ground plane
  + do raycasting to determine, for each raster line, what the z of the ground
    plane is
  + render a slice from a ground texture which is stretched and tiled
    appropriately
  + hook up controls so we can move the camera in 3 dimensions and get it
    looking shmick
  + add a horizon graphic and a sky gradient or something
  + add a straight road at a particular x co-ordinate and use same lookup
    process to render the road on top of the ground texture
  + add hills by calculating the height of the ground plane based on the z value
    and have this properly effect the raycasting calculation
  + vary the textures by height
  + add curves to the road by calculating the x value of the road based on the
    z value and make it possible to follow the road (without any kind of
    rotation)
  + add multiple overlapping roads with different curvatures

* Add some ground sprites
  + draw and move a sprite, locked to the ground
  + add shadows, scaling and draw order
  + algorithm to calculate sprites based on z value etc
  + fade them in and out

* Vectorballs objects
  + add vectorball sprites
  + aggregate objects with rotation
