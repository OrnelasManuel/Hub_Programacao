@echo off
:Inicio_Para_Refazer_Escolhas
color 07
title Programming
cls
echo O que deseja fazer:
echo Novo Projeto(NV) ^| Projeto Existente(PE) ^| Acesso Rapido(AR) ^| Ajuda(?)
echo.
set /p Projetos_Escolha=Escolha: 

cls

if /i "%Projetos_Escolha%"=="NV" (
    goto NovoProjeto
) else if /i "%Projetos_Escolha%"=="n" (
    goto NovoProjeto
) else if /i "%Projetos_Escolha%"=="EXISTENTE" (
    goto ExcluirProjetoVerProjeto
) else if /i "%Projetos_Escolha%"=="NOVO" (
    goto NovoProjeto
) else if /i "%Projetos_Escolha%"=="p" (
    goto ExcluirProjetoVerProjeto
) else if /i "%Projetos_Escolha%"=="PE" (
    goto ExcluirProjetoVerProjeto
) else if /i "%Projetos_Escolha%"=="A" (
    goto AjudaComComandos
) else if /i "%Projetos_Escolha%"=="Ajuda" (
    goto AjudaComComandos
) else if /i "%Projetos_Escolha%"=="?" (
    goto AjudaComComandos
) else if /i "%Projetos_Escolha%"=="A ou ?" (
    goto AjudaComComandos
) else if /i "%Projetos_Escolha%"=="../" (
    cd %UserProfile%\Desktop\Temp\Programacao\CMD
    cls
    start /max HUB_Geral 
    exit
) else if /i "%Projetos_Escolha%"=="AR" (
    goto AcessoRapido
) else if /i "%Projetos_Escolha%"=="A" (
    goto Acesso_Rapido
) else if /i "%Projetos_Escolha%"=="R" (
    goto AcessoRapido
) else if /i "%Projetos_Escolha%"=="ACESSO" (
    goto AcessoRapido
) else if /i "%Projetos_Escolha%"=="ACESSO RAPIDO" (
    goto AcessoRapido
) else if /i "%Projetos_Escolha%"=="RAPIDO" (
    goto AcessoRapido
) else if /i "%Projetos_Escolha%"=="RAPIDO ACESSO" (
    goto AcessoRapido
) else (
    echo Escolha invalida
    pause
    cls
    goto Inicio_Para_Refazer_Escolhas
)

:AjudaComComandos
color 0E
title Ajuda
cls
echo ---------------------------------------------------
echo.
echo Para acessar uma das opcoes voce deve escrever as letras entre os parenteses()
echo Ex: ?
echo.
echo Digitar o numero
echo Ex: 2
echo.
echo Ou Escrever o nome da opcao inteira
echo Ex: Ajuda

echo.
echo Se quiser voltar uma opcao deve se digitar ../ a qualquer momento 
echo.
echo ---------------------------------------------------
pause
goto Inicio_Para_Refazer_Escolhas

:ExcluirProjetoVerProjeto
color 07
title Tipo de Acesso

echo Oque deseja fazer com o projeto existente: 
echo Excluir(E) ^| Acessar(A)
set /p Escolha_Do_projeto=Escolha:

if /i "%Escolha_Do_projeto%"=="E" (
    goto ExcluirProjeto
) else if /i "%Escolha_Do_projeto%"=="A" (
    goto ProjetoExistente
) else if /i "%Escolha_Do_projeto%"=="ACESSAR" (
    goto ProjetoExistente
) else if /i "%Escolha_Do_projeto%"=="EXCLUIR" (
    goto ExcluirProjeto
) else if /i "%Escolha_Do_projeto%"=="EX" (
    goto ExcluirProjeto
) else if /i "%Escolha_Do_projeto%"=="../" (
    goto Inicio_Para_Refazer_Escolhas
) else (
    cls
    echo Escolha invalida
    pause
    cls
    goto ExcluirProjetoVerProjeto
)
goto end

:ExcluirProjeto
color 0C
title Exclusao de Projeto

