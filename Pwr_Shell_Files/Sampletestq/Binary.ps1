#This codes takes a decimal number and returns it's Binary form
[int32]$n=read-host
$a=@()
$str=""
for($i=0;$n -gt 0;$i++)
{
   $a+=([int32]($n%2))
   $n=([int32]($n/2))
}
for($i=($a.Length-1);$i -ge 0 ;$i--)
{
    [string]$str+=$a[$i]

}
Write-Output $str
