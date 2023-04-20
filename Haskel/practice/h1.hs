main :: IO ()
main = do
  a <- return "Hello"
  b <- return "World"
  putStrLn $ a ++ " " ++ b ++ "."
