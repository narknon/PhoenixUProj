#pragma once
#include "CoreMinimal.h"
#include "TimeDateSourceStack.generated.h"

class UTimeSource;

USTRUCT(BlueprintType)
struct DAYNIGHT_API FTimeDateSourceStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeSource*> TimeSources;
    
    FTimeDateSourceStack();
};

