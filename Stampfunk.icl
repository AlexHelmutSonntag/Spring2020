module Stampfunk
import StdEnv

//Prime

isPrime :: Int -> Bool
isPrime x = and[x rem n <> 0\\n<- [2..(x-1)]]


//fib generator

fib :: Int -> Int
fib n
| n <= 0 = abort "invalid"
= fibAux n 1 1

fibAux :: Int Int Int -> Int
fibAux 1 a b = b
fibAux n a b = fibAux (n-1) b (a+b)
 


// this generates an infinite list of fibonacci numbers
fiblist ::  [Int]
fiblist = [fib i\\ i<-[1..]]

//Start = fiblist


//Factorial

Factorial :: Int -> Int
Factorial n = foldr (*) 1 [1..n]
//Factorial n = prod[1..n]  // could be also this.
//Start = Factorial 5

//Start = foldr (\newElement list = [newElement*2] ++ list) [] [1..10]
//Start = (\n= [2..(n-1)]) 8 // creates a list from 2..7


Decimalpart :: Real -> Real
Decimalpart n = n - toReal (RoundD n)

Start = Decimalpart 4.328438538// 0.328438538

RoundD :: Real -> Int
RoundD x
|toReal (toInt x) > x = (toInt x) - 1 
|otherwise = (toInt x)

//Start = Decimalpart 12.5 //0.5
//Sorting

//qsort 

qsort :: [a] -> [a] | Ord a
qsort [] =[]
qsort [c] = [c]
qsort [c:xs] = qsort [x\\ x <-xs | x < c ] ++ [c] ++ qsort [x\\ x<-xs | x >= c]

//Start = qsort [4,3,5,6,74,2]//[2,3,4,5,6,74]

//merge

merge :: [a] [a] -> [a] | Ord a
merge [] ys = ys
merge xs [] = xs
merge [x:xs] [y:ys]
| x <= y = [x: merge xs [y:ys]]
|otherwise = [y: merge ys [x:xs]]

//Start = merge [1,2,3,4] [5,6,7,8]

//msort
msort :: [a] -> [a] | Ord a 
msort xs
| len <= 1 = xs
| otherwise = merge (msort ys) (msort zs)

where
    ys = take half xs
    zs = drop half xs
    half = len / 2
    len = length xs

//Start = msort [2,9,5,1,3,8]//[1,2,3,5,8,9]
