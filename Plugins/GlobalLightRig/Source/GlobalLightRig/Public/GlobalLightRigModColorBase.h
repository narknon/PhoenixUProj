#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigMod.h"
#include "GlobalLightRigModColorBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModColorBase : public UGlobalLightRigMod {
    GENERATED_BODY()
public:
    UGlobalLightRigModColorBase();
};

