main :: IO ()
main = do
  putStrLn "Your name?"
  name <- getLine
  putStrLn $ "Hello, " ++ name ++ "."
