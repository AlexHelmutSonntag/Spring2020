module Taskprogress
import StdEnv




/*Given a list of Persons. Write a function which keeps only the Persons
older than 16 whose height is an even number*/
fun1::[Person]->[Person]
//Start=fun1 [Nikola,Mark,Michael]//[(Person "Nikola" 19 194)]
//Start=fun1 [Nikola,Ivana]//[(Person "Nikola" 19 194)]
//Start=fun1 [Ivana,Mark,Michael]//[]

::Person ={ name :: String,
            age :: Int, 
            height :: Int
         }


Nikola::Person
Nikola={name="Nikola",age=19,height=194}
Ivana::Person
Ivana={name="Ivana",age=18,height=163}
Mark::Person
Mark={name="Mark",age=15,height=1170}
Michael::Person
Michael={name="Michael",age=16,height=180}


fun1 :: [Person] ->[Person]
fun1 list = [x \\ x<-list | x.age > 16 && isEven x.height ] 


//Start = fun1 [Nikola,Mark,Michael]//[(Person "Nikola" 19 194)]
//Start = fun1 [Nikola,Ivana]//[(Person "Nikola" 19 194)]
Start = fun1 [Ivana,Mark,Michael]//[]
