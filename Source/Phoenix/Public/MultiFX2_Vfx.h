#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_Vfx.generated.h"

class UParticleSystem;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_Vfx : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* VFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
public:
    UMultiFX2_Vfx();
};

