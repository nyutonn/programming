import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

data World = World { balls :: [Ball], ground :: Float }
data Ball = Ball { x :: Float, y :: Float, vy :: Float, elapsed :: Float }

main :: IO ()
main = play (InWindow "Circle Game" (600, 500) (120,100)) white 60
            initWorld
            renderWorld     
            eventHandler
            tickHandler     

initWorld :: World
initWorld = World { balls = [Ball { x = 0, y = 0, vy = 0, elapsed = 0 }], ground = -100 }

renderWorld :: World -> Picture
renderWorld w = pictures [
  renderGround (ground w),
  pictures
    [renderBall ball | ball <- (balls w)]
  ]

renderGround :: Float -> Picture
renderGround y = translate 0 y $ color red $ rectangleSolid 1000 2

renderBall :: Ball -> Picture
renderBall ball = color (mixColors 10 (elapsed ball) black white) $ translate (x ball) (y ball) $ circleSolid 10 

eventHandler :: Event -> World -> World
eventHandler (EventKey (MouseButton LeftButton) Down _ (mx, my)) w@World { balls = b } =
 w { balls = b ++ [ Ball { x = mx, y = my, vy = 0, elapsed = 0 } ]  }
eventHandler (EventKey (Char c) Down _ _) w@World { ground = g }
  | c == 'w' = w { ground = g + 10 }
  | c == 's' = w { ground = g - 10 }
eventHandler _ w = w

gravity = -100

tickHandler :: Float -> World -> World 
tickHandler dt w@World { balls = b, ground = d } =
  w { balls = [stepBall dt d ball | ball <- b] }

stepBall :: Float -> Float -> Ball -> Ball
stepBall dt g b =
  let y'  = y b  + vy b * dt
      vy' = vy b + gravity * dt
  in if y' < g
  then b { y  = g + (g - y'), vy = -vy', elapsed = (elapsed b + dt) }
  else b { y = y', vy = vy', elapsed = (elapsed b + dt) }
