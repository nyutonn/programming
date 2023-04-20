import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

pink = makeColor 1 0.8 1 1

picture :: Picture
picture = pictures [
  color (mixColors 1 0.5 red blue) $ translate 10 20 $ circleSolid 100
  ]
