#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
using namespace std;

class Filer;

class HighScore {
    char* name;

public:
    HighScore(char* name_) {
        name = _strdup(name_);
    }

    int get_highscore(int start_time, int end_time) {
        int game_time = end_time - start_time;
        int game_points = 1000;

        game_points /= game_time;

        return game_points;
    }

    void save_highscore(int score) {
        fstream file("highscores.txt", ios::app);

        for (int i = 0; i < 10; i++) {
            file.put(name[i]);
        }

        file << score;
        file.close();
    }

    void read_highscores() {
        fstream file("highscores.txt", ios::in);

        char* nill = new char[10]{ '-' };
        cout << "Name      High-score" << endl;
        while (!file.eof()) {
            cout << file.get();
        }

        file.close();
    }
};

void screenheader()
{
    system("cls");
    system("color f1");
    cout << "\n\t                       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t                       \xB2\xB2                                 \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @@@@@@@@@@@@@@@@@@@@@@@     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @                     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @     WELCOME TO      @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @     TIC TAC TOE     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @       GAME          @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @                     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @                     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @                     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @                     @     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2     @@@@@@@@@@@@@@@@@@@@@@@     \xB2\xB2";
    cout << "\n\t                       \xB2\xB2                                 \xB2\xB2";
    cout << "\n\t                       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n";
    cout << "\n\n-----------------------------------" << endl;
    cout << "PRESS ANY KEY TO CONTINUE......." << endl;
    _getch();
}
struct node
{
    char info;
    int pos;
    int step;
    node* next;
};

