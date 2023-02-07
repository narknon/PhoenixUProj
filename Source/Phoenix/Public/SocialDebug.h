#pragma once
#include "CoreMinimal.h"
#include "SocialDebug.generated.h"

USTRUCT(BlueprintType)
struct FSocialDebug {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> DebugStrings;
    
    PHOENIX_API FSocialDebug();
};

