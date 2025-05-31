# build_metaphone3_py.ps1
# Compilation de la DLL Metaphone3 pour Python (ctypes), sans fichiers des dossiers demo et test

Write-Host "==== Compilation Metaphone3 DLL pour Python (hors demo & test) ===="

$gcc = "gcc"
$includes = "-Iinclude"

# Lister tous les .c dans src, EXCLURE ceux dans .\test et .\demo à la racine
$srcFiles = Get-ChildItem -Path ".\src" -Filter *.c -Recurse | ForEach-Object { $_.FullName }
# Filtrer pour enlever ceux qui contiennent "\test\" OU "\demo\"
$srcFiles = $srcFiles | Where-Object { $_ -notmatch "\\test\\" -and $_ -notmatch "\\demo\\" }

$fileCount = $srcFiles.Count
Write-Host "Nombre de fichiers sources à compiler : $fileCount"

$dllName = "libmetaphone3.dll"
$cmdDLL = "$gcc -shared -o $dllName $srcFiles $includes"

Write-Host "`n>> Compilation en cours..."
Invoke-Expression $cmdDLL

if (Test-Path $dllName) {
    Write-Host "`nDLL compilée ! Fichier : $dllName" -ForegroundColor Green
}
else {
    Write-Host "`nÉchec de la compilation de la DLL." -ForegroundColor Red
}

Write-Host "`n==== Build terminé ===="
