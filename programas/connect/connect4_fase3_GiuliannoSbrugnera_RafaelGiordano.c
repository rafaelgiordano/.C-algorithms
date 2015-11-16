/*----------------------------------------------------------
   Algoritmos e Programacao II
   Programa.: Connect 4 - Fase 3
   Descricao: este programa simula o jogo Connect 4, onde
              dois jogadores colocam fichas em um 
              tabuleiro, alternadamente. O primeiro a
              fazer uma sequencia de 4 fichas ganha.
              Nesta fase, o segundo jogador pode ser uma
              pessoa ou o computador, em diferentes 
              niveis de dificuldade.
   Autores..: Giulianno Raphael Sbrugnera RA: 408093
              Rafael Paschoal Giordano    RA: 408298
 ----------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ImprimeTabuleiro(int jogo[][7], int c, int l);

void ImprimeNumeracao(int c);

int JogadaBloqueia(int jogo[][7], int c, int l, int coluna_p1, int linha_p1);

int JogadaVence(int jogo[][7], int c, int l, int coluna_cpu, int linha_cpu);

int main ()
{
	int tabuleiro[10][7],  //matriz utilizada
		i = 0,             //contador
		j = 0,             //contador
		x = 0,             //contador
		cont = 0,          //contador
		b = 1,             //contador que define de quem será a vez
		ganhou = 0,        //variavel que verifica se o jogador ganhou ou não
		a = 0,             //variavel de controle
		op = 0,            //opcao de jogo
        cpu = 0,           //jogo contra o computador ligado ou desligado
        dificuldade = 0,   //dificuldade escolhida do computador
		linhas = 0,        //quantidade de linhas da matriz
		colunas = 0,       //quantidade de colunas da matriz
		p = 0,             //posicao que vai colocar a ficha
        aux_linha = 0,     //auxiliar para verificacao da jogada do computador
        aux_cpu = 0,       //auxiliar que recebe a jogada da funcao 'JogadaVence'
        c_cpu = 0,         //guarda a coluna da ultima jogada do computador
        l_cpu = 0;         //guarda a linha da ultima jogada do computador

	char player1[21],      //nome do jogador 1
         player2[21];      //nome do jogador 2
         
	printf ("\nCONNECT 4\n");
	
    /* loop que so sera encerrado quando houver a entrada 100 para a coluna ou se o tabuleiro estiver cheio */
    do
	{
		printf ("\nMENU PRINCIPAL\n\n");
		printf ("(1) - Jogar o Connect 4\n");
		printf ("(2) - Instrucoes\n");
		printf ("Sua opcao: ");
		scanf ("%d", &op);
		
		/* tratamento de erro caso seja digitada uma opcao invalida */
		while (op < 1 || op > 2)
		{
			printf ("Opcao invalida! Digite uma opcao de 1 a 2: ");
			scanf ("%d", &op);
		}
		
		/* instrucoes do programa */
		if (op == 2)
		{
			printf ("\n\nINSTRUCOES GERAIS SOBRE O JOGO");
			printf ("\n\nCOMO JOGAR\nEscolha a opcao (1) do Menu Principal - Jogar o Connect 4.\n\n");
			printf ("COMO ESCOLHER O TAMANHO DO TABULEIRO\nEscolha a opcao (1) do Menu Principal - Jogar o Connect 4. No Menu de Opcao de Jogo, escolha entre as 4 opcoes disponiveis.\n\n");
			printf ("COMO ESCOLHER ONDE COLOCAR A FICHA\nDigite o numero da coluna onde voce deseja colocar a ficha.\n\n");
            printf ("COMO ESCOLHER O ADVERSARIO\nApos realizar sua escolha no Menu de Opcao de Jogo, escolha entre Jogador contra Jogador (opcao 1) ou Jogador contra Computador (opcao 2) no Menu de Opcoes de Jogadores\n\n");
            printf ("COMO ESCOLHER A DIFICULDADE DO COMPUTADOR\nApos escolher a opcao 2 no Menu de Opcoes de Jogadores, escolha entre as 4 opcoes de dificuldade disponiveis\nAVISO: NAO EH POSSIVEL VENCER CHUCK NORRIS!\n\n");
			printf ("JOGADOR VENCEDOR:\nO jogador vai ganhar o jogo se conseguir criar uma sequencia de 4 fichas (sendo essas fichas do proprio jogador) nas posicoes: horizontal, vertical ou diagonal.\n\n");
			printf ("EMPATE:\nO jogo terminara em empate se todo o tabuleiro for preenchido, sem que haja um vencedor em qualquer combinacao.\n\n");
            printf ("COMO SAIR DO JOGO\nPara sair do jogo:\n");
			printf ("\t1. Digite o numero 100 quando for digitar o numero da coluna.\n");
			printf ("\t2. Algum jogador vence o jogo (veja JOGADOR VENCEDOR).\n");
			printf ("\t3. Ocorre empate no jogo (veja EMPATE).\n\n");
		}
	}while (op != 1);
	
	printf ("\nMENU DE OPCAO DE JOGO\n\n");
	printf ("(1) - Tabuleiro no formato 7 x 6\n");
	printf ("(2) - Tabuleiro no formato 8 x 7\n");
	printf ("(3) - Tabuleiro no formato 9 x 7\n");
	printf ("(4) - Tabuleiro no formato 10 x 7\n");
	printf ("Sua opcao de jogo: ");
	scanf ("%d", &op);
	
	/* tratamento de erro caso seja digitada uma opcao invalida */
	while (op < 1 || op > 4)//
	{
		printf ("Opcao invalida! Digite uma opcao de 1 a 4: ");
		scanf ("%d", &op);
	}
	
	/* bloco switch para escolher qual sera o tamanho do tabuleiro
	   a variavel 'linhas' recebe o tamanho maximo das linhas
	   a variavel 'colunas' recebe o tamanho maximo das colunas */
	switch (op)
	{
		case 1:
			linhas = 7;
			colunas = 6;
		break;

		case 2:
			linhas = 8;
			colunas = 7;
		break;
		
        case 3:
			linhas = 9;
			colunas = 7;
		break;
		
        case 4:
			linhas = 10;
			colunas = 7;
		break;
	}	

	printf ("\nVoce escolheu a opcao de jogo com %d linhas e %d colunas\n", linhas, colunas);

    /* ---------------------------------------------------------------------
    Neste bloco sera escolhido se o jogo sera jogador contra jogador ou 
    jogador contra computador.
    Estrategia:
    1. Se a opcao for 1, eh lido os nomes do jogador 1 e do jogador 2.
    2. Se a opcao for 2, eh lido apenas o nome do jogador 1. O jogador 2 
    sempre sera 'CPU'. A variavel 'cpu' recebe o valor 999, que indica ao 
    longo do programa que o computador esta 'ativado'.
    --------------------------------------------------------------------- */
    printf ("\nMENU DE OPCOES DE JOGADORES\n\n");
    printf ("(1) - JOGADOR x JOGADOR\n");
    printf ("(2) - JOGADOR x CPU\n");
    printf ("Sua opcao: ");
    scanf ("%d", &op);

    /* tratamento de erro caso seja digitada uma opcao invalida */
    while (op < 1 || op > 2)
    {
        printf ("Opcao invalida! Digite uma opcao de 1 a 2: ");
        scanf ("%d", &op);
    }

    if (op == 1)
    {
	    printf ("\nJogador 1 digite seu nome: ");
	    scanf ("%s", player1);
        printf ("Jogador 2 digite seu nome: ");
	    scanf ("%s", player2);
	    printf ("\nJogador 1: %s\nJogador 2: %s\n", player1, player2);
	}
    else
    {
        /* ----------------------------------------------------------------------
        Neste bloco sera escolhida a dificuldade do computador.
        Como foi definida cada dificuldade:
        - FACIL: eh gerado um numero aleatorio de 0 ate 'colunas' - 1 para a 
          coluna que o computador vai colocar sua ficha, onde a variavel 'p' 
          recebe esse numero. Em seguida 'p' eh incrementado em 1.
        - MEDIO: com base na ultima jogada do jogador 1, o computador vai 
          bloquear qualquer sequencia que o jogador comece a fazer. Caso nao 
          tenha um sequencia em andamento do jogador 1, sera gerado um numero
          aleatorio para a coluna que o computador vai colocar a ficha.
        - DIFICIL: com base na ultima jogada do computador, procura-se uma 
          sequencia onde o computador possa ganhar. Se existir qualquer uma, o
          computador colocara a ficha de tal forma que venca a partida. Senao, o
          computador tentara bloquear o jogador 1, com base na sua ultima jogada.
          Caso nao haja aonde bloquear (jogador 1 nao possui um sequencia de 
          fichas), entao eh gerado um numero aleatorio onde para a coluna onde o
          computador vai colocar a ficha.
        - CHUCK NORRIS: a matriz eh totalmente preenchida e Chuck Norris vence
          automaticamente.
        ------------------------------------------------------------------------- */
        printf ("\nDIFICULDADE DO COMPUTADOR\n\n");
        printf ("(1) - Facil\n");
        printf ("(2) - Normal\n");
        printf ("(3) - Dificil\n");
        printf ("(4) - Chuck Norris\n");
        printf ("Sua opcao: ");
        scanf ("%d", &dificuldade);

        /* tratamento de erro caso seja digitada uma opcao invalida */
        while (dificuldade < 1 || dificuldade > 4)
        {
            printf ("Opcao invalida! Digite uma opcao de 1 a 4: ");
            scanf ("%d", &dificuldade);
        }

        printf ("\nJogador 1 digite seu nome: ");
        scanf ("%s", player1);

        cpu = 999;
    }
	
    if (dificuldade == 4)
    {
        /* loop que preenche toda a matriz, demonstrando a vitoria de Chuck Norris */
        for (i = 0; i < linhas; i++)
        {
            for (j = 0; j < colunas; j++)
            {
                tabuleiro[i][j] = 1;
            }
        }    
    }
    else
    {
	   /* loop que zera a matriz */
	    for (i = 0; i < linhas; i++)
        {
	 	    for (j = 0; j < colunas; j++)
	 	    {
		 	    tabuleiro[i][j] = 0;
		    }
        }
    }

    ImprimeNumeracao(colunas);
    
    ImprimeTabuleiro(tabuleiro, colunas, linhas);

	/* ---------------------------------------------------------------------
    Loop principal, garante a continuacao do programa ate que:
    - o tabuleiro esteja completamente preenchido;
    - um dos usuarios digite 100;
    - haja um vencedor.
    A cada iteracao, se o jogador realizou uma jogada valida, a vez de jogar
    eh passada ao proximo jogador.
    Estrategia:
    1. Foi criado um contador 'b', com valor inicial igual a 1.
    2. Definimos que quando 'b' assumir numeros impares sera a vez do 
    jogador 1, e quando assumir numeros pares, do jogador 2.
    3. Assim, quando o programa necessita saber se 'b' eh par ou impar, 
    calculamos 'b' % 2. Se o resultado for 1, 'b' eh impar, sendo entao a
    vez do jogador 1. Se o resultador for 0, 'b' eh par, sendo entao a vez
    do jogador 2.
    4. Se 'b' % 2 = 0 e 'cpu' = 999, entao eh a vez do computador.
    --------------------------------------------------------------------- */
    do
    {
		a = 0; 
		cont = 0;
        if (dificuldade != 4)
        {
    		if (b % 2 != 0)
    		{
                printf ("Sua vez %s!", player1);
            }
            else
            {
                if (cpu != 999)
                {
                    printf ("Sua vez %s!", player2);
                }
            }

            srand (time (NULL));

            if ((cpu == 999) && (b % 2 == 0))
            {
                if (dificuldade == 1)//facil - comando srand em todas as jogadas
                {
                    p = rand() % colunas;
                    p++;
                }
                if (dificuldade == 2)//medio - comando srand na primeira jogada e depois o cpu fica fechando o jogador
                {
                    if (b == 2)//primeira jogada no jogo do cpu
                    {
                        p = rand() % colunas;
                        p++;
                    }
                    else//segunda jogada ou acima do cpu
                    {
                        p = JogadaBloqueia(tabuleiro, colunas, linhas, p, aux_linha);
                        p++;
                    }
                }
                if (dificuldade == 3)//dificil - comando srand na primeira jogada e depois o cpu ganha quando der, senao fica fechando o jogador
                {
                    if (b == 2)//primeira jogada no jogo do cpu
                    {
                        p = rand() % colunas;
                        p++;
                    }
                    else//segunda jogada ou acima do cpu
                    {
                        aux_cpu = JogadaVence(tabuleiro, colunas, linhas, c_cpu, l_cpu);

                        if (aux_cpu == -1)//nao da pra ganhar agora
                        {
                            p = JogadaBloqueia(tabuleiro, colunas, linhas, p, aux_linha);
                            p++;
                        }
                        else
                        {
                            p = aux_cpu;
                        }
                    }
                }
            }
            else
            {
    	  	    printf ("\nDigite a coluna desejada (de 1 a %d). Caso queira sair do jogo, digite 100\n", colunas);
    	  	    scanf ("%d", &p);
    	  	}

    	  	/* tratamento de erro caso a coluna digitada nao exista, sendo diferente de 100
               mesmo que o jogador digite uma coluna inexistente, ainda sera sua vez de jogar */
    	  	while ((p < 1 || p > colunas) && p != 100)
    	  	{
    		 	printf ("\nColuna inexistente!");
                if (b % 2 != 0)
    		    {
                    printf ("Ainda eh sua vez %s!", player1);
                }
                else
                {
                    printf ("Ainda eh sua vez %s!", player2);
                } 
                printf ("Digite um numero de 1 a %d.\nCaso queira sair do jogo, digite 100\n", colunas);
    		 	scanf ("%d", &p);
            }
            
            /* Utilizamos o comando 'system("cls")' para limpar a tela a cada iteracao */
            system ("cls");
            
            if (p != 100)
            {
                
                /* --------------------------------------------------------------
                Loop que verifica se ha algum espaco vago na coluna requisitada
                e verifica se essa coluna esta cheia ou nao.
                Estrategia:
                1. Como as fichas devem 'cair' ao longo do tabuleiro, eh feita a
                verificacao da ultima linha ate a primeira.
                2. Quando um elemento da coluna requisitada eh igual a 0, 
                significa que aquele espaco esta vazio.
                3. Se for a vez do jogador 1, a matriz na posicao do espaco 
                vazio recebe 1. Se for a vez do jogador 2, recebe 2.
                4. Se o elemento da coluna requisitada nao eh igual a 0, a
                variavel 'cont' eh incrementada.
                5. Caso a variavel 'cont', ao final da iteracao, tenha um valor
                igual ao numero de linhas do tabuleiro, significa que a coluna
                requisitada pelo jogador esta cheia. Entao o jogador eh informado
                sobre esse fato e lhe eh requisitada outra coluna.
                ----------------------------------------------------------------- */
            	for (i = linhas - 1; i >= 0; i--)
            	{
    		 		if (tabuleiro[i][p - 1] == 0)
    		 		{
                        aux_linha = i;
                        if (b % 2 != 0)
    		            {
                            tabuleiro[i][p - 1] = 1;
                        }
                        else
                        {
                            tabuleiro[i][p - 1] = 2;
                            
                            if (cpu == 999)
                            {
                                c_cpu = p;
                                l_cpu = i;
                            }
                        }
                        
                        /* ---------------------------------------------------------
                        O bloco abaixo composto de if's e loops verificam se o 
                        jogador que acabou de realizar a jogada ganhou o jogo.
                        Estrategia:
                        1. O programa parte da posicao da ficha que acabou de ser
                        colocada.
                        2. Antes de entrar em cada possibilidade de o jogador ter
                        vencido, o programa verifica se o numero de colunas dos
                        lados e linhas acima e abaixo eh o suficiente para formar um
                        conjunto de 4 fichas. Essa restricao depende de qual 
                        'quarteto' o programa vai verificar, sempre pegando 3 fichas
                        nas direcoes da ficha colocada:
                            - horizontal direita: no minimo 3 colunas a direita da
                              ficha (colunas - p >= 3).
                            - horizontal esquerda: no minimo 3 colunas a esquerda 
                              da ficha (p > 3).
                            - diagonal baixo direita: no minimo 3 colunas a direita
                              e 3 linhas abaixo da ficha 
                              ((linhas - i >= 4) && (colunas - p >= 3)).
                            - diagonal baixo esquerda: no minimo 3 colunas a
                              esquerda e 3 linhas abaixo da ficha
                              ((linhas - i >= 4) && (p > 3)).
                            - vertical baixo: no minimo 3 linhas abaixo da ficha
                              (linhas - i >= 4).
                            - diagonal cima direita: no minimo 3 colunas a direita e
                              3 linhas acima da ficha 
                              ((i > 2) && (colunas - p >= 3)).
                            - diagonal cima esquerda: no minimo 3 colunas a esquerda
                              e 3 linhas acima da ficha (i > 2 && p > 3).
                            Temos agora as combinacoes que sao excecoes:
                            - horizontal com 2 fichas a direita e 1 ficha a 
                              esquerda: no minimo 2 colunas a direita e 1 coluna a 
                              esquerda da ficha ((colunas - p >= 2) && (p > 1)).
                            - horizontal com 1 ficha a direita e 2 fichas a 
                              esquerda: no minimo 1 coluna a direita e 2 colunas a
                              esquerda da ficha ((colunas - p >= 1) && p > 2).
                            - diagonal com 2 fichas acima e a direita e 1 ficha
                              abaixo e a esquerda: no minimo 2 colunas a direita e
                              1 coluna a esquerda da ficha 
                              ((colunas - p >= 2) && p > 1).
                            - diagonal com 1 ficha acima e a direita e 2 fichas
                              abaixo e a esquerda: no minimo 1 coluna a direita e
                              2 colunas a esquerda da ficha 
                              ((colunas - p >= 1) && p > 2).
                            - diagonal com 1 ficha abaixo e a direita e 2 fichas
                              acima e a esquerda: no minimo 1 coluna a direita e
                              2 colunas a esquerda da ficha 
                              ((colunas - p >= 1) && p > 2).
                            - diagonal com 2 fichas abaixo e a direita e 1 ficha
                              acima e a esquerda: no minimo 2 colunas a direita e
                              1 coluna a esquerda da ficha 
                              ((colunas - p >= 2) && p > 1).
                        3. O programa assume que o jogador venceu, atribuindo a
                        variavel 'ganhou' o valor 1. Em cada sequencia descrita
                        acima, ha loops ou, nas excecoes, if's que verificam se o
                        'quarteto' formado pela sequencia possui somente fichas 
                        iguais. Se possuir, a variavel 'ganhou' permanece com 1, e 
                        ao sair da iteracao ela nao entra no if seguinte, saindo do
                        loop em seguida e apontando o jogandor vencedor. Se qualquer
                        ficha das 4 for diferente das demais, a variavel 'ganhou' 
                        recebe 999. Isso faz com que entre no proximo teste de
                        sequencia, e assim sucessivamente. Caso, ao final do loop, a
                        variavel 'ganhou' tiver valor 999, significa que nenhum
                        jogador venceu, garantindo assim o prosseguimento do jogo. 
                        ------------------------------------------------------------ */
                        if (colunas - p >= 3)
    					{
    					    ganhou = 1;
    					    for (j = p - 1; j < p + 2; j++)
    				        {
                                if (tabuleiro[i][j] != tabuleiro[i][j + 1])
                                {
                                    ganhou = 999;
                                }
                            }
                        }
                        if (ganhou == 999)
                        {
                            if (p > 3)
                            {
                                ganhou = 1;
                                for (j = p - 1; j > p - 4; j--)
                                {
                                    if (tabuleiro[i][j] != tabuleiro[i][j - 1])
                                    {
                                        ganhou = 999;
                                    }
                                }
                            }     
                            if (ganhou == 999)
                            {
                                if ((linhas - i >= 4) && (colunas - p >= 3))
                                {
                                    ganhou = 1;
                                    x = i;
                                    for (j = p - 1; j < p + 2; j++)
                                    {
                                        if (tabuleiro[x][j] != tabuleiro[x + 1][j + 1])
                                        {
                                            ganhou = 999;
                                        }
                                        x++;
                                    }
                                }    
                                if (ganhou == 999)
                                {
                                    if ((linhas - i >= 4) && (p > 3))
                                    {
                                        ganhou = 1;
                                        x = i;
                                        for (j = p - 1; j > p - 4; j--)
                                        {
                                            if (tabuleiro[x][j] != tabuleiro[x + 1][j - 1])
                                            {
                                                ganhou = 999;
                                            }
                                            x++;
                                        }
                                    }   
                                    if (ganhou == 999)
                                    {
                                        if (linhas - i >= 4)
                                        {
                                            ganhou = 1;
                                            for (j = i; j < i + 3; j++)
                                            {
                                                if (tabuleiro[j][p - 1] != tabuleiro[j + 1][p - 1])
                                                {
                                                    ganhou = 999;
                                                }
                                            }
                                        }
                                        if (ganhou == 999)
                                        {
                                            if ((i > 2) && (colunas - p >= 3))
                                            {
                                                ganhou = 1;
                                                x = i;
                                                for (j = p - 1; j < p + 2; j++)
                                                {
                                                    if (tabuleiro[x][j] != tabuleiro[x - 1][j + 1])
                                                    {
                                                        ganhou = 999;
                                                    }
                                                    x--;
                                                }
                                            }
                                            if (ganhou == 999)
                                            {
                                                if (i > 2 && p > 3)
                                                {
                                                    ganhou = 1  ;
                                                    x = i;
                                                    for (j = p - 1; j > p - 4; j--)
                                                    {
                                                        if (tabuleiro[x][j] != tabuleiro[x - 1][j - 1])
                                                        {
                                                            ganhou = 999;
                                                        }
                                                        x--;
                                                    }
                                                }
                                                if (ganhou == 999)
                                                {
                                                    if ((colunas - p >= 2) && (p > 1))
                                                    {
                                                        ganhou = 1;
                                                        j = p - 1;
                                                        if (tabuleiro[i][j] != tabuleiro[i][j - 1] || tabuleiro[i][j] != tabuleiro[i][j + 1] || tabuleiro[i][j + 1] != tabuleiro[i][j + 2])
                                                        {
                                                            ganhou = 999;
                                                        }
                                                    }
                                                    if (ganhou == 999)
                                                    {
                                                        if ((colunas - p >= 1) && p > 2)
                                                        {
                                                            ganhou = 1;
                                                            j = p - 1;
                                                            if (tabuleiro[i][j] != tabuleiro[i][j + 1] || tabuleiro[i][j] != tabuleiro[i][j - 1] || tabuleiro[i][j - 1] != tabuleiro[i][j - 2])
                                                            {
                                                                ganhou = 999;
                                                            }
                                                        }
                                                        if (ganhou == 999)
                                                        {
                                                            if ((colunas - p >= 2) && p > 1)
                                                            {
                                                                ganhou = 1;
                                                                j = p - 1;
                                                                if (tabuleiro[i][j] != tabuleiro[i + 1][j - 1] || tabuleiro[i][j] != tabuleiro[i - 1][j + 1] || tabuleiro[i - 1][j + 1] != tabuleiro[i - 2][j + 2])
                                                                {
                                                                    ganhou = 999;
                                                                }
                                                            }
                                                            if (ganhou == 999)
                                                            {
                                                                if ((colunas - p >= 1) && p > 2)
                                                                {
                                                                    ganhou = 1;
                                                                    j = p - 1;
                                                                    if (tabuleiro[i][j] != tabuleiro[i - 1][j + 1] || tabuleiro[i][j] != tabuleiro[i + 1][j - 1] || tabuleiro[i + 1][j - 1] != tabuleiro[i + 2][j - 2])
                                                                    {
                                                                        ganhou = 999;
                                                                    }
                                                                }
                                                                if (ganhou == 999)
                                                                {
                                                                    if ((colunas - p >= 1) && p > 2)
                                                                    {
                                                                        ganhou = 1;
                                                                        j = p - 1;
                                                                        if (tabuleiro[i][j] != tabuleiro[i + 1][j + 1] || tabuleiro[i][j] != tabuleiro[i - 1][j - 1] || tabuleiro[i - 1][j - 1] != tabuleiro[i - 2][j - 2])
                                                                        {
                                                                            ganhou = 999;
                                                                        }
                                                                    }
                                                                    if (ganhou == 999)
                                                                    {
                                                                        if ((colunas - p >= 2) && p > 1)
                                                                        {
                                                                            ganhou = 1;
                                                                            j = p - 1;
                                                                            if (tabuleiro[i][j] != tabuleiro[i - 1][j - 1] || tabuleiro[i][j] != tabuleiro[i + 1][j + 1] || tabuleiro[i + 1][j + 1] != tabuleiro[i + 2][j + 2])
                                                                            {
                                                                                ganhou = 999;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        i = -1;
                    }
    				else
    				{
    					cont++;
    				}
    			}
    			if (ganhou == 1)
    			{
        			ImprimeNumeracao(colunas);
    				
                    ImprimeTabuleiro(tabuleiro, colunas, linhas);
    				
                    printf ("\n\n\n-----------\n");
                    printf ("FIM DE JOGO\n");
                    printf ("-----------\n\n\n");
                    printf ("-----------------------------------\n");
                    
                    if (b % 2 != 0)
                    {
                        printf ("%s ", player1);
                    }
                    else
                    {
                        if (cpu == 999)
                        {
                            printf ("CPU ");
                        }
                        else
                        {
                            printf ("%s ", player2);
                        }
                    }
                    printf ("EH O VENCEDOR!\n");
                    printf ("-----------------------------------\n\n\n");
                    p = 100;
                }
                else
                {
    			    if (cont == linhas)
    			    {
    				    a = -1;
    				    printf ("\nA coluna %d esta cheia.\n", p);
                    } 
    			    else
    			    {
        			   ImprimeNumeracao(colunas);
    				   
    				   /* ------------------------------------------------------- 
                       Loop que verifica se o tabuleiro possui algum lugar vago
                       Estrategia:
                       1. A variavel 'a' eh sempre inicializada com 0 no comeco.
                       2. Se o tabuleiro possui algum lugar vazio a variavel 'a'
                       recebe -1, garantindo a continuacao do programa.
                       3. Se o tabuleiro estiver cheio, a variavel 'a' continua
                       com seu valor 0, fazendo com que saia do loop principal e
                       termine o jogo empatado.
                       ---------------------------------------------------------- */
    				   for (i = 0; i < linhas; i++)
        			   {
    	 				    for (j = 0; j < colunas; j++)
    	 				    {
     						    if (tabuleiro[i][j] == 0)
     						    {
    							     a = -1;
    						    }
    					    }
        			   }
        			   
        			   ImprimeTabuleiro(tabuleiro, colunas, linhas);

                       if (a == 0)
    				   {
    				        printf ("\n\n\n-----------\n");
                            printf ("FIM DE JOGO\n");
                            printf ("-----------\n\n\n");
                            printf ("-----------------------------------\n");
                            if (cpu == 999)
                            {
                                printf ("%s E CPU EMPATARAM!\n", player1);    
                            }
                            else
                            {
                                printf ("%s E %s EMPATARAM!\n", player1, player2);
                            }
                            printf ("-----------------------------------\n");
                       }
                        
    				   b++;

    			    }
                }
            }
        }

	}while ((a == -1) && (p != 100));

    if (dificuldade == 4)
    {
        printf ("\n\n\n-----------\n");
        printf ("FIM DE JOGO\n");
        printf ("-----------\n\n\n");
        printf ("-----------------------------------\n");
        printf ("CHUCK NORRIS VENCEU!\n");
        printf ("-----------------------------------\n");
    }
	system("pause");
	return 0;

}

/* ------------------------------------------------------------------------------------------------------------
    Funcao que imprime na tela o tabuleiro do jogo.
    O tabuleiro eh mostrado como uma grande tabela, onde o tamanho de cada quadrado eh 4, sendo o ultimo 4 + 1.
    Por essa razao, as formulas abaixo sao (linhas * 4) + 1 e (colunas * 4) + 1.
    As linhas 0, 4, 8, 12, ... sao as linhas cheias de tracejados. Por essa razao temos i % 4.
    Na linha i % 4, as colunas 0, 4, 8, ... devem ter um espaco ao inves do traco. Por essa razao temos j % 4.
    Nas linhas 2, 6, 10, ... e nas colunas 2, 6, 10, ... temos o centro do quadrado. Eh neste momento
    que deve ser impresso na tela a ficha, caso ela exista, ou um espaco, caso ela nao exista.
    Na hora de imprimir a ficha, usamos printf ("%c", 254), que imprime na tela um pequeno quadrado preenchido 
    (utilizacao da tabela ASCII).
    ----------------------------------------------------------------------------------------------------------- */
void ImprimeTabuleiro(int jogo[][7], int c, int l)
{

    int i = 0, 
        j = 0, 
        w = 0, 
        z = 0;
    for (i = 0; i < l * 4 + 1; i++) 
    {
        if (i % 4 == 0)
        {
            for(j = 0; j < c * 4 + 1; j++)
            {
                if (j % 4 == 0)
                {
                    printf (" ");
                }
                else
                {
                    printf ("-");
                }
            }
            printf ("\n");
        }
        else
        {
            for(j = 0; j < c * 4 + 1; j++)
            {
                if (j % 4 == 0)
                {
                    printf ("|");
                }
                else
                {
                    if (((j + 2) % 4 == 0) && ((i + 2) % 4 == 0))
                    {
                        if (jogo[w][z] == 1)
                        {
                            printf ("o");
                        }
                        else
                        {
                            if (jogo[w][z] == 2)
                            {
                                printf ("x");
                            }
                            else
                            {
                                printf (" ");
                            }
                        }
                        z++;
                        if (z >= c)
                        {
                            w++;
                            z = 0;
                        }
                    }
                    else
                    {
                        printf (" ");
                    }
                }
            }
            printf ("\n");
        }
    }

}

/* funcao que imprime na tela a numeracao das colunas */
void ImprimeNumeracao(int c)
{

    int x;

    printf ("\n  ");

    for (x = 1; x <= c; x++)//
    {
        printf("#%d  ", x);
    }

    printf("\n\n");

}

/* ---------------------------------------------------------------------------------------
   Funcao que vai bloquear o jogador 1, se for possivel naquele momento
   Estrategia:
   1. Eh analisado todas as 8 combinacoes possiveis de agrupamentos de 2 ou 3 fichas, para
   que o computador possa bloquear uma tentativa de vitoria do jogador 1.
   2. Se haver alguma dessas combinacoes, entao o computador deve bloquear  a devida 
   sequencia, para que o jogador 1 nao venha a ganhar.
   3. Caso nao haja qualquer combinacao, entao eh retornado um numero aleatorio para ser a
   coluna onde o computador ira jogar.
   --------------------------------------------------------------------------------------- */
int JogadaBloqueia(int jogo[][7], int c, int l, int coluna_p1, int linha_p1)
{

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1] == 1) && (jogo[linha_p1][coluna_p1 - 3] == 1) && (jogo[linha_p1][coluna_p1 - 2] == 0))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1 - 2;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1 - 2] == 1) || (jogo[linha_p1 + 1][coluna_p1 - 2] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1 - 2;
            }
        }
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1 - 3] == 1) && (jogo[linha_p1][coluna_p1 - 4] == 1) && (jogo[linha_p1][coluna_p1 - 2] == 0))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1 - 2;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1 - 2] == 1) || (jogo[linha_p1 + 1][coluna_p1 - 2] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1 - 2;
            }
        }    
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1] == 1) && (jogo[linha_p1][coluna_p1 + 1] == 1) && (jogo[linha_p1][coluna_p1 - 2] == 0) && (coluna_p1 - 1 > 0))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1 - 2;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1 - 2] == 1) || (jogo[linha_p1 + 1][coluna_p1 - 2] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1 - 2;
            }
        }
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1] == 1) && (jogo[linha_p1][coluna_p1 + 1] == 0) && (coluna_p1 + 2 <= c))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1 + 1;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1 + 1] == 1) || (jogo[linha_p1 + 1][coluna_p1 + 1] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1 + 1;
            }
        }
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1 - 2] == 1) && (jogo[linha_p1][coluna_p1] == 0) && (coluna_p1 + 1 <= c))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1] == 1) || (jogo[linha_p1 + 1][coluna_p1] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1;
            }
        }
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1][coluna_p1 - 2] == 1) && (jogo[linha_p1][coluna_p1 - 3] == 0) && (coluna_p1 - 2 > 0))
    {
        if (linha_p1 == l - 1)
        {
            return coluna_p1 - 3;
        }
        else
        {
            if (((jogo[linha_p1 + 1][coluna_p1 - 3] == 1) || (jogo[linha_p1 + 1][coluna_p1 - 3] == 2)) && (linha_p1 + 1 < l))
            {
                return coluna_p1 - 3;
            }
        }
    }

    if ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1 + 1][coluna_p1 - 1] == 1) && (linha_p1 > 0))
    {
        return coluna_p1 - 1;
    }

    if (((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1 - 1][coluna_p1] == 1)) || ((jogo[linha_p1][coluna_p1 - 1] == 1) && (jogo[linha_p1 - 1][coluna_p1 - 2] == 1)))
    {
        return coluna_p1 - 1;
    }

    return rand() % c;

}

