# 🎓 Sistema de Controle Acadêmico

Este projeto foi desenvolvido como parte do curso de **Análise e Desenvolvimento de Sistemas**, tendo como objetivo criar um **sistema completo de controle acadêmico** em linguagem **C**.  

O sistema permite **cadastrar alunos, inserir notas e calcular médias**, utilizando **structs** para representar **Curso**, **Aluno** e **Disciplina**, dentro de uma estrutura geral chamada **Base**.

---

## 🧩 Estrutura Geral do Projeto

O sistema foi construído seguindo o modelo **CRUD (Create, Read, Update, Delete)**, permitindo:

- Adicionar alunos à base de dados  
- Consultar alunos e seus boletins  
- Atualizar notas  
- Remover alunos  

---

## 🏗️ Estruturas (Structs)

O projeto utiliza **4 structs principais**, organizadas hierarquicamente:

### 1. `Base`
- Contém um array de alunos (`Aluno alunos[]`)
- Armazena a quantidade de alunos cadastrados (`int quantAlunos`)

### 2. `Aluno`
- `int id` → Identificador único do aluno  
- `char nome[50]` → Nome completo  
- `int idade` → Idade do aluno  
- `Curso curso` → Curso matriculado (Ensino Médio ou Química)

### 3. `Curso`
- `char titulo[50]` → Nome do curso  
- `Disciplina disciplinas[]` → Lista de disciplinas do curso

### 4. `Disciplina`
- `char titulo[50]` → Nome da disciplina  
- `int cargaHoraria` → Carga horária da disciplina  
- `float notas[2]` → Duas notas referentes às avaliações do semestre  
- `float media` → Média aritmética calculada a partir das notas  

---

## 📚 Cursos e Disciplinas Padrão

O sistema já vem pré-configurado com dois cursos e suas disciplinas:

### 🏫 Ensino Médio (`E_M_`)
- Matemática  
- Português  
- História  
- Geografia  

### ⚗️ Química (`Quimica`)
- Análise Instrumental  
- Química Orgânica  
- Físico-Química  
- Química Analítica  

Cada disciplina possui sua carga horária e começa com notas e médias zeradas.

Além disso, há uma **base inicial (`baseAlunos`)** vazia, com `quantAlunos = 0`.

---

## ⚙️ Funções Principais

O projeto contém **9 funções** principais, responsáveis pela manipulação dos dados:

| Função | Descrição |
|--------|------------|
| `void atualizarMedia(Disciplina *disp)` | Calcula e atualiza a média aritmética das notas de uma disciplina. |
| `Aluno* selecionarAluno(Base *base, int id)` | Retorna o ponteiro do aluno com o ID informado, ou `NULL` se não encontrado. |
| `Disciplina* selecionarDisciplina(Curso *curso, char disp[50])` | Retorna o ponteiro da disciplina com o título informado, ou `NULL` se não encontrada. |
| `void verBoletim(Aluno aluno)` | Exibe o boletim do aluno, mostrando notas, médias e curso. |
| `void verAlunos(Base base)` | Lista todos os alunos cadastrados, com IDs, nomes e cursos. |
| `void atualizarNotas(Disciplina *disp, float nota, int indice)` | Atualiza uma das duas notas da disciplina conforme o índice informado. |
| `void adicionarAluno(Base *base, Aluno aluno)` | Adiciona um novo aluno à base, define seu ID e incrementa o contador. |
| `void removerAluno(Base *base, Aluno aluno)` | Remove um aluno da base realocando os seguintes e ajustando a contagem. |

---

## 🧭 Função Principal (`main`)

O `main` implementa um **menu interativo**, onde o usuário pode:

- Adicionar, excluir e editar alunos  
- Consultar boletins  
- Inserir notas  
- Sair do sistema  

Também há **limpeza de tela a cada operação**, para manter a interface organizada e legível.

---

## 💻 Tecnologias

- Linguagem: **C**
- Paradigma: **Estruturado**
- Compilador: `gcc`

---

## 🚀 Possíveis Melhorias Futuras

- Salvar e carregar a base de dados em arquivo (`.txt` ou `.bin`)  
- Inserir novos cursos dinamicamente  
- Interface gráfica simples (ex: com `ncurses`)

---

## 🧑‍💻 Autor

**Edylan Bonfim de Melo**  
Estudante de Análise e Desenvolvimento de Sistemas - IFBAIANO
