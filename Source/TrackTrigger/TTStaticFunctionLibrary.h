// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "TTStaticFunctionLibrary.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTTEvent
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TrackTrigger)
    float Time;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TrackTrigger)
    float Value;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TrackTrigger)
    FString TrackName;
    
    
    FTTEvent(const float initTime, const float initValue, const FString initTrackName)
    {
        Time = initTime;
        Value = initValue;
        TrackName = initTrackName;
    }
    
    FTTEvent()
    {
        Time = 0;
        Value = 0;
        TrackName = FString(TEXT("None"));
    }
    
    //    Will need this for Garbage Collection if contains a pointer to an object
    //    void Destroy()
    //    {
    //        PSCPtr = nullptr;
    //    }
};

struct FTTEventComparePredicate
{
    
    bool operator()(const FTTEvent& lhs, const FTTEvent& rhs) const
    {
        return lhs.Time < rhs.Time;
    }
    
};

UCLASS()
class TRACKTRIGGER_API UTTStaticFunctionLibrary : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
