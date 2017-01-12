#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <random>
#include <time.h>

using namespace std;

int tabla[3][3];
int numarJocuri, numarVictorii1, numarVictorii2;
int jucator = 1;

void curata()
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        tabla[i][j] = 0;
}

char inloc(int a, int b)
{
    if(tabla[a][b] == 0) return ' ';
    if(tabla[a][b] == 1) return 'X';
    if(tabla[a][b] == 2) return '0';
}

bool primeste(int &a)
{
    cin >> a;

    while(!cin)
    {
        cout << "Introduceti din nou\n";
        cin.clear();
        cin.ignore(265, '\n');
        cin >> a;
    }
}

void afisareTabla()
{
    system("cls");

    cout << "Jucatorul numarul 1 are " << numarVictorii1 << " victorii\n";
    cout << "Jucatorul numarul 2 are " << numarVictorii2 << " victorii\n\n";
    cout << "S-au jucat " << numarJocuri << " jocuri\n\n";

    cout << "\t+---+---+---+\n";
    cout << "\t| " << inloc(0, 0) <<" | " << inloc(0, 1) << " | " << inloc(0, 2) << " |\n";
    cout << "\t+---+---+---+\n";
    cout << "\t| " << inloc(1, 0) <<" | " << inloc(1, 1) << " | " << inloc(1, 2) << " |\n";
    cout << "\t+---+---+---+\n";
    cout << "\t| " << inloc(2, 0) <<" | " << inloc(2, 1) << " | " << inloc(2, 2) << " |\n";
    cout << "\t+---+---+---+\n";

    cout << "\n";
}

int verif()
{
    for(int i = 0; i < 3; i++)
    {
        if(tabla[i][0] != 0 && tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2])
        {
            return tabla[i][0];
        }
        if(tabla[0][i] != 0 && tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i])
        {
            return tabla[0][i];
        }
    }
    if(tabla[0][0] != 0 && tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2])
    {
        return tabla[0][0];
    }
    if(tabla[0][2] != 0 && tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0])
    {
        return tabla[0][2];
    }

    int ok = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        if(tabla[i][j] == 0) ok = 1;

    if(ok == 0) return 3;

    return 0;
}

void comanda()
{
    int a, b;

    cout << "Jucatorul " << jucator << "\n\n";

    while(1)
    {
        cout << "Introduceti coloana:\n";

        while(primeste(a))
        {
            if(a >= 1 && a <= 3) break;

            cout << "Comanda invalida\nIntroduceti din nou coloana\n";
        }

        cout << "Introduceti linia:\n";

        while(primeste(b))
        {
            if(b >= 1 && b <= 3) break;

            cout << "Comanda invalida\nIntroduceti din nou linia\n";
        }

        if(tabla[b-1][a-1] != 0) cout << "Pozitie ocupata\n\n";

        else
        {
            tabla[b-1][a-1] = jucator;

            break;
        }
    }
}

void schimbaJucator()
{
    if(jucator == 1) jucator = 2;

    else jucator = 1;
}

bool optiune()
{
    int a;

    cout << "Doriti sa jucati din nou?\n";
    cout << "1 Da\t2 Nu\n";

    while(primeste(a))
    {
        if(a == 1) return true;

        if(a == 2) return false;

        cout << "Comanda invalida\n";
    }
}

void comandaCalculatorUsor()
{
    int x, y;

    x = rand() % 3;
    y = rand() % 3;

    while(tabla[y][x] != 0)
    {
        x++;

        if(x == 3)
        {
            x = 0;
            y++;
        }

        if(y == 3) y = 0;
    }

    tabla[y][x] = 2;

    cout << "Calculatorul a ales coloana " << x + 1 << " si linia " << y + 1 << "\n";

    Sleep(1500);
}

