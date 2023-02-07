#pragma once
#include "CoreMinimal.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsTranslucency.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsTranslucency : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TranslucencySortPriority;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TranslucencySortDistanceOffset;
    
    USpawnByPrimitiveOptionsTranslucency();
};

