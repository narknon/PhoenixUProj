#pragma once
#include "CoreMinimal.h"
#include "FXOverride.generated.h"

class UFXRule;
class UFXSystemAsset;

USTRUCT(BlueprintType)
struct FFXOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXRule*> Rules;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* ParticleSystem;
    
    SCENERIG_API FFXOverride();
};

