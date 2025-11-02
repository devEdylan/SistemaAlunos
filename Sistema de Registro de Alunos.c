#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {
    char titulo[50];
    int cargaHoraria;
    float notas[2];
    float media;
} Disciplina;

typedef struct {
    char titulo[50];
    Disciplina disciplinas[4];
} Curso;

typedef struct {
    int id;
    char nome[50];
    int idade;
    Curso curso;
} Aluno;

typedef struct {
    Aluno alunos[10];
    int quantAlunos;
} Base;

Curso E_M_ = {
    "Ensino Medio",
    {
        {"Matematica", 80, {0,0}, 0},
        {"Portugues", 60, {0,0}, 0},
        {"Historia", 70, {0,0}, 0},
        {"Geografia", 65, {0,0}, 0}
    }
};
Curso Quimica = {
    "Quimica",
    {
        {"Analise Instrumental", 80, {0,0}, 0},
        {"Quimica Organica", 90, {0,0}, 0},
        {"Fisico-Quimica", 85, {0,0}, 0},
        {"Quimica Analitica", 75, {0,0}, 0}
    },
};
Base baseAlunos = {
    {},
    0
};

void atualizarMedia(Disciplina *disp){
    float *notas = disp->notas;
    disp->media = (notas[0] + notas[1]) / 2.0;
}

Aluno* selecionarAluno(Base *base, int id){
    for (int i = 0; i < base->quantAlunos; i++){
        if (id == base->alunos[i].id){
            return &base->alunos[i];
        }
    }
    return NULL;
}

Disciplina* selecionarDisciplina(Curso *curso, char disp[50]){
    for (int i = 0; i < 4; i++){
        if (strcmp(disp, curso->disciplinas[i].titulo) == 0){
            return &curso->disciplinas[i];
        }
    }
    return NULL;
}

void verBoletim(Aluno aluno){
    putchar('\n');
    printf("Nome: %s\n", aluno.nome);
    printf("Curso: %s\n", aluno.curso.titulo);
    puts("Disciplinas:");
    for (int i = 0; i < 4; i++){
        printf("\t%-16s\tNota 1: %.1f\tNota 2: %.1f\tMedia: %.1f\n", 
            aluno.curso.disciplinas[i].titulo, 
            aluno.curso.disciplinas[i].notas[0], 
            aluno.curso.disciplinas[i].notas[1], 
            aluno.curso.disciplinas[i].media);
    }
}

void verAlunos(Base base){
    for (int i = 0; i < base.quantAlunos; i++){
        printf("ID: %d - %-16s - Curso: %s\n", base.alunos[i].id, base.alunos[i].nome, base.alunos[i].curso.titulo);
    }
}

void atualizarNotas(Disciplina *disp, float nota, int indice){
    disp->notas[indice] = nota;
    atualizarMedia(disp);
}

void adicionarAluno(Base *base, Aluno aluno){
    base->alunos[base->quantAlunos] = aluno;
    base->alunos[base->quantAlunos].id = base->quantAlunos + 1;
    base->quantAlunos++;
}

void removerAluno(Base *base, Aluno aluno){
    int *quant = &base->quantAlunos;
    Curso cursoVazio = {"", {}};
    int indice = -1;
    for (int i = 0; i < *quant; i++){
        if (base->alunos[i].id == aluno.id){
            indice = i;
        }
    }
    if (indice == -1){
        return;
    }
    for (int i = indice; i < *quant - 1; i++){
        base->alunos[i].id = base->alunos[i+1].id;
        strcpy(base->alunos[i].nome, base->alunos[i+1].nome);
        base->alunos[i].idade = base->alunos[i+1].idade;
        base->alunos[i].curso = base->alunos[i+1].curso;
    }
    base->alunos[*quant].id = -1;
    strcpy(base->alunos[*quant].nome, "");
    base->alunos[*quant].idade = -1;
    base->alunos[*quant].curso = cursoVazio;
    base->quantAlunos--;
}

int main(){
    while(1){
        int op, id;
        puts("SREMDA - Sistema de Registro e Manipulação de Dados Academicos");
        puts("1 - Adicionar aluno");
        puts("2 - Ver Boletim");
        puts("3 - Ver Alunos");
        puts("4 - Atualizar Notas");
        puts("5 - Remover Aluno");
        puts("6 - Sair");
        printf(": ");
        scanf("%d", &op);
        getchar();
        switch (op){
            case 1:
            {
                Aluno aluno;
                int curso;
                printf("Nome: ");
                fgets(aluno.nome, sizeof(aluno.nome), stdin);
                aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
                printf("Idade: ");
                scanf("%d", &aluno.idade);
                getchar();
                puts("Cursos:");
                printf("1 - Ensino Medio\n2 - Quimica\n");
                printf(": ");
                do {
                    scanf("%d", &curso);
                } while (curso != 1 && curso != 2);
                switch (curso){
                    case 1:
                        aluno.curso = E_M_;
                        break;
                    case 2:
                        aluno.curso = Quimica;
                        break;
                }
                adicionarAluno(&baseAlunos, aluno);
                break;
            }
            case 2: {
                Aluno *aluno = NULL;
                verAlunos(baseAlunos);
                putchar('\n');
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                aluno = selecionarAluno(&baseAlunos, id);
                if (aluno == NULL){
                    printf("Aluno não encontrado.");
                    break;
                }
                verBoletim(*aluno);
                break;
            }
            case 3:
                verAlunos(baseAlunos);
                break;
            case 4: {
                Aluno *aluno = NULL;
                Disciplina *disp = NULL;
                int indice;
                float nota;
                char disciplina[50];
                verAlunos(baseAlunos);
                putchar('\n');
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                aluno = selecionarAluno(&baseAlunos, id);
                if (aluno == NULL){
                    printf("Aluno não encontrado.");
                    break;
                }
                printf("Disciplina: ");
                fgets(disciplina, sizeof(disciplina), stdin);
                disciplina[strcspn(disciplina, "\n")] = '\0';
                disp = selecionarDisciplina(&aluno->curso, disciplina);
                if (disp == NULL){
                    printf("Disciplina não encontrada.");
                    break;
                }
                float *notas = disp->notas;
                printf("Nota 1: %.1f\n", notas[0]);
                printf("Nota 2: %.1f\n", notas[1]);
                printf("Nota(1 ou 2): ");
                do {
                    scanf("%d", &indice);
                } while (indice != 1 && indice != 2);
                printf("Nova nota: ");
                do {
                    scanf("%f", &nota);
                } while (nota < 0 || nota > 10);
                atualizarNotas(disp, nota, indice-1);
                break;
            }
            case 5: {
                Aluno *aluno = NULL;
                verAlunos(baseAlunos);
                putchar('\n');
                printf("ID: ");
                scanf("%d", &id);
                getchar();
                aluno = selecionarAluno(&baseAlunos, id);
                if (aluno == NULL){
                    printf("Aluno não encontrado.");
                    break;
                }
                removerAluno(&baseAlunos, *aluno);
                break;
            }  
            case 6:
                return 0;
                break;
        }
        printf("Pressione qualquer tecla para continuar...");
        getch();
        system("cls");
    }
}