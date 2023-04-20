import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game

data World = World { ball :: Ball }
data Ball = Ball { x :: Float, y :: Float, vy :: Float }

main :: IO ()
main = play (InWindow "Circle Game" (600, 500) (120,100)) white 60
            initWorld
            renderWorld     
            eventHandler
            tickHandler     

initWorld :: World
initWorld = World { ball = Ball { x = 0, y = 0, vy = 0 } }

renderWorld :: World -> Picture
renderWorld w = renderBall (ball w) 

renderBall :: Ball -> Picture
renderBall ball = translate (x ball) (y ball) $ circleSolid 10 

eventHandler :: Event -> World -> World
eventHandler (EventKey (MouseButton LeftButton) Down _ (mx, my)) w@World { ball = b } =
 w { ball = b { x = mx, y = my, vy = 0 } }
eventHandler _ w = w

gravity = -100

tickHandler :: Float -> World -> World 
tickHandler dt w@World { ball = b } = w { ball = stepBall dt b }

stepBall :: Float -> Ball -> Ball
stepBall dt b = b { y  = y  b + vy b * dt,
                    vy = vy b + gravity * dt }

