// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class PLASMABOUNCE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(BlueprintReadOnly, Category="BaseCharacter")
	bool bIsAiming;

	UPROPERTY(EditAnywhere, Category="BaseCharacter")
	uint8 ProjectileCount;

	UPROPERTY(BlueprintReadOnly, Category="BaseCharacter")
	bool bCanFire;

	UPROPERTY(EditAnywhere, Category="BaseCharacter")
	float RateOfFire;

	UFUNCTION()
	void Turn(float Value);

	UFUNCTION()
	void Aim();

	UFUNCTION()
	void Fire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
