// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HealthComponent.h"
#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

UCLASS()
class ABaseEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	UBoxComponent* CollisionBoxComponent;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	UHealthComponent* HealthComponent;

	UPROPERTY(VisibleDefaultsOnly, Category="Components")
	UWidgetComponent* WidgetComponent;

	UFUNCTION()
	void HandleTakeDamage(UHealthComponent* ThisHealthComponent, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
