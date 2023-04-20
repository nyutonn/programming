import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = pictures [
  scale 1 0.9 $ translate 0 70 $ color blue $ circleSolid 130,
  translate 0 20 $ color white $ circleSolid 110,
  translate 0 70 $ color red $ circleSolid 50,
  translate 0 95 $ color white $ rectangleSolid 100 50,
  translate 0 100 $ color red $ circleSolid 10,
  translate 0 20 $ color blue $ circle 110,
  translate 15 125 $ scale 1 1.5 $ color white $ circleSolid 15,
  translate 15 125 $ scale 1 1.5 $ color black $ circle 15,
  translate (-15) 125 $ scale 1 1.5 $ color white $ circleSolid 15,
  translate (-15) 125 $ scale 1 1.5 $ color black $ circle 15,
  translate 8 120 $ color black $ circleSolid 7,
  translate (-8) 120 $ color black $ circleSolid 7,
  line [(0,90),(0,70)],
  color red $ line [(50,70),(-50,70)],
  translate 0 (-7) $ color red $ rectangleSolid 220 15,
  translate 0 (-7) $ color yellow $ circleSolid 15,
  translate 0 (-65) $ color white $ rectangleSolid 250 100,
  line [(60,90),(120,110)],
  line [(60,70),(120,50)],
  line [(60,80),(125,80)],
  line [(-60,90),(-120,110)],
  line [(-60,70),(-120,50)],
  line [(-60,80),(-125,80)]
  ]
