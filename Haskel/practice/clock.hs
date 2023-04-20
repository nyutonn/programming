import Graphics.Gloss
main :: IO () 
main = display (InWindow "Clock" (600, 500) (120,100)) white picture
-- 1つめの（）は表示するディスプレイの大きさ、2つめは左上からの表示する位置
-- 2つめの引数whiteは背景の色
picture :: Picture
picture = pictures [
  pictures
    [rotate (30*x) $ translate 0 100 $ rectangleSolid 10 20 | x <- [1..12]],
  pictures
    [rotate (6*x) $ translate 0 100 $ rectangleSolid 1 5 | x <- [1..60]],
  rotate 60 $ color red $ polygon [(5,0),(-5,0),(0,95)],
  rotate 300 $ color blue $ polygon [(5,0),(-5,0),(0,60)]
]
