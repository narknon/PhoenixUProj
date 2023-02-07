#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayMarkup.h"
#include "FXUpdate_ComponentHighContrastGameplayMarkupBase.h"
#include "FXUpdate_ComponentHighContrastGameplayMarkup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_ComponentHighContrastGameplayMarkup : public UFXUpdate_ComponentHighContrastGameplayMarkupBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastGameplayMarkup StencilValue;
    
    UFXUpdate_ComponentHighContrastGameplayMarkup();
};

