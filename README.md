* TODO
  + calculate slope, only draw +ve slope
  + sort by z before drawing
  + calculate g for control points, use for texture
  + fill the gaps
  + change the numbers so they make more sense, ground at (0,0)
  + properly calculate width, draw full-width
  + hook up controller
  + move forwards
  + translation
  + display fps
  + add a horizon graphic and a sky gradient or something

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

* Add some ground sprites
  + draw and move a sprite, locked to the ground
  + add shadows, scaling and draw order
  + algorithm to calculate sprites based on z value etc
  + fade them in and out

* Vectorballs objects
  + add vectorball sprites
  + aggregate objects with rotation
