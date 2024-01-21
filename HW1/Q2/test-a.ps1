Write-Host "=========== Performance check for 'MulIntMatrix' ==========="
for ($i = 0; $i -lt 10; $i++) {
    $StartMs = Get-Date
    gcc -o ./Program/MulIntMatrix.exe ./Program/MulIntMatrix.c 
    ./Program/MulIntMatrix.exe
    $EndMs = Get-Date
    $timeSpan = $EndMs - $StartMs
    Write-Host "[$i]$($timeSpan.TotalSeconds) seconds to compile&Execute for MulIntMatrix.c"
}
Write-Host "=========== Performance check for 'MulRealMatrix' ==========="
for ($i = 0; $i -lt 10; $i++) {
    $StartMs = Get-Date
    gcc -o ./Program/MulRealMatrix.exe ./Program/MulRealMatrix.c 
    ./Program/MulRealMatrix.exe
    $EndMs = Get-Date
    $timeSpan = $EndMs - $StartMs
    Write-Host "[$i]$($timeSpan.TotalSeconds) seconds to compile&Execute for MulRealMatrix.c"
}

