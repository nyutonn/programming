when :: Bool -> IO () -> IO ()
when b m = if b then m else return ()

main :: IO ()
main = do
  putStrLn "Your name?"
  name <- getLine
  when (name == "Mario") $ putStrLn "Wow!!"
  putStrLn $ "Hello, " ++ name ++ "."
