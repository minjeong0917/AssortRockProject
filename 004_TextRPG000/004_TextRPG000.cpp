// 004_TextRPG000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAttMin = 0;
int PlayerAtt = 0;
int PlayerHp = 0;
int PlayerSpeed = 10;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
int MonsterSpeed = 10;
char MonsterName[NAMELEN] = "NONE";


void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }


    int Size = strlen(_Name);
    _Arr[0] = _Name[0];

    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }
}
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
    PlayerSpeed = _Speed;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp, int _Speed)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
    MonsterSpeed = _Speed;
}

void Line(int _size)
{

    for (int i = 0; i < LINECOUNT - _size; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");

}

void StatusRender(const char* _Name, int _Att, int _HP)
{

    printf_s("%s Status ", _Name);  

    int NameSize = strlen(_Name) + strlen(" Status ");

    Line(NameSize);

    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    Line(0);

}


int CalSpeed(int _Speed)
{
    return rand() % _Speed;
}


void Damage(int& _DefHp, int _Att)
{
    _DefHp -= _Att;
}


void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);

}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}


void SpeedCheckRender(const char* const _Name)
{
    printf_s("%s 의 선공입니다\n", _Name);
}

void DamageRender(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);

}

int main()
{
    CreatePlayer("Player", 10, 100, 20);
    CreateMonster("Orc", 10, 100, 10);

    srand(time(0));

    while (true)
    {
        system("cls");

        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();

        Input = _getch();
        system("cls");

        int CurPlayerSpeed = CalSpeed(PlayerSpeed);
        int CurMonsterSpeed = CalSpeed(MonsterSpeed);

        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            Damage(MonsterHp, PlayerAtt);

        }
        else {
            Damage(PlayerHp, MonsterAtt);
;
        }

        PlayerStatusRender();
        MonsterStatusRender();

        if (CurPlayerSpeed > CurMonsterSpeed)
        {

            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        }
        else {

            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterHp, MonsterAtt);
        }


        Input = _getch();
        system("cls");
        if (CurPlayerSpeed > CurMonsterSpeed)
        {
            Damage(PlayerHp, MonsterAtt);
        }
        else {
            Damage(MonsterHp, PlayerAtt);
            
        }

        PlayerStatusRender();
        MonsterStatusRender();

        if (CurPlayerSpeed > CurMonsterSpeed)
        {

            SpeedCheckRender(PlayerName);
            DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);
            DamageRender(MonsterName, PlayerName, MonsterHp, MonsterAtt);
        }
        else {

            SpeedCheckRender(MonsterName);
            DamageRender(MonsterName, PlayerName, MonsterHp, MonsterAtt);
            DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        }


        Input = _getch();
    }

}