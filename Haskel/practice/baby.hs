doubleMe x = x + x
doubleUs x y = doubleMe x + doubleMe y
myabs x = if x >= 0 then x else -x
tri x = x*3
minus x = -x
factorial :: Integer -> Integer
factorial n = if n == 0 then 1 else n * factorial(n-1)
mygcd :: Integer -> Integer -> Integer
mygcd m n = if m == n then m
            else if m > n then mygcd (m-n) n
                 else mygcd (n-m) m
myproduct :: [Integer] -> Integer
myproduct [] = 1
myproduct (a : x) = a * myproduct x

mynth :: [a] -> Integer -> a 
-- mynth [] n = error "nothing"
mynth (a : x) 0 = a
mynth (a : x) n = mynth x (n-1)

msb2nat :: [Bool] -> Integer
msb2nat [] = 0
msb2nat (a : x) = if a == True then 2 ^ length x + msb2nat x
                  else msb2nat x

lsb2nat :: [Bool] -> Integer
lsb2nat [] = 0
lsb2nat (a : x) = if a == True then lsb2nat x * 2 + 1
                  else lsb2nat x * 2
                       
nat2lsb :: Integer -> [Bool]
nat2lsb n = if n == 0 then [False]
            else if n == 1 then [True]
            else if n `mod` 2 == 0 then [False] ++ nat2lsb (n `div` 2)
            else [True] ++ nat2lsb (n `div` 2)

nat2msb :: Integer -> [Bool]
nat2msb n = reverse (nat2lsb n)

nat2msb_2 :: Integer -> [Bool]
nat2msb_2 n = if n == 0 then [False]
              else if n == 1 then [True]
                   else if n `mod` 2 == 0 then nat2msb_2 (n `div` 2) ++ [False]
                        else nat2msb_2 (n `div` 2) ++ [True]

