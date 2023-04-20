main :: IO ()
main = loop

loop :: IO ()
loop = do
  s <- getLine
  if null s then
    return ()
  else do
    putStrLn (reverse s)
    loop
