#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterParameterSet.h"
#include "MaterialPermuterParameterSetGroup.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterParameterSetGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UMaterialInterface>, FMaterialPermuterParameterSet> ParameterMap;
    
    FMaterialPermuterParameterSetGroup();
};

