# Create a Powershell script which gets a filename as parameter.  In the file there are one name in each line.  Decide the length of the longest name and write out the names with the same length.

# E.g. If the file contains 4 lines:
# Annabel
# John
# Anne
# Caterin
# The result is => Annabel, Caterin //both length are 7

if($args.count -gt 0)
{
if(Test-Path $args[0])
       {
            $len=@()
            $file=get-content $args[0]
            foreach($line in $file)
            {   $arr=""
                for($i=0;$i -lt $line.length;$i++)
                {
                    $arr+=$line[$i]
                    
                }
                $len+=$arr.length
            }

            $max = $len[0]
            $maxind=0
           for($i=1;$i -lt $len.length;$i++)
           {
            if($len[$i] -gt $max)
            {
                $max = $len[$i]
                $maxind=$i
            }
            if($len[$i] -eq $max)
            {
            $max =$len[$i]
            $maxind2=$i
    
            }

           }
        
        Write-host $file[$maxind] $file[$maxind2]
}
 else
 {
    Write-host "Invalid File"
 }




}


else
{
Write-host "Enter at least one filename as parameter!"
}
