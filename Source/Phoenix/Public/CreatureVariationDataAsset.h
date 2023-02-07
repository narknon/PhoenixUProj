#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureFemaleVariationSettings.h"
#include "CreatureMaleVariationSettings.h"
#include "CreatureMeshVariation.h"
#include "CreatureVariationDataAsset.generated.h"

UCLASS(Blueprintable)
class UCreatureVariationDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMeshVariations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureMeshVariation> MeshVariationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapMaterialsForFemale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureMaleVariationSettings MaleVariationSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureFemaleVariationSettings FemaleVariationSettings;
    
    UCreatureVariationDataAsset();
};

