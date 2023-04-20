import           Data.Char                          (toLower, toUpper)
import           Graphics.Gloss
import           Graphics.Gloss.Interface.Pure.Game
import Data.List (sort)
import Data.Char
import System.IO
import System.Random

data GameState = GameState { secret :: String, tried :: [Char], life :: Int, word_list :: [String], random_list :: [Int], space_times :: Int, win :: Int, lose :: Int }
  deriving Show 

data GameStatus = Win | Lose | OnGoing 
  deriving Show


{- 一部の関数やデータ構造はCUI版と共通 -}

windowHeight :: Int
windowHeight = 600

windowWidth :: Int
windowWidth = 600

main :: IO () 
main = do 
  s <- initState 
  play (InWindow "Visual Hangman" (windowWidth, windowHeight) (20, 20)) white 60
       s
       renderState
       eventHandler
       tickHandler

-- 最初の状態を返す．とりあえずは「秘密の単語」は決め打ちでよい．
initState :: IO GameState
initState = do
  -- 難易度選択をしたい
  putStrLn "Choose mode. Put 1 or 2"
  putStrLn "easy : 1\ndifficult : 2"
  choice <- getLine
  if choice == "1" || choice == "2" then do

    wordlist <- if choice == "1" then do
                  putStrLn "easy mode"
                  readFile "words_easy"
                else do
                  putStrLn "difficult mode"
                  readFile "words_difficult"
    --wordlist <- readFile "words_easy"
    let words = lines wordlist
    n <- randomRIO (0, length words-1)
    let word = words !! n
  
    --ここからちゃんとした単語を選んでいるかを判定する
    if wordright word then do
      --putStrLn word
      putStrLn "Guess secret word!"
      putStrLn "Put one character one at time."
      putStrLn $ "The number of characters is " ++ show (length word)
      return $ GameState {secret = word, tried = [], life = 6, word_list = words, random_list = [n*2..n*1000], space_times = 0, win = 0, lose = 0 }
    else
      initState
  else do
    putStrLn "Please put 1 or 2 !!!"
    initState

-- 良い感じの文字を選んでいるかを判定する。だめなら選び直し  
wordright :: String -> Bool
wordright [] = True
wordright (a:x) =
  if isUpper a || isLower a then
    wordright x
  else
    False
    
face = color red $ translate 150 150 $ circle 50
body = color red $ line [(150,100),(150,-100)]
left_arm = color red $ line [(150,0),(50,0)]
right_arm = color red $ line [(150,0),(250,0)]
left_leg = color red $ line [(150,-100),(50,-200)]
right_leg = color red $ line [(150,-100),(250,-200)]