class linkedlist
{
    node* head, * tail;
    int step;
public:
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        step = 0;
    }
    void addnodes(char i, int pos)
    {
        node* temp = new node;
        temp->info = i;
        temp->pos = pos;
        temp->step = this->step;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        this->step++;
    }
    void deletelist()
    {
        head = NULL;
        tail = NULL;
        step = 0;
    }
    void display()
    {
        node* temp = head;
        while (temp != NULL)
        {
            cout << "STEP:" << temp->step << " POS: " << temp->pos << "INPUT: " << temp->info << "------>\n";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
class multi
{
    char board[16];
    int choice;
    char p1mark;
    char p2mark;
    int turn;
    string p1name;
    string p2name;
    linkedlist l1;
public:
    multi(string p1name, string p2name)
    {
        this->p1name = p1name;
        this->p2name = p2name;
        int temp = 48;
        for (int i = 0; i < 10; i++)
        {
            board[i] = (int)temp;
            temp++;
        }
        board[10] = 'a';
        board[11] = 'b';
        board[12] = 'c';
        board[13] = 'd';
        board[14] = 'e';
        board[15] = 'f';
        p1mark = 'O';
        p2mark = 'X';
        turn = 0;
    }
    void makeboard()
    {
        cout << "\n\n\t\t" << p1name << "(O)\tvs\t" << p2name << "(X)" << endl;
        cout << "\t\t\t|\t|\t|\t" << endl;
        cout << "\t\t\t" << board[0] << "|\t " << board[1] << "|\t" << board[2] << "|\t" << board[3] << endl;

        cout << "\t\t________|_______|________|________" << endl;

        cout << "\t\t\t|\t|\t|\t" << endl;
        cout << "\t\t" << board[4] << "\t|\t " << board[5] << "|\t" << board[6] << "|\t" << board[7] << endl;

        cout << "\t\t________|_______|________|________" << endl;
        cout << "\t\t\t" << board[8] << "|\t " << board[9] << "|\t" << board[10] << "|\t" << board[11] << endl;
        cout << "\t\t________|_______|________|________" << endl;
        cout << "\t\t\t" << board[12] << "|\t " << board[13] << "|\t" << board[14] << "|\t" << board[15] << endl;
        cout << "\t\t________|_______|________|________" << endl;
    }

    void addmark(int pos)
    {
        if (turn % 2 == 0)
        {
            board[pos] = p1mark;
            l1.addnodes(p1mark, pos);
        }
        else
        {
            board[pos] = p2mark;
            l1.addnodes(p2mark, pos);
        }
        turn++;
    }
    int decide()
    {
        if (board[0] == board[1] && board[1] == board[2] && board[2] == board[3])

            return 1;
        else if (board[4] == board[5] && board[5] == board[6] && board[6] == board[7])

            return 1;
        else if (board[8] == board[9] && board[9] == board[10] && board[10] == board[11])

            return 1;
        else if (board[12] == board[13] && board[13] == board[14] && board[14] == board[15])

            return 1;
        else if (board[0] == board[4] && board[4] == board[8] && board[8] == board[12])

            return 1;
        else if (board[1] == board[5] && board[5] == board[9] && board[9] == board[13])

            return 1;
        else if (board[2] == board[6] && board[6] == board[10] && board[10] == board[14])

            return 1;
        else if (board[3] == board[7] && board[7] == board[11] && board[11] == board[15])

            return 1;
        else if (board[0] == board[5] && board[5] == board[10] && board[10] == board[15])

            return 1;
        else if (board[3] == board[6] && board[6] == board[9] && board[9] == board[12])

            return 1;
        else if (board[0] != '0' && board[1] != '1' && board[2] != '2' && board[3] != '3'
            && board[4] != '4' && board[5] != '5' && board[6] != '6'
            && board[7] != '7' && board[8] != '8' && board[9] != '9'
            && board[10] != 'a' && board[11] != 'b' && board[12] != 'c' && board[13] != 'd'
            && board[14] != 'e' && board[15] != 'f')

            return 0;
        else
            return -1;


    }
    void engine()
    {
        system("cls");
        int result;
        char ask;
        do
        {
            this->makeboard();
            this->makechoice();
            result = decide();
        } while (result == -1);

        this->makeboard();
        if (result == 0)
        {
            cout << "\nGAME IS A DRAW\n";
        }
        else
        {
            if (turn % 2 == 0)
            {
                cout << "\n" << p2name << " WINS\n";
            }
            else
            {
                cout << "\n" << p1name << " WINS\n";
            }
        }
        l1.display();
        //if game over, display steps, compare the list to the sol. if new, put it there.
        //delete list and then ask for a new game with same players
        l1.deletelist();
        cout << "\nDO YOU WANT A NEW GAME WITH THE SAME PLAYERS?(y/n)";
        cin >> ask;
        if (toupper(ask) == 'Y')
        {
            multi* p = new multi(this->p1name, this->p2name);
            p->engine();
        }
        else
        {

            delete this;
        }


    }
    void makechoice()
    {
        if (turn % 2 == 0)
        {
            cout << "\n\n\t\t\tITS YOUR TURN, " << p1name;
        }
        else
        {
            cout << "\n\n\t\t\tITS YOUR TURN, " << p2name;
        }
        char choice;
        int change;
        int problem = 0;
        do {
            cout << "\nPICK THE PLACE WHERE YOU WANT TO PLACE YOUR MARK BY ENTERING THAT NUMBER: ";
            cin >> choice;
            cout << choice;
            switch (choice)
            {
            case 'a': change = 10;
                break;
            case 'b': change = 11;
                break;
            case 'c': change = 12;
                break;
            case 'd': change = 13;
                break;
            case 'e': change = 14;
                break;
            case 'f': change = 15;
                break;
            default: change = (int)choice - 48;
            }
            if ((choice < 48 || choice>57) && (choice < 97 || choice>102) || board[change] == p1mark || board[change] == p2mark)
            {
                cout << "\nERROR!!! WRONG INPUT\n";
                problem = 1;
            }
            else
            {

                addmark(change);
                problem = 0;
            }
        } while (problem == 1);
    }


};
void highscore()
{

}

int menu()
{
    int choice;
    cout << "\n\n\t\t\tMAIN MENU";
    cout << "\n\n\n\t\t\t1. SINGLE PLAYER";
    cout << "\n\t\t\t2. MULTIPLAYER";
    cout << "\n\t\t\t3. HIGH SCORE";
    cout << "\n\t\t\t4. HOW TO PLAY";
    cout << "\n\t\t\t5. REGISTRATION";
    cout << "\n\t\t\t6. EXIT";
    cout << "\n\t\t\tENTER YOUR CHOICE: ";
    cin >> choice;
    return choice;
}
void howtoplay()
{
    system("cls");
    cout << "\n\n\n\t\tTHE PLAYER MUST SELECT A SPOT WHERE THEY WANT TO PLACE THEIR MARK. AFTER ALL THE SPOTS HAVE BEEN PICKED AND THERE IS NO WINNER,THE GAME ENDS IN A DRAW. OTHERWISE, THE GAME IS WON BY WHOEVER COMPLETES A ROW,DIAGONAL, OR A COLUMN WITH THEIR MARK";
    system("pause");
}
class registration
{
    char pd[50];

public:
    char un[50];
    void reg(registration* saveobject)
    {
        cout << "\nEnter user name :: ";
        cin >> un;
        cout << "\nEnter password :: ";
        cin >> pd;

        ofstream filout;
        filout.open("registrationofplayer.txt", ios::app | ios::binary);
        if (!filout)
        {
            cout << "\nCannot open file\n";
        }
        else
        {
            cout << "\n";
            filout.write((char*)&saveobject, sizeof(registration));
            filout.close();
        }

        cout << "\n...........You are now registered for the game .......... \n\n";

    }



};


struct StepNode {
    int row, col;
    int step;
    StepNode* s_next;
};

struct Node {
    int priorty;
    int id[2];
    Node* next;
    StepNode* s_node;
};

class DeepLearner {

    Node* head, * rear;
    StepNode* s_head, * s_rear, * in_game_traverser;
    int n_sols, step_no;

    void swap_sol(Node* T1, Node* T2) {

        if (T1 == NULL || T2 == NULL || head == NULL || rear == NULL) { return; }

        Node* temp = T1;

        T1->priorty = T2->priorty;
        T1->id[0] = T2->id[0];
        T1->id[1] = T2->id[1];
        T1->s_node = NULL;
        T1->s_node = T2->s_node;

        T2->priorty = temp->priorty;
        T2->id[0] = temp->id[0];
        T2->id[1] = temp->id[1];
        T2->s_node = NULL;
        T2->s_node = temp->s_node;
    }

    void insert_sol(StepNode* sol_node, int* grid_id, int priority = 0) {
        Node* new_node = new Node;
        new_node->priorty = priority;
        new_node->s_node = sol_node;
        new_node->id[0] = grid_id[0];
        new_node->id[1] = grid_id[1];
        new_node->next = NULL;

        if (head == NULL) {
            head = rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = rear->next;
        }
        n_sols++;
    }

    StepNode* get_s_head() {
        return s_head;
    }

public:
    DeepLearner() {
        head = rear = NULL;
        s_head = s_rear = in_game_traverser = NULL;
        n_sols = step_no = 0;
    }

    //INSERT_STEP: EACH STEP IS TO BE ADDED AS THE GAME IS PLAYED SO THAT THE SOLUTION IS BEING SAVED IN REAL TIME
    void insert_step(int row, int col) {
        StepNode* new_node = new StepNode;
        new_node->col = col;
        new_node->row = row;
        new_node->step = step_no;
        new_node->s_next = NULL;

        step_no++;

        if (s_head == NULL) {
            s_head = s_rear = new_node;
        }
        else {
            s_rear->s_next = new_node;
            s_rear = s_rear->s_next;
        }
    }

    void sort_sol() {//TO SORT THE SOLUTIONS BY PRIORITY
        Node* traverser = head, * temp = NULL;
        int flagger = 0;

        while (traverser != NULL) {
            temp = traverser;
            flagger = 0;
            while (temp->next != NULL) {
                if (traverser->priorty < traverser->next->priorty) {
                    swap_sol(traverser, traverser->next);
                    flagger = 1;
                }
                temp = temp->next;
            }
            if (flagger == 0)break;
            traverser = traverser->next;
        }
    }

    void unique_sol_tester(int* grid_id) {//IF A UNIQUE SOLUTION EXISTS THEN IT IS ADDED TO THE DATASET
        Node* temp = head;
        int* flag1 = new int[1]{ -1 };
        if (n_sols > 0)flag1 = new int[n_sols] {0};
        int if_exists[16] = { 0 };

        int i = 0;
        while (temp != NULL) {
            int j = 0;
            StepNode* s_temp = s_head;
            StepNode* s_temp2 = temp->s_node;

            while (s_temp != NULL && s_temp2 != NULL)
            {
                if ((s_temp->row == s_temp2->row) && (s_temp->col == s_temp2->col)) { if_exists[j]++; }//TO CHECK FOR EXISTING SOLUTION

                if ((s_temp->row != s_temp2->row) || (s_temp->col != s_temp2->col)) {
                    if (flag1[0] != -1) {
                        flag1[i] = 1;
                        break;
                    }
                }//TO CHECK FOR UNIQUE SOLUTION

                s_temp = s_temp->s_next;
                s_temp2 = s_temp2->s_next;
                j++;
            }

            if (true) {// IF A SIMILAR SOLUTION EXISTS THEN ITS PRIORITY INCREASES
                int checker = 0;
                for (int k = 0; k < 16; k++) {
                    if (if_exists[k] != 1) { checker = 1; break; }
                }
                if (checker != 1) {
                    temp->priorty++;
                    this->sort_sol();
                    s_head = s_rear = NULL;
                    step_no = 0;
                    return;
                }
                for (int k = 0; k < 16; k++)if_exists[k] = 0;
            }

            i++;
            temp = temp->next;
        }

        if (flag1[0] != -1) {
            for (int j = 0; j < 16; j++) {
                if (flag1[j] == 0) { flag1[0] = 2; break; }
            }

            if (flag1[0] == 1) {
                this->insert_sol(s_head, grid_id);
            }
        }
        else {
            this->insert_sol(s_head, grid_id);
        }

        s_head = s_rear = NULL;
        step_no = 0;
    }

    void set_n_sols(int n_sols) {
        this->n_sols = n_sols;
    }

    void display() {
        StepNode* display_tra = head->s_node;

        while (display_tra != NULL) {
            cout << display_tra->row << " " << display_tra->col << endl;
            display_tra = display_tra->s_next;
        }
    }

    void clear_s_heads() {
        s_head = s_rear = in_game_traverser = NULL;
        step_no = 0;
    }

    friend class GameLogic;
};

class Filer;

class GameLogic {
    DeepLearner* solution_dataset;
    int* grid_id;
    bool flag;
    char** game_board;
    char** board_interface;
    int* arr_r_c;
    char cross, circle;

    int* get_step() {

        int* arr = new int[2];
        arr[0] = solution_dataset->in_game_traverser->row;
        arr[1] = solution_dataset->in_game_traverser->col;
        solution_dataset->in_game_traverser = solution_dataset->in_game_traverser->s_next;

        return arr;
    }

    int* cpu_reigns_back(char** board) {

        char pre_val[3] = { '-' };
        int* arr = new int[2]{ 0 };

        for (int i = 0; i < 4; i++) {

            //Row Checker
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][3] == '-' && board[i][0] != '-') { arr[0] = i; arr[1] = 3; flag = true; return arr; }
            else if (board[i][0] == board[i][1] && board[i][1] == board[i][3] && board[i][2] == '-' && board[i][0] != '-') { arr[0] = i; arr[1] = 2; flag = true; return arr; }
            else if (board[i][0] == board[i][2] && board[i][2] == board[i][3] && board[i][1] == '-' && board[i][0] != '-') { arr[0] = i; arr[1] = 1; flag = true; return arr; }
            else if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] == '-' && board[i][1] != '-') { arr[0] = i; arr[1] = 0; flag = true; return arr; }

            //Column Checker
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[3][i] == '-' && board[0][i] != '-') { arr[0] = 3; arr[1] = i; flag = true; return arr; }
            else if (board[0][i] == board[1][i] && board[1][i] == board[3][i] && board[2][i] == '-' && board[0][i] != '-') { arr[0] = 2; arr[1] = i; flag = true; return arr; }
            else if (board[0][i] == board[2][i] && board[2][i] == board[3][i] && board[1][i] == '-' && board[0][i] != '-') { arr[0] = 1; arr[1] = i; flag = true; return arr; }
            else if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] == '-' && board[1][i] != '-') { arr[0] = 0; arr[1] = i; flag = true; return arr; }

        }

        //Diagonal Checker
        int i = 0;
        if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 3][i + 3] == '-' && board[i][i] != '-') { arr[0] = arr[1] = 3; flag = true; return arr; }
        else if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 3][i + 3] && board[i + 2][i + 2] == '-' && board[i][i] != '-') { arr[0] = arr[1] = 2; flag = true; return arr; }
        else if (board[i][i] == board[i + 2][i + 2] && board[i + 2][i + 2] == board[i + 3][i + 3] && board[i + 1][i + 1] == '-' && board[i][i] != '-') { arr[0] = arr[1] = 1; flag = true; return arr; }
        else if (board[i + 1][i + 1] == board[i + 2][i + 2] && board[i + 2][i + 2] == board[i + 3][i + 3] && board[i][i] == '-' && board[i][i] != '-') { arr[0] = arr[1] = 0; flag = true; return arr; }

        //Reverse Diagonal Checker
        if (board[i + 3][i] == board[i + 2][i + 1] && board[i + 2][i + 1] == board[i + 1][i + 2] && board[i][i + 3] == '-' && board[i + 3][i] != '-') { arr[0] = 0; arr[1] = 3; flag = true; return arr; }
        else if (board[i + 3][i] == board[i + 2][i + 1] && board[i + 2][i + 1] == board[i][i + 3] && board[i + 1][i + 2] == '-' && board[i + 3][i] != '-') { arr[0] = 1; arr[1] = 2; flag = true; return arr; }
        else if (board[i + 3][i] == board[i + 1][i + 2] && board[i + 1][i + 2] == board[i][i + 3] && board[i + 2][i + 1] == '-' && board[i + 3][i] != '-') { arr[0] = 2; arr[1] = 1; flag = true; return arr; }
        else if (board[i + 2][i + 1] == board[i + 1][i + 2] && board[i + 1][i + 2] == board[i][i + 3] && board[i + 2][i + 1] == '-' && board[i + 2][i + 1] != '-') { arr[0] = 3; arr[1] = 0; flag = true; return arr; }

        arr[0] = -1;
        arr[1] = -1;
        return arr;
    }

    int check_winner(char** board) {

        if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == board[0][3] && board[0][0] != '-') {
            if (board[0][0] == 'X')return 1;
            else if (board[0][0] == 'O')return 2;
        }
        else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][0] != '-') {
            if (board[1][0] == 'X')return 1;
            else if (board[1][0] == 'O')return 2;
        }
        else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][0] != '-') {
            if (board[2][0] == 'X')return 1;
            else if (board[2][0] == 'O')return 2;
        }
        else if (board[3][0] == board[3][1] && board[3][1] == board[3][2] && board[3][2] == board[3][3] && board[3][0] != '-') {
            if (board[3][0] == 'X')return 1;
            else if (board[3][0] == 'O')return 2;
        }

        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] == board[3][0] && board[0][0] != '-') {
            if (board[0][0] == 'X')return 1;
            else if (board[0][0] == 'O')return 2;
        }
        else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[2][1] == board[3][1] && board[0][1] != '-') {
            if (board[0][1] == 'X')return 1;
            else if (board[0][1] == 'O')return 2;
        }
        else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] == board[3][2] && board[0][2] != '-') {
            if (board[0][2] == 'X')return 1;
            else if (board[0][2] == 'O')return 2;
        }
        else if (board[0][3] == board[1][3] && board[1][3] == board[2][3] && board[2][3] == board[3][3] && board[0][3] != '-') {
            if (board[0][3] == 'X')return 1;
            else if (board[0][3] == 'O')return 2;
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
            if (board[0][0] == 'X')return 1;
            else if (board[0][0] == 'O')return 2;
        }

        if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0]) {
            if (board[0][3] == 'X')return 1;
            else if (board[0][3] == 'O')return 2;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board[i][j] == '-')return 3;
            }
        }

        return 0;

    }

    int* get_indexes(int in_game_row, int in_game_col) {

        if (in_game_row == 1)in_game_row = 0;
        else if (in_game_row == 2)in_game_row = 2;
        else if (in_game_row == 3)in_game_row = 4;
        else if (in_game_row == 4)in_game_row = 6;

        if (in_game_col == 1)in_game_col = 2;
        else if (in_game_col == 2)in_game_col = 6;
        else if (in_game_col == 3)in_game_col = 10;
        else if (in_game_col == 4)in_game_col = 14;

        int* indexes = new int[2];
        indexes[0] = in_game_row;
        indexes[1] = in_game_col;

        return indexes;
    }

    void add_solution() {
        solution_dataset->unique_sol_tester(grid_id);
    }

    void activator(int grid_row, int grid_col) {
        solution_dataset->s_head = solution_dataset->s_rear = solution_dataset->in_game_traverser = NULL;
        grid_id[0] = grid_row;
        grid_id[1] = grid_col;

        Node* temp = solution_dataset->head;
        int flag = 0;

        while (temp != NULL) {
            solution_dataset->in_game_traverser = temp->s_node;
            if (temp->id[0] == grid_row && temp->id[1] == grid_col) {
                solution_dataset->in_game_traverser = temp->s_node;
                return;
            }
            temp = temp->next;
        }
    }

    int* in_game_logic(char** board) {//WILL USE GET_STEP

        int row = 0, col = 0, step = 0, * arr = new int[2]{ 0 };

        arr = this->cpu_reigns_back(board);

        if (flag == true) {
            flag = false;
            return arr;
        }
        arr = new int[2]{ 0 };
        if (solution_dataset->in_game_traverser != NULL) {

            row = solution_dataset->in_game_traverser->row;
            col = solution_dataset->in_game_traverser->col;
            step = solution_dataset->in_game_traverser->step;

            if (board[row][col] == '-') {//THIS CONDITION SHOULD BE ALTERED TO THE SPECIFIC BOARD CONDITION
                solution_dataset->in_game_traverser->s_next;

                arr[0] = row;
                arr[1] = col;

                solution_dataset->insert_step(row, col);

                return arr;
            }
            else {

                Node* temp = solution_dataset->head;
                while (temp != NULL) {
                    StepNode* s_temp = temp->s_node;

                    while (s_temp != NULL) {

                        if (s_temp->step == step) {
                            if (board[s_temp->row][s_temp->col] == '-') {

                                solution_dataset->in_game_traverser = s_temp->s_next;
                                arr[0] = s_temp->row;
                                arr[1] = s_temp->col;

                                solution_dataset->insert_step(row, col);

                                return arr;
                            }
                            break;
                        }
                        s_temp = s_temp->s_next;
                    }
                    temp = temp->next;
                }
            }
        }

        srand(time(0));
        row = 1 + (rand() % 4);
        col = 1 + (rand() % 4);

        if (board[row][col] != '-') { row = 0; col = 0; }//IF THE RANDOM ROW AND COL ARE OCCUPIED THEN A LOOP INITIATOR

        for (int i = 0; i < 19; i++) {
            if (board[row][col] == '-') {
                arr[0] = row;
                arr[1] = col;

                solution_dataset->insert_step(row, col);

                return arr;
            }
            else if (col < 4) { col++; }
            else { col = 0; row++; }
        }

        arr[0] = -1;
        arr[1] = -1;

        return arr;

    }

