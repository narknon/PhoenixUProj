#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigMod.h"
#include "GlobalLightRigModFloatBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModFloatBase : public UGlobalLightRigMod {
    GENERATED_BODY()
public:
    UGlobalLightRigModFloatBase();
};

