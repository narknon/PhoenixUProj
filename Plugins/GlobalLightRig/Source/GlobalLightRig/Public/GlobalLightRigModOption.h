#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightRigModOption.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModOption : public UObject {
    GENERATED_BODY()
public:
    UGlobalLightRigModOption();
};

