main :: IO ()
main = do
  putStrLn "Your name?"
  name <- getLine
  putStrLn $ "Hello " ++ name ++ "!"

plus3 :: IO ()
plus3 = do
  print "White 3 numbers."
  a <- getLine
  b <- getLine
  c <- getLine
  let d = read a + read b + read c
  print d
 -- putStrLn $ "total = " ++ d
