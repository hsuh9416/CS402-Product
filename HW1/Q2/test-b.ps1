Write-Host "=========== Performance check for 'MulIntMatrixAlt' ==========="
for ($i = 0; $i -lt 10; $i++) {
    $StartMs = Get-Date
    gcc -o ./Program/MulIntMatrixAlt.exe ./Program/MulIntMatrixAlt.c 
    ./Program/MulIntMatrixAlt.exe
    $EndMs = Get-Date
    $timeSpan = $EndMs - $StartMs
    Write-Host "[$i]$($timeSpan.TotalSeconds) seconds to compile&Execute for MulIntMatrixAlt.c"
}
Write-Host "=========== Performance check for 'MulRealMatrixAlt' ==========="
for ($i = 0; $i -lt 10; $i++) {
    $StartMs = Get-Date
    gcc -o ./Program/MulRealMatrixAlt.exe ./Program/MulRealMatrixAlt.c 
    ./Program/MulRealMatrixAlt.exe
    $EndMs = Get-Date
    $timeSpan = $EndMs - $StartMs
    Write-Host "[$i]$($timeSpan.TotalSeconds) seconds to compile&Execute for MulRealMatrixAlt.c"
}

