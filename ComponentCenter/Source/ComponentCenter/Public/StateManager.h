// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpriteAnimationComponent.h"
#include "StateManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPONENTCENTER_API UStateManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateManager();

private:

	UPROPERTY()
	FName CurrentState = "None";

	UPROPERTY()
	bool IsLocked = false;

	UPROPERTY()
	class USpriteAnimationComponent* SpriteComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "State")
	void SetState(FName State, bool Lock = false);

	UFUNCTION(BlueprintCallable, Category = "State")
	FName GetState() const;

	UFUNCTION(BlueprintCallable, Category = "State")
	bool GetLock() const;
		
};
