# build_metaphone3.ps1
# Compilation du projet Metaphone3, en excluant le dossier test

Write-Host "==== Compilation Metaphone3 (sans test) ===="

$gcc = "gcc"
$includes = "-Iinclude"

# Lister tous les .c dans src SAUF ceux dans test
$srcFiles = Get-ChildItem -Path ".\src" -Filter *.c -Recurse | Where-Object { $_.FullName -notmatch "\\test\\" } | ForEach-Object { $_.FullName }
$fileCount = $srcFiles.Count

Write-Host "Nombre de fichiers sources à compiler : $fileCount"

# Fichier principal de la démo
$demoMain = ".\demo\demo.c"
$demoExe = "metaphone3.exe"

if (Test-Path $demoMain) {
    $cmdDemo = "$gcc $demoMain $srcFiles $includes -o $demoExe"
    Write-Host "`n>> Compilation en cours..."
    Invoke-Expression $cmdDemo

    if (Test-Path $demoExe) {
        Write-Host "`nDémo compilée ! Exécutable : $demoExe" -ForegroundColor Green
    }
    else {
        Write-Host "`nÉchec de la compilation de la démo." -ForegroundColor Red
    }
}
else {
    Write-Host "`nAucun fichier demo trouvé : $demoMain" -ForegroundColor Yellow
}

Write-Host "`n==== Build terminé ===="
