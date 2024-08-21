// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManager.h"

// Sets default values for this component's properties
UStateManager::UStateManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UStateManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	SpriteComponent = Cast<USpriteAnimationComponent>(GetOwner()->GetComponentByClass(USpriteAnimationComponent::StaticClass()));
}


// Called every frame
void UStateManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FName UStateManager::GetState() const
{
	return CurrentState;
}

bool UStateManager::GetLock() const
{
	return IsLocked;
}

void UStateManager::SetState(FName State, bool Lock) 
{
	if (IsLocked)
	{
		if (State == CurrentState)
		{
			IsLocked = Lock;
			return;
		}
		return;
	}
	CurrentState = State;
	IsLocked = Lock;

	if (SpriteComponent)
	{
		SpriteComponent->SetState(CurrentState);
	}
}


