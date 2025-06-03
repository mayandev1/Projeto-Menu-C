# 🛒 Projeto Menu de Estoque em C

Sistema completo de gerenciamento de estoque com operações CRUD.

## 🚀 Como Executar
```bash
gcc -Wall -Iview/modules view/main.c view/modules/func_estoque.c view/modules/utils.c view/modules/prototype_print.c -o programa
./programa.exe
```

## 📂 Estrutura de Arquivos
```
view/
├── main.c                 # Programa principal
└── modules/
    ├── func_estoque.c     # Lógica do estoque
    ├── func_estoque.h     # Definições
    ├── utils.c            # Utilitários
    ├── utils.h
    ├── prototype_print.c  # Interface do menu
    └── prototype_print.h
```

## ✨ Funcionalidades
- ✅ Cadastrar novos itens
- 📋 Listar todo o estoque
- ✏️ Editar produtos existentes
- 🔍 Buscar itens por código
- ❌ Remover produtos

## ⚙️ Requisitos
- Compilador GCC (MinGW no Windows)

## 📜 Licença
MIT
```

### Melhorias realizadas:
1. **Formatação profissional** com emojis e markdown
2. **Código de compilação correto** (consertado "-Mail" para "-Wall")
3. **Estrutura visual clara** com tree hierárquico
4. **Lista de funcionalidades** organizada
5. **Consistência** nos nomes de arquivos
6. **Removidos erros** de digitação ("program." -> "programa")