cls
echo Qual Projeto deseja acessar:
echo React(R) ^| Java(J) ^| Node(N) ^| HTML/CSS/JavaScript(HCJ) ^| CMD(C)
echo.
set /p Projeto_Para_Excluir=Escolha:  
cls
if /i "%Projeto_Para_Excluir%"=="R" ( 
    goto Projeto_React_Excluir
) else if /i "%Projeto_Para_Excluir%"=="J" ( 
    goto Projeto_Java_Excluir
) else if /i "%Projeto_Para_Excluir%"=="N" ( 
    echo Nenhum comando projetado
    pause
    goto ExcluirProjeto
) else if /i "%Projeto_Para_Excluir%"=="HCJ" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="REACT" ( 
    goto Projeto_React_Excluir
) else if /i "%Projeto_Para_Excluir%"=="JAVA" ( 
    goto Projeto_Java_Excluir
) else if /i "%Projeto_Para_Excluir%"=="NODE" ( 
    echo Nenhum comando projetado
    pause
    goto ExcluirProjeto
) else if /i "%Projeto_Para_Excluir%"=="C" ( 
    goto Projeto_CMD_Excluir
) else if /i "%Projeto_Para_Excluir%"=="CM" ( 
    goto Projeto_CMD_Excluir
) else if /i "%Projeto_Para_Excluir%"=="CMD" ( 
    goto Projeto_CMD_Excluir
) else if /i "%Projeto_Para_Excluir%"=="H" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="HC" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="hCJ" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="HTML" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="CSS" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="JAVASCRIPT" ( 
    goto Projeto_HtmlCssJavaScript_Excluir
) else if /i "%Projeto_Para_Excluir%"=="../" ( 
    goto ExcluirProjetoVerProjeto
) else (
    cls
    echo Escolha invalida
    pause
    goto ExcluirProjeto
    )
echo Escolha invalida
pause
goto ExcluirProjeto


:Projeto_React_Excluir
cls

setlocal enabledelayedexpansion

set Repeticao_Contagem_React_Excluir=0


echo Qual pasta voce deseja excluir:
echo ---------------------------------------------------
cd %UserProfile%\Desktop\Temp\Programacao\React\
for /d %%i in (*) do (
    set /a Repeticao_Contagem_React_Excluir+=1
    set "Pasta_!Repeticao_Contagem_React_Excluir!=%%i"
    echo !Repeticao_Contagem_React_Excluir!. %%i
)
echo ---------------------------------------------------
set /p Pasta_De_Excluir_React=Pasta: 

if  /i "%Pasta_De_Excluir_React%"=="../" (
    goto ExcluirProjeto
)

if /i "!Pasta_De_Excluir_React!" LEQ "!Repeticao_Contagem_React_Excluir!" (
    for %%a in (!Pasta_De_Excluir_React!) do (
        set "Pasta_De_Excluir_React=!Pasta_%%a!"
    )
) else (
    cls
    echo Numero invalido
    pause
    goto Projeto_React_Excluir
)
cls

if /i "%Pasta_De_Excluir_React%"=="" (
    cls
    echo Pasta invalida
    pause
    goto Projeto_React_Excluir
)

echo Voce está excluindo a pasta: %Pasta_De_Excluir_React%
pause

cls

echo Excluindo pasta %Pasta_De_Excluir_React%...
    for /d %%i in (*) do (
        if /i "%%i"=="%Pasta_De_Excluir_React%" (
            rmdir /s /q "%UserProfile%\Desktop\Temp\Programacao\React\%Pasta_De_Excluir_React%"
            cls
            echo Excluido com sucesso
            pause
            goto Inicio_Para_Refazer_Escolhas
        )
    )
goto end

:Projeto_Java_Excluir
cls
echo Script de exclução de Projetos Java em desenvolvimento
pause
goto Inicio_Para_Refazer_Escolhas

:Projeto_HtmlCssJavaScript_Excluir
cls

setlocal enabledelayedexpansion

set Repeticao_Contagem_HtmlCssJavaScript_Excluir=0

