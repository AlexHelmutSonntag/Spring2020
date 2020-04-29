module Records
import StdEnv

/*Records are a way to hold different types of data in an organized fashion
Records are Structs in C btw.
*/
//This is raw and untamed, double check syntax because it was changed according to explaining the topic
myBirthday :: (Int, String,Int)
myBirthday=(2000,"April",01)
//Start = myBirthday //(2000,"April",1)
//Start = snd3 myBirthday// "April"
yourBirthday ::(String,Int,Int)
yourBirthday =("April",01,2000)

//Start = snd3 yourBirthday //01

::Date ={
            year :: Int ,
            month :: Month,
            day :: Int

        }
//declaring a variable that uses the struct with it's members
evanBDay :: Date
evanBDay = {year = 2000,month = Apr,day =1 }


//Start = evanBDay //(nameofrecord 2000 "April" 1)
//Start = evanBDay //(Date 2000 "April" 1)

//declaring a variable that uses the struct with it's members
AliBDay :: Date
AliBDay = {month = Jan,day = 26, year = 1999}

//Start = AliBDay //(Date 1999 "Januar" 26)

//Start = evanBDay.month // "April"
//to Extract a specific element from the struct you just mention the name of the variable.nameofmember
//Start = AliBDay.day//26

//Start = {year = 2000}//compile error

:: Person = {
                name :: String,
                favoriteColors :: [String],
                birthday :: Date,
                isSingle :: Bool

            }
//      Record inside a record 
//declaring a variable that uses a struct with it's members. inside the struct there is a member of type struct that uses members of another struct. Then we declare that struct (birthday) = evanBDay which is a variable that uses this struct to call it's members into this new variable called Evan.
Evan :: Person
Evan = {birthday = evanBDay, favoriteColors = ["Red","Blue","Green"],name = "Evan", isSingle =True}

//Here we defined Alex by assigning the values of birthday manually instead of defining AlexBday alone as a birthday struct then calling it.
//when u used the members of struct Person, the compiler noticed immediately that you are using the struct so when used Start = Alex, it printed the name of the struct first before the elements
Alex :: Person
Alex = {birthday = {year = 1989 , month = Nov, day = 19}, favoriteColors = ["Red","Yellow","Black"], name = "Alex", isSingle = False}

//Start = Alex //Person "Alex" ["Red","Yellow","Black"] (Date 1989 "November" 19) False)
//Start =Evan //(Person "Evan" ["Red","Blue","Green"] (Date 2000 "April" 1) True)

//Start = Evan.birthday.month // "April"
/*

//Start = Alex.birthday.month //"November"
//Start = hd Alex.favoriteColors // "Red"

///Start = Alex.isSingle // False
//Start = Alex.birthday // (Date 1989 "November" 19) // Prints out the name of the struct to which the member birthday is assigned to.


//Records of flexible types

:: Point a = { x::a ,y::a, z::a}


p1 :: (Point Int)// this is a point of Int. 
p1 = {x=1,y=2,z=3}
//Start = p1 //(Point 1 2 3)
p2 :: (Point Real)
p2 = {x=1.234 , y=2.345 ,z =3.456}

//Start = p2 //(Point 1.234 2.345 3.456)
p3 :: (Point Bool)
p3 = {x=True, y=False, z= True}

//Start = p3 //(Point True False True)
p4 :: (Point String)
p4 = {x= "IP", y = "MAC", z ="SSID"}

//Start = p4 //(Point "IP" "MAC" "SSID")

//Pattern matching with records' flexible type
//:: WeirdRecord a b c d e f = {x::(a,b),y ::[c], z ::e , s ::a , r ::Bool}
//Wr = {x=("Evan",41),y=[3,5,6,3,5],z="Hello",s="Bye",r= True}

//Start = Wr //(WeirdRecord ("Evan",41) [3,5,6,3,5] "Hello" "Bye" True)
/*
::Date ={
            year :: Int ,
            month :: String,
            day :: Int
        }
:: Person = {
                name :: String,
                favoriteColors :: [String],
                birthday :: Date,
                isSingle :: Bool
            }
*/
// a function that takes a parameter of type record Person
getBirthMonth :: Person -> String
//getBirthMonth p = p.birthday.month

//We could pattern match in order to make it easier to pick out members

//getBirthMonth {name = n ,favoriteColors = fav , birthday = b , isSingle = s} = b.month
//Start = getBirthMonth Evan //"April"

//What if we only want the birthday? we could pattern match only the elements we need 
//getBirthMonth {birthday =b }  = b.month
//you could also be more specific  
//getBirthMonth {birthday ={month = m} } 
// 'p=:'  this means it pattern matches the whole struct into p but we it would also pattern match the month to m. 
getBirthMonth p =: {birthday={month=m}}//accessing the whole record while pattern matching specific fields of the record
|p.isSingle = m
= "blah"
//Start = getBirthMonth Alex //"November"

//Start =getBirthMonth Alex // "blah"


getBirthDay :: Person -> Int
getBirthDay {birthday ={day = d}} = d
//Start = getBirthDay Alex // 19

getBirthYear :: Person -> Int
getBirthYear {birthday ={year = y}} = y

