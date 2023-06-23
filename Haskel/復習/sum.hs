main :: IO ()
main = loop 0

loop :: Integer -> IO ()
loop n = do
  new <- getLine
  if null new then do
    putStr "total = "
    print n
  else do
    loop (n + read new)
  
