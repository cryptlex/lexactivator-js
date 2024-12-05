$base_url = "https://dl.cryptlex.com/downloads"
$lexactivator_version ="v3.30.4"

New-Item -Path ".\tmp\windows" -ItemType Directory
$url = "$base_url/$lexactivator_version/LexActivator-Win.zip"
Write-Host "Downloading LexActivator library ..."
Write-Host $url
$output = ".\tmp\windows\LexActivator-Win.zip"
(New-Object System.Net.WebClient).DownloadFile($url, $output)

Expand-Archive $output -DestinationPath ".\tmp\windows\LexActivator-Win"

Copy-Item -Path ".\tmp\windows\LexActivator-Win\libs\vc17\arm64\LexActivator.lib" -Destination ".\"
npm i
node-gyp rebuild --arch=arm64

Copy-Item -Path ".\build\Release\lexactivator.node" -Destination ".\lib\bindings\windows\arm64\lexactivator.node"
Copy-Item -Path ".\tmp\windows\LexActivator-Win\libs\vc17\arm64\LexActivator.dll" -Destination ".\lib\bindings\windows\arm64\LexActivator.dll"s