//Start = getBirthYear Alex //1989
//If we want to flip the boolean.
//V1
//updateSingleStatus :: Person -> Person
//updateSingleStatus p ={isSingle = not p.isSingle, name = p.name, favoriteColors = p.favoriteColors, birthday = p.birthday}
//Start = updateSingleStatus Evan //(Person "Evan" ["Red","Blue","Green"] (Date 2000 "April" 1) False)

//updateSingleStatus p = {p & isSingle = not p.isSingle} // this way we cloned the entire record & update the field isSingle

//Start = updateSingleStatus Evan //(Person "Evan" ["Red","Blue","Green"] (Date 2000 "April" 1) False)
//This copies the entire record to p and then it pattern matches isSingle to s and then it clones the isSingle from p and updates the field to be not s
updateSingleStatus :: Person -> Person
updateSingleStatus p =: {isSingle = s} = {p & isSingle = not s}//this is the same as in line 150 but we also have access to the whole record

//Start = updateSingleStatus Evan //(Person "Evan" ["Red","Blue","Green"] (Date 2000 "April" 1) False)
//v1
//updateColors :: Person -> Person
//updateColors p 
//| p.isSingle = {p& isSingle = not p.isSingle, favoriteColors =p.favoriteColors ++ ["White"]}
//= {p & isSingle = not p.isSingle, favoriteColors = []}
//| p.isSingle = {p& isSingle = not p.isSingle, favoriteColors =p.favoriteColors ++ ["White"], name = "LONELYMANSONN"}
// the & operator when added after the record lets you change the value of any member in it.
//(Person "LONELYMANSONN" ["Red","Blue","Green","White"] (Date 2000 "April" 1) False)

//Start = updateColors Evan //(Person "Evan" ["Red","Blue","Green","White"] (Date 2000 "April" 1) False)

updateColors :: Person -> Person
updateColors p=:{isSingle = s, favoriteColors =f}
| s = {p& isSingle =not s , favoriteColors = f ++ ["White"]}
= {p& isSingle = not s, favoriteColors = []}

//Start = updateColors (updateSingleStatus Evan)//(Person "Evan" [] (Date 2000 "April" 1) True)

//Algebraic data type
//You're controlling how this data is represented
*/

Jack :: Person 
Jack = {isSingle = False , birthday = {month = Jan, day = 24 , year = 1999},favoriteColors = [], name = "Jack"}
:: Month = Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec  

//Start = Evan.birthday.month // Apr 
//Start = Evan == Jack// doesn't work
//Start = Evan == Evan// doesn't work

//If we try to do inequality this will fail 
//You have to make your own equality

//== this is called class and this has been defined in the compiler in Clean and when you make your own type you have to define it 
//You have to define it because you made a new type Person
instance == Person
where 
//    (==) p1 p2 = p1.name == p2.name && p1.isSingle == p2.isSingle// works but ugly looking
    (==) {name =n1, birthday = b1} {name=n2, birthday = b2} = n1==n2 && b1==b2 // This also works



instance == Date where (==) {day =d1, year =y1 , month =m1} {day = d2, year =y2, month = m2} = d1==d2 && y1==y2 && m1==m2

//We created instance for the month type and then if the month is equal to the month then 
instance  == Month
where
    (==) Jan Jan = True
    (==) Feb Feb = True
    (==) Mar Mar = True
    (==) Apr Apr = True
    (==) May May = True
    (==) Jun Jun = True
    (==) Jul Jul = True
    (==) Aug Aug = True
    (==) Sep Sep = True
    (==) Oct Oct = True
    (==) Nov Nov = True
    (==) Dec Dec = True
    (==) _ _ = False

//Start = Evan == Evan//True that means we created our own instance (inequality) for this 
//Start = Evan == Jack //False

instance < Person
where
    (<) {birthday = {year = y1}} {birthday = {year =y2}} = y1<y2


//Start = Evan < Jack //False// this tests if the year of Jack's birthday is bigger than the year of Evan which is false
//Bonus tip in Clean : If you define an instance for '<', the 'Ord' class will automatically define and create for you the > , >= , <= instances
//If you define an instance for '==', the 'Eq' class will automatically define and create for you the <> instances



ListPeople = [Evan,Jack]
//Start = sort ListPeople //[(Person "Jack" [] (Date 1999 Jan 24) False),(Person "Evan" ["Red","Blue","Green"] (Date 2000 Apr 1) True)]
//For some reason Jack is sorted and comes before Evan
//Start = isMember Evan ListPeople //True yes, Evan is in the list of people


makeBabies :: Person Int -> [Person]
makeBabies p=: {name = n} x = [{p&name = n +++(toString j)}\\j<-[1..x]]
//This basically made a list of Numbered evans where it added j which was an int and converted it to a string and then contcatenated it to the clone of the name from the p
//Start = makeBabies Evan 10//[(Person "Evan1" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan2" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan3" ["Red","Blue","Green"]
//(Date 2000 Apr 1) True),(Person "Evan4" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan5" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan6"
//["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan7" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan8" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan9" ["Red","Blue","Green"] (Date 2000 Apr 1) True),(Person "Evan10" ["Red","Blue","Green"] (Date 2000 Apr 1) True)]

//Bonus question
func :: (Int,Int,Int) -> ((Int,Int,Int),Int)
func t=: (a,b,c) = (t,a+b+c)

Start = func (1,2,3)//((1,2,3),6)
