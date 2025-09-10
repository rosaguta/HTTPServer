$currentdir = $pwd
$testPath = $currentdir.Path
if(-not($currentdir.Path.EndsWith("tests"))){
  $testPath += "/tests/"
}
# write-host $testPath
$tests = (Get-ChildItem $testPath).FullName
$filteredTests = foreach($test in $tests){
  $splittedTestName = $test.split("/")
  if($splittedTestName[$splittedTestName.Length - 1] -eq "RunAllTests.ps1"){
    continue
  }
  $test
}

foreach($test in $filteredTests){
  & $test
}
