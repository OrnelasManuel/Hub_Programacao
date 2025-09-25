# Hub Programação

O **Hub Programação** é uma aplicação open source feita em **C++ com GTK** para organizar, criar e gerenciar seus projetos de programação de forma prática e rápida.

Com ele, você pode:
- Criar novos projetos baseados em **templates por linguagem** (ex: `Programacao/CPP/MeuProjeto`).
- Abrir projetos já existentes diretamente pelo Hub.
- Remover projetos de forma simples.
- Inicializar automaticamente ferramentas úteis:
  - **VS Code** no diretório do projeto
  - **Explorador de arquivos**
  - **Sites de documentação** da linguagem escolhida
- Personalizar temas e estilos visuais com editor embutido de CSS/cores/fontes.

---

## 🚧 Status do Projeto
- ✅ Funcionalidades principais de criação, abertura e remoção já implementadas
- ✅ Editor de configurações (tema, fonte, cores, pastas)
- ⚠️ Atualmente **estático** (baseado em suas pastas, modelos e ícones pessoais)
- 🔜 Planejado: **instalador automático** (dependências/flags) e **dinamicidade** para facilitar uso em qualquer ambiente

---

## 📂 Estrutura do Projeto
- `Developer/` → Contém o código-fonte bruto do projeto
- `output/` → Contém o programa já compilado e finalizado
- `Obsidian/` → Contém materiais de documentação e organização
- `Index.cpp` → Tela principal (entrada no programa)
- `Configuracoes.cpp` → Configurações de tema, pastas e fontes
- `Novo_Projeto_Acesso_De_Projeto_Interface.cpp` → Escolha de linguagem do projeto
- `Projetos_Acesso_Ou_Criacao.cpp` → Listagem e gerenciamento de projetos
- E outros módulos específicos (remoção, abertura, etc.)

---

## 📖 Documentação

A documentação do fluxo geral do programa está disponível em:  
👉 [Vizualizacao Geral.md](Obsidian/Vizualizacao%20Geral.md)

> ⚠️ O arquivo foi criado com **Excalidraw** dentro do Obsidian.  
> Para visualizar o diagrama corretamente, é recomendado abrir o `.md` no **Obsidian com o plugin Excalidraw instalado**.  

---

## 📜 Licença
Este projeto é **open source**.  
Você pode usar, estudar e modificar, mas **não pode comercializar**.

---

## ✨ Futuro
- Criar instalador que configure automaticamente dependências
- Tornar o programa totalmente dinâmico (modelos, ícones e pastas customizáveis)
