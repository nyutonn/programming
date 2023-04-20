import Graphics.Gloss
main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture
picture :: Picture
picture = pictures [
  circleSolid 100,
  translate 100 100 $ circleSolid 50,
  scale (-1) 1 $  translate 100 100 $ circleSolid 50
                   ]
