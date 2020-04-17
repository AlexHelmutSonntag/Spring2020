module Aly

import StdEnv


func1 :: Int Int -> Int
func1 x y 
| func2 x y = y
= x

func2 :: Int Int -> Bool
func2 x y = x*2 > y

//Start = func2 2 3 // true 
//Start = func1 2 3 // 3 
//Start = (func1 3 2) + (func1 4 7)//9

func3 :: Int Int -> Bool
func3 a b = (func1 a b) < (func1 b a) 

//Start = func3 5 6 // false
func4 :: Int Int -> Int
func4 a 0 = a 
func4 a b = (func4 (a+1) (b-1))

//Start = func4 6 5// takes value from b and adds it to a till b =0 then prints a


filter1 :: [Int] -> [Int]
filter1 list = [hd list] ++ [hd(tl list)]

filtereveryother :: [Int] -> [Int]
filtereveryother list 
| length list < 3 = [hd list]
= [hd list] ++ filtereveryother (drop 2 list)

//Start = filtereveryother [1,2,3,4,5]//[1,3,5]

roundD :: Real -> Int
roundD x 
| toReal (toInt x) > x =  (toInt x) - 1 
= toInt x

Decimal :: Real -> Real
Decimal x = x - toReal (roundD x)

//Start = Decimal 12.543//0.542999999999999


feoAux :: [Int] Int -> [Int] 
feoAux list i
| i >= length list = []
| isEven i = [list!!i] ++ (feoAux list (i+1))
= (feoAux list (i+1))

//Start = feoAux [1,2,3,4,5,6,7,8] 1// [3,5,7]
function:: [Int] -> [Int]
function list = [list!!i\\ i<-[0,2..(length list)]]
//Start = function [3,6,3,7,8] // [3,3,8]




//Generate a list of the first n "prime index" of fibonacci numbers
/* [1,1,2,3,4,5,13,..]
*/

isPrime :: Int -> Bool
isPrime x = and[x rem n <> 0\\n<- [2..(x-1)]]

//Start = isPrime 5//True

fib :: Int -> Int
fib n
| n <= 0 = abort "invalid"
= fibAux n 1 1

fibAux :: Int Int Int -> Int
fibAux 1 a b = b
fibAux n a b = fibAux (n-1) b (a+b)
 

fiblist ::  [Int]
fiblist = take 10 [fib i\\ i<-[1..]]

//Start = fiblist//[1,2,3,5,8,13,21,34,55,89]
primefiblist :: [Int]
primefiblist = [fib i\\i<-[1..]| isPrime i]

//Start = take 10 primefiblist// [1,2,3,8,21,144,377,2584,6765,46368]


finalFunk :: Int -> [Int]
finalFunk n = takeWhile (\x = x < n) primefiblist

//Start = finalFunk 1000




qsort :: [a] -> [a] | Ord a 
qsort [] =[]
qsort [c] = [c]
qsort [c:xs] = qsort [x\\ x <-xs | x < c ] ++ [c] ++ qsort [x\\ x<-xs | x >= c]

//Start = qsort [4,3,5,6,74,2]


merge :: [a] [a] -> [a] | Ord a
merge [] ys = ys
merge xs [] = xs
merge [x:xs] [y:ys]
| x <= y = [x: merge xs [y:ys]]
|otherwise = [y: merge ys [x:xs]]

//Start = merge [1,2,3,4] [5,6,7,8]


msort :: [a] -> [a] | Ord a 
msort xs
| len <= 1 = xs
| otherwise = merge (msort ys) (msort zs)

where
    ys = take half xs
    zs = drop half xs
    half = len / 2
    len = length xs

//Start = msort [2,9,5,1,3,8]


//Start = foldr (\newElement list = [newElement*2] ++ list) [] [1..10]



f:: [Int] [Int] -> [(Int,Int)]
f a b = [(x,y) \\ x <- a, y <- b | x > y]

//Start= f [1,7,3] [8,4,2,5]

mySort :: [Int] -> [Int]
mySort [] = []
mySort [x:xs] = left ++ [x] ++ right
where
    left = mySort [y \\ y <- xs | y > x]
    right = mySort [y \\ y <- xs | y < x]

//Start = mySort [2,3,2,1,4,3,3,5]



Bank :: [(String,Int)]
Bank = [("John",467),("Jim",0),("Jack",900000001),("Evan",-384859493)]
 
lookUp :: String [(String,Int)] -> Int
//lookUp name accountsList = snd(hd[  account \\ account<-accountsList | fst account == name ])
lookUp name accountsList = hd[ accountBalance \\  ( accountName, accountBalance) <- accountsList | accountName == name]
 
//Start = lookUp "Evan" Bank
 
updateAccount :: [ ( String, Int) ] -> [ ( String, Int, Bool) ]
//updateAccount accountsList = [ ( fst account, snd account, snd account > 0 ) \\  account<-accountsList ]
updateAccount l = [(a,b,b>0)\\(a,b)<-l]
 
//Start = updateAccount Bank //[("John",467,True),("Jim",0,False),("Jack",900000001,True),("Evan",-384859493,False)]
 
stimulus :: [ ( String, Int, Bool ) ] -> [ ( String, Int, Bool ) ]
//stimulus accountsList = map (\account | thd3 account == False = (fst3 account, (snd3 account)+1000, True ) = account  ) accountsList
stimulus accountsList = map (\( a, b, c) | c == False = (a, b+1000, True ) = (a,b,c)  ) accountsList
 
//Start = stimulus (updateAccount Bank)
