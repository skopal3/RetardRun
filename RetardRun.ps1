<#************************************************************************
* Retard RUN
*************************************************************************
* Fonction : Jeux basé sur le spamm de touche
*************************************************************************
* Entrée : 
* précision sur entrée (doc)
* Sortie : 
*  précision sur sortie (doc)
* ***********************************************************************
* Librairie :
*************************************************************************
* Auteur   : Philippe Skopal                    * Date  : 07/01/2016
* Version  : v1.0                   			* Script Powershell 
*************************************************************************#>

#--------------------- Bloc du premier screen --------------------#

Clear-Host

Write-Host -NoNewline "############################################################# `n"
Write-Host -NoNewline "######## Bienvenue BANDE de retards sur RETARD RUN  ######### `n" 
Write-Host -NoNewline "############################################################# `n"
Write-Host -NoNewline "##                                                         ## `n"
Write-Host -NoNewline "## Le joueur 1 est : vert : sa touche  est le q (lol)      ## `n"
Write-Host -NoNewline "## Le joueur 2 est : rouge : sa touche  est le m           ## `n"
Write-Host -NoNewline "##                                                         ## `n"
Write-Host -NoNewline "##### Quand chaque tardos est prêt il apui sur sa touch ##### `n"
Write-Host -NoNewline "##                                                         ## `n"
Write-Host -NoNewline "############################################################# `n"

#--------------------- Bloc du attente des deux tardos --------------------#

$var1 = 0
$var2 = 0
$var3 = 0
$varTard = " "

do
{
      
      $varTard = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')
      Clear-Host
      if ($varTard -match "81") { Write-Host -NoNewline "Bon le deuxième tardos t'appuie sur ta touche ? `n" ; $var1++ }
      elseif ($varTard -match "77") { Write-Host -NoNewline "Bon le deuxième tardos t'appuie sur ta touche ? `n"  ; $var2++ }
      else {  Write-Host -NoNewline "Pas les bonnes touches bandes de RETARDs `n" }
      $varTard = " " 
      if($var1 -gt 0 -and $var2 -eq 0 ){$var3 = 1}
      elseif($var1 -eq 0 -and $var2 -gt 0 ) {$var3 = 1}
      elseif($var1 -gt 0 -and $var2 -gt 0 ) {$var3 = 2}
      

}while ( $var3 -lt 2 )

#--------------------- Bloc du décompte 5 secondes --------------------#
Clear-Host

Write-Host -NoNewline "##### Début de la guerre dans : 5 #####`n"
Start-Sleep -s 1
Clear-Host

Write-Host -NoNewline "#### Début de la guerre dans : 4 ####`n"
Start-Sleep -s 1

Clear-Host

Write-Host -NoNewline "### Début de la guerre dans : 3 ###`n"
Start-Sleep -s 1

Clear-Host

Write-Host -NoNewline "## Début de la guerre dans : 2 ##`n"
Start-Sleep -s 1

Clear-Host

Write-Host -NoNewline "# Début de la guerre dans : 1 #`n"
Start-Sleep -s 1
Write-Host -NoNewline "Début à la première pression`n"

#--------------------- Bloc bourinage --------------------#


$varRecupBourinage = " "
$compteurGeneral = 0
$compteur = 25

$compteurErreur = 0

$varProgressBar = "========================="



$varBreak = 0

do
{
      $varTard = " "
      $varTard = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown')
      $compteurGeneral++

      if ( $varTard -match "81" ) { $compteur++ }
      elseif ( $varTard -match "77" ) {  $compteur-- }
      else { $compteurErreur++ }
       
      if ( $compteur -eq 0 ) { $varBreak = 2 }
      elseif ( $compteur -eq 50 ) { $varBreak = 2 }
      else  { $varBreak = 0 }
   

      Clear-Host

      Write-Host -NoNewline "############################################################# `n"
      Write-Host -NoNewline "######## RETARD RUN the game by Philippe Skopal     ######### `n" 
      Write-Host -NoNewline "############################################################# `n"
      Write-Host -NoNewline "##                                                         ## `n"
      Write-Host -NoNewline "##      Allez les tards on bourinnent sa touche            ## `n"
      Write-Host -NoNewline "##                                                         ## `n"

      if     ($compteur -lt 25) { Write-Host -NoNewline "##      Joueur 1/vert en tete                              ## `n"}
      elseif ($compteur -gt 25) { Write-Host -NoNewline "##      Joueur 2/rouge en tete                             ## `n"}    
      elseif ($compteur -eq 25) { Write-Host -NoNewline "##      Egalite tardosienne                                ## `n"}                 

      Write-Host -NoNewline "##                                                         ## `n"
      $progressCount = 0
      $varProgressBar = ""
      do
      {
            $varProgressBar += "="
            $progressCount++

      }until($progressCount -eq $compteur)

      do
      {
            $varProgressBar += " "
            $progressCount++

      }until($progressCount -eq 50)

      Write-Host -NoNewline "##  ["
      Write-Host -NoNewline $varProgressBar                        
      Write-Host -NoNewline "]   ## `n"
      Write-Host -NoNewline "##                                                         ## `n"
      Write-Host -NoNewline "############################################################# `n"
      Write-Host -NoNewline $compteur


}while ( $varBreak -lt 2 )





#--------------------- Bloc de fin --------------------#
Clear-Host
if($compteur -eq 0) { Write-Host  " GG TARDOS VERT WIN " }
elseif ($compteur -eq 50) { Write-Host  " GG TARDOS ROUGE WIN "  }
