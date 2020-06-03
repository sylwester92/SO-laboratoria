$plik = Read-Host -Prompt 'Podaj nazwę pliku: '
$znak = Read-Host -Prompt 'Podaj znak: '

$wynik = (Select-String -Path $plik -Pattern $znak -AllMatches).Matches.Count

Write-Output "Znak $znak w pliku $plik wystepuje $wynik razy."