echo Qual pasta voce deseja excluir:
echo ---------------------------------------------------
cd %UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\
for /d %%i in (*) do (
    set /a Repeticao_Contagem_HtmlCssJavaScript_Excluir+=1
    set "Pasta_!Repeticao_Contagem_HtmlCssJavaScript_Excluir!=%%i"
    echo !Repeticao_Contagem_HtmlCssJavaScript_Excluir!. %%i
)
echo ---------------------------------------------------
set /p Pasta_De_Excluir_HtmlCssJavaScript=Pasta: 

if  /i "%Pasta_De_Excluir_HtmlCssJavaScript%"=="../" (
    goto ExcluirProjeto
)

if /i "!Pasta_De_Excluir_HtmlCssJavaScript!" LEQ "!Repeticao_Contagem_HtmlCssJavaScript_Excluir!" (
    for %%a in (!Pasta_De_Excluir_HtmlCssJavaScript!) do (
        set "Pasta_De_Excluir_HtmlCssJavaScript=!Pasta_%%a!"
    )
) else (
    cls
    echo Numero invalido
    pause
    goto Projeto_HtmlCssJavaScript_Excluir
)

cls

if /i "%Pasta_De_Excluir_HtmlCssJavaScript%"=="" (
    cls
    echo Pasta invalida
    pause
    goto Projeto_React_Excluir
)

echo Voce está excluindo a pasta: %Pasta_De_Excluir_HtmlCssJavaScript%
pause

cls

echo Excluindo pasta %Pasta_De_Excluir_HtmlCssJavaScript%...
    for /d %%i in (*) do (
        if /i "%%i"=="%Pasta_De_Excluir_HtmlCssJavaScript%" (
            rmdir /s /q "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Excluir_HtmlCssJavaScript%"
            cls
            echo Excluido com sucesso
            pause
            goto Inicio_Para_Refazer_Escolhas
        )
    )
goto end

:Projeto_CMD_Excluir
cls

echo Qual arquivo voce deseja excluir:

setlocal enabledelayedexpansion

set Repeticao_Contagem_CMD_Excluir=0

echo ---------------------------------------------------
cd %UserProfile%\Desktop\Temp\Programacao\CMD\
for /f "delims=" %%i in ('dir /b /a-d *.bat') do (
    set /a Repeticao_Contagem_CMD_Excluir+=1
    set "Pasta_!Repeticao_Contagem_CMD_Excluir!= %%i"
    echo !Repeticao_Contagem_CMD_Excluir!. %%i
)
echo ---------------------------------------------------
set /p Pasta_De_Excluir_CMD=Pasta: 

if  /i "%Pasta_De_Excluir_CMD%"=="../" (
    goto ExcluirProjeto
)

if /i "!Pasta_De_Excluir_CMD!" LEQ "!Repeticao_Contagem_CMD_Excluir!" (
    for %%a in (!Pasta_De_Excluir_CMD!) do (
        set "Pasta_De_Excluir_CMD=!Pasta_%%a!"
    )
) else (
    cls
    echo Numero invalido
    pause
    goto Projeto_CMD_Excluir
)

cls

if /i "%Pasta_De_Excluir_CMD%"=="" (
    cls
    echo Pasta invalida
    pause
    goto Projeto_React_Excluir
)

echo Voce está excluindo o arquivo: %Pasta_De_Excluir_CMD%
pause

cls

echo Excluindo arquivo %Pasta_De_Excluir_CMD%...
    del /q %Pasta_De_Excluir_CMD%
    if exist "%UserProfile%\Desktop\Temp\Programacao\CMD\%Pasta_De_Excluir_CMD%" (
        cls
        echo Falha ao excluir o arquivo
        pause
        goto Inicio_Para_Refazer_Escolhas
    ) else (
        cls
        echo Excluido com sucesso
        pause
        goto Inicio_Para_Refazer_Escolhas
    )
goto end

:Inicio_Para_Refazer_Escolha_Projeto_Abrir
:ProjetoExistente
color 09
title Acessar Projeto

