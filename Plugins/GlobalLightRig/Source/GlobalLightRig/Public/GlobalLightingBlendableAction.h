#pragma once
#include "CoreMinimal.h"
#include "ActiveGlobalLightingBlendOps.h"
#include "EGlobalLightingBlendableInputType.h"
#include "GlobalLightingBlendableAction.generated.h"

class UGlobalLightingBlendableBase;
class UObject;

USTRUCT(BlueprintType)
struct FGlobalLightingBlendableAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendableBase* Blendable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveGlobalLightingBlendOps CachedActiveBlendOps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGlobalLightingBlendableInputType InputType;
    
    GLOBALLIGHTRIG_API FGlobalLightingBlendableAction();
};

