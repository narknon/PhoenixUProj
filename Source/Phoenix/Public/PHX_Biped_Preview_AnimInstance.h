#pragma once
#include "CoreMinimal.h"
#include "Biped_AnimInstance.h"
#include "PHX_Biped_Preview_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPHX_Biped_Preview_AnimInstance : public UBiped_AnimInstance {
    GENERATED_BODY()
public:
    UPHX_Biped_Preview_AnimInstance();
};

