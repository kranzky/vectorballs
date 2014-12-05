* algorithm thoughts
  + we want to find, for each raster line, the height, z-distance,
    ground-distance and slope/normal of the terrain; allocate an array of
    structures, one member for each raster line (this is the z-map)
  + we assume the terrain is a continuous line, so raycasting to find an
    intersection can be an expensive operation
  + instead, represent the terrain as a discrete series of heights, and raycast
    from the terrain to the screen. this won't give us every line, but it will
    give us a line for each entry in the terrain heightmap... it is important to
    take the closest one if several map onto the same raster line
  + each raster line on the screen is now either known or unknown... we need to
    start at the first known one that is <= 0 and walk down the screen to figure
    out the rest... any unknown raster will be on one of two line segments, the
    one connecting the previous one or the one connecting the next one... it
    should be a simple test to figure out which is which

* drawing thoughts
  + for each raster we know h, z-distance, g-distance and slope, so draw the
    texture as follows:
      - have a bunch of 256x256 tiles of ground textures for various heights
        (sand, grass, rock, snow) and select two textures with a percentage
        weighting, selecting the line of the texture using the g-distance
      - draw the two textures overlaid with alpha so we smoothly blend between
        the different terrain types
      - use the slope to determine how bright the texture should be, and
        brighten or darken it by drawing over with some blend mode or other
      - use the z-distance to fade in the distance
  + remember to start drawing in the middle of the screen, and select the
    x-offset into the source texture appropriately
  + move the eye up-and-down to be a constant height above the terrain
  + draw mountains on the horizon, and a suitable sky; should be able to get the
    y co-ordinate of the horizon from the eye height and assuming z->infinity

* width thoughts
  + need to calculate the width ratio; assume a 256x256 square and look at the
    fov stuff to do this properly

* road thoughts
  + a road is just an x coordinate; instead of centering the road texture on the
    screen we use the x-coordinate corresponding to the g-distance of that
    segment of road, and probably use the same calculations as above for the
    width to determine what the screen-x coordinate is
  + support multiple roads / tracks / rivers
  + should fade to alpha near the borders so it blends with the terrain
    underneath
  + allow the x-position of the eye to be changed, and the z-position too, so we
    can start running along roads / up hills and so on

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
