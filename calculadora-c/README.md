# Calculadora Robusta em C 🧮

Este é um projeto de calculadora desenvolvido em linguagem C focado em **estabilidade, tratamento de erros e experiência do usuário**.

## 🚀 Diferenciais do Projeto
Diferente de calculadoras simples que travam ou entram em loop infinito quando o usuário digita uma letra por engano, este programa foi projetado para ser "inquebrável":
- **Tratamento de Strings com `fgets`**: Captura a entrada inteira como texto antes de avaliar, prevenindo estouro de buffer (overflow).
- **Conversão Segura com `strtol`/`strtof`**: Valida rigorosamente se o que foi digitado é realmente um número ou se contém caracteres inválidos.
- **Suporte Regional (`setlocale`)**: Aceita automaticamente tanto o ponto quanto a vírgula como separadores decimais (ex: `5.5` ou `5,5`).
- **Proteção contra Divisão por Zero**: Evita falhas críticas de execução no sistema.

## 🛠️ Como Executar
1. Instale um compilador C (como o GCC).
2. Compile o arquivo:
   ```bash
   gcc calculadora.c -o calculadora
   ```
3. Execute o programa:
   ```bash
   ./calculadora
   ```
