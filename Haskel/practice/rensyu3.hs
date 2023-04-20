import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

data World = World { balls :: [Ball], ground :: Float, number :: Integer }
data Ball = Ball { x :: Float, y :: Float, vy :: Float, elapsed :: Float }

main :: IO ()
main = play (InWindow "Circle Game" (600, 500) (120,100)) white 60
            initWorld
            renderWorld     
            eventHandler
            tickHandler     

initWorld :: World
initWorld = World { balls = [Ball { x = 0, y = 0, vy = 0, elapsed = 0 }], ground = -100, number = 1 }

renderWorld :: World -> Picture
renderWorld w = pictures [
  renderGround (ground w),
  translate 40 200 $ scale 0.2 0.2 $ text "max ball : 5",
  translate 40 170 $ scale 0.2 0.2 $ text "press W then up",
  translate 40 140 $ scale 0.2 0.2 $ text "press S then down",
  pictures
    [renderBall ball | ball <- (balls w)]
  ]

renderGround :: Float -> Picture
renderGround y = translate 0 y $ color red $ rectangleSolid 1000 2

renderBall :: Ball -> Picture
renderBall ball = color (mixColors 10 (elapsed ball) black white) $ translate (x ball) (y ball) $ circleSolid 10
                      

-- 個数が6個以上になったら最初のやつを消す
eventHandler :: Event -> World -> World
eventHandler (EventKey (MouseButton LeftButton) Down _ (mx, my)) w@World { balls = b } =
 w { balls = if number w < 5
             then b ++ [ Ball { x = mx, y = my, vy = 0, elapsed = 0 } ]
             else tail b ++ [Ball {x = mx, y = my, vy = 0, elapsed = 0} ]
               , number = number w + 1  }
             
eventHandler (EventKey (Char c) Down _ _) w@World { ground = g }
  | c == 'w' = w { ground = g + 10 }
  | c == 's' = w { ground = g - 10 }
eventHandler _ w = w

gravity = -200


tickHandler :: Float -> World -> World 
tickHandler dt w@World { balls = b, ground = d } =
  w { balls = [stepBall dt d ball | ball <- b, elapsed ball < 10] }

removeOldBalls :: [Ball] -> [Ball]
removeOldBalls (a:x) = x

stepBall :: Float -> Float -> Ball -> Ball
stepBall dt g b =
  let y'  = y b  + vy b * dt
      vy' = vy b + gravity * dt
  in if y' < g
  then b { y  = g + (g - y'), vy = -vy' - 7, elapsed = (elapsed b + dt) }
  else b { y = y', vy = vy', elapsed = (elapsed b + dt) }
