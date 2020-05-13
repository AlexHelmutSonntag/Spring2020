# Create a Powershell script which gets a filename as parameter and a name.  In the file there are one name and a grade - separated by " ".  Count how many  the student is called  given by the parameter.  E.g. If the file contains 3 lines: 
# John 3
# Jane 4
# John 5


# The result with name John => 2
# with Jane =>1

if($args.count -eq 2)
{
  if(test-path $args[0])
  {
    $file =get-content $args[0]
    $cnt=0
    $cnt2=0
    $name=$args[1]
    for($i=0; $i -lt $file.length;$i++)
    {
        $new=$file[$i].split(" ")

        if([string]$new[0] -eq [string] $name)
        {
            $cnt++
            
        }

        else
        {
            [string]$othername=$new[0]
            $cnt2++
             
        }

    }
    write-host $name ==> $cnt
    write-host $othername ==> $cnt2

}
}

else
{
Write-host "I need two parameters"
}
