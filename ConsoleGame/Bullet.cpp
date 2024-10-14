#include "Bullet.h"


void Bullet::BeginPlay()
{
	Super::BeginPlay();
	RenderImage.Create({ 1, 1 }, 'I');
}

void Bullet::Tick()
{
	Super::Tick();
	AddActorLocation(FIntPoint::UP); // 총알이 올라가도록!
}
