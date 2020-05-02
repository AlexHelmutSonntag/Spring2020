module HW03
import StdEnv




//List splitter-----------------------------------------------------


Split :: [Int] -> [[Int]]
Split x = [[a \\ a <- x | isOdd a ]] ++ [[ b \\ b <- x | isEven b ]]
Split [] = [[]]

//Start = Split [420]




//Prime Factors (+VE)-----------------------------------------------


CheckDiv :: Int Int -> Bool
CheckDiv a b = b rem a <>0

Checkpos :: Int Int -> Bool

Checkpos acc 0 = False
Checkpos acc 1 = False
Checkpos acc 2 = True
Checkpos acc x
|acc == x-1 = True
=CheckDiv (acc) (x) && Checkpos (acc+1) (x)


Factors :: Int -> [Int]
Factors s = [x \\ x <- [2..(s)] | s rem x == 0 && Checkpos 2 x ]



Start = Factors 10




//LCM---------------------------------------------



lcm :: [Int] -> Int
lcm [] = 0
lcm [x] = x 
lcm [x,y] = x*y/gcd x y
lcm [x:xs] = lcm [x, lcm xs]

//Start = lcm [4,5,6]

// 2 4
