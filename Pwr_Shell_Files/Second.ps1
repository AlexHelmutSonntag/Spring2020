#29/4/2020

#we need to cast the type of $number to int so we type [int]$variablename
[int]$number=read-host "Give me a number"

for($j=1;$j -lt 10 ; $j++)
{
for ($i=1; $i -le 10 ; $i++)
{   
    #Write-Host -NoNewline prints without doing \n a the end
    Write-Host -NoNewline ($j*$number*$i)
    Write-Host -NoNewline " "
}
Write-Host
}


#Write-Host alone gives a new line
Write-Host