renderState :: GameState -> Picture
renderState s = pictures
  [
  if tried s == [] then
    -- この中に最初の情報をいろいろ書く
    pictures[
    translate (-250) 200 $ scale 0.2 0.2 $ text "Guess secret word",
    translate (-250) 150 $ scale 0.2 0.2 $ text ("The number of character is " ++ show (length (secret s))),
    translate (-280) 0     $ scale 0.3 0.3 $ text ("tried  : " ++ (tried s)),
    translate (-280) (-40) $ scale 0.3 0.3 $ text ("life   : " ++ show(life s)),
    translate (-280) (-80) $ scale 0.3 0.3 $ text ("answer : " ++ output (secret s) "" s)
    ]
  else
    pictures[
    translate (-250) 250 $ scale 0.2 0.2 $ text ("The number of character is " ++ show (length (secret s))),
    translate 150 (-275) $ scale 0.1 0.1 $ text "restart : Space Key",
    color red $ line [(150,200),(150,300)],
    if life s == 5 then pictures[face]
    else if life s == 4 then pictures[face, body]
    else if life s == 3 then pictures[face, body, left_arm]
    else if life s == 2 then pictures[face, body, left_arm, right_arm]
    else if life s == 1 then pictures[face, body, left_arm, right_arm, left_leg]
    else if life s <= 0 then pictures[face, body, left_arm, right_arm, left_leg, right_leg]
    else blank
  ,
    if checkStatus s == "win" then
      pictures[
      translate (-250) 50 $ scale 0.3 0.3 $ text "You win ! !",
      translate (-250) 0 $ scale 0.3 0.3 $ text ("The answer is [" ++ secret s ++ "]"),
      translate (-250) (-50) $ scale 0.3 0.3 $ text ("Rest life is " ++ show(life s)),
      translate (-150) (-100) $ scale 0.2 0.2 $ text "restart : Space Key",
      translate (-150) (-150) $ scale 0.2 0.2 $ text "exit : Esc Key",
      color blue $ translate (-20) (-120) $ rectangleWire 300 100
      ]
    else if checkStatus s == "lose" then
      pictures[
      translate (-250) 50 $ scale 0.3 0.3 $ text "You lose...",
      translate (-250) 0 $ scale 0.3 0.3 $ text ("The answer is [" ++ secret s ++ "]"),
      translate (-150) (-100) $ scale 0.2 0.2 $ text "restart : Space Key",
      translate (-150) (-150) $ scale 0.2 0.2 $ text "exit : Esc Key",
      color blue $ translate (-20) (-120) $ rectangleWire 300 100
      ]
    else
      pictures[
      translate (-280) 0     $ scale 0.3 0.3 $ text ("tried  : " ++ [c | c <- tried s, isLower c]),
      translate (-280) (-40) $ scale 0.3 0.3 $ text ("life   : " ++ show(life s)),
      translate (-280) (-80) $ scale 0.3 0.3 $ text ("answer : " ++ output (secret s) "" s)
      ]
  ]
            
  ]
  {- FIXME: checkStatusを利用し，勝ち，負け，その他の場合に応じていい感じに描画する -}

output :: String -> String -> GameState -> String
output [] str state = str
output (a:x) str state = 
  if a `elem` tried state
    then output x (str ++ [a]) state
    else output x (str ++ "_") state

-- 勝ちか（「秘密の単語」が開示された状態になる），負けか（「残り挑戦回数」が付きる）か，継続中（その何れでもない）かを判定する
checkStatus :: GameState -> String
checkStatus state = judge (secret state) state

judge :: String -> GameState -> String
judge [] state = "win"
judge (a:x) state =
  if life state <= 0 then "lose"
  else if a `elem` tried state then judge x state
  else "ongoing"

eventHandler :: Event -> GameState -> GameState
eventHandler (EventKey (Char c) Down _ _) s = updateState c s

-- スペースキー押したらリスタート
eventHandler (EventKey (SpecialKey KeySpace) Down _ _) s =
  s{ tried = [], life = 6, secret = word, space_times = space_times s + 1 }
    where
      word = (word_list s) !! ((random_list s !! space_times s) `mod` (length (word_list s)))
      
-- 裏技　[↑]で1機アップ
eventHandler (EventKey (SpecialKey KeyUp) Down _ _) s = s { life = life s + 1 }
      
  {- FIXME: キー入力イベントに対応して `updateState`を呼ぶ？ -}
eventHandler _ s = s

-- 解答者の入力に応じて，現在の状態を更新する．小文字と大文字両方格納する
updateState :: Char -> GameState -> GameState 
updateState c state = 
  if c `elem` tried state then
    state { life = life state - 1 }
  else if isLower c then
    if c `elem` secret state then
      state { tried = sort (tried state ++ [c] ++ [toUpper c]) }
    else state { tried = sort (tried state ++ [c] ++ [toUpper c]), life = life state - 1 }
  else
    if c `elem` secret state then
      state { tried = sort (tried state ++ [c] ++ [toLower c]) }
    else state { tried = sort (tried state ++ [c] ++ [toLower c]), life = life state - 1 }


tickHandler :: Float -> GameState -> GameState
tickHandler _ s = s {- 今回は時間で何かが変化したりはしない -}
