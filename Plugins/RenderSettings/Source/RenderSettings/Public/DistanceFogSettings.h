#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DistanceFog.h"
#include "DistanceFogSettings.generated.h"

class UMaterialInterface;
class UMaterialParameterCollection;

UCLASS(Blueprintable)
class RENDERSETTINGS_API UDistanceFogSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* DistanceFogMPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DistanceFogPPMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDistanceFog> Settings;
    
    UDistanceFogSettings();
};

