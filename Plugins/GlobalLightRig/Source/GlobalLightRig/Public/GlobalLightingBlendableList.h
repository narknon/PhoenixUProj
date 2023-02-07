#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableList.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FGlobalLightingBlendableList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> Blendables;
    
    GLOBALLIGHTRIG_API FGlobalLightingBlendableList();
};

