const express = require('express')
const app = express()
const axios = require('axios')


app.use(express.json())


app.get("/", (req, res) => {
    return res.status(200).send("Ok ")
});


app.get("/convertemoeda/:valor", async (req, res) => {
    const { valor } = req.params
    console.log(valor)
    let dolar, euro;
    await axios.get('https://economia.awesomeapi.com.br/json/last/USD-BRL,EUR-BRL')
        .then(function(response) {
            //console.log(response.data);
            dolar = response.data.USDBRL.low;
            euro = response.data.EURBRL.low;
            //console.log(response.data)
    });
    return res.status(200).json({ conversao: [{'real': valor, 'dolar': (valor/dolar).toFixed(2), 'euro': (valor/euro).toFixed(2)}]})
});


app.listen(3333, () => {
    console.log('Rodando servidor')
})
