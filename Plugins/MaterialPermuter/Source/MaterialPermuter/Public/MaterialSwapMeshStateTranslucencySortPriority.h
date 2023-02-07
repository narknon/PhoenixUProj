#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapMeshStateIntMap.h"
#include "MaterialSwapMeshStateTranslucencySortPriority.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMaterialSwapMeshStateTranslucencySortPriority : public UMaterialSwapMeshStateIntMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TranslucencySortPriority;
    
    UMaterialSwapMeshStateTranslucencySortPriority();
};

