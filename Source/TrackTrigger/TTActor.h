// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TTStaticFunctionLibrary.h"
#include "TTActor.generated.h"

UCLASS()
class TRACKTRIGGER_API ATTActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATTActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
    UFUNCTION(BlueprintImplementableEvent, Category=TrackTrigger)
    void OnTrackTrigger(FTTEvent triggerEvent);

};
