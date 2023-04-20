import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = rotate 45 $ scale 1 2 $ translate 10 0 $ color red (circleSolid 50)