bool verificareCastig()
{
    int nr1, nr2;

    for(int i = 0; i < 3; i++)
    {
        nr1 = 0; nr2 = 0;

        for(int j = 0; j < 3; j++)
        {
            if(tabla[i][j] == 1) nr1++;
            if(tabla[i][j] == 2) nr2++;
        }

        if(nr1 == 0 && nr2 == 2)
        {
            for(int j = 0; j < 3; j++)
            {
                if(tabla[i][j] == 0)
                {
                    tabla[i][j] = 2;

                    cout << "Calculatorul a ales coloana " << j + 1 << " si linia " << i + 1 << endl;

                    Sleep(1500);

                    return true;
                }
            }
        }
    }

    for(int j = 0; j < 3; j++)
    {
        nr1 = 0; nr2 = 0;

        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][j] == 1) nr1++;
            if(tabla[i][j] == 2) nr2++;
        }

        if(nr1 == 0 && nr2 == 2)
        {
           for(int i = 0; i < 3; i++)
           {
               if(tabla[i][j] == 0)
               {
                   tabla[i][j] = 2;

                   cout << "Calculatorul a ales coloana " << j + 1 << " si linia " << i + 1 << endl;

                   Sleep(1500);

                   return true;
               }
           }
        }
    }

    nr1 = 0; nr2 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(tabla[i][i] == 1) nr1++;
        if(tabla[i][i] == 2) nr2++;
    }

    if(nr1 == 0 && nr2 == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][i] == 0)
            {
                tabla[i][i] = 2;

                cout << "Calculatorul a ales coloana " << i + 1 << " si linia " << i + 1 << endl;

                Sleep(1500);

                return true;
            }
        }
    }

    nr1 = 0; nr2 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(tabla[i][2 - i] == 1) nr1++;
        if(tabla[i][2 - i] == 2) nr2++;
    }

    if(nr1 == 0 && nr2 == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][2 - i] == 0)
            {
                tabla[i][2 - i] = 2;

                cout << "Calculatorul a ales coloana " << 2 - i + 1 << " si linia " << i + 1 << endl;

                Sleep(1500);

                return true;
            }
        }
    }

    return false;
}

bool verificarePericol()
{
    int nr1, nr2;

    for(int i = 0; i < 3; i++)
    {
        nr1 = 0; nr2 = 0;

        for(int j = 0; j < 3; j++)
        {
            if(tabla[i][j] == 1) nr1++;
            if(tabla[i][j] == 2) nr2++;
        }

        if(nr1 == 2 && nr2 == 0)
        {
            for(int j = 0; j < 3; j++)
            {
                if(tabla[i][j] == 0)
                {
                    tabla[i][j] = 2;

                    cout << "Calculatorul a ales coloana " << j + 1 << " si linia " << i + 1 << endl;

                    Sleep(1500);

                    return true;
                }
            }
        }
    }

    for(int j = 0; j < 3; j++)
    {
        nr1 = 0; nr2 = 0;

        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][j] == 1) nr1++;
            if(tabla[i][j] == 2) nr2++;
        }

        if(nr1 == 2 && nr2 == 0)
        {
           for(int i = 0; i < 3; i++)
           {
               if(tabla[i][j] == 0)
               {
                   tabla[i][j] = 2;

                   cout << "Calculatorul a ales coloana " << j + 1 << " si linia " << i + 1 << endl;

                   Sleep(1500);

                   return true;
               }
           }
        }
    }

    nr1 = 0; nr2 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(tabla[i][i] == 1) nr1++;
        if(tabla[i][i] == 2) nr2++;
    }

    if(nr1 == 2 && nr2 == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][i] == 0)
            {
                tabla[i][i] = 2;

                cout << "Calculatorul a ales coloana " << i + 1 << " si linia " << i + 1 << endl;

                Sleep(1500);

                return true;
            }
        }
    }

    nr1 = 0; nr2 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(tabla[i][2 - i] == 1) nr1++;
        if(tabla[i][2 - i] == 2) nr2++;
    }

    if(nr1 == 2 && nr2 == 0)
    {
        for(int i = 0; i < 3; i++)
        {
            if(tabla[i][2 - i] == 0)
            {
                tabla[i][2 - i] = 2;

                cout << "Calculatorul a ales coloana " << 2 - i + 1 << " si linia " << i + 1 << endl;

                Sleep(1500);

                return true;
            }
        }
    }

    return false;
}

