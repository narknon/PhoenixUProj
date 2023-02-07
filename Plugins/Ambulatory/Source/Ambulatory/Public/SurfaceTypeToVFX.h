#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SurfaceTypeToVFX.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FSurfaceTypeToVFX : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SurfaceTypeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* VFX;
    
    AMBULATORY_API FSurfaceTypeToVFX();
};

