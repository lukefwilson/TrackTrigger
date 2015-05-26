// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TrackTrigger.h"
#include "TrackTriggerGameMode.h"
#include "TrackTriggerHUD.h"
#include "TrackTriggerCharacter.h"

ATrackTriggerGameMode::ATrackTriggerGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATrackTriggerHUD::StaticClass();
    
    PrimaryActorTick.bCanEverTick = true;
    
    for (int32 i = 0; i < 10; i++) {
        FTTEvent event(i+5, i, FString(TEXT("Test")));
        TriggerEvents.Add(event);
    }
    
    TriggerEvents.HeapPop(NextEvent, FTTEventComparePredicate());
    MoreEvents = true;
}

void ATrackTriggerGameMode::RegisterForTrack(ATTActor *actor, FString trackName) {
    TArray<ATTActor*, FDefaultAllocator>* trackActors = RegisteredActors.Find(trackName);

    if (trackActors != NULL) {
        trackActors->Add(actor);
    } else {
        TArray<ATTActor*> newTrackActors;
        newTrackActors.Add(actor);
        RegisteredActors.Add(trackName, newTrackActors);
    }
    
}

void ATrackTriggerGameMode::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); // Call parent class tick function
    
    PlayTime += DeltaTime;
    
    while (MoreEvents == true && PlayTime > NextEvent.Time) {
        TArray<ATTActor*, FDefaultAllocator>* trackActors = RegisteredActors.Find(NextEvent.TrackName);
        
        if (trackActors != NULL) {
            for (auto Itr(trackActors->CreateIterator()); Itr; Itr++) {
                if(!(*Itr)->IsValidLowLevel()) continue;
                
                (*Itr)->OnTrackTrigger(NextEvent);
            }
        }
        
        if (TriggerEvents.Num() > 0) {
            TriggerEvents.HeapPop(NextEvent, FTTEventComparePredicate());
        } else {
            MoreEvents = false;
        }
    }
    
}