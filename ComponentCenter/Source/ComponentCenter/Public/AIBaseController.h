// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIComponent.h"
#include "AIBaseController.generated.h"

/**
 * 
 */
UCLASS()
class COMPONENTCENTER_API AAIBaseController : public AAIController
{
	GENERATED_BODY()

public:
	AAIBaseController();

protected:

	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(Transient)
	UBlackboardComponent* BlackboardComponent;

};
