#pragma once
#include "CoreMinimal.h"
#include "FrontendPlayerState.generated.h"

USTRUCT(BlueprintType)
struct FFrontendPlayerState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> Values;
    
    PERSISTENTDATA_API FFrontendPlayerState();
};