public:
    GameLogic() {

        flag = false;
        grid_id = new int[2]{ 0 };
        solution_dataset = new DeepLearner;
        cross = 'X';
        circle = 'O';
        arr_r_c = new int[2]{ 0 };

        game_board = new char* [4];
        for (int i = 0; i < 4; i++) {
            game_board[i] = new char[4];
            for (int j = 0; j < 4; j++) {
                game_board[i][j] = '-';
            }
        }

        board_interface = new char* [8];
        for (int i = 0, k = 0; i < 8; i++) {
            board_interface[i] = new char[16];
            for (int j = 0; j < 16; j++) {

                if (j == 4 || j == 8 || j == 12) {
                    board_interface[i][j] = 245;
                    continue;
                }
                if (j == 0 && i % 2 != 0) {
                    board_interface[i][j] = i + 48 - k;
                    k++;
                }
                else if (i % 2 == 0 || i >= 7) {
                    board_interface[i][j] = ' ';
                }
                else if (i < 7) {
                    board_interface[i][j] = '_';
                }
            }
        }

        grid_id[0] = 0; grid_id[1] = 0;
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->clear_s_heads();

        grid_id[0] = 0; grid_id[1] = 1;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(0, 3);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->clear_s_heads();

        grid_id[0] = 0; grid_id[1] = 2;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(0, 3);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->clear_s_heads();

        grid_id[0] = 0; grid_id[1] = 3;
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->clear_s_heads();

        grid_id[0] = 1; grid_id[1] = 0;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(3, 3);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->clear_s_heads();

        grid_id[0] = 1; grid_id[1] = 1;
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(3, 3);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 1; grid_id[1] = 2;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 1; grid_id[1] = 3;
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(0, 3);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_step(3, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 2; grid_id[1] = 0;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 2; grid_id[1] = 1;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_step(0, 3);
        solution_dataset->insert_step(2, 2);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 2; grid_id[1] = 2;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 2; grid_id[1] = 3;
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(3, 3);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 3; grid_id[1] = 0;
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 3; grid_id[1] = 1;
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(0, 0);
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(0, 3);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_step(3, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 3; grid_id[1] = 2;
        solution_dataset->insert_step(1, 0);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(1, 2);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(2, 0);
        solution_dataset->insert_step(3, 1);
        solution_dataset->insert_step(0, 1);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

        grid_id[0] = 3; grid_id[1] = 3;
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(2, 3);
        solution_dataset->insert_step(3, 0);
        solution_dataset->insert_step(1, 1);
        solution_dataset->insert_step(0, 2);
        solution_dataset->insert_step(3, 2);
        solution_dataset->insert_step(2, 1);
        solution_dataset->insert_step(1, 3);
        solution_dataset->insert_sol(solution_dataset->s_head, grid_id);
        solution_dataset->n_sols++;

    }

    void input() {

        int winner = 0, input_row = 0, input_col = 0;
        int* player_start_grid = new int[2]{ 0 };
        int* opponent_start_grid = new int[2]{ 0 };
        bool first = true;

        time_t start_time, end_time;
        start_time = time(NULL);

        DeepLearner player_sol;
        DeepLearner opponent_sol;

        while (true) {
        ask_again:
            system("cls");
            cout << "\n\n\n\t\t\t\t4X4 Tic-Tac-Toe\n\n" << "\t\t\t\t   1   2   3   4" << endl;
            print_interface_board();

            cout << "\n\n\t\t\tEnter row number: "; cin >> input_row;
            cout << "\t\t\tEnter column number: "; cin >> input_col;

            if (input_row > 0 && input_row < 5 && input_col > 0 && input_col < 5 && game_board[input_row - 1][input_col - 1] == '-') {
                if (first == true) {
                    activator(input_row - 1, input_col - 1);
                    player_start_grid[0] = input_row - 1;
                    player_start_grid[1] = input_col - 1;
                }

                game_board[input_row - 1][input_col - 1] = cross;
                player_sol.insert_step(input_row - 1, input_col - 1);

                arr_r_c = get_indexes(input_row, input_col);
                board_interface[arr_r_c[0]][arr_r_c[1]] = cross;
            }
            else {
                cout << "\n\t\t\t\tWrong input" << endl << "\n\t\t\t";
                system("pause");
                goto ask_again;
            }

            arr_r_c = in_game_logic(game_board);
            game_board[arr_r_c[0]][arr_r_c[1]] = circle;
            if (first == true) {
                first = false;
                opponent_start_grid[0] = arr_r_c[0];
                opponent_start_grid[1] = arr_r_c[1];
            }
            opponent_sol.insert_step(arr_r_c[0], arr_r_c[1]);

            arr_r_c = get_indexes(arr_r_c[0] + 1, arr_r_c[1] + 1);
            board_interface[arr_r_c[0]][arr_r_c[1]] = circle;

            winner = check_winner(game_board);
            if (winner == 1) {
                end_time = time(NULL);
                cout << "\n\t\t\t\tYou Won the game!" << endl;
                char* name = new char[10]{ ' ' };
                cout << "Enter Name: "; cin >> name;

                HighScore Recorder(name);
                Recorder.save_highscore(Recorder.get_highscore(start_time, end_time));
                Recorder.read_highscores();

                system("pause");
                solution_dataset->clear_s_heads();
                solution_dataset->insert_sol(player_sol.get_s_head(), player_start_grid);
                solution_dataset->unique_sol_tester(player_start_grid);
                break;
            }
            else if (winner == 2) {
                end_time = time(NULL);
                cout << "\n\t\t\t\tBot won the game" << endl;
                system("pause");
                solution_dataset->clear_s_heads();
                solution_dataset->insert_sol(opponent_sol.get_s_head(), opponent_start_grid);
                solution_dataset->unique_sol_tester(opponent_start_grid);
                break;
            }
            else if (winner == 0) {
                end_time = time(NULL);
                cout << "\n\t\t\t\tDraw!" << endl;
                system("pause");
                solution_dataset->clear_s_heads();
                solution_dataset->insert_sol(opponent_sol.get_s_head(), opponent_start_grid);
                solution_dataset->unique_sol_tester(opponent_start_grid);
                break;
            }
        }
        system("cls");

    }

    void print_game_board() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << game_board[i][j];
            }
            cout << endl;
        }
    }

    void print_interface_board() {
        for (int i = 0; i < 8; i++) {
            cout << "\t\t\t\t";
            for (int j = 0; j < 16; j++) {
                cout << board_interface[i][j];
                if (j == 0) { cout << " "; }
            }
            cout << endl;
        }
    }

};

