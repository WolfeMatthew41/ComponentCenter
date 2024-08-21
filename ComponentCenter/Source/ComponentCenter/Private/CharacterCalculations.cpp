// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCalculations.h"

// Sets default values for this component's properties
UCharacterCalculations::UCharacterCalculations()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCharacterCalculations::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


//// Called every frame
//void UCharacterCalculations::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

//The general calculation that is used
int UCharacterCalculations::DamageCalculation(float AttackValue)
{
	return AttackValue;
}

//We have the damage calculation separated for the player because the enemies may do more damage in later waves
//This way we can keep the base attack stat on enemies and just 
int UCharacterCalculations::PlayerDamageCalculation(float AttackValue)
{
	float modifiedAtk = AttackValue;
	return DamageCalculation(modifiedAtk);
}

