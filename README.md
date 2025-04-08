<p align="center">
 <img width="1000" src="https://github.com/beyondBitsLtda/beyondpay/blob/main/logo.jpg" alt="icon"/>
</p>


# Projeto BeyondPay

## Descrição
Este projeto consiste no desenvolvimento de um sistema de gestão financeira com funcionalidades para registrar, visualizar e calcular transações financeiras, bem como gerar relatórios e salvar os dados de forma segura e eficiente.

---

## Requisitos Funcionais

### 1. Registro de Transações
**Funcionalidades:**
- **Data da Transação:**
  - Deve ser indicada pelo usuário.
  - **RNF:** A data deve ser validada para garantir que esteja no formato correto (dd/mm/aaaa).
- **Descrição:**
  - O usuário deve poder fornecer uma descrição para a transação.
- **Valor:**
  - O usuário deve poder inserir o valor da transação.
  - **RNF:** O valor deve ser validado para garantir que seja um número positivo.
- **Categoria:**
  - O usuário deve poder selecionar ou inserir uma categoria para a transação.
  - **RNF:** Deve haver uma lista de categorias predefinidas, mas o usuário também deve poder adicionar novas categorias.

---

### 2. Visualização de Transações
**Funcionalidades:**
- **Listagem de Transações:**
  - O sistema deve permitir a visualização de todas as transações registradas com os seguintes campos:
    - Data da transação
    - Descrição
    - Valor
    - Categoria
- **Filtros Opcionais:**
  - O sistema deve permitir a aplicação de filtros para a visualização das transações:
    - Filtro por categoria
---

### 3. Cálculo de Saldo
**Funcionalidades:**
- **Cálculo do Saldo Atual:**
  - O sistema deve calcular o saldo atual com base nas transações registradas.
---

### 4. Relatórios Simples
**Funcionalidades:**
- **Relatório por Categoria:**
  - O sistema deve gerar um relatório das transações agrupadas por categoria.
- **Relatório por Período:**
  - O sistema deve gerar um relatório das transações em um período especificado pelo usuário.

---

### 5. Persistência de Dados
**Funcionalidades:**
- **Salvar Transações:**
  - O sistema deve permitir salvar todas as transações em um arquivo.
- **Carregar Transações:**
  - O sistema deve permitir carregar transações de um arquivo salvo anteriormente.

---

## Como Contribuir
1. Faça um fork do repositório.
2. Crie uma branch para sua funcionalidade: `git checkout -b minha-funcionalidade`.
3. Faça commit das suas alterações: `git commit -m 'Adiciona nova funcionalidade'`.
4. Envie para o repositório remoto: `git push origin minha-funcionalidade`.
5. Abra um Pull Request.

---

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).
