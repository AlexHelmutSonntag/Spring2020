module Tuples
import StdEnv

//17.04.2020 "TUPLES"

/* Tuples are way to put things together easily */

list1= [1124,12412,6757]
list2 = ["James","Jack","John"]
//List must be of same type

james :: (String,Int) 
james = ("james",1124)

//Start = fst james // "James" this grabs the first record but only if it's a two-record tuple
//Start = snd james // 1124 


//Start = fst ("James",1124,True)// fails because fst demands a tuple of 2 elements, not of more

//Start = fst3 ("James",1124,True)// "James" 
//Start = snd3 ("James",1124,True)// 1124
//Start = thd3 ("James",1124,True)// True 


//Start = fourth("James",1124,True,'a')//undefined. we only have fns to extract elements of tuples of 2 or 3 elements.
// with more than 3 we have to use pattern matching
//Singleton tuples don't exist 

func1 :: Int Int -> (Int,Int)
func1 x y = (x,y)

//Start = func1 2 3 // (2,3)

//Start = [(a,b) \\ a<-[1..7] ,b<-[1..7] |  a+b==7 ] //[(1,6),(2,5),(3,4),(4,3),(5,2),(6,1)] all pairs that add up to 7
//Start = [(a,b) \\ a<-[1..7] ,b<-[a..7] |  a+b==7 ] // [(1,6),(2,5),(3,4)] to eliminate duplicates we only get b starting from a.

func2 :: Int -> [(Int,Int)]
func2 n = [(a,b) \\ a<-[1..n] ,b<-[a..n] |  a+b==n ] //

//Start = func2 7 //[(1,6),(2,5),(3,4)]
//Start = func2 20 //[(1,19),(2,18),(3,17),(4,16),(5,15),(6,14),(7,13),(8,12),(9,11),(10,10)]

func3 :: Int -> [(Int,Int,Int)]
func3 n = [(a,b,b-a) \\ a<-[1..n] ,b<-[a..n] |  a+b==n ] //
//Start = func3 15 // [(1,14,13),(2,13,11),(3,12,9),(4,11,7),(5,10,5),(6,9,3),(7,8,1)]

func4 :: Int -> [(Int,Int,Int,Bool)]
func4 n = [(a,b,b-a,isEven a && isEven b) \\ a<-[1..n] ,b<-[a..n] |  a+b==n ]

//Start = func4 16// [(1,15,14,False),(2,14,12,True),(3,13,10,False),(4,12,8,True),(5,11,6,False),(6,10,4,True),(7,9,2,False),(8,8,0,True)]

//dictionary/map/key pairings a concept of tuples implemented for generally json and other uses in the workfield 
//Bank is just a list here.
Bank :: [(String,Int)]
Bank = [("John",467),("Jim",0),("Jack",90000),("Evan",-21000)]

lookUp :: String [(String,Int)] -> Int
//lookUp name accountsList =  snd (hd [account \\ account<-accountsList | fst account == name])

//after pattern matching
lookUp name accountsList =  hd [accountBalance \\ (accountName,accountBalance)<-accountsList | accountName == name ]

//Start = lookUp "Evan" Bank // -21000 I wrote a function that given a list of accounts and the name, it prints me the balance of that account

lookUp1 :: String [(String,Int)] -> [Int]
lookUp1 name accountsList =  [accountBalance \\ (accountName,accountBalance)<-accountsList | accountName == name ]
//Start = lookUp1 "Evan" Bank// [-21000]

updateAccount :: [(String,Int)] -> [(String,Int,Bool)]
//updateAccount accountsList = [(fst account ,snd account,snd account> 0 ) \\account<-accountsList ]
//after pattern matching
updateAccount list = [(a,b,b> 0 ) \\ (a,b)<-list]

//Start = updateAccount Bank //[("John",467,True),("Jim",0,False),("Jack",90000,True),("Evan",-21000,False)] we updated it with a boolean.

stimulus :: [(String,Int,Bool)] -> [(String,Int,Bool)] 
//stimulus accountsList = map (\account | thd3 account == False = (fst3 account,(snd3 account)+1000,True) = account ) accountsList
//after pattern matching it still works
stimulus accountsList = map (\(a,b,c) | c== False = (a,b+1000,True) = (a,b,c)) accountsList

//Start = stimulus (updateAccount Bank) // [("John",467,True),("Jim",1000,True),("Jack",90000,True),("Evan",-20000,True)]

/*
ask a server for a status on an ip address  10.0.0.1

[10,0,0,1] :: [Int]

(10,0,0,1) :: [Int,Int,Int,Int] you basically forced it to enter only ints as elements of the tuple
(a,b,c,d)

((10,0,0,1),(True,"Node1",["John","James","Jack"]))
*/





