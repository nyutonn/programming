import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = pictures [
  scale 2 20000 $ color red $ line [(-30, 0), (30, 0)],
  color blue $ line [(-30, 0), (0, 51)],
  translate 10 0 $ color green $ line [(30, 0), (0, 51)]
  ]
