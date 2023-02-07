#pragma once
#include "CoreMinimal.h"
#include "ChromaSDKGuid.h"
#include "ChromaSDKEffectResult.generated.h"

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKEffectResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Result;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChromaSDKGuid EffectId;
    
    FChromaSDKEffectResult();
};

