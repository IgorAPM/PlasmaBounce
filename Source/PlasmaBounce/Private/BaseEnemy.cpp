// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetCanEverAffectNavigation(false);

	CollisionBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBoxComponent->SetBoxExtent(FVector(64.0f, 64.0f, 100.0f));
	CollisionBoxComponent->SetupAttachment(RootComponent);
	CollisionBoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionBoxComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionBoxComponent->SetGenerateOverlapEvents(true);

	SkeletalMesh->SetupAttachment(CollisionBoxComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	HealthComponent->OnHealthChanged.AddDynamic(this, &ABaseEnemy::HandleTakeDamage);

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseEnemy::HandleTakeDamage(UHealthComponent* ThisHealthComponent, float Health, float HealthDelta,
	const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if(Health <= 0)
	{
		this->Die();		
	}
}

void ABaseEnemy::Die()
{
	this->Destroy();
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
{
}

