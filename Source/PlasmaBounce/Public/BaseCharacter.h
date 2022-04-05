// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseProjectile.h"
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
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UArrowComponent* ShotRoot;

	UPROPERTY(BlueprintReadOnly, Category="BaseCharacter")
	bool bIsAiming;

	UPROPERTY(BlueprintReadWrite, Category="BaseCharacter")
	int ProjectileCount;

	UPROPERTY(BlueprintReadWrite, Category="BaseCharacter")
	bool bCanFire;

	UPROPERTY(BlueprintReadWrite, Category="BaseCharacter")
	float RateOfFire;

	UPROPERTY(EditAnywhere, Category="BaseCharacter")
	TSubclassOf<ABaseProjectile> ProjectileClass;

	UPROPERTY(BlueprintReadOnly, Category="BaseCharacter")
	TArray<ABaseProjectile*> ProjectilePool;

	UFUNCTION(BlueprintCallable,  Category="BaseCharacter")
	void AddProjectile();

	UFUNCTION(BlueprintImplementableEvent,  Category="BaseCharacter")
	void FireAllProjectiles();

	UFUNCTION()
	void Turn(float Value);

	UFUNCTION()
	void Aim();

	UFUNCTION()
	void Fire();

	FTimerHandle TimerHandle_TimeBetweenShots;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
