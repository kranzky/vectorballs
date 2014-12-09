* ground
  + change the numbers so they make more sense, ground at (0,0)
    - perhaps 1 unit = 1mm or something like that
    - make camera height explicit
    - render with camera height of zero to get single line in centre
  + properly calculate width, draw full-width
    - might require fov calculation?
    - calculate screen y and scaling factor for a given z
    - limit number of draw calls per raster line
    - fade out based on distance
  + fill the gaps
    - sort by z before drawing
    - calculate g for control points
  + calculate slope, only draw +ve slope
    - brighten based on slope
  + hook up controller
    - move forwards/backwards
    - translation (x and y)
* performance
  + display fps
* road
  + a road is just an x coordinate; instead of centering the road texture on the
    screen we use the x-coordinate corresponding to the g-distance of that
    segment of road, and probably use the same calculations as above for the
    width to determine what the screen-x coordinate is
  + support multiple roads / tracks / rivers
  + should fade to alpha near the borders so it blends with the terrain
    underneath
  + allow the x-position of the eye to be changed, and the z-position too, so we
    can start running along roads / up hills and so on
* objects
  + draw and move a sprite, locked to the ground
  + add shadows, scaling and draw order
  + algorithm to calculate sprites based on z value etc
  + fade them in and out
* vectorballs
  + add vectorball sprites
  + aggregate objects with rotation
* sound
* physics
* engine
* release build
  + support windows, linux and osx
  + package installer
* debugger
  + open a port for debugging
  + configuration values as JSON
  + write an external console in JS
