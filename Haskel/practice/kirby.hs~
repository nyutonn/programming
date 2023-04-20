import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

pink = makeColor 1 0.8 1 1

picture :: Picture
picture = pictures [
  color red $ translate 75 (-85) $ scale 2 1 $ circleSolid 30,
  color pink $ circleSolid 100,
  translate 30 30 $ scale 1 2 $ circleSolid 15,
  translate (-30) 30 $ scale 1 2 $ circleSolid 15,
  color white $ translate 30 45 $ scale 1 1.4 $ circleSolid 8,
  color white $ translate (-30) 45 $ scale 1 1.4 $ circleSolid 8,
  color pink $ rotate (-10) $ translate 100 0 $ scale 1.5 1 $ circleSolid 30,
  color pink $ rotate 170 $ translate 100 0 $ scale 1.5 1 $ circleSolid 30,
  color red $ translate (-75) (-85) $ scale 2 1 $ circleSolid 30,
  color red $ translate 0 (-30) $ circleSolid 20,
  color pink $ translate 0 (-20) $ rectangleSolid 40 20
  ]
