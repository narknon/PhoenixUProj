#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialPermuterLoadingStrategies.h"
#include "MaterialPermuterLoadingStrategiesAsset.generated.h"

class UMaterialPermuterDynamicTrigger;

UCLASS(Blueprintable)
class MATERIALPERMUTER_API UMaterialPermuterLoadingStrategiesAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMaterialPermuterDynamicTrigger*> DynamicLoadingTriggers;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategies Built;
    
    UMaterialPermuterLoadingStrategiesAsset();
    UFUNCTION(BlueprintCallable)
    void BuildLoadingStrategies();
    
};

