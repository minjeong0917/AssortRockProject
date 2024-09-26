// 005_TextRPG002inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

const int NAMELEN = 10;

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;
};

class FightUnit : public StatusUnit
{
public:
    // MinMax
    int GetDamage() const
    {
        // minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
        // return MinAtt + rand
        __int64 Value = time(0);
        srand(Value);

        int AttDamage = MinAtt + rand() % (MaxAtt - MinAtt + 1);
        return AttDamage;
    }

    void DamageLogic(const FightUnit& _AttUnit)
    {
        Hp -= _AttUnit.GetDamage();
    }

    void DamageRender(const FightUnit& _DefUnit)
    {
        printf_s(" %d의 데미지를 받아 Hp가 %d가 되었습니다.\n",  GetDamage(), _DefUnit.Hp);

    }

    const char* GetName() const
    {
        return Name;
    }

protected:

private:

};

class Player : public FightUnit
{

};

class Monster : public FightUnit
{

};

int main()
{
    Player NewPlayer;
    Monster NewMonster;
    while (true) {
        char Input = ' ';
        Input = _getch();

        NewMonster.DamageLogic(NewPlayer);
        NewMonster.DamageRender(NewMonster);

    }

}