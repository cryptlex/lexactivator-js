$base_url = "https://dl.cryptlex.com/downloads"
$lexactivator_version ="v3.14.7"

New-Item -Path "$PSScriptRoot\tmp\windows" -ItemType Directory
$url = "$base_url/$lexactivator_version/LexActivator-Win.zip"
Write-Host "Downloading LexActivator library ..."
Write-Host $url
$output = "$PSScriptRoot\tmp\windows\LexActivator-Win.zip"
(New-Object System.Net.WebClient).DownloadFile($url, $output)

Expand-Archive "$PSScriptRoot\tmp\windows\LexActivator-Win.zip" -DestinationPath "$PSScriptRoot\tmp\windows\"

Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x64\LexActivator.lib" -Destination "$PSScriptRoot\"
npm i
node-gyp rebuild --msvs_version=2015

Copy-Item -Path "$PSScriptRoot\build\Release\lexactivator.node" -Destination "$PSScriptRoot\lib\bindings\windows\x64\lexactivator.node"
Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x64\LexActivator.dll" -Destination "$PSScriptRoot\lib\bindings\windows\x64\LexActivator.dll"

Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x86\LexActivator.lib" -Destination "$PSScriptRoot\"
npm i
node-gyp rebuild --arch=ia32 --msvs_version=2015

Copy-Item -Path "$PSScriptRoot\build\Release\lexactivator.node" -Destination "$PSScriptRoot\lib\bindings\windows\x32\lexactivator.node"
Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x86\LexActivator.dll" -Destination "$PSScriptRoot\lib\bindings\windows\x32\LexActivator.dll"

