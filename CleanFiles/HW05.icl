module HW05
import StdEnv

//1st Task

f1 :: Int
f1 = foldr (+) 0 [x*x\\x<-[1..100] | isOdd x ]

//Start = f1//166650

//2nd Task

sublist1 :: Int [Int] -> [[Int]]
sublist1 n [] = []
sublist1 n [x:xs] 
|(length [x:xs]) == n = [take n [x:xs]]
= [take n [x:xs] : sublist1 n xs]

//Start = sublist1 3 [1,2,3,4]  //[[1,2,3],[2,3,4]]

sublist2 :: [Int] Int -> [[Int]]
sublist2 list 0 = []
sublist2 x n = sublist1 n x ++ sublist2 x (n-1)

insgesamt list = sublist2 list (length list)

removeDup :: [Int] -> [Int]
removeDup [] = []
removeDup [x:xs]
|isMember x xs = removeDup xs
= [x : removeDup xs]

f2 :: [Int] -> Int
f2 list = length (removeDup (map sum (insgesamt list)))
//[1], [2], [1,2], [3], [2,3], [1,2,3], [4], [3,4], [2,3,4], [1,2,3,4]

//Start = f2 [1,-3,2,-4,-3,1,7,6,2,8,9]// 34
//----------------------------------------------------
//3rd Task



f3 :: [Int] -> [Int]
f3 [] = []
f3 list = longestRight
where
	insgesamt = sublist2 list (length list)  
	noRep = [ n \\ n <- insgesamt | (not o isDup) n ]
	longestRight = last [ n \\ n <- noRep |length (hd noRep) == length n]

isDup :: [Int] -> Bool
isDup [] = False
isDup [x:xs] = isMember x xs || isDup xs

//Start = f3 [1,1,2,4,5,3,2,6,3]// [4,5,3,2,6]
