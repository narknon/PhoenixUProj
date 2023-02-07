#pragma once
#include "CoreMinimal.h"
#include "MIDTextureParameter.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMIDTextureParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* Value;
    
    FMIDTextureParameter();
};