cls
echo Qual Projeto deseja acessar:
echo React(R) ^| Java(J) ^| Node(N) ^| HTML/CSS/JavaScript(HCJ) ^| CMD(C)
echo.
set /p Projeto_Para_Abrir=Escolha:  
cls
if /i "%Projeto_Para_Abrir%"=="R" ( 
    goto Projeto_React_Abrir
) else if /i "%Projeto_Para_Abrir%"=="J" ( 
    goto Projeto_Java_Abrir
) else if /i "%Projeto_Para_Abrir%"=="N" ( 
    echo Nenhum comando projetado
    pause
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
) else if /i "%Projeto_Para_Abrir%"=="HCJ" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="REACT" ( 
    goto Projeto_React_Abrir
) else if /i "%Projeto_Para_Abrir%"=="JAVA" ( 
    goto Projeto_Java_Abrir
) else if /i "%Projeto_Para_Abrir%"=="NODE" ( 
    echo Nenhum comando projetado
    pause
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
) else if /i "%Projeto_Para_Abrir%"=="C" ( 
    goto Projeto_CMD_Abrir
) else if /i "%Projeto_Para_Abrir%"=="CM" ( 
    goto Projeto_CMD_Abrir
) else if /i "%Projeto_Para_Abrir%"=="CMD" ( 
    goto Projeto_CMD_Abrir
) else if /i "%Projeto_Para_Abrir%"=="H" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="HC" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="hCJ" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="HTML" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="CSS" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="JAVASCRIPT" ( 
    goto Projeto_HtmlCssJavaScript_Abrir
) else if /i "%Projeto_Para_Abrir%"=="../" ( 
    goto ExcluirProjetoVerProjeto
) else (
    echo Escolha invalida
    pause
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
    )
echo Escolha invalida
pause
goto Inicio_Para_Refazer_Escolha_Projeto_Abrir

:Projeto_React_Abrir
cls

setlocal enabledelayedexpansion

set Repeticao_Contagem_React_Abrir=0

echo Qual pasta voce quer acessar:
echo ---------------------------------------------------
cd "%UserProfile%\Desktop\Temp\Programacao\React\"
for /d %%i in (*) do (
    set /a Repeticao_Contagem_React_Abrir+=1
    set "Pasta_!Repeticao_Contagem_React_Abrir!=%%i"
    echo !Repeticao_Contagem_React_Abrir!. %%i
)
echo.
echo Nao insira nada para acessar a pasta geral
echo ---------------------------------------------------
set /p Pasta_De_Abertura_React=Pasta: 

if  /i "%Pasta_De_Abertura_React%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

    for %%a in (!Pasta_De_Abertura_React!) do (
        set "Pasta_De_Abertura_React=!Pasta_%%a!"
    )

    if not "!Pasta_De_Abertura_React!"=="" (
        echo !Pasta_De_Abertura_React!

    )  else (
    cls
    echo Numero invalido
    pause
    goto Projeto_React_Abrir
)

cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Abertura_React=Abrir: 

echo Abrindo local dos Arquivos
cd %UserProfile%\Desktop\Temp\Programacao\React\%Pasta_De_Abertura_React%
cls

start .

echo Aguardando Visual Studio Code iniciar...
if /i "%Pasta_De_Abertura_React%"=="" (
    start code .
) else (
    start code "%UserProfile%\Desktop\Temp\Programacao\Areas De Trabalho\%Pasta_De_Abertura_React%.code-workspace"
)
timeout /t 3 /nobreak >nul
cls
if /i "%Teste_Abrir_Sites_Abertura_React%"=="S" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    if /i not "%Pasta_De_Abertura_React%"=="" (
        npm start
    )
) else if /i "%Teste_Abrir_Sites_Abertura_React%"=="SI" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    if /i not "%Pasta_De_Abertura_React%"=="" (
        npm start
    )
) else if /i "%Teste_Abrir_Sites_Abertura_React%"=="SIM" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    if /i not "%Pasta_De_Abertura_React%"=="" (
        npm start
    )
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_Java_Abrir
cls

echo Abrindo local dos Arquivos
cd C:\Program Files\NetBeans-19\netbeans\bin
cls

echo Voce quer abrir os sites:
echo Sim(S) Nao(N)
set /p Teste_Abrir_Sites_Abertura_Java=Abrir: 

cls

echo Aguardando NetBeans iniciar...

if /i "%Teste_Abrir_Sites_Abertura_Java%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
) else (
    start netbeans64.exe
)

timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Abertura_React%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_React%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_React%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_HtmlCssJavaScript_Abrir
cls

