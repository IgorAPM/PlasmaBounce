// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereCollision->InitSphereRadius(5.0f);
	SphereCollision->SetCollisionProfileName("Projectile");
	SphereCollision->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);
	SphereCollision->SetCollisionResponseToAllChannels(ECR_Block);
	SphereCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SphereCollision->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	SphereCollision->CanCharacterStepUpOn = ECB_No;

	RootComponent = SphereCollision;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = SphereCollision;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bRotationRemainsVertical = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.0f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->BounceVelocityStopSimulatingThreshold = 0.0f;

	ProjectileMovement->SetAutoActivate(false);

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this))
	{
		//UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, )
		UE_LOG(LogTemp, Log, TEXT("Projectile Hit"));
	}
}

void ABaseProjectile::OnFired(FVector Direction, float Speed)
{
	SetActorHiddenInGame(false);
	ProjectileMovement->Activate(true);
	ProjectileMovement->SetVelocityInLocalSpace(Direction * Speed);
}

void ABaseProjectile::Disable()
{
	SetActorHiddenInGame(true);
	ProjectileMovement->Deactivate();
}

