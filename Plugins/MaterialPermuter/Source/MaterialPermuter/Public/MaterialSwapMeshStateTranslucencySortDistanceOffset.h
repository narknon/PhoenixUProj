#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateFloatMap.h"
#include "MaterialSwapMeshStateTranslucencySortDistanceOffset.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateTranslucencySortDistanceOffset : public UMaterialSwapMeshStateFloatMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TranslucencySortDistanceOffset;
    
    UMaterialSwapMeshStateTranslucencySortDistanceOffset();
};

