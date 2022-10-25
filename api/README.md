###
Código em Node usando Express (api.js)

Load Balancer => Porta 80

Instancias => Porta 3333

Código rodando no load balancer (porta 80 redirecionando pra instancias 1 e 2) 76 reais conversão

![loadconv-76](https://user-images.githubusercontent.com/22060317/197898781-dbcfba67-4cee-4059-949f-730202f17e2e.jpg)
###
Código rodando no load balancer (porta 80 redirecionando pra instancias 1 e 2) 1 reais conversão
![loadconv-1](https://user-images.githubusercontent.com/22060317/197898786-1ac718f7-42d0-4fdd-9d79-913ee9da1a05.jpg)

Teste para ver se está redirecionando para maquina 1 -> status(200) "ok"
![api1](https://user-images.githubusercontent.com/22060317/197898784-9c107a70-e69d-470c-ae46-5ef330216a16.jpg)

Teste para ver se está redirecionando para maquina 2 -> status(200) "ok 2"
![api2](https://user-images.githubusercontent.com/22060317/197898785-9267dfd6-07b8-42fb-81fb-d6acd131e5df.jpg)
