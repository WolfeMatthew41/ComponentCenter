// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseStatComponent.h"
#include "Misc/OutputDeviceNull.h"
#include "CharacterCalculations.h"


UBaseStatComponent::UBaseStatComponent() 
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UBaseStatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseStatComponent::ApplyDamage(float AttackersStat)
{
	UCharacterCalculations* charCalc = NewObject<UCharacterCalculations>();
	float damage = charCalc->DamageCalculation(AttackersStat);

	HealthPoints -= damage;

	if (HealthPoints <= 0)
	{
		if (TagToFunctionMap.Contains("Death"))
		{
			FName functionName = TagToFunctionMap["Death"];
			FOutputDeviceNull ar;
			GetOwner()->CallFunctionByNameWithArguments(*functionName.ToString(), ar, nullptr, true);
		}
	}
}