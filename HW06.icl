module HW06
import StdEnv

//1st Task

Food :: [(String,String)] -> [String]
Food list = removeDup [fruit\\(name,fruit)<-list]

People :: Int [(String,String)]-> [[String]]
People x list
|x == (length (Food list)) =[]
= [[name \\ (name,fruit)<- list | (Food list) !!x == fruit]] ++ People (x+1) list

combine :: [String] [[String]] -> [(String,[String])]
combine lista listb =[(x,y)\\x<-lista & y<-listb]

FavFood :: [(String,String)] -> [(String,[String])]
FavFood list = combine (Food list) (People 0 list)

//Start = FavFood [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "apple")]//[("apple",["Zuka","Ahmed"]),("orange",["Beka"]),("pineapple",["Emad"])]


//2nd Task

findYounger :: [(String,Int,String)]->[String]
findYounger x = [fst3(hd(dude x ))] ++ [fst3 (hd (gal x))]

dude:: [(String,Int,String)]-> [(String,Int,String)]
dude list = sortBy (\x y =snd3 x < snd3 y) [a\\a<-list| thd3 a == "male"]

gal :: [(String,Int,String)]-> [(String, Int,String)]
gal list = sortBy (\x y = snd3 x < snd3 y) [a\\a<-list | thd3 a=="female"]

//Start = findYounger [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")]//["Hossam","Nani"]
//Start = findYounger [("Hossam", 19, "male"), ("Evan", 17, "male"), ("Tringa", 18, "female")]//["Evan","Tringa"]

//3rd Task

isTriangularNum :: Int-> (Bool,Int)
isTriangularNum x 
|x <= 0 = (False, -1)
= Traux x 0 1
Traux:: Int Int Int -> (Bool,Int)
Traux x a b
|x == a = (True, b - 1)
|x > a = Traux x (a+b) (b+1)
=(False,-1)

//Start = isTriangularNum -1//(False,-1)
//Start = isTriangularNum 10 // (True,4)
Start = isTriangularNum 666 // (True,36)
