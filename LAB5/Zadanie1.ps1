$folder = Read-Host -Prompt 'Podaj nazwe folderu'
$pliki = Read-Host -Prompt 'Podaj ilosc plikow do utworzenia'

$dir = New-Item -Name $folder -ItemType "directory"

Write-Output "Utworzono folder o nazwie $folder oraz $pliki nowe pliki."

for($i = 1; $i -le $pliki; $i++)
{
    $dir = New-Item -Name $folder/$i.txt -ItemType "file"
}