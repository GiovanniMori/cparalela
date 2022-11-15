const express = require("express");
const app = express();
const fs = require("fs");
const uuid = require("uuid");

conta = [1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000];
acesso = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
operacao = 0;
token = [];

fs.writeFile("log.txt", "", function (err) {
  if (err) throw err;
  console.log("Log Criado");
});

app.use(express.json());
app.get("/", async (req, res) => {
  let uid = uuid.v1();
  token.push(uid);
  return res.status(200).json(uid);
});

const tokenIsValid = function (req, res, next) {
  console.log(req.headers.token);
  if (token.includes(req.headers.token)) {
    console.log("token valido");
    next();
  } else {
    console.log("token invalido");
    return res.status(403).json("Token Inválido");
  }
};
app.use(tokenIsValid);

app.post("/deposito/:acnt/:amt", async (req, res) => {
  if (acesso[req.params.acnt] == 0) {
    acesso[req.params.acnt] = 1;
    console.log(acesso);
    console.log(req.params);
    conta[req.params.acnt] += parseFloat(req.params.amt);
    var ip = req.socket.remoteAddress;

    fs.appendFile(
      "log.txt",
      `${Date.now()} - ${operacao} - ${ip} - Depósito - ${req.params.acnt} - ${
        req.params.amt
      }\n`,
      function (err) {
        if (err) throw err;
      }
    );
    operacao += 1;
    acesso[req.params.acnt] = 0;
    return res.status(200).json(conta[req.params.acnt]);
  } else {
    return res.status(200).json("Conta sendo acessada por outra máquina");
  }
});

app.delete("/saque/:acnt/:amt", async (req, res) => {
  console.log(req.params);
  var ip = req.socket.remoteAddress;
  if (acesso[req.params.acnt] == 0) {
    acesso[req.params.acnt] = 1;
    if (conta[req.params.acnt] < req.params.amt) {
      acesso[req.params.acnt] = 0;
      return res.status(200).json("Saque maior do que saldo na conta");
    }
    conta[req.params.acnt] -= parseFloat(req.params.amt);

    acesso[req.params.acnt] = 0;
    fs.appendFile(
      "log.txt",
      `${Date.now()} - ${operacao} - ${ip} - Saque - ${req.params.acnt} - ${
        req.params.amt
      }\n`,
      function (err) {
        if (err) throw err;
      }
    );
    operacao += 1;
    return res.status(200).json(conta[req.params.acnt]);
  } else {
    return res.status(200).json("Conta sendo acessada por outra máquina");
  }
});

app.get("/saldo/:acnt/", async (req, res) => {
  console.log(req.params);

  var ip = req.socket.remoteAddress;
  fs.appendFile(
    "log.txt",
    `${Date.now()} - ${operacao} - ${ip} - saldo - ${req.params.acnt} \n`,
    function (err) {
      if (err) throw err;
    }
  );
  operacao += 1;
  return res.status(200).json(conta[req.params.acnt]);
});

app.patch("/transferencia/:acnt_orig/:acnt_dest/:amt", async (req, res) => {
  console.log(req.params);
  var ip = req.socket.remoteAddress;
  if (acesso[req.params.acnt_orig] == 0) {
    acesso[req.params.acnt_orig] = 1;
    if (conta[req.params.acnt_orig] < req.params.amt) {
      acesso[req.params.acnt_orig] = 0;
      return res.status(200).json("Transferência Negada: Saldo Insuficiente");
    }
    conta[req.params.acnt_orig] -= parseFloat(req.params.amt);
    conta[req.params.acnt_dest] += parseFloat(req.params.amt);

    acesso[req.params.acnt_orig] = 0;
    fs.appendFile(
      "log.txt",
      `${Date.now()} - ${operacao} - ${ip} - Transferencia - ${
        req.params.acnt_orig
      }  para  ${req.params.acnt_dest} - ${req.params.amt}\n`,
      function (err) {
        if (err) throw err;
      }
    );
    operacao += 1;
    return res
      .status(200)
      .send(
        `Conta ${req.params.acnt_orig} transferiu ${req.params.amt} para conta ${req.params.acnt_dest}`
      );
  } else {
    return res.status(200).json("Conta sendo acessada por outra máquina");
  }
});

app.listen(3001, () => {
  console.log("Rodando servidor");
});
