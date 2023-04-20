import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = pictures [
  circle 100,
  translate 90 90 $ circleSolid 50,
  translate (-90) 90 $ circleSolid 50,
  translate 20 30 $ scale 1 2 $ circle 15,
  translate (-20) 30 $ scale 1 2 $ circle 15,
  translate 20 15 $ scale 1 1.4 $ circleSolid 11
  
  ]
