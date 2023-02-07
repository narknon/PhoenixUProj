#pragma once
#include "CoreMinimal.h"
#include "LightAdaptationComponent.h"
#include "LightAdaptationComponentAuto.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API ULightAdaptationComponentAuto : public ULightAdaptationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeepScanChildren;
    
    ULightAdaptationComponentAuto();
};

