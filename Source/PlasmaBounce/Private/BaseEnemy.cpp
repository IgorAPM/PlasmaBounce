// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent=CollisionBoxComponent;
	CollisionBoxComponent->SetBoxExtent(FVector(64.0f, 64.0f, 100.0f));
	CollisionBoxComponent->SetupAttachment(RootComponent);
	CollisionBoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBoxComponent->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionBoxComponent->SetCollisionResponseToAllChannels(ECR_Block);
	CollisionBoxComponent->SetGenerateOverlapEvents(true);
	CollisionBoxComponent->SetNotifyRigidBodyCollision(true);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetCanEverAffectNavigation(false);
	SkeletalMesh->SetupAttachment(CollisionBoxComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->OnHealthChanged.AddDynamic(this, &ABaseEnemy::HandleTakeDamage);
	HealthComponent->OnDeath.AddDynamic(this, &ABaseEnemy::Die);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseEnemy::HandleTakeDamage(UHealthComponent* ThisHealthComponent, float Health, float HealthDelta,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{

}

void ABaseEnemy::Die(UHealthComponent* ThisHealthComponent, AController* InstigatedBy)
{
	this->Destroy();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
}

