sumTo :: Integer -> Integer
sumTo n = if n == 0 then 0 else n + sumTo (n-1)

factorial :: Integer -> Integer
factorial n = if n == 0 then 1 else n * factorial (n-1)

mygcd :: Integer -> Integer -> Integer
mygcd m n = if m == n then m
            else if m > n then mygcd (m-n) n
                 else mygcd (n-m) m

mysum :: [Integer] -> Integer
mysum [] = 0
mysum (a : x) = a + mysum x

myhead :: [a] -> a
myhead (a : x) = a

myproduct :: [Integer] -> Integer
myproduct (a : x) = a * myproduct x
myproduct [] = 1

mynth :: [a] -> Integer -> a
mynth (a : x) 0 = a
mynth (a : x) n = mynth x (n-1)

lsb2nat :: [Bool] -> Integer
lsb2nat (a : x) = if a == True then 1 + 2 * lsb2nat x
                  else 2 * lsb2nat x
lsb2nat [] = 0

nat2lsb :: Integer -> [Bool]
nat2lsb 0 = [False]
nat2lsb 1 = [True]
nat2lsb n = if n `mod` 2 == 0 then [False] ++ nat2lsb (n `div` 2)
            else [True] ++ nat2lsb (n `div` 2)

msb2nat :: [Bool] -> Integer
msb2nat (a : x) = if a == True then 2 ^ length x + msb2nat x
                  else msb2nat x
msb2nat [] = 0

nat2msb :: Integer -> [Bool]
nat2msb 0 = [False]
nat2msb 1 = [True]
nat2msb n = if n `mod` 2 == 0 then nat2msb (n `div` 2) ++ [False]
            else nat2msb (n `div` 2) ++ [True]
