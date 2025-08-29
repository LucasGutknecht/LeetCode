#include <string.h>

int lengthOfLongestSubstring(char *s)
{
  // Inicializar ponteiros esquerdo e direito para rastrear a janela deslizante.
  // Left significa o inicio da substring atual.
  int left = 0;

  // Right significa o final da substring atual.
  int right = 0;

  // Usando malloc para alocar memoria para lastSeen.
  int* lastSeen = malloc(256 * sizeof(int));

  // Adicionar opcao de nunca visto(-1), dado que malloc nao zera a memoria mas contem valores aleatorios.
  for (int i = 0; i < 256; i++)
  {
    lastSeen[i] = -1;
  }

  // Inicializar variaveis para rastrear o comprimento maximo e o comprimento atual.
  int maxLength = 0;
  int currentLength = 0;

  // Variavel para obter o tamanho da string.
  int stringSize = strlen(s);

  // Loop executado enquanto o ponteiro direito for menor que o tamanho da string
  /*
     Nesse caso, o loop funciona assim:
      1. O ponteiro direito (right) começa no inicio da string e se move para a direita, um caractere de cada vez.
      2. Para cada caractere, verificamos se ele ja foi visto antes (usando lastSeen).
      3. Se o caractere foi visto e está dentro da janela atual (ou seja, seu indice e maior ou igual a left), movemos o ponteiro esquerdo (left) para a direita do ultimo indice visto desse caractere.
      4. Atualizamos o indice do caractere atual no lastSeen.
      5. Calculamos o comprimento atual da substring (right - left + 1) e atualizamos o comprimento máximo, se necessário.
  */
  while (right < stringSize)
  {
    // Busca o caractere atual
    char charActual = s[right];

    // Verifica se o caractere atual foi visto antes
    if (lastSeen[(unsigned char) charActual] >= left)
    {
      // Se o caracter foi visto, movemos o ponteiro esquerdo
      left = lastSeen[(unsigned char) charActual] + 1;
    }

    // Atualiza o indice do caractere atual no lastSeen.
    lastSeen[(unsigned char) charActual] = right;

    // Calcula o comprimento da substring atual.
    currentLength = right - left + 1;

    // Atualiza o comprimento maximo, se necessario.
    if (currentLength > maxLength)
    {
      maxLength = currentLength;
    }

    right++;
  }

  // libera memoria
  free(lastSeen);

  // Retorna o tamanho da substring maxima.
  return maxLength;

}
