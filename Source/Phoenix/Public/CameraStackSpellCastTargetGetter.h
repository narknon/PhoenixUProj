#pragma once
#include "CoreMinimal.h"
#include "CameraStackSecondaryTargetGetterBlend.h"
#include "CameraStackSpellCastTargetGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackSpellCastTargetGetter : public UCameraStackSecondaryTargetGetterBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timeout;
    
    UCameraStackSpellCastTargetGetter();
};

