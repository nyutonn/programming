-- 完成版
import Data.List (sort)
import Data.Char
import System.IO
import System.Random

data GameState = GameState { secret :: String, tried :: [Char], life :: Int }
  deriving Show 

data GameStatus = Win | Lose | OnGoing 
  deriving Show

main :: IO () 
main = do 
  state <- initState 
  loop state

-- ゲームループ
loop :: GameState -> IO () 
loop state = 
   case checkStatus state of 
      Win  -> renderWin state
      Lose -> renderLose state
      OnGoing -> do
         renderState state
         c <- readUserInput state
         loop (updateState c state)

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
      return $ GameState {secret = word, tried = [], life = 6}
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
    
-- 勝ちか（「秘密の単語」が開示された状態になる），負けか（「残り挑戦回数」が付きる）か，継続中（その何れでもない）かを判定する
checkStatus :: GameState -> GameStatus
checkStatus state = if judge (secret state) state == "win" then Win
                    else if judge (secret state) state == "lose" then Lose
                    else OnGoing

judge :: String -> GameState -> String
judge [] state = "win"
judge (a:x) state =
  if life state == 0 then "lose"
  else if a `elem` tried state then judge x state
  else "ongoing"

-- 解答者側の勝利であるという情報を表示する
renderWin :: GameState -> IO () 
renderWin state = do
  putStrLn ""
  putStrLn "You win!!"
  putStrLn $ "The answer is " ++  secret state ++ "."
  putStrLn $ "Your rest life is " ++ show (life state) ++ "."
  
-- 解答者側の敗北であるという情報を表示する
renderLose :: GameState -> IO () 
renderLose state = do
  putStrLn ""
  putStrLn "You lose..."
  putStrLn $ "The answer is " ++ secret state ++ "."

-- GameStateを適切に表示する。残りライフと開いたところを表示する
renderState :: GameState -> IO ()
renderState state = do
  putStrLn ""
  putStrLn $ "life : " ++ show (life state)
  output (secret state) state
  
output :: String -> GameState -> IO ()
output [] state = putStrLn ""
output (a:x) state =
  if a `elem` tried state then do
    putChar a
    output x state
  else do
    putStr "_"
    output x state

-- 解答者の入力を読みこむ．
-- 一行読んで，先頭の文字を使ったのでよい（getLineを使う？）
-- 空行だったら？あるいは先頭の文字が数字等英語アルファベットでなかったら？
readUserInput :: GameState -> IO Char
readUserInput state = do
  putStrLn "write answer."
  new <- getLine
  let c = head new
  -- 空白のとき
  if null new then do
    putStrLn "Don't put space!"
    putStrLn ""
    readUserInput state
  else if c `elem` tried state then do
    putStrLn "already done"
    putStrLn ""
    readUserInput state
  else if isLower c || isUpper c then do
    return (head new)
  else do
    putStrLn "Put the alphabet"
    putStrLn ""
    readUserInput state

-- when関数の実装
when :: Bool -> IO () -> IO ()
when b m = if b then m else return ()

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