setlocal enabledelayedexpansion

set Repeticao_Contagem_HtmlCssJavaScript_Abertura=0

echo Qual pasta voce quer acessar:
echo ---------------------------------------------------
cd %UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\
for /d %%i in (*) do (
    set /a Repeticao_Contagem_HtmlCssJavaScript_Abertura+=1
    set "Pasta_!Repeticao_Contagem_HtmlCssJavaScript_Abertura!=%%i"
    echo !Repeticao_Contagem_HtmlCssJavaScript_Abertura!. %%i
)
echo.
echo Nao insira nada para acessar a pasta geral
echo ---------------------------------------------------
set /p Pasta_De_Abertura_HtmlCssJavaScript=Pasta: 

if  /i "%Pasta_De_Abertura_HtmlCssJavaScript%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

if /i "!Pasta_De_Abertura_HtmlCssJavaScript!" LEQ "!Repeticao_Contagem_HtmlCssJavaScript_Abertura!" (
    for %%a in (!Pasta_De_Abertura_HtmlCssJavaScript!) do (
        set "Pasta_De_Abertura_HtmlCssJavaScript=!Pasta_%%a!"
    )
) else (
    cls
    echo Numero invalido
    pause
    goto Projeto_HtmlCssJavaScript_Abrir
)

cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Abertura_HtmlCssJavaScript=Abrir: 

echo Abrindo local dos Arquivos
cd %UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Abertura_HtmlCssJavaScript%
cls

start .

echo Aguardando Visual Studio Code iniciar...
if /i "%Pasta_De_Abertura_HtmlCssJavaScript%"=="" (
    start code .
) else (
    start code "%UserProfile%\Desktop\Temp\Programacao\Areas De Trabalho\%Pasta_De_Abertura_HtmlCssJavaScript%.code-workspace"
    echo {"command": "extension.liveServer.goOnline"} > "%APPDATA%\Code\User\globalStorage\ritwickdey.liveserver\settings.json"
)
timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Abertura_HtmlCssJavaScript%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_HtmlCssJavaScript%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_HtmlCssJavaScript%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_CMD_Abrir
cls

setlocal enabledelayedexpansion

set Repeticao_Contagem_CMD_Abertura=0

echo Qual arquivo voce quer acessar:
echo Obs: Digite tudo
echo ---------------------------------------------------
cd "%UserProfile%\Desktop\Temp\Programacao\CMD\"
for /f "delims=" %%i in ('dir /b /a-d *.bat') do (
    set /a Repeticao_Contagem_CMD_Abertura+=1
    set "Pasta_!Repeticao_Contagem_CMD_Abertura!= %%i"
    echo !Repeticao_Contagem_CMD_Abertura!. %%i
)
echo.
echo Nao insira nada para acessar a pasta geral
echo ---------------------------------------------------
set /p Pasta_De_Abertura_CMD=Arquivo: 

if  /i "%Pasta_De_Abertura_CMD%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

if /i "!Pasta_De_Abertura_CMD!" LEQ "!Repeticao_Contagem_CMD_Abertura!" (
    for %%a in (!Pasta_De_Abertura_CMD!) do (
        set "Pasta_De_Abertura_CMD=!Pasta_%%a!"
    )
) else (
    cls
    echo Numero invalido
    pause
    goto Projeto_CMD_Abrir
)
cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Abertura_CMD=Abrir: 

cd "%UserProfile%\Desktop\Temp\Programacao\CMD\%Pasta_De_Abertura_CMD%"
cls



echo Aguardando Visual Studio Code iniciar...
if /i "%Pasta_De_Abertura_CMD%"=="" (
    start code .
) else (
    start code . 
    start code %Pasta_De_Abertura_CMD%
)
timeout /t 3 /nobreak >nul
cls


if /i "%Teste_Abrir_Sites_Abertura_CMD%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_CMD%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Abertura_CMD%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
)
goto end


:NovoProjeto
color 0A
title Criacao de Projeto

