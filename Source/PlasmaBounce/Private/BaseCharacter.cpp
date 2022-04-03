// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsAiming = false;
	ProjectileCount = 10;
	bCanFire = true;
	RateOfFire = 0.2;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::Turn(float Value)
{
	if(bIsAiming && bCanFire)
	{
		AddControllerYawInput(Value);
	}
}

void ABaseCharacter::Aim()
{
	bIsAiming = true;
}

void ABaseCharacter::Fire()
{
	bIsAiming = false;
	if(bCanFire)
	{
		
	}
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator ClampedRotation;
	ClampedRotation.Pitch = GetActorRotation().Pitch;
	ClampedRotation.Roll = GetActorRotation().Roll;
	ClampedRotation.Yaw = FMath::ClampAngle(GetActorRotation().Yaw, -80.f, 80.f);
	
	SetActorRotation(ClampedRotation);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::Turn);
	PlayerInputComponent->BindAction("Aim/Fire", IE_Pressed, this,&ABaseCharacter::Aim);
	PlayerInputComponent->BindAction("Aim/Fire", IE_Pressed, this,&ABaseCharacter::Fire);
	
}

