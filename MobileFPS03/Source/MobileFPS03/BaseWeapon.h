// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FPSProjectile.h"

#include "BaseWeapon.generated.h"

UCLASS()
class MOBILEFPS03_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Ҫ���ɵķ������ࡣ
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;

	// ǹ������������λ�õ�ƫ�ơ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	UFUNCTION(BlueprintCallable)
		void Fire();

};
