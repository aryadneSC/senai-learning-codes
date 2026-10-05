Objetivo: criar uma página web simples, utilizando HTML para estruturar o conteúdo, CSS para estilizar a página e JavaScript para executar uma ação quando o usuário clicar em um botão.

Conceitos trabalhados:
- Variáveis (let e const).
- Strings e números.
- Operadores matemáticos.
- Funções.
- Condicionais (if e else).
- Eventos de clique, sem manipulação do DOM.

1. Situação-problema
Você foi contratado para criar uma página de boas-vindas para uma startup de tecnologia. A página deve apresentar o nome da empresa e um botão que, ao ser clicado, mostre uma mensagem personalizada ao visitante. Como desafio extra, o botão também deverá realizar uma operação matemática simples e informar se o visitante tem idade suficiente para acessar um evento fictício (18 anos).



2. Estrutura dos arquivos
Crie uma pasta chamada atividade_javascript com três arquivos:
atividade_javascript/
├── index.html
├── style.css
└── script.js

3. Desenvolvimento
TECH START

Bem-vindo à Tech Start!
Tecnologia, criatividade e inovação.
Conhecer a empresa
OBS: Ao clicar, uma mensagem aparecerá na tela.

Parte 3 – JavaScript
No arquivo script.js, crie uma função chamada mostrarMensagem().
Quando o usuário clicar no botão, a função deverá:
- Declarar uma variável com o nome da empresa.
- Declarar uma variável com uma mensagem de boas-vindas.
- Exibir um alerta com a mensagem e o nome da empresa.

Exemplo do alerta:

Olá! Seja bem-vindo à Tech Start!
Estamos felizes com sua visita.

Para executar a função, utilize o atributo onclick no botão do HTML, chamando mostrarMensagem().
