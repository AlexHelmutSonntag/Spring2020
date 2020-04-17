module firstmidterm
import StdEnv

/*
Grade 2: Please write a function, where given an Int 'n', you return the nth Fibonacci number.
Grade 3: Make a list of infinite Fibonacci numbers.
Grade 4: Make a list only containing only Fibonacci numbers generated from prime integers. 
Grade 5: Take from the list of primes indexed Fibonacci list
the Fibonacci numbers that are less than an Int x.
INFO: A Fibonacci number is calculated from a sequence start with 1 and 1, and each 
successive number is the sum of the previous two numbers.
A prime number is a number that has no divisors except 1 and itself.
*/

Fib :: Int -> Int
Fib n 
| n <= 0 = abort "invalid"
= fibAux n 0 1

fibAux :: Int Int Int -> Int
fibAux 1 a b = b
fibAux n a b = fibAux (n-1) b (a+b)


//Start = Fib 5 //5
//Start = Fib 8 //21
//Start = Fib 20 //6765

FibList :: [Int]
FibList = [ Fib i \\ i<-[1..]]

//Start = take 10 FibList //[1,1,2,3,5,8,13,21,34,55]
//Start = drop 10 (take 20 FibList) //[89,144,233,377,610,987,1597,2584,4181,6765]


isPrime :: Int -> Bool
isPrime x = and[x rem n <> 0 \\ n<-[2..(x-1)]]

//Start = isPrime 4

PrimeFibList :: [Int]
PrimeFibList = [Fib i \\i<- [1..] | isPrime i]

//Start = take 10 PrimeFibList //[1,1,2,5,13,89,233,1597,4181,28657]

crazyFibList :: Int -> [Int]
crazyFibList n = takeWhile (\x= x < n) PrimeFibList

//Start = crazyFibList 100 //[1,1,2,5,13,89]
//Start = crazyFibList 9001 //[1,1,2,5,13,89,233,1597,4181]
