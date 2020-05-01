module HW07
import StdEnv



:: Month = January | February | March | April | May | June | July | August | September | October | November | December
:: Gender = Male | Female | AttackHelicopter | Nghia

:: Date = { year::Int,
            month::Month, 
            day::Int
           }

:: Person = {name::String, 
            gender::Gender, 
            age::Int, 
            birthday::Date,
            isDead::Bool
             }

:: Account = {  number::Int, 
                owner::Person, 
                balance::Real, 
                dateCreated::Date
             }


Tringa :: Person
Tringa = {name = "Tringa", gender = Female, age = 42, birthday = {year = 1977, month = May, day = 12}, isDead = False}

Hossam :: Person
Hossam = {name = "Hossam", gender = AttackHelicopter, age = 69, birthday = {year = 1950, month = June, day = 27}, isDead = False}

Nicola :: Person
Nicola = {name = "Nicola", gender = Male, age = 9001, birthday = {year = -6982, month = January, day = 1}, isDead = True}

Zuka :: Person
Zuka = {name = "Zuka", gender = Male, age = 20, birthday = {year = 1999, month = February, day = 11}, isDead = False}

LeMinhNghia :: Person
LeMinhNghia = {name = "Nghia", gender = Nghia, age = 420, birthday = {year = 1599, month = February, day = 4}, isDead = True}             


SittBank :: [Account]
SittBank = [A00,A01,A02,A03]

A00 :: Account
A00 = {number = 0, owner = Nicola, balance = 9000.01, dateCreated = {year = 1945, month = August, day = 6}}

A01 :: Account
A01 = {number = 1, owner = Hossam, balance = -1337.42, dateCreated = {year = 1900, month = December, day = 25}}

A02 :: Account
A02 = {number = 2, owner = Tringa, balance = 123.45, dateCreated = {year = 2010, month = May, day = 12}}

A03 :: Account
A03 = {number = 3, owner = Zuka, balance = 35.0, dateCreated = {year = 2019, month = November, day = 11}}

A420 :: Account
A420 = {number = 420, owner = LeMinhNghia, balance = 420.0, dateCreated = {year = 420, month = April, day = 20}}


//1st Task

/*
Write a function that takes an Int and a
list of Accounts updates each Account
in the list by adding the number to the balance.

number::Int, 
                owner::Person, 
                balance::Real, 
                dateCreated::Date
             }
*/

// A00 :: Account
// A00 = {number = 0, owner = Nicola, balance = 9000.01, dateCreated = {year = 1945, month = August, day = 6}}

gimmeMoney :: [Account] Real -> [Account]
gimmeMoney [] cash = []
gimmeMoney [x=:{balance = b}:xs] cash = [{x& balance = b +cash}] ++ gimmeMoney xs cash


// Start = gimmeMoney SittBank 10000.0 // Works

//2nd Task

/*
Write a function that takes a list of Accounts
and returns the name of the owner with the
highest balance who is NOT dead.
*/

//This function gives me back the accounts whose owners are still alive
isNDED :: [Account] -> [Account]
isNDED [] = []
isNDED [x=:{owner={Person | isDead = d}}:xs] 
| d == False = [x] ++ isNDED xs 
= isNDED xs

// Start = isNDED SittBank // it works


Skrrt :: [Account] -> Real
Skrrt list =  maxList [x.balance\\x<-(isNDED list)]


// Start = Skrrt SittBank// 123.45

soRich :: [Account] -> String
soRich list = hd [x.owner.name\\x<-(list)| x.balance == (Skrrt (isNDED list))]
// Start = soRich [A01, A02, A03] //"Tringa"
// Start = soRich SittBank //"Tringa"


//3rd Task  

/*
Write a function that takes a tuple containing a
condition and two numbers, and a list of Accounts,
and returns a list containing all accounts
that match the condition, and that were created between
the two years (numbers provided).
*/
instance == Gender
where
      (==) Male Male = True
      (==) Female Female = True
      (==) AttackHelicopter AttackHelicopter = True
      (==) Nghia Nghia = True
      (==) _ _ =False


query :: ((Account->Bool),Int,Int) [Account] -> [Account]
query (lambda,x,y) list = [a\\a <-list | lambda a == True && x < a.dateCreated.year && a.dateCreated.year < y  ]

// Start = query ((\x = x.owner.gender==Male),0,2000) SittBank

// Start = query ((\x = x.balance > 0.0),-9999,9999) SittBank //nice one ;)  Almost lost it thinking A420 was in SittBank
// Start = query ((\x = not x.owner.isDead && length[z\\z<-:x.owner.name]==6),0,2020) [A00,A01,A02,A03,A420]
