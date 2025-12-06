# 📑 Index - Sistema de Navegação

> Menu central para navegação entre todos os projetos CRUD do portfolio.

---

## 📋 **Sobre**

O **Index** é o ponto de entrada do portfolio, oferecendo uma interface limpa e intuitiva para navegar entre os diferentes sistemas CRUD implementados.

---

## 🎯 **Funcionalidades**

- ✅ Menu interativo com 9 opções de CRUDs
- ✅ Navegação entre projetos
- ✅ Validação robusta de entrada (previne letras)
- ✅ Sistema de retorno ao menu principal
- ✅ Interface visual padronizada

---

## 🛠️ **Conceitos Aplicados**

| Conceito | Descrição |
|----------|-----------|
| **Switch-case** | Estrutura de seleção múltipla para navegação |
| **Loops** | `do-while` para manter o programa ativo |
| **Modularização** | Funções separadas para cada CRUD |
| **Validação** | Verificação de retorno do `scanf` |
| **Buffer** | Limpeza adequada do buffer de entrada |

---

## 📸 **Demonstração**
```
|========================================|
|              INDEX CRUDS               |
|========================================|

   [1] Biblioteca
   [2] Contatos
   [3] Alunos
   [4] Produtos
   [5] Usuários
   [6] Playlist
   [7] Veículos
   [8] Receitas
   [9] Filmes
   [0] Sair

Escolha: _
```

---

## 🔍 **Detalhes Técnicos**

### **Validação de Entrada**

O sistema implementa validação robusta que:
1. Verifica se `scanf` conseguiu ler um número inteiro
2. Se falhar (usuário digitou letra), solicita nova entrada
3. Loop continua até entrada válida
```c
int lerOpcaoValida() {
    int op;
    int leitura;
    
    do {
        leitura = scanf("%d", &op);
        limparBuffer();
        
        if(leitura == 0) {
            printf("❌ Entrada inválida! Digite um número: ");
        }
    } while(leitura == 0);
    
    return op;
}
```

### **Fluxo de Execução**
```
┌─────────────────┐
│  Exibir Menu    │
└────────┬────────┘
         │
┌────────▼────────┐
│  Ler Opção      │
│  (validada)     │
└────────┬────────┘
         │
┌────────▼────────┐
│  Limpar Tela    │
└────────┬────────┘
         │
┌────────▼────────┐
│  Executar CRUD  │
└────────┬────────┘
         │
┌────────▼────────┐
│  Pausar         │
└────────┬────────┘
         │
┌────────▼────────┐
│  Limpar Tela    │
└────────┬────────┘
         │
         └──────► Repetir (se opção ≠ 0)
```

---

## 💻 **Como Executar**

### **Compilação:**
```bash
gcc main.c -o index.exe
```

### **Execução:**
```bash
./index.exe
```

---

## 📝 **Estrutura do Código**
```c
// Protótipos
void menu();
void limparBuffer();
int lerOpcaoValida();  // Validação robusta
void biblioteca();
void contatos();
// ... outros CRUDs

// Main com loop e switch
int main() {
    do {
        // Menu → Escolha → Ação → Pausa → Repetir
    } while(op != 0);
}
```

---

## 🎓 **Aprendizados**

- ✅ Estruturação de menu interativo
- ✅ Validação de entrada do usuário
- ✅ Modularização com funções
- ✅ Controle de fluxo com switch-case
- ✅ Limpeza de buffer
- ✅ Interface de usuário em terminal

---

## 🔄 **Próximas Melhorias**

- [ ] Adicionar cores no terminal (ANSI codes)
- [ ] Implementar histórico de navegação
- [ ] Adicionar sistema de ajuda (tecla H)
- [ ] Estatísticas de uso (contador de acessos)

---

## 📊 **Status**
```
✅ Concluído e funcional
✅ Validação implementada
✅ Código limpo e documentado
✅ Pronto para integração com CRUDs
```

---

<p align="center">
  <strong>Projeto 01/10 - Portfolio SENAI</strong>
</p>