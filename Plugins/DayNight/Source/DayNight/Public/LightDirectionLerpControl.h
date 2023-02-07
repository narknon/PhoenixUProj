#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LightDirectionLerpControl.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpControl : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ULightDirectionLerpControl();
};

