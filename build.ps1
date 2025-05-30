# build_metaphone3.ps1
# Compilation des tests unitaires pour le projet Metaphone3

Write-Host "==== Compilation des tests Metaphone3 ===="

$gcc = "gcc"
$includes = "-Iinclude"

# Lister TOUS les .c dans src (y compris metaphone3.c)
$srcFiles = Get-ChildItem -Path ".\src" -Filter *.c -Recurse | ForEach-Object { $_.FullName }

# Fichier principal du test
$testMain = ".\test\test_utils.c"
$testExe = "test_utils.exe"

if (Test-Path $testMain) {
    # Compile test_utils.c + tous les modules (avec metaphone3.c)
    $cmdTest = "$gcc $testMain $srcFiles $includes -o $testExe"
    Write-Host "`n>> $cmdTest"
    Invoke-Expression $cmdTest

    if (Test-Path $testExe) {
        Write-Host "`nTest compilé ! Exécutable : $testExe" -ForegroundColor Green
    }
    else {
        Write-Host "`nÉchec de la compilation du test." -ForegroundColor Red
    }
}
else {
    Write-Host "`nAucun fichier de test trouvé : $testMain" -ForegroundColor Yellow
}

Write-Host "`n==== Build terminé ===="
