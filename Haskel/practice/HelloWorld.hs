main :: IO ()
main = putStrLn "Hello, world."

main :: IO ()
main = do
  putStrLn "Your name?"
  name <- getLine
  putStrLn $ "Hello"

  
