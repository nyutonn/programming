import Graphics.Gloss

main :: IO () 
main = display (InWindow "Circle" (600, 500) (120,100)) white picture

picture :: Picture
picture = pictures [
  color black (circleSolid 50),
  translate (-50) 50 $ color black $ circleSolid 25,
  translate 50 50 $ color black $ circleSolid 25
  ]

--picture2 :: Picture
--picture2 = pictures2 [
--  color black (circleSolid 50),
--  scale (-1) 1 $ translate (-50) 50 $ color black $ circleSolid 25
--  ]
