## Modificações realizadas
## Nathaly Loggiovini

## Disciplina: Processamento Gráfico

Realizei as seguintes modificações e melhorias no código da Tarefa | Jogo das Cores

*Centralização da grade na janela:* 

Ajustei o cálculo das posições dos retângulos para que a grade de cores fique centralizada e preencha a área útil da janela, sem deixar espaços vazios.

*Correção do clique do mouse:*  

Corrigi a conversão das coordenadas do mouse para o índice correto da matriz da grade, garantindo que o clique do usuário corresponda exatamente ao retângulo selecionado.

*Implementação da lógica de eliminação:*  

Ao clicar em um retângulo, implementei a verificação de semelhança de cor entre ele e os demais retângulos. Os retângulos com cores próximas são eliminados, e a pontuação é atualizada conforme o desempenho do jogador.

*Aprimoramento das mensagens do jogo:*  

Melhorei as mensagens exibidas no terminal, deixando o fim de jogo mais bonito e garantir um melhor entendimento.

*Adoção das práticas recomendadas da atividade:*  

Segui as orientações do enunciado, utilizando exclusivamente recursos do OpenGL moderno (OpenGL 3.3+), VBO, VAO, shaders (GLSL) e uniforms, sem utilizar comandos das versões antigas do OpenGL.

**Os detalhes de cada modificação, os pontos principais do código alterado estão sinalizados com comentários ou podem ser encontrados nas funções main, mouse_button_callback e eliminarSimilares.**

## Lógica de Reinício do Jogo

O jogo agora permite que o usuário reinicie a partida pressionando a tecla **R** a qualquer momento após o fim do jogo. Ao pressionar "R", todas as variáveis de controle, como pontuação, tentativas e a grade de cores, são reinicializadas, possibilitando um novo jogo sem precisar fechar e abrir a janela. Este comportamento foi implementado utilizando uma função `resetGame()` e a verificação da tecla no callback de teclado (`key_callback`).

## Obrigada