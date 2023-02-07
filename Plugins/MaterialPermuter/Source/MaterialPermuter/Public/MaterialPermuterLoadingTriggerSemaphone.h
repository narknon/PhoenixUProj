#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingTriggerSemaphone.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingTriggerSemaphone {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> Requests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastCount;
    
    FMaterialPermuterLoadingTriggerSemaphone();
};

