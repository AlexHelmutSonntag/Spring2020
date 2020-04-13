module HW01
import StdEnv


// Task 1

calcGrade :: Real -> Int
calcGrade grade
| grade <0.0 = -1
| grade > 0.0 && grade < 50.0 = 1
| grade >= 50.0 && grade <= 60.0 =2
| grade >=61.0 && grade <= 70.0 = 3
| grade >=71.0 && grade <= 85.0 = 4
| grade >=86.0 && grade <= 100.0 = 5

Start = calcGrade 100.0



// Task 2





Monthcalc :: Int -> String
Monthcalc month
| month <= 0 || month > 12 = "Invalid Month"
| month == 1 = "January"
| month == 2 = "February"
| month == 3 = "March"
| month == 4 = "April"
| month == 5 = "May"
| month == 6 = "June"
| month == 7 = "July"
| month == 8 = "August"
| month == 9 = "September"
| month == 10 = "October"
| month == 11 = "November"
| month == 12 = "December"
 
Start = Monthcalc -1


// Task 3





Billcalc :: Real Real -> Real
Billcalc subtotal gratuity = subtotal +(gratuity * subtotal)

Start = Billcalc 10.00 0.15
