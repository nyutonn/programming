-- Circles2.hs
import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = pictures [ color (makeColor (x/10) 0 0 1) $ translate (5 * x) 0 p | x <- [1..10] ]
  where 
    p = circleSolid 10 
