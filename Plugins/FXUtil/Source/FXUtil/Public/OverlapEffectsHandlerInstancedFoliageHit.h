#pragma once
#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "OverlapEffectsHandlerMinimumSpeedBase.h"
#include "OverlapEffectsHandlerInstancedFoliageHit.generated.h"

class UOverlapEffectsHandlerEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerInstancedFoliageHit : public UOverlapEffectsHandlerMinimumSpeedBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EPhysicalSurface> SurfaceType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> Effects;
    
    UOverlapEffectsHandlerInstancedFoliageHit();
};

