import Data.Char
import System.IO
import System.Random
import Data.Array

what :: IO ()
what = do
  let a = 1
      b = 2
      c = 3
      d = a + b + c
  print d

change :: Char -> Bool
change c = isUpper c

line :: String -> [String]
line s = lines s

abc :: IO ()
abc = do
  word <- readFile "words"
  let words = lines word
  putStrLn $ words !! 2

ab :: IO ()
ab = do
  a <- randomRIO (1,10) :: IO Int
  print a

aaa :: IO ()
aaa = do
  a <- getLine
  putStrLn a


square = array (1,10) [(i,i*i) | i <- [1..10]]

kuku = array ((1,1),(9,9)) [((i,j),i*j) | i <- [1..9], j <- [1..9]]
