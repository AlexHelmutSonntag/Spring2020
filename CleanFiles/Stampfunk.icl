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


// Start = Negative -12.552// 0.5

//Start = Decimalpart 12.5 //0.5

//Converting a number into a list

Numlist :: Int -> [Int]
Numlist 0 = []
Numlist x =  Numlist (x / 10) ++ [x rem 10] 

//Start = Numlist 54321 // [5,4,3,2,1]
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

/*---------------------------------------*/
//Instances 


instance + (a,b) | + a & + b
where
    (+) (x1,y1) (x2,y2) = (x1+x2, y1+y2)


// Start  = (1,2) + (1,2)

instance - (a,b) | - a & - b
where
    (-) (x1,y1) (x2,y2) = (x1-x2, y1-y2)

// Start = (1,2) - (1,1)

instance * (a,b) | * a & * b
where
    (*) (x1,y1) (x2,y2) = (x1*x2, y1*y2)

// Start = (1,2) * (1,2)



instance / (a,b) | / a & / b
where
    (/) (x1,y1) (x2,y2) = (x1/x2, y1/y2)

// Start = (1,2) / (1,2)

// ==, < and > are predefined for tuples of 3

// Start  = (1,2,3) == (1,2,3)
// Start  = (1,2,3) < (1,2,4)

// + and - for tuples of 3
instance + (a,b,c) | + a & + b & + c
where
    (+) (x1,y1,z1) (x2,y2,z2) = (x1+x2, y1+y2,z1+z2)

// Start = (1,2,3) + (1,2,3)

instance - (a,b,c) | - a & - b & - c
where
    (-) (x1,y1,z1) (x2,y2,z2) = (x1-x2, y1-y2,z1-z2)

// Start = (1,2,4) - (1,2,3)


/* for Strings */

instance + String
where
    (+) s1 s2 = s1 +++ s2
// Start  = "Hello" + " Friend" //"Hello Friend"




/*--------------------------------*/
//Arrays 


isPal:: String -> Bool
isPal x = l == reverse l 
where
    l = [e\\e<-:x]
    

palArr :: {String} -> {String}
palArr myArr = {elem\\elem <-: myArr | isPal elem }



reverseString :: String -> String
reverseString x = result
where
    list = [ a\\a<-:x ]
    m = reverse list
    result = {a\\a<-m}
    

MyArray :: {Int}
MyArray = {1,3,5,7,9}

MapArrays :: (a->b) {a} -> {b} 
MapArrays f a = {f e \\ e<-:a}

// Start = MapArrays (\x=x*2) {1,2,3,4}
// Start = MapArrays inc MyArray // {2,4,6,8,10}



/*---------------------------------------------------*/
//Records



:: Person = { name :: String, 
           birthdate :: (Int,Int,Int), 
           fpprogrammer :: Bool}


ChangeName :: Person String -> Person
ChangeName p=:{ name = n} s = {p&name = n+++s}

// Start = ChangeName {name = "XY" ,birthdate= (1,1,2000), fpprogrammer = True } "Alex"


:: Date = { year :: Int,  month :: Int, day :: Int}

date1 = {year = 2000, month=1, day=3}
date2 = {year = 2001, month=1, day=4}
date3 = {year = 2001, month=2, day=3}
date4 = {year = 2001, month=2, day=4}

instance == Date
where
    (==) { day = d1, month = m1, year = y1}{ day = d2, month = m2, year = y2} = and[d1==d2,m1==m2,y1==y2]

// Start = isMember daya listodays // True

instance < Date
where
    (<){ day = d1, month = m1, year = y1}{ day = d2, month = m2, year = y2} = or[y1<y2,y1==y2&&m1<m2,y1==y2&&m1==m2&&d1<d2]
//Now we can sort the list of dates due to having the < instance 

// Start = date2 < date3


