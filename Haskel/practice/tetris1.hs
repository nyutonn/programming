-- テトリス（上下左右は自分で入力）
{-# LANGUAGE NamedFieldPuns, RecordWildCards #-}
{-# LANGUAGE GADTs #-}

import           Data.Char                          (toLower, toUpper)
import           Graphics.Gloss
import           Graphics.Gloss.Interface.Pure.Game
import Data.List (sort)
import Data.Char
import System.IO
import System.Random
import qualified Data.Map as M
import Data.Map ((!))

import Debug.Trace
import Control.Applicative

-- ゲームの状態 (点数、置いたミノ、動かすミノ)
data GameState = GameState { score :: Int, box :: Box, randomg :: StdGen  }
--  deriving Show

-- mcolor : ミノの色, mshape : ミノの形
data Mino = Mino { mcolor :: Color, mshape :: [(Int, Int)] }

-- すでに置いたミノの配列
type Box = M.Map (Int,Int) Color
type Time = Float
emptyColor = white

seven_minos :: [Mino]
seven_minos = [
  -- Oミノ
  Mino{ mcolor = red,
        mshape = [(0,0),(0,1),(1,0),(1,1)]},
  -- Lミノ
  Mino{ mcolor = blue,
        mshape = [(0,0),(0,1),(1,0),(0,2)]},
  -- Jミノ
  Mino{ mcolor = green,
        mshape = [(0,0),(0,1),(1,0),(2,0)]},
  -- Sミノ
  Mino{ mcolor = magenta,
        mshape = [(0,0),(1,0),(1,1),(2,1)]},
  -- Zミノ
  Mino{ mcolor = orange,
        mshape = [(0,0),(0,1),(1,1),(1,2)]},
  -- Iミノ
  Mino{ mcolor = cyan,
        mshape = [(0,0),(0,1),(0,2),(0,3)]},
  -- Tミノ
  Mino{ mcolor = yellow,
        mshape = [(0,0),(1,0),(1,1),(2,0)]}
  ]


main :: IO () 
main = do
    play (InWindow "Tetris 1" (600,600) (20,20))
      white 5 (start (mkStdGen 1))
      drawWorld
      eventHandler
      frameHandler

start :: StdGen -> Freer ()
start gen = mainloop initState
  where
   initState = GameState { score = 0, randomg = gen, box = emptyBox }
    
-- ここにメインの挙動を記述する。ここから手をつけていく
mainloop :: GameState -> Freer ()
mainloop s =
  let (mino,randomg') = chooseMino (randomg s)
      s' = s{ randomg = randomg'}
  in lowerMino (5,19) mino s'

-- 7つのミノからどれを落とすか選ぶ
chooseMino :: StdGen -> (Mino,StdGen)
chooseMino gen = (seven_minos !! 2, gen)

-- ミノを下に落とす
lowerMino :: (Int,Int) -> Mino -> GameState -> Freer()
lowerMino pt mino s@GameState{..} = do
  key <- getKey s (drawMino pt mino)
-- キー入力で上下左右にミノを動かす。ミノを回転させる
  let (pt', mino'') =
        if      key == Just 'a' && okPlace (point_add (-1,0) pt) mino s then (point_add (-1,0) pt, mino)
        else if key == Just 'd' && okPlace (point_add (1,0) pt) mino s  then (point_add (1,0) pt, mino)
        else if key == Just 'w' && okPlace (point_add (0,1) pt) mino s  then (point_add (0,1) pt, mino)
        else if key == Just 's' && okPlace (point_add (0,-1) pt) mino s  then (point_add (0,-1) pt, mino)
        else (pt, mino)
  lowerMino pt' mino'' s

-- ミノが落下し終わったら、もう一回mainloopを繰り返す
lowerMino pt Mino{..} st@GameState{..} = do
  
  
--ミノが次の場所に行けるかどうか判断する
okPlace :: (Int,Int) -> Mino -> GameState -> Bool
okPlace pt Mino{mshape} GameState{box} =
  all(\mpt -> let p@(_,j) = point_add mpt pt
     in (okPoint p && box ! p == emptyColor)) mshape
  
-- ミノが壁にぶつかっていないかを判断する
okPoint :: (Int,Int) -> Bool
okPoint (i,j) = and [i >= 0, i <= 9, j >= 0, j <= 19]
  
-- 座標の和をとる
point_add :: (Int,Int) -> (Int,Int) -> (Int,Int)
point_add (i1, j1) (i2, j2) = (i1+i2, j1+j2)
  
-- ミノをGUIに描く
drawMino :: (Int,Int) -> Mino -> Picture
drawMino pt Mino{..} =
  uncurry translate (boxToWorldRel pt) $ color mcolor $ shapes
 where
  shapes = pictures $ map drawCell mshape

-- ミノの4つそれぞれのブロックの位置
drawCell :: (Int,Int) -> Picture
drawCell pt = polygon [(x-boxWidth_half, y-boxWidth_half),
                       (x-boxWidth_half, y+boxWidth_half),
                       (x+boxWidth_half, y+boxWidth_half),
                       (x+boxWidth_half, y-boxWidth_half)]
 where (x,y) = boxToWorld pt

-- ミノの形と色を出力する
drawBox :: Box -> Picture
drawBox box =
  pictures $ M.foldlWithKey' (\ps pt c ->
            if c == emptyColor then ps
            else (color c $ drawCell pt):ps) [drawEmptyBox] box

-- ミノが置かれていない場所
drawEmptyBox :: Picture
drawEmptyBox =
  line [(fst ul - boxWidth_half, snd ul + boxWidth_half),
        (fst bl - boxWidth_half, snd bl - boxWidth_half),
        (fst br + boxWidth_half, snd br - boxWidth_half),
        (fst ur + boxWidth_half, snd ur + boxWidth_half)]
  where ul = boxToWorld (0,19)
        ur = boxToWorld (9,19)
        bl = boxToWorld (0,0)
        br = boxToWorld (9,0)
        
-- 描きたいものの場所を決める
boxToWorld :: (Int,Int) -> (Float,Float)
boxToWorld (i,j) =
  (fromIntegral i*boxWidthWorld-50,
   fromIntegral j*boxWidthWorld+boxWidth_half)

-- ミノを表示するときの倍率
boxWidthWorld :: Float
boxWidthWorld = 5.0

-- ミノの辺の半分の長さの倍率。ミノを表示するうえで中心から上下左右にずらすときに使う
boxWidth_half :: Float
boxWidth_half = boxWidthWorld/2

-- ミノを表示するときの大きさに変換する
boxToWorldRel :: (Int,Int) -> (Float,Float)
boxToWorldRel (i,j) =
  (fromIntegral i*boxWidthWorld, fromIntegral j*boxWidthWorld)

-- 初期のミノが何もない状態
emptyBox :: Box
emptyBox = M.fromList [((i,j),emptyColor) | i <- [0..9], j <- [0..19]]


timeout :: Float
timeout = 0.3  --  秒

type World = Freer ()

drawWorld :: World -> Picture
drawWorld (Effect _ p _ _) = translate 10 (-240) . scale 4 4 $ p
drawWorld _                = blank

-- キー入力でテトリミノを動かす

eventHandler :: Event -> World -> World
eventHandler (EventKey (Char c) Up _ _) (Effect _ _ KeyReq k) = k (Just c)
eventHandler _ w = w

-- 時間で操作中のテトリミノを下に落とす
-- 今回は未実装
frameHandler :: Time -> World -> World
frameHandler _ (Effect t p Pause k)  | t > timeout = k ()
frameHandler _ (Effect t p KeyReq k) | t > timeout = k Nothing
frameHandler t (Effect t'  p r k) = Effect (t+t') p r k
frameHandler _ w = w

---------------------------------------------------------------------------
-- Hangmanで使ったIOモナドのようなもの
data Freer a where
  Pure  :: a -> Freer a
  Effect :: Time -> Picture -> Req x -> (x -> Freer a) -> Freer a

instance Functor Freer where
  fmap f (Pure x) = Pure $ f x
  fmap f (Effect t p r k) = Effect t p r (fmap f . k)

instance Applicative Freer where
  pure = Pure
  Pure f <*> m = fmap f m
  Effect t p r k <*> m = Effect t p r (\x -> k x <*> m)

instance Monad Freer where
  return = Pure
  Pure x >>= k = k x
  Effect t p r k' >>= k = Effect t p r (k' >>> k)

-- 副作用を持つ関数を合成する (CBV 合成)
(>>>) :: Monad m => (a -> m b) -> (b -> m c) -> (a -> m c)
f >>> g = (>>= g) . f


data Req a where
  Pause  :: Req ()
  KeyReq :: Req (Maybe Char)

-- Key入力を受け取って、出力する。getLineのようなもの
getKey :: GameState -> Picture -> Freer (Maybe Char)
getKey GameState{..} extrap = do
  let pict = pictures [drawBox box, extrap]
  Effect 0 pict KeyReq pure

-- StateとPictureを出力する。PutStrLnのようなもの
pause :: GameState -> Picture -> Freer ()
pause GameState{..} extrap = do
  let pict = pictures [drawBox box, extrap]
  Effect 0 pict Pause pure
  

-- ------------------------------------------------------------------------
