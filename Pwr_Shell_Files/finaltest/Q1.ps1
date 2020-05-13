# Write a script that takes two words as arguments
# and checks if the last letter on the first word
# is equal to the first letter on the second word
#Mr Robot gives true

if($args.Count -eq 2)
{
    $a=$args[0]
    $b=$args[1]
   
   $len=$a.length
    $i=$a[$len-1]
    $j=$b[0]
    
   
   
    if([string]$i -eq [string]$j)
   {
         Write-host "True last letter in ($a) = first letter in ($b)"
    }
  
     else
    {
             write-host "Not true"
    }
}

else 
{
"I need two parameters"
}



