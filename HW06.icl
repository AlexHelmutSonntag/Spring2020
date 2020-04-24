module HW06
import StdEnv


/* Task 1
Given a list of pairs of name of the person and his/her favourite food.
Make function which returns list of pairs of food and a list of people who likes it.
Note : order doesn't matter

// Start = favFood [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "apple")] // [("apple", ["Zuka", "Ahmed"]),("orange",["Beka"]),("pineapple",["Emad"])]
// Start = favFood [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "pineapple")] // [("apple", ["Zuka"]),("orange",["Beka"]),("pineapple",["Emad","Ahmed"])]
*/



Food :: [(String,String)] -> [String]//generated a list of fruits only 
Food list = removeDup [b\\(a,b)<-list]

People :: Int [(String,String)]-> [[String]]// generated a list of people who share the same fav fruit. we iterated from x=0 up to the length of the array "list" using for loop concept where u check the 1st element of array whether it fits the element inside the tuple and if it it's correct, you take that name from the tuple and store it into a list. if you have two names, it adds them in a sub list as you can see using the [[list comprehension]] 
People x list
|x == (length (Food list)) = []
= [[name\\(name,fruit)<-list | (Food list) !!x == fruit ]] ++ People (x+1) list

combine:: [String] [[String]] -> [(String,[String])]//this one basically combined both of them. 
combine list1 list2 = [(x,y)\\x<-list1 & y<-list2]

favFood :: [(String,String)] -> [(String,[String])]//this is the one that got called where the list was used as both lists for combine
favFood list = combine (Food list) (People 0 list)

//Start = favFood [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "apple")]//[("apple",["Zuka","Ahmed"]),("orange",["Beka"]),("pineapple",["Emad"])]
//Start = People 0 [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "apple")] //[["Zuka","Ahmed"],["Beka"],["Emad"]]
//Start = Food [("Zuka", "apple"), ("Beka", "orange"), ("Emad", "pineapple"), ("Ahmed", "apple")]//["apple","orange","pineapple"]






/*Task 2 

Having a list of tuples, each tuple represent a person in that form (name, age, gender)
Write a function to produce a list of two elements, the youngest man's name and the youngest woman's name
i.e : [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")] -> ["Hossam", "Nani"]
Note : You can assume that the input for the gender will be "male", "female".

// Start = findYounger [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")] // ["Hossam", "Nani"]
// Start = findYounger [("Hossam", 19, "male"), ("Evan", 17, "male"), ("Tringa", 18, "female")] // ["Evan", "Tringa"]
// Start = findYounger [("Hossam", 21, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 18, "female")] // ["Hossam", "Tringa"]
*/


isGirl :: [(String,Int,String)] -> [(String,Int,String)] //separated only females and sorted them
isGirl list = sortBy (\x y = snd3 x < snd3 y) [a\\a<-list | thd3 a == "female"]

//Start = isGirl [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")]// [("Nani",17,"female"),("Tringa",18,"female")]

isGuy :: [(String,Int,String)] -> [(String,Int,String)]//separated only males and sorted them
isGuy list = sortBy (\x y = snd3 x < snd3 y ) [a\\a<-list | thd3 a == "male"]

//Start = isGuy [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")] // [("Hossam",19,"male"),("Nikola",21,"male")]
findYounger :: [(String,Int,String)] -> [String] //basically added only the first tuple of the head of each list together.
findYounger list = [fst3 (hd(isGuy list))] ++ [fst3(hd(isGirl list))]

//Start = findYounger [("Hossam", 19, "male"), ("Nikola", 21, "male"), ("Tringa", 18, "female"), ("Nani", 17, "female")]//["Hossam","Nani"]



/*
        Task3
Decide if a number is triangular number and write the count of levels of triangle. 
Triangular number is a number that can form a triangle.
The output should be in a tuple.
Note : if it is false the count should be -1. 
examples:

1       3         6          10          15              21
                                                         *      
                                          *              * * 
                               *          * *            * * * 
                  *            * *        * * *          * * * *
        *         * *          * * *      * * * *        * * * * *
*       * *       * * *        * * * *    * * * * *      * * * * * * 
Note : 0 is not a triangular number
*/

// Start = isTringularNum -1 // (False,-1)
//Start = isTringularNum 0 // (False,-1)
// Start = isTringularNum 1 // (True,1)
// Start = isTringularNum 5 // (False,-1)
// Start = isTringularNum 10 // (True,4)
// Start = isTringularNum 666 // (True,36)
isTringularNum :: Int -> (Bool,Int)
isTringularNum x
| x <= 0 = (False,-1)
= Traux x 0 1 

Traux :: Int Int Int -> (Bool, Int)
Traux x a b
|x == a = (True, b - 1)
|x > a = Traux x (a+b)(b+1)
=(False,-1)



//Start = isTringularNum -1 // (False,-1)
//Start = isTringularNum 0 // (False,-1)
//Start = isTringularNum 1 // (True,1)
//Start = isTringularNum 5 // (False,-1)
//Start = isTringularNum 10 // (True,4)
//Start = isTringularNum 666 // (True,36)