cls
echo Escolha o tipo de projeto: 
echo React(R) ^| Java(J) ^| Node(N) ^| HTML/CSS/JavaScript(HCJ) ^| CMD(C)
echo.
set /p Projeto_Para_Criar=Escolha:  
cls
if /i "%Projeto_Para_Criar%"=="R" ( 
    goto Projeto_React_Criar
) else if /i "%Projeto_Para_Criar%"=="J" ( 
    goto Projeto_Java_Criar
) else if /i "%Projeto_Para_Criar%"=="N" ( 
    echo Nenhum comando projetado
    pause
    goto NovoProjeto
) else if /i "%Projeto_Para_Criar%"=="HCJ" ( 
    goto Projeto_HtmlCssJavaScript_Criar
) else if /i "%Projeto_Para_Criar%"=="r" ( 
    goto Projeto_React_Criar
) else if /i "%Projeto_Para_Criar%"=="j" ( 
    goto Projeto_Java_Criar
) else if /i "%Projeto_Para_Criar%"=="n" ( 
    echo Nenhum comando projetado
    pause
    goto NovoProjeto
) else if /i "%Projeto_Para_Criar%"=="C" ( 
    goto Projeto_CMD_Criar
) else if /i "%Projeto_Para_Criar%"=="c" ( 
    goto Projeto_CMD_Criar
) else if /i "%Projeto_Para_Criar%"=="CMD" ( 
    goto Projeto_CMD_Criar
) else if /i "%Projeto_Para_Criar%"=="cmd" ( 
    goto Projeto_CMD_Criar
) else if /i "%Projeto_Para_Criar%"=="hcj" ( 
    goto Projeto_HtmlCssJavaScript_Criar
) else if  /i "%Projeto_Para_Criar%"=="../" (
    goto Inicio_Para_Refazer_Escolhas
) else (
    echo Escolha invalida
    pause
    goto NovoProjeto
    )
echo Escolha invalida
pause
goto NovoProjeto

:Projeto_React_Criar
cls

set /p Pasta_De_Criacao_React=Nome do Projeto: 

cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Criacao_React=Abrir: 


 if  /i "%Pasta_De_Criacao_React%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

echo Abrindo local dos Arquivos
cd %UserProfile%\Desktop\Temp\Programacao\React\
cls

mkdir %Pasta_De_Criacao_React%

cd %Pasta_De_Criacao_React%

echo Iniciando copia de Arquivos...
timeout /t 1 /nobreak>nul
xcopy "%UserProfile%\Desktop\Temp\Programacao\React\Modelo_React\*" "%UserProfile%\Desktop\Temp\Programacao\React\%Pasta_De_Criacao_React%\" /E /I 
cls
echo Arquivos copiados
timeout /t 1 /nobreak >nul

start .

start  code . %UserProfile%\Desktop\Temp\Programacao\React\%Pasta_De_Criacao_React%\src\CorpoSite.js

timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Criacao_React%"=="S" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    npm start
) else if /i "%Teste_Abrir_Sites_Criacao_React%"=="SI" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    npm start
) else if /i "%Teste_Abrir_Sites_Criacao_React%"=="SIM" (
    echo Abrindo Paginas
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1Lu5wZ6GB2O-ETYLF8GIyJ4qorDdPRQ2tfW8quOPWg4E/edit#heading=h.ckv6il383iz1"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
    cls
    echo Abrindo servidor
    timeout /t 2 /nobreak >nul
    npm start
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_Java_Criar
cls

echo Abrindo local dos Arquivos
cd C:\Program Files\NetBeans-19\netbeans\bin
cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Criacao_Java=Abrir: 

cls
echo Aguardando NetBeans iniciar...

if /i "%Teste_Abrir_Sites_Criacao_Java%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
) else (
    start netbeans64.exe
)

timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Criacao_Java%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_Java%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_Java%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/16OCxYDiFXzobrY29lHLLwMrhRGKMKltY4fjHZtoIl9w/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_HtmlCssJavaScript_Criar
cls

set /p Pasta_De_Criacao_HtmlCssJavaScript=Nome do Projeto: 

cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Criacao_HtmlCssJavaScript=Abrir: 


if /i "%Pasta_De_Criacao_HtmlCssJavaScript%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

echo Abrindo local dos Arquivos
cd %UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\
cls

