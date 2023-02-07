#pragma once
#include "CoreMinimal.h"
#include "FXEnd.h"
#include "MultiFX2End_Vfx.generated.h"

class UParticleSystem;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2End_Vfx : public UFXEnd {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* VFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
public:
    UMultiFX2End_Vfx();
};

