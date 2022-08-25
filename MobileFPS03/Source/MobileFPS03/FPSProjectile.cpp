// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSProjectile.h"

// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSceneComponent"));
	}
	if (!CollisionComponent)
	{
		// ��������м򵥵���ײչʾ��
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

		//_____________
		// ���������ײ�����ļ���������Ϊ"Projectile"��
		CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));

		// �������ĳ��ʱ���õ��¼���
		CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);
		//_____________

		// �����������ײ�뾶��
		CollisionComponent->InitSphereRadius(3.0f);
		// �����������Ϊ��ײ�����//�����ø��������Ϊ�Զ�����ײ�����
		RootComponent = CollisionComponent;
	}

	if (!ProjectileMovementComponent)
	{
		// ʹ�ô����������������ƶ���
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);//CollisionComponent�Ѿ���Ϊ��������൱�ڸ��¸����
		ProjectileMovementComponent->InitialSpeed = 3000.0f;
		ProjectileMovementComponent->MaxSpeed = 3000.0f;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
		ProjectileMovementComponent->bShouldBounce = true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	}

	if (!ProjectileMeshComponent)
	{
		ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
		//static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("'/Game/Models/Sphere.Sphere'"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/Models/SM_Projectile.SM_Projectile'"));
		
		if (Mesh.Succeeded())
		{
			ProjectileMeshComponent->SetStaticMesh(Mesh.Object);
		}
	}


	//static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Game/Models/SphereMaterial.SphereMaterial'"));
	//if (Material.Succeeded())
	//{
	//	ProjectileMaterialInstance = UMaterialInstanceDynamic::Create(Material.Object, ProjectileMeshComponent);
	//}
	//ProjectileMeshComponent->SetMaterial(0, ProjectileMaterialInstance);
	// 
	//ProjectileMeshComponent->SetRelativeScale3D(FVector(0.09f, 0.09f, 0.09f));
	//ProjectileMeshComponent->SetRelativeScale3D(FVector(0.9f, 0.9f, 0.9f));
	ProjectileMeshComponent->SetupAttachment(RootComponent);


	// 3 ���ɾ�������
	InitialLifeSpan = 10.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	


}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ��ʼ����������Ϸ������ٶȵĺ�����
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// ���������������ʱ����õĺ�����
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics()     &&OtherActor!=GetOwner())
	{
		OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}

	Destroy();
}
