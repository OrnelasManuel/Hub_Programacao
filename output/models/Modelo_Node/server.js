//#region Importações de bibliotecas
const express = require("express");
const app = express("");
const mysql = require("mysql2");
const cors = require("cors");
const bodyParser = require("body-parser");
const { JSDOM } = require("jsdom");
//#endregion

const dom = new JSDOM(
  `<!DOCTYPE html><html><head><title>RVS Server</title></head><body></body></html>`
);

//#region Informações para acesso de Banco de Dados
const Banco_De_Dados = mysql.createPool({
  // host: "rvsprice.c74wcaki2gcr.us-east-2.rds.amazonaws.com",
  // port: 3306,
  // user: "admin",
  // password: "adminadmin",
  // database: "rvsprice",
  host: "127.0.0.1",
  port: 3306,
  user: "root",
  password: "devmanuel2006",
  database: "rvsprice",
});
//#endregion

//#region USE

//#region Liberação de acesso de site externo
app.use(
  cors({
    origin: [
      "https://rvsprice.vercel.app",
      "http://localhost:3000",
      "http://192.168.100.18:3000",
    ],
    optionsSuccessStatus: 200,
    allowedHeaders: ["Content-Type", "Authorization"],
  })
);
//#endregion

//#region Utilização do express para rodar o servidor
app.use(bodyParser.json({ limit: "100mb" }));
//#endregion

//#endregion

//#region GET

//#region Teste de conexão realizada pelo navegador
app.get("/teste-conexao", (req, res) => {
  Banco_De_Dados.getConnection((err, connection) => {
    if (err) {
      console.error("Erro ao conectar ao banco de dados:", err);
      res
        .status(500)
        .send("Erro ao conectar ao banco de dados: " + err + dom.serialize());
    } else {
      console.log("Conexão bem-sucedida ao banco de dados");
      connection.release();
      res
        .status(200)
        .send("Conexão bem-sucedida ao banco de dados" + dom.serialize());
    }
  });
});
//#endregion

//#region Informação de servidor rodando, acessando pasta raiz no navegador
app.get("/", (Requisicao, Resposta) => {
  Resposta.send("Servidor rodando" + dom.serialize());
});
//#endregion

//#endregion

//#region POST

//#region Sistema de validação de login
app.post("/validar", (Requisicao, Resposta) => {
  const { User, Senha } = Requisicao.body;

  console.log();
  console.log(
    "--------------------------------------------------------------------------"
  );

  console.log("Usuario: " + User);
  console.log("Senha: " + Senha);

  var Sintaxe_SQL_Verificacao_De_Usuario =
    "SELECT CASE WHEN COUNT(*) > 0 THEN 'true' ELSE 'false' END AS resultado FROM  usuarios WHERE nome = " +
    '"' +
    User +
    '"' +
    ";";
  var Sintaxe_SQL_Verificacao_De_Senha =
    "SELECT CASE WHEN COUNT(*) > 0 THEN 'true' ELSE 'false' END AS resultado FROM  usuarios WHERE senha = " +
    '"' +
    Senha +
    '"' +
    ";";
  var Sintaxe_SQL_Obter_Token =
    "SELECT token FROM usuarios WHERE nome = " + '"' + User + '"' + ";";

  var Resultado_Validacao_User;
  var Resultado_Validacao_Senha;
  var Token_User;

  // console.log("Sintaxe: " + Sintaxe_SQL_Verificacao_De_Usuario);
  // console.log("Sintaxe: " + Sintaxe_SQL_Verificacao_De_Senha);
  // console.log("Sintaxe: " + Sintaxe_SQL_Obter_Token);

  Banco_De_Dados.query(
    Sintaxe_SQL_Verificacao_De_Usuario,
    (erro, Resultado) => {
      console.log("Erro: " + erro);
      Resultado.map((item) => {
        Resultado_Validacao_User = item.resultado;
      });
      console.log(
        "Resultado da validacao de usuario: " + Resultado_Validacao_User
      );
      return Resultado_Validacao_User;
    }
  );
  Banco_De_Dados.query(Sintaxe_SQL_Obter_Token, (erro, Resultado) => {
    console.log("Erro: " + erro);
    Resultado.map((item) => {
      Token_User = item.token;
    });
    console.log("Token: " + Token_User);
    return Token_User;
  });
  setTimeout(() => {
    Banco_De_Dados.query(
      Sintaxe_SQL_Verificacao_De_Senha,
      (erro, Resultado) => {
        console.log("Erro: " + erro);
        Resultado.map((item) => {
          Resultado_Validacao_Senha = item.resultado;
        });
        console.log(
          "Resultado da validacao de senha: " + Resultado_Validacao_Senha
        );
        if (
          Resultado_Validacao_User == "true" &&
          Resultado_Validacao_Senha == "true" &&
          Token_User
        ) {
          console.log("Usuário valido.");
          console.log(
            "--------------------------------------------------------------------------"
          );
          console.log();
          Resposta.send({ permitir: true, token: Token_User });
        } else {
          console.log("Usuário invalido.");
          console.log(
            "--------------------------------------------------------------------------"
          );
          console.log();
          Resposta.send({ permitir: false });
        }
      }
    );
  }, 1000);
});
//#endregion

