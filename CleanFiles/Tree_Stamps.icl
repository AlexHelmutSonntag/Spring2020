module Tree_Stamps
import StdEnv



:: Tree a = Node a (Tree a) (Tree a) | Leaf

atree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 3 Leaf Leaf)(Node 7 Leaf Leaf))

btree = Node 4 (Node 2 (Node 1 Leaf Leaf)(Node 3 Leaf Leaf)) (Node 6 (Node 5 Leaf Leaf)(Node 7 Leaf Leaf))

ctree =  Node 4 (Node 2 (Node 8 Leaf Leaf)(Node 9 (Node 4 (Node 16 Leaf Leaf) Leaf) Leaf)) (Node 7 (Node 3 Leaf Leaf)(Node 2 Leaf Leaf))

ourTree :: (Tree Int)
ourTree = Node 15(Node 3(Node 1 Leaf Leaf)(Node 10(Node 7 Leaf (Node 8 Leaf Leaf))(Node 13 (Node 11 Leaf Leaf) Leaf)))(Node 20 (Node 18 Leaf (Node 19 Leaf Leaf)) (Node 21 Leaf (Node 26 (Node 24 Leaf Leaf) (Node 28 Leaf Leaf))))




getNode :: (Tree a) -> a
getNode (Node x l r) = x


isLeaf :: (Tree a) -> Bool
isLeaf Leaf = True
isLeaf _ = False

/*This func gets the depth of a each node and puts it into a tuple and then sorts them into a list*/
DepTree:: (Tree a ) -> [(a,Int)] | Eq, Ord a 
DepTree x = sort (removeDup(Depaux x 0 ))

Depaux :: (Tree a) Int -> [(a,Int)]
Depaux Leaf _ = []
Depaux (Node x l r) depth =  Depaux l (depth+1) ++  [(x,depth)] ++Depaux r (depth+1)

// Start = DepTree atree//[(1,2),(2,1),(3,2),(4,0),(3,2),(6,1),(7,2)]
// Start = DepTree btree // [(1,2),(2,1),(3,2),(4,0),(5,2),(6,1),(7,2)]
// Start = DepTree ctree//[(2,1),(2,2),(3,2),(4,0),(4,3),(7,1),(8,2),(9,2),(16,4)]

/*This func finds the level between max node and min node*/

DiffDepth :: (Tree Int) -> Int
DiffDepth x = (snd (hd (reverse(DepTree x))) ) - (snd (last(reverse(DepTree x))))

// Start = DiffDepth ctree//3


smallTree :: Tree Int
smallTree = Node 8 (Node 6 (Node 5 Leaf Leaf)(Node 7 Leaf Leaf)) (Node 12 (Node 11 Leaf Leaf) (Node 14 (Node 13 Leaf Leaf) (Node 15 Leaf Leaf)))



DivideTree :: (Tree a) -> [(Tree a)] | Eq, Ord a 
DivideTree Leaf = []
DivideTree (Node x l r) = [l] ++ [r]

// Start = DivideTree smallTree

getSubTrees :: (Tree a) -> [(Tree a)]
getSubTrees (Node x l r) = [l,r]

// Start = getSubTrees smallTree
//There's sth wrong with this
// getSubTrees1 :: (Tree a) -> [(Tree a)]
// getSubTrees1 Leaf = []
// getSubTrees1 (Node x l r) = (getSubTrees1 l) ++ [l] ++ [r] ++ (getSubTrees1 r)
// Start = getSubTrees1 smallTree


MinTree :: (Tree a) -> a | Eq, Ord a
MinTree (Node x Leaf _) = x
MinTree (Node x l r) = MinTree l

maxTree :: (Tree a) -> a | Eq , Ord a
maxTree t = MinTree(reverseTree t)

// Start = MinTree smallTree //  5
reverseTree :: (Tree a) -> (Tree a)
reverseTree Leaf = Leaf
reverseTree (Node x l r) = (Node x (reverseTree r) (reverseTree l))

// Start = reverseTree smallTree
// Start = smallTree


ListoKids :: a (Tree a) -> [Tree a] | Eq, Ord a 
ListoKids n Leaf = []
ListoKids n (Node x l r)
| n == x =  [l] ++ [r]
| n < x = ListoKids n l
| n > x = ListoKids n r 

// Start = ListoKids 14 smallTree

TreetoList :: (Tree a ) -> [a]
TreetoList Leaf = []
TreetoList (Node x l r) = TreetoList l ++ [x] ++ TreetoList r

// Start = TreetoList smallTree

isNodeInTree :: a (Tree a) -> Bool | Eq a
isNodeInTree n t = isMember n (TreetoList t)

ListtoTree ::  [a] -> (Tree a) | Eq, Ord a
ListtoTree [] = Leaf
ListtoTree list =  (Node (hd sortedlist) Leaf (ListtoTree(tl sortedlist))) 
where
    sortedlist = removeDup (sort list)

// Start = ListtoTree [4,2,6,5,23,7]
//Create a level balanced Binary search tree from a list
levelBalance :: [Int] -> (Tree Int)
levelBalance [] = Leaf
levelBalance list = (Node midNode (levelBalance leftList) (levelBalance rightList))
where 
    sortedList = sort (removeDup list)
    len = length sortedList
    midNode = sortedList!!(len/2)
    leftList = take (len/2) sortedList
    rightList = drop ((len/2) + 1) sortedList

// Start = levelBalance [5,2,4,9,6,8,7,1,3]

