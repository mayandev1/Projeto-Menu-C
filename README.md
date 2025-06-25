# 🛒 Projeto Menu de Estoque em C

![GitHub](https://img.shields.io/badge/license-MIT-blue)

Um sistema completo de gerenciamento de estoque desenvolvido em C com operações CRUD (Create, Read, Update, Delete) e suporte à persistência de dados em arquivos.

## 🌟 Recursos Principais

| Funcionalidade     | Descrição                                                      |
|--------------------|----------------------------------------------------------------|
| 📦 **Cadastro**     | Adicione novos itens ao estoque com todos os detalhes         |
| 📋 **Listagem**     | Visualize todos os produtos cadastrados de forma organizada   |
| ✏️ **Edição**       | Atualize informações de itens existentes                      |
| 🔍 **Busca**        | Encontre produtos específicos por ID                          |
| 🗑️ **Remoção**      | Delete itens do estoque quando necessário                     |
| 📁 **Importação**   | Carregue produtos de um arquivo `.txt` formatado              |
| 💾 **Exportação**   | Salve o estoque atual em um arquivo `.txt` para uso posterior |

## 🚀 Começando

### Pré-requisitos
- Compilador GCC (ou MinGW no Windows)
- Terminal/Command Prompt

### Instalação e Execução

```bash
# Clone o repositório
git clone https://github.com/mayandev1/Projeto-Menu-C.git

# Navegue até o diretório
cd Projeto-Menu-C

# Compile o programa
gcc -Wall -Iview/modules view/main.c view/modules/func_estoque.c view/modules/utils.c view/modules/prototype_print.c -o programa

# Execute
./programa.exe
````

## 🏗️ Estrutura do Projeto

```
📦 view
├── 📜 main.c                 # Ponto de entrada do programa
└── 📂 modules
    ├── 📜 func_estoque.c      # Núcleo das operações de estoque
    ├── 📜 func_estoque.h      # Definições e estruturas
    ├── 📜 utils.c             # Funções utilitárias
    ├── 📜 utils.h
    ├── 📜 prototype_print.c   # Interface do usuário
    └── 📜 prototype_print.h
```

## 🎯 Funcionalidades Detalhadas

### ✔️ Validações Robusta

* Verificação de tipos de entrada
* Prevenção contra IDs duplicados
* Validação de nomes e intervalos numéricos

### 💾 Persistência de Dados em Arquivos `.txt`

* ✅ **Carregamento**: use a opção 6 do menu para importar um arquivo com produtos no formato:
  `id,nome,quantidade,preco`
* ✅ **Salvamento**: use a opção 7 do menu para exportar o estoque atual para um arquivo

### 🖥️ Interface Intuitiva

* Menu interativo
* Feedback claro das operações
* Formatação consistente

## 📁 Exemplo de arquivo de estoque

```txt
1001,Arroz,20,4.99
1002,Feijao,15,6.50
1003,Macarrao,30,3.75
```

## 🤝 Contribuição

Contribuições são bem-vindas! Siga estes passos:

1. Faça um Fork do projeto
2. Crie sua Branch (`git checkout -b feature/NovaFeature`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova feature'`)
4. Push para a Branch (`git push origin feature/NovaFeature`)
5. Abra um Pull Request

## 📜 Licença

Distribuído sob licença MIT. Veja `LICENSE` para mais informações.

## ✉️ Contato

Desenvolvido por Mayan Gabriel - mayangabriel654@gmail.com

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/mayandev1)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logoColor=white)