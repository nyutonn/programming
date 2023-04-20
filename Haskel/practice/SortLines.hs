import Data.List (sort)

main :: IO ()
main = loop []

loop :: [String] -> IO ()
loop a = do
  s <- getLine
  if null s then do
    syuturyoku (sort a)
  else
    loop (a ++ [s])

syuturyoku :: [String] -> IO ()
syuturyoku [] = return ()
syuturyoku (a:x) = do
  putStrLn a
  syuturyoku x
