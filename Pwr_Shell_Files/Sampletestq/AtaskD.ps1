#This script gets names in a file(filename as parameter) and prints the one longer than a predefinded value(parameter)
if($args.count -ne 2)
{
    "I need a file name and an integer value"
}
else
{

    if(Test-Path $args[0])
    {
        $out=@()
        $filename = Get-Content $args[0]        
        $value = $args[1]
        foreach($line in $filename)
        {
           $out+=($line.split()[0])

        }
        for($i=0;$i -lt $out.length;$i++)
        {
            if($out[$i].length -ge $value)
            {

                Write-host $filename[$i]

            }

     }
}
}
