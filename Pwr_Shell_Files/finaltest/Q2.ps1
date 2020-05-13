# Create a Powershell script which gets some parameter  from the command line - they are words. Write out the last word in reverse order. E.g. apple;melon;plum=>mulp //strings can be indexed like in C

if($args.count -gt 0)
{
$last=$args.count

$word=$args[$last-1]

$arr=""

for($i=($word.length-1);$i -ge 0; $i--)
{
    $arr+=$word[$i]
}

Write-host $arr


}

else
{
write-host "insert at least one paramter"
}
