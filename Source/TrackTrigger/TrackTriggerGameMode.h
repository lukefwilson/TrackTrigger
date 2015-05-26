// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "TTStaticFunctionLibrary.h"
#include "TTActor.h"
#include "TrackTriggerGameMode.generated.h"



//struct FTTTrack
//{
//    FString Name;
//    
//    bool operator==(const FTTTrack& Comparison) const
//    {
//        return Name == Comparison.Name;
//    }
//    
//    FTTTrack(const FString initName)
//    {
//        Name = initName;
//    }
//    
//    FTTTrack()
//    {
//        Name = FString(TEXT("None"));
//    }
//    
//    /**
//     * Serialize to Archive
//     */
////    friend FArchive& operator<<( FArchive& Ar, FBoneIndexPair& W )
////    {
////        return Ar << W.BoneIdx[0] << W.BoneIdx[1];
////    }
//};

UCLASS(minimalapi)
class ATrackTriggerGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATrackTriggerGameMode(const FObjectInitializer& ObjectInitializer);
    
    UFUNCTION(BlueprintCallable, Category=TrackTrigger)
    void RegisterForTrack(ATTActor *actor, FString trackName);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TrackTrigger)
    TArray<FTTEvent> TriggerEvents;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TrackTrigger)
    float PlayTime;
    
    FTTEvent NextEvent;
    
    BOOL MoreEvents;
    
    TMap<FString, TArray<ATTActor*> > RegisteredActors;
    
    

    virtual void Tick(float DeltaTime) override;
};



