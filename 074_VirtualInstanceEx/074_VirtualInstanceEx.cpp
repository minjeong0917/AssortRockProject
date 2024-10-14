// 074_VirtualInstanceEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class AActor
{
public:
    virtual ~AActor()
    {

    }
};

// Monster Is A AActor
// Player* => AActor* => UpCasting
class Monster : public AActor
{
};

// Player Is A AActor
// Player* => AActor* => UpCasting
class Player : public AActor
{
};

// 게임에서 나올 모든 눈에 보이는 오브젝트가 여기안에 담겨있을 것이다.
// 게임마다 달라. 예상할수 있다고
// 유저는 항상 개발의 상상력을 깹니다. 상식적으로 유저를 접근하면 안됩니다.
// 그래서 항상 가장 다형적인 측면으로 접근해도 된다.
// 일단 문제가 없게 접근해야 합니다.
// 일단 상수가 절대로 가능하지가 않아요.

// 최초에 몇개를 만들지 정하지 않아요. 일반적으로

AActor** AllActorList = nullptr;
int AllActorSize = 0;

// 이런식의 함수를 만듭니다.
void SpawnActor(AActor* _Actor)
{
    // 새로만든 플레이어를 받을공간이 없으므로

    AllActorList = new AActor*[AllActorSize + 1];

    AllActorList[AllActorSize] = _Actor;
    ++AllActorSize;
}


int main()
{
    // 그러면서도 leck은 없어야 합니다.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //// 10마리 10마리를 만든다음 다음과 같이 해야한다.
    //Player NewPlayer[10];
    //Monster NewMonster[10];

    //// 당연히 됩니다.
    //// 참조형이기 때문에 아주 간단
    //Player* Ptr = new Player[10];
    //Monster* Ptr0 = new Monster[10];

    // 플레이어를 잃어버린것이다.
    // AActor* Ptr = new Player();




    // 두번 실행 했을 때 터지는 이유  cf. ppt 다형성을 이용한 메모리 그리기 메모리 그림 참고
    // = SpawnActor(new Player());
    // = SpawnActor(new Player());
    // 위 코드를 풀어보면..
    AllActorList = new AActor*[1]; // new 하면 힙에 생김!
    AllActorList[0] = new Player();
    ++AllActorSize;


    AllActorList = new AActor*[2]; // AllActorList = new AActor * [1]; 여기서 이 연결이 끊겨서(릭) 여기서부터 문제임 
                                     // AllActorList가 new AActor[1]의 주소값을 가지고 있었는데 new AActor[2]의 주소값으로 바껴서 포인터는 2개를 연결 할 수 없으니 새로 정의한new AActor[2]의 주소값으로 연결된거임
                                     // 그래서 AllActorList[0] = new Player();얘네는 잃어버린 메모리가 된거지 -> 릭 문제 발생함!
    AllActorList[1] = new Player(); // AllActorList = new AActor * [2]; 새로 만든 배열에서 1번에 new플레이어 연결 
    ++AllActorSize;



    for (size_t i = 0; i < AllActorSize; i++)
    {
        delete AllActorList[i]; // AllActorList[0]여기에 아무 값도 없는(null)인데 지우려했기 때문에 "0xC0000005: 0xFFFFFFFFFFFFFFFF 위치를 읽는 동안 액세스 위반이 발생" 오류 생긴거임!
    }


    delete[] AllActorList;

    //SpawnActor(new Player());
    //SpawnActor(new Player());
    //SpawnActor(new Player());


}
