// 004_TextRPG000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
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

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}
int main()
{
    CreatePlayer("Playertest", 10, 100);
    CreateMonster("Orc", 10, 50);

    PlayerStatusRender();
    MonsterStatusRender();

}