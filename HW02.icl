module HW02
import StdEnv



*/
1st Task

Fibo :: [Int] -> [Int]
Fibo [x,y,n]

| x>n && y>n = []
| n == 0 = [0]
| n < 0 = [] 
= [x] ++ Fibo [y, x+y, n]

change :: Int -> [Int]
change n = Fibo [0,1,n]

Start = change -1


//2nd Task



prime :: Int -> Bool
prime 2 = True
prime 1 = False
prime 0 = False
prime -1 = False
prime -2 = True
prime n
|n > 0 = prpos 2 n
|n < 0 = prneg -2 n

prpos :: Int Int -> Bool
prpos i n 
| i == n-1 = True
= divisible (i) (n) && prpos (i+1) (n)

divisible :: Int Int -> Bool
divisible x y = y rem x <> 0 


prneg :: Int Int -> Bool
prneg i n
|i == n+1 = True
=divisible (i) (n) && prneg (i-10) (n) 


Start = prime 97

/*

// 3rd Task

NumtoSet :: Int -> [Int]
NumtoSet 0 = []
NumtoSet x = [x rem 10] ++ NumtoSet (x/10)

Pali :: Int -> Bool
Pali n = test (NumtoSet n)

test :: [Int] -> Bool
test num = num == reverse num 

Start = Pali -9823







