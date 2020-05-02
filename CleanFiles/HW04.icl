module HW04
import StdEnv

// For every sublist, eliminates its elements
// Until the current element is a prime number
// After that, multiply each number by 5
// And remove all elements that end with 0.
//I.e. divisible by 10.

//1st Task

isPrime :: Int -> Bool
isPrime 1 = False
isPrime x = and[x rem n <> 0 && x <> 1 \\ n <-[2..(x-1)]]

isnotDiv :: Int -> Bool
isnotDiv num = and[num rem 10 <> 0 ]

link :: [Int] -> [Int]
link x = filter isnotDiv (map (\x = x*5) (dropWhile (not o isPrime) x ))

sublist :: [[Int]] -> [[Int]]
sublist [] = []
sublist [x:xs] = [(link x) : sublist xs]

//Start = sublist [[1,2,3,4],[9,7,6,5,4,3,0],[3,5,7,9],[128,64,32]]

/////////////////////////////////
//2nd Task


ones :: [Int] -> [Int]
ones list = map (\x=1) list

f2 :: [Int] -> Int
f2 list = foldr (+) 0 (ones list)

Start = f2 [1,2,3] // 3
//Start = f2 [1] // 1
//Start = f2 (take 100 [1..]) // 100

/////////////////////////////

//3rd Task

f3 :: [Int] -> [Int]
f3 list = foldr (\x y = y ++ [x]) [] list


//Start = f3 [1,2,3,4,5,6,7,8] // [8,7,6,5,4,3,2,1]
//Start = f3 [] // []
//Start = f3 [1] // [1]



