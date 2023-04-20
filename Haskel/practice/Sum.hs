main :: IO ()
main = loop 0

loop :: Integer -> IO ()
loop n = do
  s <- getLine
  if null s then do
    putStr "Total: "
    print n
  else loop (n + read s)
