module Stampfunk
import StdEnv

//Prime

isPrime :: Int -> Bool
isPrime x = and[x rem n <> 0\\n<- [2..(x-1)]]


//primeFactors

primeFactors :: Int -> [Int]
primeFactors n = [n \\ x<-[2..n] | isPrime x && n rem x == 0]

Start = primeFactors 17




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

Negative :: Real -> Real
Negative x
| x < 0.0 = Decimalpart (abs x)
= Decimalpart x


Decimalpart :: Real -> Real
Decimalpart n = n - toReal (Round n)

//Start = Decimalpart 4.328438538// 0.328438538

Round :: Real -> Int
Round x
| x < 0.0  = Round (abs x)
|toReal (toInt x) > x = (toInt x) - 1 
|otherwise = (toInt x)


Start = Negative -12.5// 0.5

//Start = Decimalpart 12.5 //0.5

//Converting a number into a list

Numlist :: Int -> [Int]
Numlist 0 = []
Numlist x =  Numlist (x / 10) ++ [x rem 10] 

//Start = Numlist 54321 // [5,4,3,2,1]

// Real no. Negative checker.
isNegative :: Real -> Bool
isNegative x
| x < 0.0 = True
= False

// Real no. Positive checker.
isPositive :: Real -> Bool
isPositive x
| x >= 0.0 = True
= False

//Start = isPositive 5.0// True

// function that takes only positive numbers in a list.
TakePositive :: [Real] -> [Real]
TakePositive list = [i\\i<-list | isPositive i]

//Start = TakePositive [1.0,-1.0,2.3,-3.9] // [1.0,2.3]

// a function that does square root to a real no.
root :: Real -> Real
root x 
| x == 0.0 = 0.0
| x < 0.0 = abort "Invalid" 
= x^(1.0/2.0)

//Start = root 20.0//4.47213595499958

//A function that square roots all the positive real no.s in a list.

Square :: [Real] -> [Real]
Square list = map root a 
where
    a = (filter (\x = isPositive x ) list)


Start = Square [16.0,49.0,69.0,-120.0,1.0,-1.0,2.3,-3.9]//[1,1.51657508881031]



/*
-----------------------------------------------------------------------------------------------------------------------------
*/
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
