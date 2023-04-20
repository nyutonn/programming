import Graphics.Gloss

main :: IO ()
main = display (InWindow "clock" (600, 500) (120, 100)) white picture

picture :: Picture
picture = pictures [
  pictures
    [rotate (30*x) $ translate 0 100 $ rectangleSolid 10 20 | x <- [1..12]],
  color blue $ rotate 120 $ polygon [(5,0), (-5,0), (0,90)],
  color red $ rotate 225 $ polygon [(5,0), (-5,0), (0,60)]
  ]
