# I2C Scan
Script simples para varrer o barramento I2C em busca de dispositivos. Se um dispositivo for encontrado, seu endereço será reportado na serial.

## :dart: Funcionamento
  1. Conecte somente o dispositivo no arduino utilizando os pinos de `SDA` e `SCL`;
  2. Rode o programa e abra a serial com `baud rate` igual a 9600;
  3. Ao final da varredura, será exibido o endereço do dispositivo, se encontrado. 


## 🔥 Instalação e execução

* Utilizando o [PlataformIO](https://platformio.org/platformio-ide)
  1. Faça um clone desse repositório;
  2. Dentro da interface do PlataformIO navegue até `Projects` e depois selecione `Add Existing`;
  3. Selecione a pasta `I2Cscan` que foi clonada anteriormente.
    

## :warning: Observações
  * O script possui um `feedback` visual para arduinos. Durante a varredura o `LED_BUILTIN` permanecera acesso e, finalizada a varredura, ficara em modo `blink`;
  * Se o endereço for encontrado, será mostrado em `decimal` e `hexadecimal` ao final do script.


<a id="ancora3"></a>
## :link: Links Úteis

1. [Pinout Arduino Uno](https://www.circuito.io/blog/arduino-uno-pinout/)
2. [Sobre o protocolo I2C](https://www.circuitbasics.com/basics-of-the-i2c-communication-protocol/)


## ⚡️ Como contribuir

- Faça um fork desse repositório;
- Cria uma branch com a sua feature: `git checkout -b minha-feature`;
- Faça commit das suas alterações: `git commit -m 'feat: Minha nova feature'`;
- Faça push para a sua branch: `git push origin minha-feature`.

Depois que o merge da sua pull request for feito, você pode deletar a sua branch.


## :memo: Licença

Esse projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
