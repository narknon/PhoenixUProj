#pragma once
#include "CoreMinimal.h"
#include "EWorldBaseHeightAffect.h"
#include "RenderSettingsComponent.h"
#include "CameraHeightRenderSettingsComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCameraHeightRenderSettingsComponent : public URenderSettingsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartEffectHeightMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullEffectHeightMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWorldBaseHeightAffect Base;
    
    UCameraHeightRenderSettingsComponent();
};

