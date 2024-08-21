// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/CapsuleComponent.h"
#include "CollisionHandler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMPONENTCENTER_API UCollisionHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollisionHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	//FName CollisionTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	TArray<FName> TagList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	TMap<FName, FName> TagToFunctionMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UPrimitiveComponent* CollisionComponent;
};