//#region Sistema de cadastro de produtos
app.post("/cadastrar", (Requisicao, Resposta) => {
  const {
    Imagem_Produto,
    Nome_Produto,
    Valor_Produto_Formatado,
    Nome_Mercado,
    Categoria,
    Informacoes_Adicionais,
    Outros_Nomes,
  } = Requisicao.body;

  if (
    !Imagem_Produto ||
    Imagem_Produto == "/static/media/Sem_Imagem.60408411369fbfea2d38.webp"
  ) {
    Resposta.send("Está faltando adicionar a imagem", { imagem: false });
  } else if (!Nome_Produto) {
    Resposta.send("Está faltando adicionar o nome", { nome: false });
  } else if (!Valor_Produto_Formatado) {
    Resposta.send("Está faltando adicionar o valor", { valor: false });
  } else if (!Nome_Mercado) {
    Resposta.send("Está faltando adicionar o mercado", { mercado: false });
  } else if (!Categoria) {
    Resposta.send("Está faltando adicionar a categoria", { categoria: false });
  } else {
    console.log("Itens requiridos verificados!");
  }

  console.log("Imagem: " + Imagem_Produto);
  console.log("Nome: " + Nome_Produto);
  console.log("Valor: " + Valor_Produto_Formatado);
  console.log("Mercado: " + Nome_Mercado);
  console.log("Categoria: " + Categoria);
  console.log("Informacoes: " + Informacoes_Adicionais);
  console.log("Outros Nomes: " + Outros_Nomes);

  var Sintaxe_SQL_Insercao_De_Dados =
    'INSERT INTO produtos(Nome, Preco, Mercado, Categoria, Informacoes_Adicionais, Outros_Nomes, Imagem) values ("' +
    Nome_Produto +
    '", "' +
    Valor_Produto_Formatado +
    '", "' +
    Nome_Mercado +
    '", "' +
    Categoria +
    '", "' +
    Informacoes_Adicionais +
    '", "' +
    Outros_Nomes +
    '", "' +
    Imagem_Produto +
    '");';

  setTimeout(() => {
    Banco_De_Dados.query(Sintaxe_SQL_Insercao_De_Dados, (erro, Resultado) => {
      if (erro) {
        console.log(erro);
      } else {
        console.log(Resultado);
        Resposta.send({ cadastro_realizado: true });
      }
    });
  }, 1000);
});
//#endregion

//#region Obtendo Produtos cadastrados no banco de dados
app.post("/pesquisa-categoria-produto", (Requisicao, Resposta) => {
  const { Categoria_Para_Pesquisa, Filtro_De_Pesquisa } = Requisicao.body;

  var Sintaxe_SQL_Pesquisa_De_Produtos;

  if (Filtro_De_Pesquisa) {
    var Sintaxe_SQL_Pesquisa_De_Produtos =
      'SELECT * FROM produtos WHERE Categoria LIKE "%' +
      Categoria_Para_Pesquisa +
      '%"' +
      'AND Mercado LIKE "%' +
      Filtro_De_Pesquisa +
      '%"';
  } else {
    var Sintaxe_SQL_Pesquisa_De_Produtos =
      'SELECT * FROM produtos WHERE Categoria LIKE "%' +
      Categoria_Para_Pesquisa +
      '%";';
  }

  setTimeout(() => {
    Banco_De_Dados.query(
      Sintaxe_SQL_Pesquisa_De_Produtos,
      (erro, Resultado) => {
        if (erro) {
          console.log(erro);
        } else {
          Resposta.send({ produtos_achados: Resultado });
        }
      }
    );
  }, 1000);
});
//#endregion

//#endregion

//#region Local onde está rodando o servidor e aviso
app.listen(5000, () => {
  console.log("Servidor na porta 5000 atualmente");
});
//#endregion
