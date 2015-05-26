// Fill out your copyright notice in the Description page of Project Settings.

#include "TrackTrigger.h"
#include "TTActor.h"
#include "Engine.h"


// Sets default values
ATTActor::ATTActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATTActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATTActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
//
//void ATTActor::OnTrackTrigger(FTTEvent triggerEvent) {
//     GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Trigger event"));
//}

