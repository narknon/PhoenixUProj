#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RecordMovieInterface.h"
#include "RecordMovieWin64.generated.h"

UCLASS(Blueprintable)
class URecordMovieWin64 : public UObject, public IRecordMovieInterface {
    GENERATED_BODY()
public:
    URecordMovieWin64();
    
    // Fix for true pure virtual functions not being implemented
};

