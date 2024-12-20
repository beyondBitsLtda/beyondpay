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
    - Filtro por data
    - Filtro por categoria
- **Total por Categoria:**
  - O sistema deve calcular e exibir o total de transações por categoria.

---

### 3. Cálculo de Saldo
**Funcionalidades:**
- **Cálculo do Saldo Atual:**
  - O sistema deve calcular o saldo atual com base nas transações registradas.
- **Filtros Opcionais:**
  - O sistema deve permitir a aplicação de filtros para o cálculo do saldo:
    - Filtro por data
    - Filtro por categoria

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

## Requisitos Não Funcionais

### 1. Interface Gráfica
- **Descrição:** O sistema deve ter uma interface gráfica amigável e intuitiva.
- **RNF:** Pesquisar e utilizar uma biblioteca de GUI apropriada (por exemplo, GTK, Qt, etc.).

### 2. Performance
- **Descrição:** O sistema deve ser capaz de processar e exibir transações rapidamente, mesmo com um grande número de registros.
- **RNF:** O tempo de resposta para a visualização de transações não deve exceder 2 segundos.

### 3. Segurança
- **Descrição:** Os dados das transações devem ser armazenados de forma segura.
- **RNF:** Utilizar métodos de criptografia para proteger os dados armazenados no arquivo.

### 4. Compatibilidade
- **Descrição:** O sistema deve ser compatível com diferentes sistemas operacionais (Windows, Linux, macOS).
- **RNF:** O código deve ser portável e utilizar bibliotecas multiplataforma sempre que possível.

### 5. Manutenibilidade
- **Descrição:** O código do sistema deve ser modular e bem documentado para facilitar a manutenção e futuras expansões.
- **RNF:** Seguir as melhores práticas de programação e padrões de codificação.

### 6. Usabilidade
- **Descrição:** O sistema deve ser fácil de usar, com uma curva de aprendizado mínima para novos usuários.
- **RNF:** Realizar testes de usabilidade com usuários finais para identificar e corrigir problemas de interface.

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
