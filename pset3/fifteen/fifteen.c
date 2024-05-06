 /**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board доска
int board[DIM_MAX][DIM_MAX];

// dimensions размеры
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions обеспечить допустимые размеры
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log не разобралась!
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions приветствовать пользователя с инструкциями
    greet();

    // initialize the board инициализировать доску
    init();

    // accept moves until game is won принимать ходы до тех пор, пока игра не будет выиграна
    while (true)
    {
        // clear the screen очистить экран
        clear();

        // draw the current state of the board нарисовать текущее состояние доски
        draw();

        // log the current state of the board (for testing) лог текущего состояния доски (для тестирования)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win проверить на победу
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move запрос на перемещение
        printf("Tile to move: ");
        int tile = get_int("");

        // quit if user inputs 0 (for testing) выйти, если пользователь вводит 0 (для тестирования)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing) перемещение
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality переместиться, если это возможно, в противном случае сообщить о нарушении
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake спящая нить ради анимации ??
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences. Очищает экран с помощью управляющих последовательностей ANSI.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player Приветствует игрока.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them
 * Инициализирует игровое поле тайлами с номерами от 1 до d*d - 1 *
 * (т. е. заполняет 2D-массив значениями, но фактически не печатает их).
 */
void init(void)
{
    int currentTileValue = d * d - 1;
    int tilesWhithValueCount = currentTileValue;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = currentTileValue;
            currentTileValue --;

            if (i == d - 1 && j == d - 1)
            {
                board[i][j] = 0;
            }
        }
    }

    if (tilesWhithValueCount % 2 != 0)
    {

        int buf = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = buf;
    }
}

/**
 * Prints the board in its current state. Печатает доску в ее текущем состоянии.
 */
void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
                printf("%s", "  _");
            }
            else
            {
                printf("%3d", board[i][j]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else returns false.
 * Если тайл граничит с пустым пространством, перемещает тайл и возвращает true, иначе возвращает false.
 */
bool move(int tile)
{
    int itile, jtile, ivoid, jvoid;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                itile = i;
                jtile = j;
            }
            if (board[i][j] == 0)
            {
                ivoid = i;
                jvoid = j;
            }
        }
    }

    if ((itile == ivoid && (jvoid + 1 == jtile || jvoid - 1 == jtile)) || (jtile == jvoid && (ivoid + 1 == itile || ivoid - 1 == itile)))
    {
        board[ivoid][jvoid] = board[itile][jtile];
        board[itile][jtile] = 0;
        return true;
    }

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), else false.
 * Возвращает true, если игра выиграна (т. е. доска находится в выигрышной конфигурации), иначе false.
 */
bool won(void)
{
    int value = 1;

    if (board[d - 1][d - 1] != 0)
    {
        return false;
    }

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != value && board[i][j] != 0)
            {
                return false;
            }
            value++;
        }
    }

    return true;
}