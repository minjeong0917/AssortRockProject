// 004_TextRPG000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAtt = 10;
int PlayerHp = 100;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 50;
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
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
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

void DamageRender(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);

}

int main()
{
    CreatePlayer("Playertest", 10, 100);
    CreateMonster("Orc", 10, 50);

    while (true)
    {
        system("cls");

        char Input = ' ';

        PlayerStatusRender();
        MonsterStatusRender();

        Input = _getch();
        Damage(MonsterHp, PlayerAtt);

        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);


        Input = _getch();
        Damage(PlayerHp, MonsterAtt);

        system("cls");
        PlayerStatusRender();
        MonsterStatusRender();
        DamageRender(PlayerName, MonsterName, MonsterHp, PlayerAtt);
        DamageRender(MonsterName, PlayerName, PlayerHp, MonsterAtt);

        Input = _getch();
    }

}