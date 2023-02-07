#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "BTT_Camera_Base.h"
#include "ECameraStackResetType.h"
#include "BTT_Camera_ResetCut.generated.h"

UCLASS(Blueprintable)
class UBTT_Camera_ResetCut : public UBTT_Camera_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackResetType ResetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator FixedArmRotationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RotationOffset;
    
    UBTT_Camera_ResetCut();
};

