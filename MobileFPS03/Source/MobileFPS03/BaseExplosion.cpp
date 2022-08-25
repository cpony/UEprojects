// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseExplosion.h"

// Sets default values
ABaseExplosion::ABaseExplosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseExplosion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseExplosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

