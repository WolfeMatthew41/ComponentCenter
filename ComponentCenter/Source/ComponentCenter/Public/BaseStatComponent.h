// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPONENTCENTER_API UBaseStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBaseStatComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float HealthPoints;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float MaxHealthPoints;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float MoveSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float BaseMoveSpeed;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		float AttackStat;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
		TMap<FName, FName> TagToFunctionMap;

		void ApplyDamage(float Damage);
};
