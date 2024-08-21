// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBaseController.h"

AAIBaseController::AAIBaseController()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}

void AAIBaseController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UAIComponent* AIComponent = InPawn->FindComponentByClass<UAIComponent>();

	if (AIComponent && AIComponent->BehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*(AIComponent->BehaviorTree->BlackboardAsset));
		RunBehaviorTree(AIComponent->BehaviorTree);
	}
}