/* ---------------------------------------------------------------------------------------
   Funcao que vai fazer com que o computador ganhe o jogo, se for possivel naquele momento
   Estrategia:
   1. Eh analizado todas as 37 combinacoes possiveis a partir da ultima ficha colocada
   pelo computador.
   2. Se em alguma dessas combinacoes for possivel colocar a ficha em tal lugar que de a 
   vitoria ao computador, entao eh retornado a coluna onde se deve colocar a ficha.
   3. Caso nao exista nenhum lugar no tabuleiro em que o computador possa vencer, entao eh
   retornado o valor '-1', que indica que o computador nao pode vencer nessa rodada, 
   devendo entao tentar bloquear o jogador 1.
   --------------------------------------------------------------------------------------- */
int JogadaVence(int jogo[][7], int c, int l, int coluna_cpu, int linha_cpu)
{

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 2) && (jogo[linha_cpu][coluna_cpu + 2] == 0) && (coluna_cpu + 2 < c))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 3;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu + 2] == 1) || (jogo[linha_cpu + 1][coluna_cpu + 2] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 3;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu + 2] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 2;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu + 1] == 1) || (jogo[linha_cpu + 1][coluna_cpu + 1] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 2;       
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 2) && (jogo[linha_cpu][coluna_cpu + 2] == 2) && (jogo[linha_cpu][coluna_cpu] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 1;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu] == 1) || (jogo[linha_cpu + 1][coluna_cpu] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 0) && (coluna_cpu - 1 > 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 1;
        }
        else
        {
            if (((jogo[linha_cpu][coluna_cpu - 1] == 1) || (jogo[linha_cpu][coluna_cpu - 1] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 2) && (jogo[linha_cpu][coluna_cpu] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 1;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu] == 1) || (jogo[linha_cpu + 1][coluna_cpu] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu + 1] == 0) && (coluna_cpu + 1 < c))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 2;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu + 1] == 1) || (jogo[linha_cpu + 1][coluna_cpu + 1] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 2;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 0) && (coluna_cpu - 1 > 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 2;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu - 3] == 1) || (jogo[linha_cpu + 1][coluna_cpu - 3] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 2;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 2) && (jogo[linha_cpu][coluna_cpu] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 1;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu - 2] == 1) || (jogo[linha_cpu + 1][coluna_cpu - 2] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 2) && (jogo[linha_cpu][coluna_cpu] == 0) && (coluna_cpu < c))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu + 1;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu] == 1) || (jogo[linha_cpu + 1][coluna_cpu] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu + 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 2) && (jogo[linha_cpu][coluna_cpu - 4] == 0) && (coluna_cpu - 3 > 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 3;
        }
        else
        {
            if (((jogo[linha_cpu + 1][coluna_cpu - 4] == 1) || (jogo[linha_cpu + 1][coluna_cpu - 4] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 3;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 2) && (jogo[linha_cpu][coluna_cpu - 4] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 2;
        }
        else
        {
            if (((jogo[linha_cpu][coluna_cpu - 3] == 1) || (jogo[linha_cpu][coluna_cpu - 3] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 2;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu][coluna_cpu - 3] == 2) && (jogo[linha_cpu][coluna_cpu - 4] == 2) && (jogo[linha_cpu][coluna_cpu - 2] == 0))
    {
        if (linha_cpu == l - 1)
        {
            return coluna_cpu - 1;
        }
        else
        {
            if (((jogo[linha_cpu][coluna_cpu - 2] == 1) || (jogo[linha_cpu][coluna_cpu - 2] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 1] == 0) && (linha_cpu > 0))
    {
        return coluna_cpu;
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu - 3][coluna_cpu + 2] == 0) && (coluna_cpu + 2 < c) && (linha_cpu > 2))
    {
        if ((jogo[linha_cpu - 2][coluna_cpu + 3] == 1) || (jogo[linha_cpu - 2][coluna_cpu + 3] == 2))
        {
            return coluna_cpu + 3;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu - 3][coluna_cpu + 2] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 0) && (linha_cpu > 2))
    {
        if ((jogo[linha_cpu - 1][coluna_cpu + 2] == 1) || (jogo[linha_cpu - 1][coluna_cpu + 2] == 2))
        {
            return coluna_cpu + 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu - 3][coluna_cpu + 2] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 0) && (linha_cpu > 2))
    {
        if ((jogo[linha_cpu][coluna_cpu] == 1) || (jogo[linha_cpu][coluna_cpu] == 2))
        {
            return coluna_cpu + 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 0) && (coluna_cpu > 1) && (linha_cpu < l - 1))
    {
        if (linha_cpu == l - 2)
        {
            return coluna_cpu - 1;
        }
        else
        {
            if (((jogo[linha_cpu + 2][coluna_cpu - 2] == 1) || (jogo[linha_cpu + 2][coluna_cpu - 2] == 2)) && (linha_cpu + 1 < l))
            {
                return coluna_cpu - 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 0))
    {
        if ((jogo[linha_cpu][coluna_cpu] == 1) || (jogo[linha_cpu][coluna_cpu] == 2))
        {
            return coluna_cpu + 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu - 2][coluna_cpu + 1] == 0) && (linha_cpu - 1 > 0) && (c - coluna_cpu > 1))
    {
        if ((jogo[linha_cpu - 1][coluna_cpu + 1] == 1) || (jogo[linha_cpu - 1][coluna_cpu + 1] == 2))
        {
            return coluna_cpu + 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 3] == 0) && (l - linha_cpu > 2) && (coluna_cpu > 2))
    {
        if (linha_cpu == l - 3)
        {
            return coluna_cpu - 2;
        }
        else
        {
            if ((jogo[linha_cpu + 3][coluna_cpu - 3] == 1) || (jogo[linha_cpu + 3][coluna_cpu - 3] == 2))
            {
                return coluna_cpu - 2;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 0))
    {
        if ((jogo[linha_cpu + 1][coluna_cpu - 2] == 1) || (jogo[linha_cpu + 1][coluna_cpu - 2] == 2))
        {
            return coluna_cpu - 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu - 1][coluna_cpu] == 0) && (linha_cpu > 0) && (coluna_cpu < c))
    {
        if ((jogo[linha_cpu][coluna_cpu] == 1) || (jogo[linha_cpu][coluna_cpu] == 2))
        {
            return coluna_cpu + 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu + 3][coluna_cpu - 4] == 0) && (l - linha_cpu > 3) && (coluna_cpu > 3))
    {
        if (linha_cpu == l - 4)
        {
            return coluna_cpu - 3;
        }
        else
        {
            if ((jogo[linha_cpu + 4][coluna_cpu - 4] == 1) || (jogo[linha_cpu + 4][coluna_cpu - 4] == 2))
            {
                return coluna_cpu - 3;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu + 3][coluna_cpu - 4] == 2) && (jogo[linha_cpu + 2][coluna_cpu - 3] == 0))
    {
        if ((jogo[linha_cpu + 3][coluna_cpu - 3] == 1) || (jogo[linha_cpu + 3][coluna_cpu - 3] == 2))
        {
            return coluna_cpu - 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 2][coluna_cpu  - 3] == 2) && (jogo[linha_cpu + 3][coluna_cpu - 4] == 2) && (jogo[linha_cpu + 1][coluna_cpu - 2] == 0))
    {
        if ((jogo[linha_cpu + 2][coluna_cpu - 2] == 1) || (jogo[linha_cpu + 2][coluna_cpu - 2] == 2))
        {
            return coluna_cpu - 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu - 3][coluna_cpu - 4] == 0) && (linha_cpu > 2) && (coluna_cpu > 3))
    {
        if ((jogo[linha_cpu - 2][coluna_cpu - 4] == 1) || (jogo[linha_cpu - 2][coluna_cpu - 4] == 2))
        {
            return coluna_cpu - 3;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 3][coluna_cpu - 4] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 0))
    {
        if ((jogo[linha_cpu - 1][coluna_cpu - 3] == 1) || (jogo[linha_cpu - 1][coluna_cpu - 3] == 2))
        {
            return coluna_cpu - 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu - 3][coluna_cpu - 4] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 0))
    {
        if ((jogo[linha_cpu][coluna_cpu - 2] == 1) || (jogo[linha_cpu][coluna_cpu - 2] == 2))
        {
            return coluna_cpu - 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (linha_cpu < l - 1) && (coluna_cpu < c))
    {
        if (linha_cpu == l - 2)
        {
            return coluna_cpu + 1;
        }
        else
        {
            if ((jogo[linha_cpu + 1][coluna_cpu] == 1) || (jogo[linha_cpu + 1][coluna_cpu] == 2))
            {
                return coluna_cpu + 1;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2]))
    {
        if ((jogo[linha_cpu][coluna_cpu - 2] == 1) || (jogo[linha_cpu][coluna_cpu - 2] == 2))
        {
            return coluna_cpu - 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu - 2][coluna_cpu - 3] == 0) && (linha_cpu > 1) && (coluna_cpu > 2))
    {
        if ((jogo[linha_cpu - 1][coluna_cpu - 3] == 1) || (jogo[linha_cpu - 1][coluna_cpu - 3] == 2))
        {
            return coluna_cpu - 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 0) && (l - linha_cpu > 2) && (coluna_cpu < c - 2))
    {
        if (linha_cpu == l - 2)
        {
            return coluna_cpu + 2;
        }
        else
        {
            if ((jogo[linha_cpu + 3][coluna_cpu + 1] == 1) || (jogo[linha_cpu + 3][coluna_cpu + 1] == 2))
            {
                return coluna_cpu + 2;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 0))
    {
        if ((jogo[linha_cpu + 2][coluna_cpu] == 1) || (jogo[linha_cpu + 2][coluna_cpu] == 2))
        {
            return coluna_cpu+ 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu - 1][coluna_cpu - 2] == 0) && (linha_cpu > 0) && (coluna_cpu > 1))
    {
        if ((jogo[linha_cpu][coluna_cpu - 2] == 1) || (jogo[linha_cpu][coluna_cpu - 2] == 2))
        {
            return coluna_cpu - 1;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu + 3][coluna_cpu + 2] == 0) && (l - linha_cpu > 3) && (coluna_cpu < c - 2))
    {
        if (linha_cpu == l - 3)
        {
            return coluna_cpu + 3;
        }
        else
        {
            if ((jogo[linha_cpu + 4][coluna_cpu + 2] == 1) || (jogo[linha_cpu + 4][coluna_cpu + 2] == 2))
            {
                return coluna_cpu + 3;
            }
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 1][coluna_cpu] == 2) && (jogo[linha_cpu + 3][coluna_cpu + 2] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1]))
    {
        if ((jogo[linha_cpu + 3][coluna_cpu + 1] == 1) || (jogo[linha_cpu + 3][coluna_cpu + 1] == 2))
        {
            return coluna_cpu + 2;
        }
    }

    if ((jogo[linha_cpu][coluna_cpu - 1] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 2) && (jogo[linha_cpu + 3][coluna_cpu + 2] == 2) && (jogo[linha_cpu + 2][coluna_cpu + 1] == 0))
    {
        if ((jogo[linha_cpu + 2][coluna_cpu] == 1) || (jogo[linha_cpu + 2][coluna_cpu] == 2))
        {
            return coluna_cpu + 1;
        }
    }

    return -1;

}
