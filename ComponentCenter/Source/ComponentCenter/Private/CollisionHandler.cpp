// Fill out your copyright notice in the Description page of Project Settings.


#include "CollisionHandler.h"
#include "GameFramework/Actor.h"
#include "Misc/OutputDeviceNull.h"
#include "BaseStatComponent.h"

// Sets default values for this component's properties
UCollisionHandler::UCollisionHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	//GetOwner()->OnActorBeginOverlap.AddDynamic(this, &UCollisionHandler::OnOverlapBegin);
}


// Called when the game starts
void UCollisionHandler::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//CollisionComponent = Cast<UPrimitiveComponent>(GetOwner()->GetComponentByClass(UPrimitiveComponent::StaticClass()));
	if (CollisionComponent)
	{
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UCollisionHandler::OnOverlapBegin);
	}
}


//// Called every frame
//void UCollisionHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UCollisionHandler::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != GetOwner()))
	{
		for (const FName& Tag : TagList)
		{
			if (OtherActor->ActorHasTag(Tag))
			{
				if (TagToFunctionMap.Contains(Tag))
				{
					UBaseStatComponent* Defendent = GetOwner()->FindComponentByClass<UBaseStatComponent>();
					UBaseStatComponent* AttackersStat = OtherActor->FindComponentByClass<UBaseStatComponent>();

					if (AttackersStat && Defendent)
					{
						float AttackStat = AttackersStat->AttackStat;
						Defendent->ApplyDamage(AttackStat);
					}
					
					FName functionName = TagToFunctionMap[Tag];
					FOutputDeviceNull ar;
					GetOwner()->CallFunctionByNameWithArguments(*functionName.ToString(), ar, nullptr, true);
				}
			}
		}
	}
}