class Filer {
    string file_name;

public:
    Filer(string file_name) {
        this->file_name = file_name;
    }

    void save_solutions(GameLogic* saver) {

        fstream file(file_name, ios::out);
        file.write((char*)saver, sizeof(saver));
        file.close();
    }

    void load_solutions(GameLogic* loading_object) {

        fstream file(file_name, ios::in);
        file.read((char*)loading_object, sizeof(loading_object));
        file.close();
    }
};

int main()
{
    //make menu here;
    screenheader();
    int c;
    while (1)
    {
        system("cls");
        c = menu();
        if (c == 1)
        {
            GameLogic caller;
            caller.input();
        }
        if (c == 2)
        {
            string name1, name2;
            cout << "ENTER PLAYER 1'S NAME: ";
            cin >> name1;
            cout << "ENTER PLAYER 2'S NAME: ";
            cin >> name2;
            multi* m;
            m = new multi(name1, name2);
            m->engine();
        }
        else if (c == 3)
        {
            highscore();
        }
        else if (c == 4)
        {
            howtoplay();
        }
        else if (c == 5)
        {

            cout << "\nEnter Registration Details :: \n";
            registration obj;
            obj.reg(&obj);
            registration obj2;
            ifstream filein;
            filein.open("registrationofplayer.txt");
            if (!filein)
            {
                cout << "\nUnable to open file \n";
            }
            else
            {
                cout << "\nRegistered Details of All Users :: \n";
                filein.read((char*)&obj2, sizeof(obj2));
                while (filein)
                {
                    cout << "\nUsername :: " << obj2.un << "\n";
                    filein.read((char*)&obj2, sizeof(obj2));
                }

            }
        }
        else if (c == 6)
        {
            exit(0);
        }
        else if (c < 1 || c>6)
        {
            cout << "WRONG CHOICE";
        }
    }
}