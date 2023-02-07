#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_ComponentHighContrastGameplayMarkupBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_ComponentHighContrastGameplayMarkupBase : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnce;
    
    UFXUpdate_ComponentHighContrastGameplayMarkupBase();
};

