$previousNumber = 0
$currentNumber = 1
$MAXLOOP = 100
$currentLoop = 0
while ($currentLoop -lt $MAXLOOP) {
    $result = $previousNumber + $currentNumber
    write-host "fib: $result, datatype = $($result.gettype())"
    $previousNumber = $currentNumber
    $currentNumber = $result
    $currentLoop++
}