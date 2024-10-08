// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterCalculations.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPONENTCENTER_API UCharacterCalculations : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterCalculations();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Damage")
	int DamageCalculation(float AttackValue);

	UFUNCTION(BlueprintCallable, Category = "Damage")
	int PlayerDamageCalculation(float AttackValue);

		
};
