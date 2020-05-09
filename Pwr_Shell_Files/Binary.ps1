#This is still bugged, will fix it later.
#
$n=read-host
$a=@{}

for($i=0;$n -gt 0;$i++)
{
   $a+=($n % 2)
   $n=$n/2

}
for($i=($i-1);$i -le 0 ;$i--)
{
    write-host -NoNewline $a[$i]
}
