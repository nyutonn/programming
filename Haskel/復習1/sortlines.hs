import Data.List (sort)

main :: IO ()
main = loop []

loop :: [String] -> IO ()
loop a = do
  new <- getLine
  if null new then do
    syuturyoku (sort a)
  else loop (a ++ [new])

syuturyoku :: [String] -> IO ()
syuturyoku [] = return ()
syuturyoku (a:x) = do
  putStrLn a
  syuturyoku x