mkdir %Pasta_De_Criacao_HtmlCssJavaScript%

cd %Pasta_De_Criacao_HtmlCssJavaScript%

cls

echo Iniciando copia de Arquivos...
timeout /t 1 /nobreak>nul
xcopy "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\Modelo_Site\*" "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Criacao_HtmlCssJavaScript%\" /E /I 
cls
echo Arquivos copiados
timeout /t 1 /nobreak >nul
cls

echo Aguardando Visual Studio Code iniciar...

start .

start code . "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Criacao_HtmlCssJavaScript%\HTML\Index.html"
echo {"command": "extension.liveServer.goOnline"} > "%APPDATA%\Code\User\globalStorage\ritwickdey.liveserver\settings.json"
timeout /t 4 /nobreak >nul
start code "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Criacao_HtmlCssJavaScript%\Script\Programa.js"
timeout /t 2 /nobreak >nul
start code "%UserProfile%\Desktop\Temp\Programacao\HTML CSS JS\%Pasta_De_Criacao_HtmlCssJavaScript%\Style\Estilo_Padrao.css"

timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Criacao_HtmlCssJavaScript%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_HtmlCssJavaScript%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_HtmlCssJavaScript%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/172vgTMC2t4hcMx5Y9T3WCXIVG1aF0d_gDg7elyGcQpg/edit#heading=h.nsq0wihpi6j4"
    timeout /t 2 /nobreak >nul
    start chrome "https://docs.google.com/document/d/1yEekOt9I3SO8unC8SptfXk1PGbqoFno7fhXCxZw8EuY/edit#heading=h.ckv6il383iz1"
    start chrome "https://chat.openai.com/"
)
goto end

REM ------------------------------------------------------------------------------

:Projeto_CMD_Criar
cls

set /p Pasta_De_Criacao_CMD=Nome do Projeto:

cls

echo Voce quer abrir os sites:
echo Sim(S) ^| Nao(N)
set /p Teste_Abrir_Sites_Criacao_CMD=Abrir: 

if  /i "%Pasta_De_Criacao_CMD%"=="../" (
    goto Inicio_Para_Refazer_Escolha_Projeto_Abrir
)

cd "%UserProfile%\Desktop\Temp\Programacao\CMD\"
cls

type nul > %Pasta_De_Criacao_CMD%.bat

echo Aguardando Visual Studio Code iniciar...
start code "%UserProfile%\Desktop\Temp\Programacao\CMD\%Pasta_De_Criacao_CMD%.bat"
timeout /t 3 /nobreak >nul
cls

if /i "%Teste_Abrir_Sites_Criacao_React%"=="S" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_React%"=="SI" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
) else if /i "%Teste_Abrir_Sites_Criacao_React%"=="SIM" (
    echo Aguardando um momento...
    start chrome --profile-directory="Profile 1" --new-window "https://docs.google.com/document/d/1lqzBjK0ZtO9Aey428SDF3Ysan88vyTth4L7MgXbJm2U/edit"
    timeout /t 2 /nobreak >nul
    start chrome "https://chat.openai.com/"
)
goto end

:AcessoRapido
cls
setlocal enabledelayedexpansion
cd %UserProfile%"\Desktop\Temp\Programacao\Acesso Rapido"
color B
title Acesso Rapido

echo Qual Acesso voce quer fazer:
echo RVS Price(RVS) ^| Outros
echo. 
set /p Acesso_Escolhido=Escolha: 

set "Verifcador_RVS_Price=R RV RVS PRICE RVSPRICE PRICE P PR"

for /d %%i in (%Verifcador_RVS_Price%) do (
    if /i "%%i"=="%Acesso_Escolhido%" (
        cls
        cd "%UserProfile%\Desktop\Temp\Programacao\Acesso Rapido\RVS_Price"
        start RVS_Price_Script.bat.lnk
        exit
    )
)
if  /i "%Acesso_Escolhido%"=="../" (
    goto Inicio_Para_Refazer_Escolhas
) else (
    cls
    echo Escolha invalida
    pause
    goto AcessoRapido
    )


:end
timeout /t 2 /nobreak >nul
taskkill /F /IM cmd.exe /T