void comandaCalculatorGreu()
{

    if(verificareCastig()) return;

    if(verificarePericol()) return;

    int x, y;

    x = rand() % 3;
    y = rand() % 3;

    while(tabla[y][x] != 0)
    {
        x++;

        if(x == 3)
        {
            x = 0;
            y++;
        }

        if(y == 3) y = 0;
    }

    tabla[y][x] = 2;

    cout << "Calculatorul a ales coloana " << x + 1 << " si linia " << y + 1 << "\n";

    Sleep(1500);
}

void jocIn2()
{
    jucator = rand() % 2 + 1;

    while(1)
    {
        afisareTabla();

        comanda();

        schimbaJucator();

        int stare = verif();

        if(stare == 1)
        {
            numarVictorii1++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 1\n";
            curata();
            Sleep(3000);
        }
        if(stare == 2)
        {
            numarVictorii2++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 2\n";
            curata();
            Sleep(3000);
        }
        if(stare == 3)
        {
            numarJocuri++;
            afisareTabla();
            cout << "Remiza\n";
            curata();
            Sleep(3000);
        }

        if(stare != 0)
        {
            if(!optiune()) break;
        }
    }
}

void jocUsorCalculator()
{
    jucator = rand() % 2 + 1;

    while(1)
    {
        afisareTabla();

        if(jucator == 1)
        {
            comanda();
        }
        else
        {
            comandaCalculatorUsor();
        }

        int stare = verif();

        if(stare == 1)
        {
            numarVictorii1++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 1\n";
            curata();
            Sleep(3000);
        }
        if(stare == 2)
        {
            numarVictorii2++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 2\n";
            curata();
            Sleep(3000);
        }
        if(stare == 3)
        {
            numarJocuri++;
            afisareTabla();
            cout << "Remiza\n";
            curata();
            Sleep(3000);
        }

        if(stare != 0)
        {
            if(!optiune()) break;
        }

        schimbaJucator();
    }
}

void jocGreuCalculator()
{
    jucator = rand() % 2 + 1;

    while(1)
    {
        afisareTabla();

        if(jucator == 1)
        {
            comanda();
        }
        else
        {
            comandaCalculatorGreu();
        }

        int stare = verif();

        if(stare == 1)
        {
            numarVictorii1++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 1\n";
            curata();
            Sleep(3000);
        }
        if(stare == 2)
        {
            numarVictorii2++;
            numarJocuri++;
            afisareTabla();
            cout << "A castigat jucatorul 2\n";
            curata();
            Sleep(3000);
        }
        if(stare == 3)
        {
            numarJocuri++;
            afisareTabla();
            cout << "Remiza\n";
            curata();
            Sleep(3000);
        }

        if(stare != 0)
        {
            if(!optiune()) break;
        }

        schimbaJucator();
    }
}

int afisareMeniu()
{
    int t;

    system("cls");

    cout << "X si 0\n\n";

    cout << "Alegeti modul de joc:\n";
    cout << "1 Joc in 2\n";
    cout << "2 Joc usor cu calculatorul\n";
    cout << "3 Joc greu cu calculatorul\n";
    cout << "4 Iesire din joc\n";

    primeste(t);

    if(t >= 1 && t <= 4)
    {
        return t;
    }

    return 0;
}

int main()
{
    srand(time(NULL));

    while(1)
    {
        numarJocuri = 0;
        numarVictorii1 = 0;
        numarVictorii2 = 0;

        int alegere;

        alegere = afisareMeniu();

        if(alegere == 1) jocIn2();

        if(alegere == 2) jocUsorCalculator();

        if(alegere == 3) jocGreuCalculator();

        if(alegere == 4) break;
    }
}
