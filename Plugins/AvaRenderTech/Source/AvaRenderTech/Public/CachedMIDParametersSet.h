#pragma once
#include "CoreMinimal.h"
#include "CachedMIDParameters.h"
#include "CachedMIDParametersSet.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct AVARENDERTECH_API FCachedMIDParametersSet {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMaterialInstanceDynamic>, FCachedMIDParameters> MIDMap;
    
    FCachedMIDParametersSet();
};

