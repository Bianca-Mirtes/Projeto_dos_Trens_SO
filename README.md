# 🚂 Projeto dos Trens com deadlock 

### O trabalho consiste no desenvolvimento de uma malha ferroviária que comporta 5 trens, todos circulando no sentido horário.
### Cada trem (quadrados coloridos na imagem anterior) circula em sua malha (quadrado com linhas em azul) sem colidir com os demais trens. Além disso, se um trem pode se mover sem causar colisão ou deadlock, ele deve se mover.
### A implementação considera a existência de 7 regiões críticas diferentes (regiões de colisão entre trens) controladas por "semáforos", destacadas e numeradas na imagem a seguir.
<br>

<p align="center">
<img src="https://user-images.githubusercontent.com/71523376/202059247-5c450442-bec0-46d2-ab2e-3276de6438f5.png">
</p>

# 💻 Requisitos

* ### Qt 6.4.0
* ### MinGW 11.2.0 64-bit for C++

 * ## Como rodar:
  1. Abra o Qt creator

  2. Abre um projeto

  3. Encontre o arquivo "ProjetoTrens_SO.pro" localizado dentro desse repositório

  4. Faça o build pelo qt

  5. Execute pelo qt



# 🚦 Funcionamento 
### Cada trem é uma thread independente que possui velocidade própria alterada por um controlador de velocidade, que está implementado na interface visual. Utilizamos a biblioteca semaphore.h para administrar o acesso às regiões críticas, onde podem haver colisões dos trens. 

***

# 🚈 Interface desenvolvida 

<p align="center">
<img src="https://user-images.githubusercontent.com/71523376/202059212-3942d545-6c54-466a-bdac-9a42a5845000.png">
</p>

# 🤝 Colaboradores
  * ### [Bianca Mirtes](https://github.com/Bianca-Mirtes)
  * ### [Danrley Lima](https://github.com/Danrley-Lima)
