$base_url = "https://dl.cryptlex.com/downloads"
$lexactivator_version ="v3.14.7"
new-item -Name tmp -ItemType directory

$url = "$base_url/$lexactivator_version/LexActivator-Win.zip"
Write-Host "Downloading LexActivator library ..."
Write-Host $url
$output = "$PSScriptRoot\tmp\LexActivator-Win.zip"
(New-Object System.Net.WebClient).DownloadFile($url, $output)
Expand-Archive "$PSScriptRoot\tmp\LexActivator-Win.zip" -DestinationPath "$PSScriptRoot\tmp\windows\"
npm i
node-gyp rebuild 
Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x64\LexActivator.lib" -Destination "$PSScriptRoot\lib\bindings\windows\x32\lexactivator.node"
Copy-Item -Path "$PSScriptRoot\tmp\windows\LexActivator-Win\libs\vc14\x86\LexActivator.lib" -Destination "$PSScriptRoot\lib\bindings\windows\x64\lexactivator.node"

