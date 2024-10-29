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

//#region __ Informações para acesso de Banco de Dados
const Banco_De_Dados = mysql.createPool({
  host: "127.0.0.1",
  port: 3306,
  user: "root",
  password: "devmanuel2006",
  database: "rvsprice",
});
//#endregion __

//#region USE

//#region __ Liberação de acesso de site externo
app.use(
  cors({
    origin: ["http://localhost:3000", "http://192.168.100.18:3000"],
    optionsSuccessStatus: 200,
    allowedHeaders: ["Content-Type", "Authorization"],
  })
);
//#endregion __

//#region __ Utilização do express para rodar o servidor
app.use(bodyParser.json({ limit: "100mb" }));
//#endregion

//#endregion __

//#region GET

//#region __ Teste de conexão realizada pelo navegador
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
//#endregion __

//#region __ Informação de servidor rodando, acessando pasta raiz no navegador
app.get("/", (Requisicao, Resposta) => {
  Resposta.send("Servidor rodando" + dom.serialize());
});
//#endregion __

//#endregion

//#region POST

//#region __ Exemplo de consulta
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
//#endregion __

//#endregion

//#region Local onde está rodando o servidor e aviso
app.listen(5000, () => {
  console.log("Servidor na porta 5000 atualmente");
});
//#endregion