instance toString Date
where
    toString {year=y, month=m, day=d} = "Year=" +++ toString y +++ " Month=" +++ toString m +++ " Day=" +++ toString d


// Start = toString date3//"Year=2001 Month=2 Day=3"
:: Tree a = Node a (Tree a) (Tree a) | Leaf

dateTree2 = Node date3 (Node date1 Leaf (Node date2 Leaf Leaf)) (Node date4 Leaf Leaf)


earliestDate :: (Tree Date) -> String
earliestDate (Node x Leaf _) = toString x
earliestDate (Node _ l _) = earliestDate l 

// Start = earliestDate dateTree2 // "Year=2000 Month=1 Day=3"


:: Q = {nom :: Int, den :: Int}

simplify :: Q -> Q
simplify {nom=n,den=d}
| d == 0 = abort "denominator is 0"
| d < 0 =  {nom = ~n/g , den = ~d/g}
| otherwise = {nom = n/g , den = d/g}
where
	g = gcmd n d 

gcmd:: Int Int -> Int 
gcmd x y = gcdnat (abs x) (abs y)
where
	gcdnat x 0 = x 
	gcdnat x y = gcdnat y (x rem y)


mkQ :: Int Int -> Q 
mkQ n d = simplify {nom=n,den = d}

// Start = mkQ 36 -4
instance / Q 
where
    (/) x y = simplify{nom=x.nom *y.den, den =x.den* y.nom}

fracDivision :: Q Q -> Q
fracDivision a b = a/b

// Start = {nom=5, den=1} / {nom=6, den=5}
// Start = fracDivision {nom=10, den=2} {nom=3, den=4} //(Q 20 3)
// Start = fracDivision {nom=0, den=2} {nom=100, den=4} //{nom=0, den=1}
// Start = fracDivision {nom=15, den=2} {nom=3, den=12} //{nom=30, den=1}

instance + Q 
where
    (+) {nom =n1,den = d1} {nom = n2, den = d2} = {nom = n1*d2+ n2*d1, den = d1*d2}

// Start = fourth + fifth// (Q 9 20)

instance zero Q
where
    zero = {nom = 0,den = 1}



sumTree :: (Tree Q )-> Q
sumTree Leaf = zero
sumTree (Node x l r) = sumTree l + x + sumTree r


instance == Q 
where
    (==) {nom =n1,den = d1} {nom = n2, den = d2} = n1*d2==n2*d1

instance < Q 
where
    (<) {nom =n1,den = d1} {nom = n2, den = d2} = n1*d2 <n2*d1 

checkTree :: (Tree Q) -> Bool
checkTree t = l == sort l
where
    l = TreetoList t


TreetoList :: (Tree a ) -> [a]
TreetoList Leaf = []
TreetoList (Node x l r) = TreetoList l ++ [x] ++ TreetoList r

/*Common questions for records*/


Gpa :: Student -> Real
Gpa {grades=g} = Average
where
    list = [e\\e<-:g]
    Average = (toReal(sum list)) / (toReal (length list)) 


UniGpa :: University -> [Real]
UniGpa {students = list} = map Gpa list



bettershorterThan6::University->{String}
bettershorterThan6 uni = {c\\c<-list}
where
	list=[x.studentName\\x<-uni.students | size (x.studentName)<6] ++ [x.tname\\x<-uni.teachers | size(x.tname)<6]

f7 :: {Int} -> Bool
f7 x = result
where
    toList :: {Int}->[Int]
    toList a = [ z \\ z <-: a ]
    checkOnePlz :: Int [Int] -> Bool
    checkOnePlz x list = length(filter ((==) x) list) >= 2
    result = and(map (\elem = checkOnePlz elem listarr) listarr)
    where
        listarr = toList x




instance toString Teacher
where
    toString teacher = teacher.tname

instance toString Student
where
    toString student = student.studentName +++ " " +++ toString (Gpa student) +++ " " +++  toString student.favoriteTeacher
