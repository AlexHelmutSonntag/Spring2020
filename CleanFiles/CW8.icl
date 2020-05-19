module CW8
import StdEnv

/*
1. Given a tree and an integer n, find the nodes equal to n and replace by '0'
*/

:: Tree a = Node a (Tree a) (Tree a) | Leaf

atree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 3 Leaf Leaf)(Node 7 Leaf Leaf))

f1 :: Int (Tree Int) -> (Tree Int)
f1 n Leaf = Leaf
f1 n (Node x l r)
| n == x = Node 0 (f1 n l) (f1 n r)
= Node x (f1 n l) (f1 n r)

// Start = f1 3 atree////(Node 4 (Node 2 (Node 1 Leaf Leaf) (Node 0 Leaf Leaf)) (Node 6 (Node 0 Leaf Leaf) (Node 7 Leaf Leaf)))

/*
2. Given a tree, find the level between max node and min node
*/
btree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 5 Leaf Leaf)(Node 7 Leaf Leaf))

ctree =  Node 4 (Node 2 (Node 8 Leaf Leaf)(Node 9 (Node 4 (Node 16 Leaf Leaf) Leaf) Leaf)) (Node 7 (Node 3 Leaf Leaf)(Node 2 Leaf Leaf))

DepthTree :: (Tree a) -> [(a,Int)] | Eq, Ord a
DepthTree x = reverse (sort (removeDup(Dt2 x 0 [])))

Dt2 :: (Tree a) Int [(a,Int)] -> [(a,Int)]
Dt2 Leaf _ acc = []
Dt2 (Node x l r) depth acc = (Dt2 l (depth + 1) acc) ++ [(x,depth)]++(Dt2 r (depth + 1) acc)


f2 :: (Tree Int) -> Int
f2 x = (snd (hd (DepthTree x)) ) - (snd (last(DepthTree x)))


// Start = f2 ctree //3
// Start = f2 btree // 0

/*
3. 
Define algebraic type : Day (Mon,Tue,Wed,Thu,Fri,Sat,Sun).
And define function IsWeekend :: Day -> Bool to check if it is Sat or Sun.
if it is weekend, then output "Happy day!",Otherwise,"Oh my god"
*/


:: Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun

instance == Day
where
    (==) Sun Sun = True
    (==) Sun _ = False
    (==) _ Sun = False
    (==) Sat Sat = True
    (==) Sat _ = False
    (==) _ Sat = False

f3 :: Day -> String
f3 x
| x == Sat|| x == Sun = "Happy day!"
= "Oh my god" 



// Start = f3 Sun  // "Happy day!"
// Start = f3 Tue  // "Oh my god"


