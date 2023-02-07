#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GlobalLightRigMod.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigMod : public UObject {
    GENERATED_BODY()
public:
    UGlobalLightRigMod();
};

